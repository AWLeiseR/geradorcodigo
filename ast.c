#include "ast.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sintatico.tab.h>

struct parametros {
    char* id;
    int tipo;
    Parametros *prox;
};

struct no {
    int tipo;
    //ponteiro para as structs
    expression x;
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

struct if_struct{
    Expressao *exprCond;
    Comandos *comandos_if;
    Comandos *comandos_else;
};

struct printf_struct{
    char *string_impressao;
    Cmd_expressao *expressoes;
};

struct scanf_struct{
    int formato;
    Cmd_expressao *expressoes;
};

struct number_struct{
    int num;
};

struct return_struct{
    Cmd_expressao *expressoes;
};

struct comandos{
    int tipo; // expr ou tipo comando (if, while, for...)
    Cmd_expressao expr_comandos;
    If_struct *cmd_if;
    Printf_struct *cmd_printf;
    Scanf_struct *cmd_scanf;
    Return_struct *cmd_return;
    Comandos *prox;
};

struct function_struct{
    char* nome;
    int tipo_retorno;
    Parametros *parametros;
    Comandos function_comandos;
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

No* inserirNo(int tipo){
    No* treeNode = (No*) malloc(sizeof(No));
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
            break;
        case PRINTF:
            //treeNode->x =
            break;
        case SCANF:
            //treeNode->x =
            break;
        default:
            break;
    }
    return treeNode;
}

// TreeNode* mallocTree(TreeNode* p1, TreeNode * p3, float value,int type){
// 	// treenode* p1 = (treenode*) x1;
// 	// treenode* p3 = (treenode*) x3;
// 	TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
// 	if(type == REAL){
//         aux->node_type = type;
//         aux->value = value;
//         aux->left = NULL;
//         aux->right = NULL;   
//     }else {
// 		aux->node_type = type;
//     	aux->value = 0;
//         aux->left = p1;
//         aux->right = p3;   
//     }

//     return aux;
// }