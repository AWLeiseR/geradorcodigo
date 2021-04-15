#ifndef _FUNCOES_H_
#define _FUNCOES_H_
    typedef struct item Item_struct;
    typedef struct programaMips ProgramaMips;
    void imprimiprintf();
    ProgramaMips *iniciaProgramaStruct();
    void imprimirPrograma(ProgramaMips *p);
    void imprimiAND(int reg1, int reg2, int reg3);
#endif