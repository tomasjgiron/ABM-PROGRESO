#ifndef PANTALLAS_H_INCLUDED
#define PANTALLAS_H_INCLUDED
typedef struct
{
    char nombre[50];
    char direccion[250];
    float precio;
    int tipo;
    int isEmpty; // lleno=0 ; vacio=1
    int idPantalla; //autoincremental
} Pantalla;

int pan_initializeArray(Pantalla* pPantallas, int len);

int pan_showArray(Pantalla* pPantallas,int len);

int pan_create(Pantalla* pPantallas,int len, int pIndex,int idPan, char* msgE,int tries);

int pan_searchFreeSpace(Pantalla* pPantallas, int len);


#endif // PANTALLAS_H_INCLUDED
