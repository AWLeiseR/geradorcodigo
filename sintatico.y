%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "ast.h"
    extern int yylex();
    extern int yyparse();
    extern char* yytext;
    void yyerror(char *s);
    Tree *AST = NULL;
%}

%union {
    char *str;
    int num;
    Parametros *parametros;
    Variaveis *variaveis;
    Cmd_expressao *expressao;
    Comandos *comandos;
    Expressao *expr;
    Printf_struct *printf_struct;
    Scanf_struct *scanf_struct;
    If_struct *if_struct;
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

%type <num> tipos funcao_tipo_retorno INT CHAR VOID IDENTIFIER STRING
%type <str> expressao_primaria
%type <parametros> funcao_parametros
%type <variaveis> funcao_variaveis
%type <expressao> expressao 
%type <comandos> comandos
%type <expressao> lista_comandos
%type <if_struct> if
%type <printf_struct> printf
%type <scanf_struct> scanf

%start inicio

%%

inicio: funcoes {printf("teste");};

funcoes: 
    | funcoes FUNCTION COLON expressao_primaria funcao_tipo_retorno funcao_parametros funcao_variaveis lista_comandos return_fun END_FUNCTION {novaFunction($4, $5, $6, $7, $8);}
;

return_fun:RETURN L_PARENTESE NUM_INTEGER R_PARENTESE {printf("\nreturn\n");};

funcao_tipo_retorno: RETURN_TYPE COLON tipos{$$ = $3; /*printf("%d\n", $3);*/};

funcao_variaveis: { }
    | funcao_variaveis VARIABLE COLON expressao_primaria TYPE COLON tipos {$$ = novaVariavel($4, $7, $1);/*printf("func_var\n");*/}
;

funcao_parametros: { }
    | funcao_parametros PARAMETER COLON expressao_primaria TYPE COLON tipos {$$ = novoParametro($4, $7, $1);printf("params\n");}
;

lista_comandos: { }
    | lista_comandos comandos { $$ = novoCmdExpressao($2, $1); }
;

comandos: if ponto_virgula lista_comandos { $$ = setProxGenerico($1, $3); }
    | printf ponto_virgula lista_comandos { $$ = setProxGenerico($1, $3); }
    | scanf ponto_virgula lista_comandos { $$ = setProxGenerico($1, $3); }
;

scanf: SCANF L_PARENTESE expressao_primaria COMMA BITWISE_AND L_PARENTESE expressao_primaria R_PARENTESE R_PARENTESE ponto_virgula {$$ = cmd_generico(SCANF,$3, $7,NULL);}
;

printf: PRINTF L_PARENTESE expressao_primaria COMMA expressao R_PARENTESE { $$ = cmd_generico(PRINTF,$3, $5,NULL);}
    | PRINTF L_PARENTESE expressao_primaria R_PARENTESE {$$ = cmd_generico(PRINTF,$3, NULL,NULL);}
;

if: IF L_PARENTESE expressao COMMA comandos COMMA comandos R_PARENTESE { $$ = cmd_generico(IF, $3, $5, $7); }
    | IF L_PARENTESE expressao COMMA comandos R_PARENTESE { $$ = cmd_generico(IF, $3, $5, NULL); }
;

ponto_virgula: { }
    | SEMICOLON { }
    | COMMA {}
;

expressao: { }
    | expressao expressao_aditiva {/*printf("exp_aditiva\n");*/}
    | expressao expressao_comparativa {/*printf("exp_comp\n");*/}
    | expressao expressao_logica {/*printf("exp_logica\n");*/}
    | expressao expressao_multiplicativa {/*printf("exp_mul\n");*/};
;

expressao_aditiva: expressao_primaria {/*printf("expr_primar\n");*/}
    | PLUS L_PARENTESE expressao_aditiva COMMA expressao_aditiva R_PARENTESE {/*printf("PLUS op\n");*/}
    | MINUS L_PARENTESE expressao_aditiva COMMA expressao_aditiva R_PARENTESE {/*printf("MINUS op\n");*/}
;

expressao_comparativa: GREATER_THAN L_PARENTESE expressao COMMA expressao R_PARENTESE {printf("greather than");}
    | GREATER_EQUAL L_PARENTESE expressao COMMA  expressao R_PARENTESE {printf("greather equal");}
    | LESS_THAN L_PARENTESE expressao COMMA  expressao R_PARENTESE {/*printf("less than");*/}
    | LESS_EQUAL L_PARENTESE expressao COMMA  expressao R_PARENTESE {printf("less equal");}
    | EQUAL L_PARENTESE expressao COMMA  expressao R_PARENTESE {/*printf("equal");*/}
    | NOT_EQUAL L_PARENTESE expressao COMMA  expressao R_PARENTESE {printf("not equal");}
;

expressao_logica: LOGICAL_AND L_PARENTESE expressao COMMA expressao R_PARENTESE {/*printf("&&");*/}
    | LOGICAL_OR L_PARENTESE expressao COMMA expressao R_PARENTESE {/*printf("||");*/}
;

expressao_multiplicativa: MULTIPLY L_PARENTESE expressao COMMA expressao R_PARENTESE {printf("mul");}
    | DIV L_PARENTESE expressao COMMA expressao R_PARENTESE {printf("div");}
;

expressao_primaria: IDENTIFIER {$$ = yytext; novaExpressao($1, 0, yytext, 0, NULL, NULL); }
    | NUM_INTEGER {}
    | CHARACTER {}
    | L_PARENTESE expressao R_PARENTESE {}
    | STRING {$$ = yytext; novaExpressao($1, 0, yytext, 0, NULL, NULL);}
;

tipos: INT {$$ = INT; /*printf(" %d \n",INT);*/}
    | CHAR {$$ = CHAR; /*printf(" %d \n",CHAR);*/}
    | VOID {$$ = VOID; /*printf(" %d \n",VOID);*/}
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