#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "Pantallas.h"
#include "Publicidades.h"

static int generateID(void);

int pub_initializeArray(Publicidad* pPublicidades, int len)
{
    int i;

    if(pPublicidades != NULL && len > 0)
    {
       for(i=0; i<len;i++)
        {
            pPublicidades[i].isEmpty = 1;
        }
    }
    return 0;
}

int pub_create(Publicidad* pPublicidades,Pantalla* pPantallas,int len, char* msgE,int tries)
{
    int auxiliarID;
    int posOfID;
    char bufferCuCli[20];
    char bufferNaFi[20];
    char bufferStrDia[20];
    int bufferDia;
    int ret = -1;

    if(pPublicidades != NULL && len > 0) ///SIEMPRE VALIDAR AL USAR ARRAYS
    {
        auxiliarID = pub_getID(pPublicidades,len,msgE,tries);
        posOfID = pan_findPosID(pPantallas,len,auxiliarID);
        if((auxiliarID >= 1) && (posOfID != -1))
        {
            if((getCuit(bufferCuCli,"Ingrese cuit de cliente: ",msgE,tries) == 0) &&
            (getStringAlphanumeric(bufferNaFi,"Ingrese nombre de archivo: ",msgE,tries) == 0))
            {
                if(getStringNumerosInt(bufferStrDia,"Ingrese cantidad de dias: ",msgE,tries) == 0)
                {
                    bufferDia = atoi(bufferStrDia);
                    strncpy(pPublicidades[posOfID].cuitCliente,bufferCuCli,sizeof(bufferCuCli));
                    strncpy(pPublicidades[posOfID].archivo,bufferNaFi,sizeof(bufferNaFi));
                    pPublicidades[posOfID].dias = bufferDia;
                    pPublicidades[posOfID].isEmpty = 0;
                    pPublicidades[posOfID].idPublicidad = generateID();
                    ret = 0;
                }
            }
        }
    }
    else
    {
        printf("\n~~~~El ID es invalido~~~~\n");
    }

    return ret;
}

int pub_searchFreeSpace(Publicidad* pPublicidades, int len)
{
    int i;
    int ret=-1;

    if(pPublicidades != NULL && len > 0)
    {
       for(i=0;i<len;i++)
        {
            if(pPublicidades[i].isEmpty==1)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int pub_findPosID(Publicidad* pPublicidades, int len,int idPub)
{
    int i;
    int ret=-1;

    if(pPublicidades != NULL && len > 0)
    {
      for(i = 0;i < len;i++)
        {
            if(pPublicidades[i].idPublicidad == idPub)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int pub_bajaLogica(Publicidad* pPublicidades, int len,char* msgE,int tries)
{
    int auxiliarID;
    int posID;
    int ret = -1;

    if(pPublicidades != NULL && len > 0)
    {
       auxiliarID = pub_getID(pPublicidades,len,msgE,tries);
       if(auxiliarID >= 1)
       {
            posID = pub_findPosID(pPublicidades,len,auxiliarID);
            if(posID != -1)
            {
                pPublicidades[posID].isEmpty = 1;
                ret = 0;
            }
            else
            {
                printf("\n\tID inexistente\t\n");
            }

        }
    }
    return ret;
}

int pub_getID(Publicidad * pPublicidad, int len, char* msgE, int tries)
{
    char bufferID[20];
    int auxiliarID;
    int ret = -1;

    if(pPublicidad != NULL && len > 0)
    {
        if(getStringNumerosInt(bufferID,"\nIngrese ID: ",msgE,tries) == 0)
        {
            auxiliarID = atoi(bufferID);
            ret = auxiliarID;
        }
    }
    return ret;
}

static int generateID(void)
{
    static int idPub = 0;
    return idPub++;
}
