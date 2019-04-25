#ifndef PUBLICIDADES_H_INCLUDED
#define PUBLICIDADES_H_INCLUDED

typedef struct
{
    char cuitCliente[20];
    char archivo[50];
    int dias;
    int isEmpty; // lleno=0 ; vacio=1
    int idPublicidad;
    int idPantalla;//autoincremental
} Publicidad;

int pub_initializeArray(Publicidad* pPublicidades, int len);

int pub_showArray(Publicidad* pPublicidades,int len);

int pub_create(Publicidad* pPublicidades,int len, int pIndex, char* msgE);

int pub_searchFreeSpace(Publicidad* pPublicidades, int len, int* pIndex);

int pub_buscarEnArray (Publicidad* publicidad, int cantidad, int* PublicidadesEncontrado);
int pub_baja(Publicidad* publicidad, int cantidad);

#endif // PUBLICIDADES_H_INCLUDED
