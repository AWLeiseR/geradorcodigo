#include "ast.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sintatico.tab.h>

typedef struct {
    char* nome;
    int tipo_retorno;
    parametros *parametros;
    COMANDOS function_comandos;
} FUNCTION_STRUCT;

typedef struct {
    char* id;
    int tipo;
    parametros *prox;
} parametros;

typedef struct{
    int tipo;
    //ponteiro para as structs
    expression x;
}no;

typedef struct{
    int tipo; // expr ou tipo comando (if, while, for...)
    Cmd_expressao expr_comandos;
    IF *cmd_if;
    PRINTF *cmd_printf;
    SCANF *cmd_scanf;
    RETURN *cmd_return;
    COMANDOS *prox;
}COMANDOS;

typedef struct{
    expressao *exp;
    Cmd_expressao *prox;
}Cmd_expressao;

typedef struct {
    int tipo; //+ - * / % ++ += -- -= ...
    int value;
    char * str;
    int dimensaoArray;
    expressao *filho_esquerdo;
    expressao *filho_direito;
} expressao;

// typedef struct {
//     int tipo; //== != <= >=
//     expressao *filho_esquerdo;
//     expressao *filho_direito;
// } expressaoCondicional;

typedef struct{
    expressaoCondicional *exprCond;
    COMANDOS *comandos_if;
    COMANDOS *comandos_else;
}IF_STRUCT;

typedef struct{
    char *string_impressao;
    Cmd_expressao *expressoes;
}PRINTF_STRUCT;

typedef struct{
    int formato;
   Cmd_expressao *expressoes;
}SCANF_STRUCT;

typedef struct{
    int num;
}NUMBER_STRUCT;

typedef struct {
    Cmd_expressao *expressoes;
}RETURN_STRUCT;

void analisaAST(tree *t){
    switch(t->tipo){
        case PLUS:
            break;
        case MINUS: 
            break;
        case DIV: 
            break;
        case IF:
            break;
        case FUNCTION:
            break
        case PRINTF:
            break;
        case SCANF:
            break;
        default:
        break;
    }
}

no* inserirNo(int tipo){
    no* treeNode = (no*) malloc(sizeof(no));
    treeNode->tipo = tipo;
    switch(tipo){
        case PLUS:
            //treeNode->x =
            break;
        case MINUS: 
            //treeNode->x =
            break;
        case DIV: 
            //treeNode->x =
            break;
        case IF:
            //treeNode->x =
            break;
        case FUNCTION:
            //treeNode->x =
            break
        case PRINTF:
            //treeNode->x =
            break;
        case SCANF:
            //treeNode->x =
            break;
        default:
            break;
    }

};

