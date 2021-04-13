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
    typedef struct function_struct Function_struct;
    typedef struct return_struct Return_struct;
    No *novo_no(int tipo, expression x);
    Cmd_expressao *novoCmdExpressao(Expressao *exp, Cmd_expressao *prox);
    Expressao *novaExpressao(int tipo, int value, char *str, int dimensaoArray, Expressao *filho_esquerdo, Expressao *filho_direito);
    Comandos *novoComandos(int tipo, Cmd_expressao expr_comandos, If_struct *cmd_if, Printf_struct *cmd_printf, Scanf_struct *cmd_scanf);
    Function_struct *novaFunction(char *nome, int tipo_retorno, Parametros *parametros, Variaveis *variaveis, Cmd_expressao *function_comandos);
    Parametros *novoParametro(char *id, int tipo, Parametros *prox);
    Variaveis *novaVariavel(char *id, int tipo, Variaveis *prox);
    Comandos *cmd_generico(int tipo, Cmd_expressao *exp, Cmd_expressao *cmd1, Cmd_expressao *cmd2);
    void setProxGenerico(Comandos *atual, Comandos *prox);
#endif