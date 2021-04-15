#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"

int contadorRotulos = 0;

typedef struct item{
  char * comandoImpressao;
  Item_struct *prox;
};

typedef struct programaMips{
  Item_struct *data;
  Item_struct *text;
};

Item_struct* iniciaData(){
  char *inicio = malloc(sizeof(char)*7);
  Item_struct *item = malloc(sizeof(Item_struct));
  strcpy(inicio,".data\n");
  item->prox=NULL;
  item->comandoImpressao = inicio;
  return item;
}

Item_struct *iniciaText(){
  char *inicio = malloc(sizeof(char)*7);
  Item_struct *item = malloc(sizeof(Item_struct));
  strcpy(inicio,".text\n");
  item->prox=NULL;
  item->comandoImpressao = inicio;
  return item;
}

ProgramaMips *iniciaProgramaStruct(){
  ProgramaMips *i = malloc(sizeof(ProgramaMips));
  i->data = iniciaData();
  i->text = iniciaText();
  return i;
}

Item_struct *inseriRotulo(Item_struct *lista,char* str){
  Item_struct *aux = lista;
  char strAux[]="\t printf";
  char strAux2[]=":\t .asciiz ";
  char* strConcatenada = malloc(sizeof(char)*(strlen(strAux)+strlen(strAux2)+2));
  sprintf(strConcatenada,"%s%d%s",strAux,contadorRotulos,strAux2);
  while(aux->prox != NULL){
    aux = aux->prox;
  }
  char *inicio = malloc(sizeof(char)*(strlen(strConcatenada)));
  Item_struct *item = malloc(sizeof(Item_struct));
  strcpy(inicio,strConcatenada);
  item->prox=NULL;
  item->comandoImpressao = inicio;
  aux->prox = item;
  return lista;
}

Item_struct* inseriLista(Item_struct *lista, char *c){
  Item_struct *item = malloc(sizeof(Item_struct));
  Item_struct *aux = lista;
  item->comandoImpressao;
  while (aux->prox != NULL){
    aux = aux->prox; 
  }
  aux->prox = item;
  return lista;
}

void imprimirPrograma(ProgramaMips *p){
  Item_struct *data = p->data;
  Item_struct *text = p->text;
  Item_struct *aux = data;
  while(aux!=NULL){
    printf("%s",aux->comandoImpressao);
    aux =aux->prox;
  }
  aux = text;
  while(aux!=NULL){
    printf("%s",aux->comandoImpressao);
    aux =aux->prox;
  }
}

char* inseriAd(char *destino, char *registrador2, char *registrador3){
  char *c = malloc(sizeof(char)+(strlen(destino)+strlen(registrador2)+strlen(registrador3)+10));
  sprintf(c,"add %s, %s, %s\n", destino, registrador2, registrador3);
  return c;
}

char* inseriSub(char *destino, char *registrador2, char *registrador3){
  char *c = malloc(sizeof(char)+(strlen(destino)+strlen(registrador2)+strlen(registrador3)+10));
  sprintf(c,"sub %s, %s,%s\n", destino, registrador2, registrador3);
  return c;
}

char* inseriLabel(char *str){
  char *c = malloc(sizeof(char)*(strlen(str)));
  sprintf(c,"%s",str);
}

//0 para int e 1 para string
void imprimePrintf(int tipo, char *registrador){
  if(!tipo){
    printf("li $v0, 1\n");
    printf("add $a0, %s, $zero\n",registrador);
  }else{
    printf("li $v0, 4\n");
    printf("move $a0, %s, $zero\n",registrador);
  }
    printf("syscall\n");
}

void imprimeScanf(){
  printf("li $v0, 5\n");
  printf("syscall\n");
}

void imprimeExit(){
  printf("addi $v0, $zero, 10\n");
  printf("syscall\n");
}