%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "ast.h"
    extern int yylex();
    extern char* yytext;
    void yyerror(char *s);
%}
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

%start inicio

%%

inicio: funcoes { printf("teste");};

/* <--colocar recursao--> */
funcoes: FUNCTION COLON IDENTIFIER funcao_tipo_retorno funcao_parametros funcao_variaveis comandos return_fun END_FUNCTION {printf("end\n");};

return_fun:RETURN L_PARENTESE NUM_INTEGER R_PARENTESE {printf("\nreturn\n");};

funcao_tipo_retorno: RETURN_TYPE COLON tipos{printf("tip_return\n");};

funcao_variaveis: 
    | funcao_variaveis VARIABLE COLON IDENTIFIER TYPE COLON tipos {printf("func_var\n");}
;

funcao_parametros:
    | funcao_parametros PARAMETER COLON IDENTIFIER TYPE COLON tipos {printf("params\n");}
;

/* <--cofirir printf e scanf--> */
comandos: 
    | comandos WHILE L_PARENTESE expressao R_PARENTESE R_CURLY_BRACKET comandos L_CURLY_BRACKET {printf("while\n");}
    | comandos IF L_PARENTESE expressao COMMA comandos COMMA comandos R_PARENTESE ponto_virgula {printf("if\n");}
    | comandos IF L_PARENTESE expressao COMMA comandos R_PARENTESE ponto_virgula { printf("if_else\n");}
    | comandos PRINTF L_PARENTESE STRING COMMA expressao R_PARENTESE ponto_virgula  {printf("printf\n");}
    | comandos PRINTF L_PARENTESE STRING R_PARENTESE ponto_virgula {printf("\nprintf2\n");}
    | comandos SCANF L_PARENTESE STRING COMMA BITWISE_AND L_PARENTESE IDENTIFIER R_PARENTESE R_PARENTESE ponto_virgula {printf("scanf\n");}
    | comandos L_PARENTESE expressao R_PARENTESE R_CURLY_BRACKET comandos L_CURLY_BRACKET ELSE R_CURLY_BRACKET comandos L_CURLY_BRACKET ponto_virgula{printf("alguma coisa \n");}
;

ponto_virgula: { }
    | SEMICOLON { }
    | COMMA {}
;

expressao: 
    |expressao expressao_aditiva {printf("exp_aditiva\n");}
    |expressao expressao_comparativa {printf("exp_comp\n");}
    |expressao expressao_logica {printf("exp_logica\n");}
    |expressao expressao_multiplicativa {printf("exp_mul\n")};
;

expressao_aditiva: expressao_primaria {printf("expr_primar\n");}
    | PLUS L_PARENTESE expressao_aditiva COMMA expressao_primaria R_PARENTESE {printf("PLUS op\n");}
    | MINUS L_PARENTESE expressao_aditiva COMMA expressao_primaria R_PARENTESE {printf("MINUS op\n");}
;

expressao_comparativa: expressao_primaria

    | GREATER_THAN L_PARENTESE expressao COMMA  expressao R_PARENTESE {printf("greather than");}
    | GREATER_EQUAL L_PARENTESE expressao COMMA  expressao R_PARENTESE {printf("greather equal");}
    | LESS_THAN L_PARENTESE expressao COMMA  expressao R_PARENTESE {printf("less than");}
    | LESS_EQUAL L_PARENTESE expressao COMMA  expressao R_PARENTESE {printf("less equal");}
    | EQUAL L_PARENTESE expressao COMMA  expressao R_PARENTESE {printf("equal");}
    | NOT_EQUAL L_PARENTESE expressao COMMA  expressao R_PARENTESE {printf("not equal");}
;

expressao_logica: expressao_primaria
    | LOGICAL_AND L_PARENTESE expressao COMMA expressao R_PARENTESE {printf("&&");}
    | LOGICAL_OR L_PARENTESE expressao COMMA expressao R_PARENTESE {printf("||");}
;

expressao_multiplicativa: expressao_primaria
    |MULTIPLY L_PARENTESE expressao COMMA expressao R_PARENTESE {printf("mul");}
    |DIV L_PARENTESE expressao COMMA expressao R_PARENTESE {printf("div");}

expressao_primaria: IDENTIFIER {printf("identifier\n");}
    | NUM_INTEGER {printf("num_interger\n");}
    | CHARACTER {printf("characater\n");}
    | L_PARENTESE expressao R_PARENTESE {printf("(expression)\n");}
;

tipos: INT {printf("int \n");}
    | CHAR {printf("char \n");}
    | VOID {printf("void \n");}
;
%%

void yyerror(char *s) {
    printf("Erro %s",s);
}

int main(int argc, char **argv) {
    yyparse();
    return 0;
}