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

int pan_create(Pantalla* pPantallas,int len, int pIndex, char* msgE);

int pan_searchFreeSpace(Pantalla* pPantallas, int len, int* pIndex);

int pan_buscarEnArray (Pantalla* pPantallas, int cantidad, int* PantallaEncontrada,char* msgE);
int pan_baja(Pantalla* pPantallas, int cantidad,char* msgE);


#endif // PANTALLAS_H_INCLUDED
