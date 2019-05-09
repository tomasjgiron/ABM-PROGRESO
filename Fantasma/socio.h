#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

typedef struct
{
    int idSocio; /// se va autoincrementando
    char name[31];
    char surname[31];
    char sexo;
    char email[31];
    char telephone[16];
    int fechaAsociado[12];
    int isEmpty; /// lleno=0 ; vacio=1
}Socio;

int socio_menu(Socio* pSocios,int len,char* textMenu,char* msgE,int escape,int tries);

int socio_initArray(Socio* pSocios, int len);

int socio_addSocio(Socio* pSocios,int len, char* msgE,int tries);

int socio_removeSocio(Socio* pSocios, int len,char* msgE,int tries);

int socio_printSocio(Socio* pSocios,int len);

int socio_sortSocioSurnameSector(Socio* pSocios,int len);

int socio_printTotalPromAboveSalary(Socio* pSocios, int len);

int socio_modifySocio(Socio* pSocios,int len,char* msgE,int escape,int tries);


int socio_searchFreeSpace(Socio* pSocios, int len);

int socio_findPosID(Socio* pSocios, int len,int idSoc);

int socio_getID(Socio* pSocios, int len, char* msgE, int tries);

int socio_aboveSalary(Socio* pSocios, int len, float prom);

#endif // SOCIO_H_INCLUDED
