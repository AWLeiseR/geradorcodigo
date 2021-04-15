#include "ast.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "sintatico.tab.h"
#include <string.h>
#include "funcoes.h"

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
    float valueFloat;
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
    Expressao *nome;
    int tipo_retorno;
    Expressao *exp_retorno;
    Parametros *parametros;
    Variaveis *variaveis;
    Comandos *function_comandos;
    Function_struct * prox;
};
//colocar variavel para saber de qual lado esta vindo 0 direita, 1 esquerda
int imprimeExpressao(Expressao *exp, int reg){
    Expressao *aux = exp;
    int auxReg;
    int auxReg2;
    if(aux){

        switch (aux->tipo){
            case NUM_INTEGER:
                //printf("--aux %f\n",aux->valueFloat);
                break;
            case STRING:
                printf("%s\n",aux->str);
                break;
            case EQUAL:
                auxReg = imprimeExpressao(aux->filho_direito,reg+1);
                auxReg2 = imprimeExpressao(aux->filho_esquerdo,auxReg);
                //chamar funcao equal
                break;
            case NOT_EQUAL:
                auxReg = imprimeExpressao(aux->filho_direito,reg+1);
                auxReg2 = imprimeExpressao(aux->filho_esquerdo,auxReg);
                break;
            case GREATER_EQUAL:
                auxReg = imprimeExpressao(aux->filho_direito,reg+1);
                auxReg2 = imprimeExpressao(aux->filho_esquerdo,auxReg);
                break;
            case GREATER_THAN:
                auxReg = imprimeExpressao(aux->filho_direito,reg+1);
                auxReg2 = imprimeExpressao(aux->filho_esquerdo,auxReg);
                break;
            case LESS_EQUAL:
                auxReg = imprimeExpressao(aux->filho_direito,reg+1);
                auxReg2 = imprimeExpressao(aux->filho_esquerdo,auxReg);
                break;
            case LESS_THAN:
                auxReg = imprimeExpressao(aux->filho_direito,reg+1);
                auxReg2 = imprimeExpressao(aux->filho_esquerdo,auxReg);
                break;
            case MULTIPLY:
                auxReg = imprimeExpressao(aux->filho_direito,reg+1);
                auxReg2 = imprimeExpressao(aux->filho_esquerdo,auxReg);
                break;
            case DIV:
                auxReg = imprimeExpressao(aux->filho_direito,reg+1);
                auxReg2 = imprimeExpressao(aux->filho_esquerdo,auxReg);
                break;
            case PLUS:
                auxReg = imprimeExpressao(aux->filho_direito,reg+1);
                auxReg2 = imprimeExpressao(aux->filho_esquerdo,auxReg);
                break;
            case MINUS:
                auxReg = imprimeExpressao(aux->filho_direito,reg+1);
                auxReg2 = imprimeExpressao(aux->filho_esquerdo,auxReg);
                break;
            case LOGICAL_AND:
                auxReg = imprimeExpressao(aux->filho_direito,reg+1);
                auxReg2 = imprimeExpressao(aux->filho_esquerdo,auxReg);
                    //chamar inserir and ->reg resultado total
                break;
            case LOGICAL_OR:
                auxReg = imprimeExpressao(aux->filho_direito,reg+1);
                auxReg2 = imprimeExpressao(aux->filho_esquerdo,auxReg);
                    //chamar funcao de inserir or -> reg resultado total
                break;
            default:
                //printf("--aux %d\n",aux->tipo);
                break;
        }
    }
    return reg;
    
}

void imprimiAST(Function_struct *f){
    int reg;
    Expressao *n =(Expressao*) f->nome;
    Expressao *r = f->exp_retorno;
    Variaveis *aux = f->variaveis;
    Comandos *auxC = f->function_comandos;
    ProgramaMips *program = iniciaProgramaStruct();
    //inserir nome da funcao no .text NOME_FUNC:
    while (aux !=NULL){
        Expressao *nomeVar= aux->id;
        printf("variveis = %s tipo=%d\n",nomeVar->str,aux->tipo);
        aux = aux->prox;
    }
    while (auxC != NULL){
        switch (auxC->tipo){
        case PRINTF:
            //inserir rotulos no .data
            //inserir comando de impressao no .text
            break;
        case SCANF:
            //inserir .text
            break;
        case IF:
            //imprimir comparacoes
            reg = imprimeExpressao(auxC->cmd_if,0);
            imprimiIF(reg);
            //label
            //comandos if
            //label j pra sair do if
            //label if_else
            //comandos else
            //label sair if
            break;
        default:
            break;
        }
        
        imprimeExpressao(auxC->expr_comandos);
        auxC = auxC->prox;
    } 
}

Cmd_expressao *novoCmdExpressao(Expressao *exp, Cmd_expressao *prox) {
    Cmd_expressao *novo;
    novo = (Cmd_expressao *) malloc(sizeof(Cmd_expressao));
    novo->exp = exp;
    novo->prox = prox;
    return novo;
}

Expressao *novaExpressao(int tipo, int value, char *str, int dimensaoArray, Expressao *filho_esquerdo, Expressao *filho_direito, float valueFloat){
    Expressao *novo;
    novo = (Expressao *) malloc(sizeof(Expressao));
    novo->tipo = tipo;
    novo->filho_direito = filho_direito;
    novo->filho_esquerdo = filho_esquerdo;
    if(tipo == IDENTIFIER || tipo == STRING){
        char *aux = (char*) malloc(sizeof(char)*(strlen(str)+4));
        strcpy(aux,str);
        aux[strlen(aux)] ='\0'; 
        novo->str = aux;
    }else if(tipo == NUM_INTEGER){
        novo->valueFloat = valueFloat;
    }
    
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
    novo->nome = nome;
    novo->tipo_retorno = tipo_retorno;
    novo->parametros = parametros;

    novo->variaveis = variaveis;
    novo->exp_retorno = exp_retorno;
    novo->function_comandos = function_comandos;
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