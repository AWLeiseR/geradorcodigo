#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"

int contadorRotulos = 0;
typedef struct item{
  char * comandoImpressao;
  Item_struct *prox;
};

typedef struct{
  Item_struct *data;
  Item_struct *text;
}ProgramaMips;

//> 0, >= 1,< 2, <= 3, == 4, 0== 5
void imprimeIf(int tipo){
  switch(tipo){
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    default:
      break;
  }
}

ProgramaMips *iniciaProgramaStruct(){
  ProgramaMips *i = malloc(sizeof(ProgramaMips));
  return i;
}

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

// void imprimiprintf(){
//   char strAux[]="\t printf";
//   char strAux2[]=":\t .asciiz ";
//   char* strConcatenada = malloc(sizeof(char)*(strlen(strAux)+strlen(strAux2)+2));
//   sprintf(strConcatenada,"%s%d%s",strAux,contadorRotulos,strAux2);
//   printf("--%s\n",strConcatenada);
// }

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

void imprimeAd(char *registrador1, char *registrador2, char *registrador3){
  printf("add %s, %s, %s\n", registrador1, registrador2, registrador3);
}

void imprimeSub(char *registrador1, char *registrador2, char *registrador3){
  printf("sub %s, %s,%s\n", registrador1, registrador2, registrador3);
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

}

void imprimeExit(){
  printf("addi $v0, $zero, 10\n");
  printf("syscall\n");
}