#ifndef PANTALLAS_H_INCLUDED
#define PANTALLAS_H_INCLUDED
typedef struct
{
    char nombre[50];
    char direccion[250];
    float precio;
    int tipo;
    int isEmpty; // lleno=0 ; vacio=1
    int idPantalla; // se va autoincrementando
}Pantalla;

int pan_initializeArray(Pantalla* pPantallas, int len);

int pan_showArray(Pantalla* pPantallas,int len);

int pan_create(Pantalla* pPantallas,int len, int pIndex,char* msgE,int tries);

int pan_searchFreeSpace(Pantalla* pPantallas, int len);

int pan_findPosID(Pantalla* pPantallas, int len,int idPan);

int pan_bajaLogica(Pantalla* pPantallas, int len,char* msgE,int tries);

int pan_modifyByID(Pantalla* pPantallas,int len, char* msgE,int tries);

int pan_sortByPrice(Pantalla* pPantallas,int len);

int pan_sortByID(Pantalla* pPantallas,int len);

int pan_getID(Pantalla * pPantallas, int len, char* msgE, int tries);


#endif // PANTALLAS_H_INCLUDED
