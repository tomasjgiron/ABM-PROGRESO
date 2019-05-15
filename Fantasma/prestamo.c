#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "prestamo.h"
#include "arraynuevo.h"
#include "socio.h"
#include "libro.h"

static int generateID(void);

int prestamo_menu(Prestamo* pPrestamos,int lenPres,
                         Socio* pSocios,int lenSoc,
                         Libro* pLibros,int lenLib,char* textMenu,char* msgE,
                         int escape,int tries)
{
    return 0;
}

int prestamo_initArray(Prestamo* pPrestamos, int len)
{
    int i;
    if(pPrestamos != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            pPrestamos[i].isEmpty = 1;
        }
    }
    return 0;
}

int prestamo_addPrestamo(Prestamo* pPrestamos,int lenPres,
                         Socio* pSocios,int lenSoc,
                         Libro* pLibros,int lenLib,
                         char* msgE,int tries)
{
    int indexFree;
    int auxiliarDia;
    int auxiliarMes;
    int auxiliarAnio;
    int auxiliarIDSoc;
    int auxiliarIDLib;
    int posIDSoc;
    int posIDLib;
    int ret = -1;

    if(pPrestamos != NULL && pSocios != NULL && pLibros != NULL && lenPres > 0
       && lenSoc > 0 && lenLib > 0)
    {
        indexFree = prestamo_searchFreeSpace(pPrestamos,lenPres);
        auxiliarIDSoc = socio_getID(pSocios,lenSoc,msgE,tries);
        auxiliarIDLib = libro_getID(pLibros,lenLib,msgE,tries);
        posIDSoc = socio_findPosID(pSocios,lenSoc,auxiliarIDSoc);
        posIDLib = libro_findPosID(pLibros,lenLib,auxiliarIDLib);

        if((indexFree >= 0) && (auxiliarIDSoc >= 0) && (posIDSoc != -1)
           && (auxiliarIDLib >= 0) && (posIDLib != -1) &&
           (getFecha(&auxiliarDia,&auxiliarMes,&auxiliarAnio,msgE,tries) == 0))
        {
            pPrestamos[indexFree].idSocio = auxiliarIDSoc;
            pPrestamos[indexFree].idLibro = auxiliarIDLib;
            pPrestamos[indexFree].dia = auxiliarDia;
            pPrestamos[indexFree].mes = auxiliarMes;
            pPrestamos[indexFree].anio = auxiliarAnio;
            pPrestamos[indexFree].idPrestamo = generateID();
            pPrestamos[indexFree].isEmpty = 0;
            ret = 0;
        }
    }
    return ret;
}

int prestamo_searchFreeSpace(Prestamo* pPrestamos, int len)
{
int i;
    int ret=-1;

    if(pPrestamos != NULL && len > 0)
    {
       for(i=0;i<len;i++)
        {
            if(pPrestamos[i].isEmpty==1)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int prestamo_findPosID(Prestamo* pPrestamos, int len,int idPres)
{
    int i;
    int ret=-1;

    if(pPrestamos != NULL && len > 0)
    {
      for(i = 0;i < len;i++)
        {
            if(pPrestamos[i].idPrestamo == idPres)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int prestamo_getID(Prestamo* pPrestamos, int len, char* msgE, int tries)
{
     char bufferID[20];
    int auxiliarID;
    int ret = -1;

    if(pPrestamos != NULL && len > 0)
    {
        if(getStringNumerosInt(bufferID,"\nIngrese ID Prestamo: ",msgE,tries) == 0)
        {
            auxiliarID = atoi(bufferID);
            ret = auxiliarID;
        }
    }
    return ret;
}

static int generateID(void)
{
    static int idPres = 0;
    return idPres++;
}
