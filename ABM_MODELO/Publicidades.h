#ifndef PUBLICIDADES_H_INCLUDED
#define PUBLICIDADES_H_INCLUDED

typedef struct
{
    char cuitCliente[20];
    char archivo[50];
    int dias;
    int isEmpty; /// lleno=0 ; vacio=1
    int idPublicidad; /// se va autoincrementando
    int idPantalla;
}Publicidad;

int pub_initializeArray(Publicidad* pPublicidades, int len);

int pub_printContrataciones(Publicidad* lista,int len);

int pub_create(Publicidad* pPublicidades,Pantalla* pPantallas,int len, char* msgE,int tries);

int pub_searchFreeSpace(Publicidad* pPublicidades, int len);

int pub_findPosID(Publicidad* pPublicidades, int len,int idPub);

int pub_bajaLogica(Publicidad* pPublicidades, int len,char* msgE,int tries);

int pub_getID(Publicidad* pPublicidades, int len, char* msgE, int tries);

int pub_printPublicidades(Publicidad* pPublicidades,Pantalla* pPantallas,int lenPan,int lenPub);

int pub_printPantallaByCuit(Pantalla* pPantallas,Publicidad* pPublicidades,int lenPan,int lenPub,char* valor); ///PUNTO 8 EXAMEN MODELO

int pub_sortByPrice(Publicidad* pPublicidades,int len);

#endif // PUBLICIDADES_H_INCLUDED
