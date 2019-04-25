#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "publicidades.h"

int pub_initializeArray(Publicidad* pPublicidades, int len)
{
    int i;
    for(i=0; i<len;i++)
    {
        pPublicidades[i].isEmpty = 1;
    }
    return 0;
}

int pub_showArray(Publicidad* pPublicidades,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        //if(pPublicidades[i].isEmpty == 0)
        //{
            printf("Publicidad %d:%s %s %d \n",i,pPublicidades[i].cuitCliente,pPublicidades[i].archivo,pPublicidades[i].dias);
        //}
    }
    return 0;
}

int pub_create(Publicidad* pPublicidades,int len, int pIndex, char* msgE)
{
    char bufferC[20];
    char bufferA[20];
    int bufferD;
    char bufferStrDias[20];

    if((getStringLetras(bufferC,"Ingrese cuit: ",msgE,2) == 0) && (getStringLetras(bufferA,"Ingrese nombre de archivo: ",msgE,2) == 0))
    {
        strncpy(pPublicidades[pIndex].cuitCliente,bufferC,20);
        //*pPublicidades[pIndex].name=bufferN;
        strncpy(pPublicidades[pIndex].archivo,bufferA,20);
        //*pPublicidades[pIndex].surname=bufferS;
        if(!getString(bufferStrDias,"Ingrese cantidad de dias: ",msgE) && isNumber(bufferStrDias))
        {
            bufferD = atoi(bufferStrDias);
            pPublicidades[pIndex].dias = bufferD;
            pPublicidades[pIndex].isEmpty=0;
        }
    }
    else
    {
        printf(msgE);
    }
    return 0;
}

int pub_searchFreeSpace(Publicidad* pPublicidades, int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pPublicidades[i].isEmpty==1)
        {
            ret = i;
            break;
        }
    }
    return ret;
}
