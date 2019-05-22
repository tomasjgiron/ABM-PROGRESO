#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#include "orquesta.h"
#include "instrumento.h"

typedef struct
{
    int idMusico; /// se va autoincrementando
    char name[50];
    char surname[50];
    int edad;
    int idOrquesta;
    int idInstrumento;
    int isEmpty; /// lleno=0 ; vacio=1
}Musico;

//int musico_menu(Musico* pMusicos,int len,char* textMenu,char* msgE,int escape,int tries);

int musico_initArray(Musico* pMusicos, int len);

int musico_addMusico(Musico* pMusicos,int lenMus,
                         Orquesta* pOrquestas,int lenOrq,
                         Instrumento* pInstrumentos,int lenIns,
                         char* msgE,int tries);

int musico_removeMusico(Musico* pMusicos, int len,char* msgE,int tries);

int musico_bajaValorRepetidoInt(Musico* pMusicos, int len, int valorBuscado);

int musico_bubbleSortEficiente(Musico* pMusicos, int len,int order);///1up 0down

int musico_sortMusicoEdad(Musico* pMusicos,int len,int order);

int musico_printMusico(Musico* pMusicos,Instrumento* pInstrumento,int lenMus,int lenIns);

//int musico_sortMusicoSurnameName(Musico* pMusicos,int len,int order);

//int musico_printTotalPromAboveSalary(Musico* pMusicos, int len);

int musico_modifyMusico(Musico* pMusicos,int lenMus,Orquesta* pOrquestas,int lenOrq,char* msgE,int escape,int tries);

int musico_searchFreeSpace(Musico* pMusicos, int len);

int musico_findPosID(Musico* pMusicos, int len,int idMus);

int musico_getID(Musico* pMusicos, int len, char* msgE, int tries);

//int musico_aboveSalary(Musico* pMusicos, int len, float prom);


#endif // MUSICO_H_INCLUDED
