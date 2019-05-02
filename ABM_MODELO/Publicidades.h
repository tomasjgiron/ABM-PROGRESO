#ifndef PUBLICIDADES_H_INCLUDED
#define PUBLICIDADES_H_INCLUDED

typedef struct
{
    char cuitCliente[20];
    char archivo[50];
    int dias;
    int isEmpty; /// lleno=0 ; vacio=1
    int idPublicidad; /// se va autoincrementando
}Publicidad;

int pub_initializeArray(Publicidad* pPublicidades, int len);

int pub_create(Publicidad* pPublicidades,Pantalla* pPantallas,int len, char* msgE,int tries);

int pub_searchFreeSpace(Publicidad* pPublicidades, int len);

int pub_findPosID(Publicidad* pPublicidades, int len,int idPub);

int pub_bajaLogica(Publicidad* pPublicidades, int len,char* msgE,int tries);

int pub_getID(Publicidad* pPublicidades, int len, char* msgE, int tries);

#endif // PUBLICIDADES_H_INCLUDED
