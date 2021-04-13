#include "ast.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "sintatico.tab.h"
#include <string.h>

struct no {
    int tipo;
    //ponteiro para as structs
    expression x;
};

struct parametros {
    char* id;
    int tipo;
    Parametros *prox;
};

struct variaveis{
    int tipo;
    char *id;   
    Variaveis *prox;
};

struct expressao{
    int tipo; //+ - * / % ++ += -- -= ...
    int value;
    char * str;
    int dimensaoArray;
    Expressao *filho_esquerdo;
    Expressao *filho_direito;
};

struct cmd_expressao{
    Expressao *exp;
    Cmd_expressao *prox;
};

struct comandos{
    int tipo; // expr ou tipo comando (if, while, for...)
    //if, while,
    Cmd_expressao *expr_comandos;
    Cmd_expressao *cmd_if;
    Cmd_expressao *cmd_else;
    Cmd_expressao *cmd_printf;
    Cmd_expressao *cmd_scanf;
    Return_struct *cmd_return;
    Comandos *prox;
};

struct function_struct{
    char* nome;
    int tipo_retorno;
    Parametros *parametros;
    Variaveis *variaveis;
    Cmd_expressao *function_comandos;
};

void analisaAST(No *t){
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

            break;
        case PRINTF:

            break;
        case SCANF:

            break;
        default:
        break;
    }
}

No* inserirNo(int tipo /*,colocar outros ponteiros/parametros*/){
    No* treeNode = (No*) malloc(sizeof(No));
    treeNode->tipo = tipo;
    //se comando IF, printf, scanf, return -> fazer algo
    // if(tipo == IF || tipo == PRINTF || tipo == SCANF || tipo == RETURN){

    // }else{

    // }
    //operações de adição, comparacao e logica fazer de outro jeito
   
    return treeNode;
}

No *novo_no(int tipo, expression x) {
    No *novo;
    novo = (No *) malloc(sizeof(No));
    novo->tipo = tipo;
    novo->x = x;
    return novo;
}

Cmd_expressao *novoCmdExpressao(Expressao *exp, Cmd_expressao *prox) {
    Cmd_expressao *novo;
    novo = (Cmd_expressao *) malloc(sizeof(Cmd_expressao));
    novo->exp = exp;
    novo->prox = prox;
    return novo;
}

Expressao *novaExpressao(int tipo, int value, char *str, int dimensaoArray, Expressao *filho_esquerdo, Expressao *filho_direito){
    Expressao *novo;
    novo = (Expressao *) malloc(sizeof(Expressao));
    novo->tipo = tipo;
    // printf("tipo %d", tipo);
    // if (tipo == PLUS || tipo == MINUS || tipo == MULTIPLY || tipo == DIV || tipo == REMAINDER || tipo == LOGICAL_AND || tipo == LOGICAL_OR || tipo == GREATER_THAN || tipo == GREATER_EQUAL || tipo == LESS_THAN || tipo == LESS_EQUAL || tipo == EQUAL || tipo == NOT_EQUAL) {
    //     novo->str = NULL;
    //     novo->filho_esquerdo = filho_esquerdo;
    //     novo->filho_direito = filho_direito;
    // }else if (tipo == INC || tipo == DEC || tipo == ADD_ASSIGN || tipo == MINUS_ASSIGN){
    //     novo->str = NULL;
    //     novo->filho_esquerdo = filho_esquerdo;
    //     novo->filho_direito = NULL;
    // } else if (tipo == NUM_INTEGER || tipo == IDENTIFIER || tipo == STRING) {
    //     strcpy(novo->str, str);
    //     novo->filho_direito = NULL;
    //     novo->filho_esquerdo = NULL;
    // }
    // novo->value = value;
    // novo->dimensaoArray = dimensaoArray;
    return novo;
}

Comandos *cmd_generico(int tipo, Cmd_expressao *exp, Cmd_expressao *cmd1, Cmd_expressao *cmd2){
    Comandos *novo = (Comandos *)malloc(sizeof(Comandos));
    novo->tipo = tipo;
    switch(tipo){
        case IF: 
            novo->expr_comandos = exp;
            novo->cmd_if = cmd1;
            novo->cmd_else = cmd2;
            break;
        case PRINTF:
            novo->expr_comandos = exp;
            novo->cmd_printf = cmd1;
            break;
        case SCANF:
            novo->expr_comandos = exp;
            novo->cmd_scanf= cmd1;
            break;
    }
    return novo;
}

void setProxGenerico(Comandos *atual, Comandos *prox) {
    atual->prox = prox;
}

Comandos *novoComandos(int tipo, Cmd_expressao expr_comandos, If_struct * cmd_if, Printf_struct * cmd_printf, Scanf_struct * cmd_scanf){
    Comandos *novo = (Comandos*) malloc(sizeof(Comandos));
    // novo->tipo = tipo;
    // novo->expr_comandos = expr_comandos;
    // novo->cmd_if = cmd_if;
    // novo->cmd_printf = cmd_printf;
    // novo->cmd_scanf = cmd_scanf;
    // novo->cmd_return = cmd_return;
    return novo;
}

Function_struct *novaFunction(char *nome, int tipo_retorno, Parametros *parametros, Variaveis *variaveis, Cmd_expressao *function_comandos) {
    Function_struct *novo = (Function_struct *) malloc(sizeof(Function_struct));
    // strcpy(novo->nome, nome);
    // novo->tipo_retorno = tipo_retorno;
    // novo->parametros = parametros;
    // novo->variaveis = variaveis;
    // novo->function_comandos = function_comandos;
    return novo;
}

Parametros *novoParametro(char *id, int tipo, Parametros *prox) {
    Parametros *novo = (Parametros *) malloc(sizeof(Parametros));
    // strcpy(novo->id, id);
    // novo->tipo = tipo;
    // novo->prox = prox;
    return novo;
}

Variaveis *novaVariavel(char *id, int tipo, Variaveis *prox) {
    Variaveis *novo = (Variaveis *) malloc(sizeof(Variaveis));
    // strcpy(novo->id, id);
    // novo->tipo = tipo;
    // novo->prox = prox;
    return novo;
}