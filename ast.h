#ifndef _AST_H_
#define _AST_H_
    typedef struct No Tree;
    typedef void * expression;
    typedef struct parametros Parametros;
    typedef struct variaveis Variaveis;
    typedef struct expressao Expressao;
    typedef struct cmd_expressao Cmd_expressao;
    typedef struct comandos Comandos;
    typedef struct no No;
    typedef struct if_struct If_struct;
    typedef struct printf_struct Printf_struct;
    typedef struct scanf_struct Scanf_struct;
    typedef struct number_struct Number_struct;
    typedef struct function_struct Function_struct;
    typedef struct return_struct Return_struct;
    No *novo_no(int tipo, expression x);
    Printf_struct *novoPrintf(char *string_impressao, Cmd_expressao *expressoes);
    Cmd_expressao *novoCmdExpressao(Expressao *exp, Cmd_expressao *prox);
    Expressao *novaExpressao(int tipo, int value, char *str, int dimensaoArray, Expressao *filho_esquerdo, Expressao *filho_direito);
    Scanf_struct *novoScanf(char *string_impressao, Cmd_expressao *expressoes);
    If_struct *novoIf(Expressao *exprCond, Comandos *comandos_if, Comandos *comandos_else);
    Comandos *novoComandos(int tipo, Cmd_expressao expr_comandos, If_struct *cmd_if, Printf_struct *cmd_printf, Scanf_struct *cmd_scanf);
    Function_struct *novaFunction(char *nome, int tipo_retorno, Parametros *parametros, Variaveis *variaveis, Cmd_expressao *function_comandos);
    Parametros *novoParametro(char *id, int tipo, Parametros *prox);
    Variaveis *novaVariavel(char *id, int tipo, Variaveis *prox);
    
#endif