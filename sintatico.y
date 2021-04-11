%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "ast.h"
    extern int yylex();
    extern int auxColune;
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
%token DO
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

%token STRING

%start inicio

%%

inicio: funcoes; 
/* <--colocar recursao--> */
funcoes: FUNCTION COLON IDENTIFIER funcao_tipo_retorno funcao_parametros funcao_variaveis comandos END_FUNCTION;

funcao_tipo_retorno: RETURN_TYPE COLON tipos;

funcao_variaveis: 
    | funcao_variaveis VARIABLE COLON IDENTIFIER TYPE COLON tipos
;

funcao_parametros:
    | funcao_parametros PARAMETER COLON IDENTIFIER TYPE COLON tipos
;

comandos_prime: comandos comandos_prime
    |
;

/* <--cofirir printf e scanf--> */
comandos: WHILE L_PARENTESE expressao R_PARENTESE R_CURLY_BRACKET comandos L_CURLY_BRACKET
    | IF L_PARENTESE expressao R_PARENTESE R_CURLY_BRACKET comandos L_CURLY_BRACKET
    | PRINTF L_PARENTESE STRING expressao R_PARENTESE
    | SCANF L_PARENTESE STRING expressao R_PARENTESE
    |L_PARENTESE expressao R_PARENTESE R_CURLY_BRACKET comandos L_CURLY_BRACKET ELSE R_CURLY_BRACKET comandos L_CURLY_BRACKET
    |expressao
;

expressao: expressao_aditiva
;

expressao_aditiva: expressao_primaria
    | expressao_aditiva PLUS expressao_primaria
    | expressao_aditiva MINUS expressao_primaria
;

expressao_primaria: IDENTIFIER
    | NUM_INTEGER
    | CHARACTER
    | L_PARENTESE expressao R_PARENTESE
;

tipos: INT;
    | CHAR;
    | VOID;
%%

void yyerror(void *s) {
    printf("Erro");
}

int main(int argc, char **argv) {
    yyparse(0);
    return 0;
}