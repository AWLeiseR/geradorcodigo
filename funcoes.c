#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void imprimeAd(char *registrador1, char *registrador2, char *registrador3)
{
  printf("add %s, %s, %s\n", registrador1, registrador2, registrador3);
}

void imprimeSub(char *registrador1, char *registrador2, char *registrador3)
{
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