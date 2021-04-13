%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "ast.h"
    extern int yylex();
    extern int yyparse();
    extern char* yytext;
    void yyerror(char *s);
    Function_struct *AST = NULL;
%}

%union {
    char *str;
    int num;
    Parametros *parametros;
    Variaveis *variaveis;
    Cmd_expressao *expressao;
    Comandos *comandos;
    Expressao *expr;
    Function_struct *funcao;
}

%token FUNCTION
%token CHARACTER
%token VOID
%token INT
%token NUM_INTEGER
%token CHAR
%token RETURN
%token BREAK
%token SWITCH
%token CASE
%token DEFAULT
%token DO_WHILE
%token WHILE
%token FOR
%token IF
%token ELSE
%token TYPEDEF
%token STRUCT
%token PLUS
%token MINUS
%token MULTIPLY
%token DIV
%token REMAINDER
%token INC
%token DEC
%token BITWISE_AND
%token BITWISE_OR
%token BITWISE_NOT
%token BITWISE_XOR
%token NOT
%token LOGICAL_AND
%token LOGICAL_OR
%token EQUAL
%token NOT_EQUAL
%token LESS_THAN
%token GREATER_THAN
%token GREATER_EQUAL
%token LESS_EQUAL
%token R_SHIFT
%token L_SHIFT
%token ASSIGN
%token ADD_ASSIGN
%token MINUS_ASSIGN
%token SEMICOLON
%token COMMA
%token COLON
%token L_PARENTESE
%token R_PARENTESE
%token L_CURLY_BRACKET
%token R_CURLY_BRACKET
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token TERNARY_CONDITIONAL
%token NUMBER_SIGN
%token POINTER
%token PRINTF
%token SCANF
%token DEFINE
%token EXIT
%token IDENTIFIER
%token RETURN_TYPE
%token VARIABLE
%token TYPE
%token PARAMETER
%token END_FUNCTION
%token GLOBAL
%token STRING
%token VALUE
%token CONSTANT

%type <funcao> inicio
%type <funcao> funcoes
%type <num> tipos funcao_tipo_retorno
%type <expr> expressao_primaria expressao_aditiva expressao_comparativa expressao_logica
%type <expr> expressao_multiplicativa
%type <parametros> funcao_parametros
%type <variaveis> funcao_variaveis
%type <expr> expressao 
%type <comandos> comandos
%type <expr> lista_comandos
%type <comandos> if
%type <comandos> printf
%type <comandos> scanf

%start inicio

%%

inicio: funcoes {AST = $1;};

funcoes: 
    | funcoes FUNCTION COLON expressao_primaria funcao_tipo_retorno funcao_parametros funcao_variaveis lista_comandos return_fun END_FUNCTION {}
;

return_fun:RETURN L_PARENTESE NUM_INTEGER R_PARENTESE {};

funcao_tipo_retorno: RETURN_TYPE COLON tipos{};

funcao_variaveis: {$$ = NULL ;}
    | funcao_variaveis VARIABLE COLON expressao_primaria TYPE COLON tipos {$$ = novaVariavel($4, $7, $1);}
;

funcao_parametros: { $$ = NULL;}
    | funcao_parametros PARAMETER COLON expressao_primaria TYPE COLON tipos {$$ = novoParametro($4, $7, $1);}
;

lista_comandos: {$$ = NULL; }
    | lista_comandos comandos {  }
;

comandos: if ponto_virgula lista_comandos {  }
    | printf ponto_virgula lista_comandos {  }
    | scanf ponto_virgula lista_comandos {  }
;

scanf: SCANF L_PARENTESE expressao_primaria COMMA BITWISE_AND L_PARENTESE expressao_primaria R_PARENTESE R_PARENTESE ponto_virgula {}
;

printf: PRINTF L_PARENTESE expressao_primaria COMMA expressao R_PARENTESE { }
    | PRINTF L_PARENTESE expressao_primaria R_PARENTESE {}
;

if: IF L_PARENTESE expressao COMMA comandos COMMA comandos R_PARENTESE {}
    | IF L_PARENTESE expressao COMMA comandos R_PARENTESE {  }
;

ponto_virgula: { }
    | SEMICOLON { }
    | COMMA {}
;

expressao: {$$ = NULL; }
    | expressao expressao_aditiva {}
    | expressao expressao_comparativa {}
    | expressao expressao_logica {}
    | expressao expressao_multiplicativa {};
;

expressao_aditiva: expressao_primaria {$$ = $1;}
    | PLUS L_PARENTESE expressao_aditiva COMMA expressao_aditiva R_PARENTESE {$$ = novaExpressao(PLUS,0,NULL,0,$3,$5);}
    | MINUS L_PARENTESE expressao_aditiva COMMA expressao_aditiva R_PARENTESE {$$ = novaExpressao(MINUS,0,NULL,0,$3,$5);}
;

expressao_comparativa: GREATER_THAN L_PARENTESE expressao COMMA expressao R_PARENTESE {$$ = novaExpressao(GREATER_THAN,0,NULL,0,$3,$5);}
    | GREATER_EQUAL L_PARENTESE expressao COMMA  expressao R_PARENTESE {$$ = novaExpressao(GREATER_EQUAL,0,NULL,0,$3,$5);}
    | LESS_THAN L_PARENTESE expressao COMMA  expressao R_PARENTESE {$$ = novaExpressao(LESS_THAN,0,NULL,0,$3,$5);}
    | LESS_EQUAL L_PARENTESE expressao COMMA  expressao R_PARENTESE {$$ = novaExpressao(LESS_EQUAL,0,NULL,0,$3,$5);}
    | EQUAL L_PARENTESE expressao COMMA  expressao R_PARENTESE {$$ = novaExpressao(EQUAL,0,NULL,0,$3,$5);}
    | NOT_EQUAL L_PARENTESE expressao COMMA  expressao R_PARENTESE {$$ = novaExpressao(NOT_EQUAL,0,NULL,0,$3,$5);}
;

expressao_logica: LOGICAL_AND L_PARENTESE expressao COMMA expressao R_PARENTESE {$$ = novaExpressao(LOGICAL_AND,0,NULL,0,$3,$5);}
    | LOGICAL_OR L_PARENTESE expressao COMMA expressao R_PARENTESE {$$ = novaExpressao(LOGICAL_OR,0,NULL,0,$3,$5);}
;

expressao_multiplicativa: MULTIPLY L_PARENTESE expressao COMMA expressao R_PARENTESE {$$ = novaExpressao(MULTIPLY,0,NULL,0,$3,$5);}
    | DIV L_PARENTESE expressao COMMA expressao R_PARENTESE {$$ = novaExpressao(DIV,0,NULL,0,$3,$5);}
;

expressao_primaria: IDENTIFIER { $$ = novaExpressao(IDENTIFIER,0,yytext,0,NULL,NULL);}
    | NUM_INTEGER {}
    | CHARACTER {}
    | L_PARENTESE expressao R_PARENTESE {}
    | STRING {$$ = novaExpressao(STRING,0,yytext,0,NULL,NULL);}
;

tipos: INT {$$ = INT; }
    | CHAR {$$ = CHAR; }
    | VOID {$$ = VOID; }
;
%%

void yyerror(char *s) {
    printf("Erro %s",yytext);
}

int main(int argc, char **argv) {
    printf(".data\n");
    // tratar prints
    printf(".text\n");
    // tratar comandos
    yyparse();
    return 0;
}