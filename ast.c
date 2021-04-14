#include "ast.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "sintatico.tab.h"
#include <string.h>

struct parametros {
    int tipo;
    Expressao* id;
    Parametros *prox;
};

struct variaveis{
    int tipo;
    Expressao *id;   
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
    Expressao *expr_comandos;
    Comandos *cmd_if;
    Comandos *cmd_else;
    Expressao *cmd_printf;
    Expressao *cmd_scanf;
    Comandos *cmd_return;
    Comandos *prox;
};

struct function_struct{
    Expressao nome;
    int tipo_retorno;
    Expressao *exp_retorno;
    Parametros *parametros;
    Variaveis *variaveis;
    Comandos *function_comandos;
    Function_struct * prox;
};


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
    if(tipo == IDENTIFIER || tipo == STRING){
        char *aux = (char*) malloc(sizeof(strlen(str))+4);
        strcpy(aux,str);
        novo->str = aux;
    }
    
    novo->filho_direito = filho_direito;
    novo->filho_esquerdo = filho_direito;
    // novo->value = value;
    // novo->dimensaoArray = dimensaoArray;
    return novo;
}

Comandos *cmd_generico(int tipo, Expressao *exp, Comandos *cmd1, Comandos *cmd2, Expressao *exp2){
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
            novo->cmd_printf = exp2;
            break;
        case SCANF:
            novo->expr_comandos = exp;
            novo->cmd_scanf= exp2;
            break;
    }
    return novo;
}

Comandos* setProxGenerico(Comandos *atual, Comandos *prox) {
    atual->prox = prox;
    return atual;
}

Function_struct *novaFunction(Expressao *nome, int tipo_retorno, Expressao *exp_retorno, Parametros *parametros, Variaveis *variaveis, Comandos *function_comandos, Function_struct *proximo) {
    Function_struct *novo = (Function_struct *) malloc(sizeof(Function_struct));
    printf("%s\n",nome->str);
    // novo->tipo_retorno = tipo_retorno;
    // novo->parametros = parametros;
    // novo->variaveis = variaveis;
    // novo->function_comandos = function_comandos;
    novo->prox = proximo;
    return novo;
}

Parametros *novoParametro(Expressao *id, int tipo, Parametros *prox) {
    Parametros *novo = (Parametros *) malloc(sizeof(Parametros));
    novo->id = id;
    novo->tipo = tipo;
    novo->prox = prox;
    return novo;
}

Variaveis *novaVariavel(Expressao *id, int tipo, Variaveis *prox) {
    Variaveis *novo = (Variaveis *) malloc(sizeof(Variaveis));
    novo->id = id;
    novo->tipo = tipo;
    novo->prox = prox;
    return novo;
}