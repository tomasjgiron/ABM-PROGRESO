#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED
#define LEN_INS 5

typedef struct
{
    int idInstrumento; /// se va autoincrementando
    char name[50];
    int type;
    int isEmpty; /// lleno=0 ; vacio=1
}Instrumento;

//int instrumento_menu(Instrumento* pInstrumentos,int len,char* textMenu,char* msgE,int escape,int tries);

int instrumento_initArray(Instrumento* pInstrumentos, int len);

int instrumento_addInstrumento(Instrumento* pInstrumentos,int len,int* idAlta, char* msgE,int tries);

int instrumento_removeInstrumento(Instrumento* pInstrumentos, int len,char* msgE,int tries);

int instrumento_printInstrumento(Instrumento* pInstrumentos,int len);

int instrumento_printTipo(int tipoInstrumento);

int instrumento_printInstrumentoID(Instrumento* pInstrumentos,int len);

int instrumento_printValorRepetidoInt(Instrumento* pInstrumentos,int len,int valorBuscado);


//int instrumento_sortInstrumentoSurnameName(Instrumento* pInstrumentos,int len,int order);

//int instrumento_printTotalPromAboveSalary(Instrumento* pInstrumentos, int len);

//int instrumento_modifyInstrumento(Instrumento* pInstrumentos,int len,char* msgE,int escape,int tries);


int instrumento_searchFreeSpace(Instrumento* pInstrumentos, int len);

int instrumento_findPosID(Instrumento* pInstrumentos, int len,int idIns);

int instrumento_getID(Instrumento* pInstrumentos, int len, char* msgE, int tries);

//int instrumento_aboveSalary(Instrumento* pInstrumentos, int len, float prom);

#endif // INSTRUMENTO_H_INCLUDED
