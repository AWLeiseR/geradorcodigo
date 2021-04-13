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
    
    
    Cmd_expressao *novoCmdExpressao(Expressao *exp, Cmd_expressao *prox);
    
    Expressao *novaExpressao(int tipo, int value, char *str, int dimensaoArray, Expressao *filho_esquerdo, Expressao *filho_direito);
    
    Function_struct *novaFunction(Function_struct *proximo, Expressao *nome, Expressao tipo_retorno, Parametros *parametros, Variaveis *variaveis, Cmd_expressao *function_comandos) ;
    
    Parametros *novoParametro(Expressao *id, int tipo, Parametros *prox);
    
    Variaveis *novaVariavel(Expressao *id, int tipo, Variaveis *prox);
    
    Comandos *cmd_generico(int tipo, Cmd_expressao *exp, Comandos *cmd1, Comandos *cmd2);
    
    void setProxGenerico(Comandos *atual, Comandos *prox);
#endif