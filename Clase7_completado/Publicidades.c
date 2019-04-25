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
            printf("Publicidad %d:%s %s %d \n",i,pPublicidades[i].cuit,pPublicidades[i].archivo,pPublicidades[i].dias);
        //}
    }
    return 0;
}

int pub_create(Publicidad* pPublicidades,int len, int pIndex, char* msgE)
{
    char bufferN[20];
    char bufferS[20];

    if((getStringLetras(bufferN,"Ingrese nombre: ",msgE,2) == 0) && (getStringLetras(bufferS,"Ingrese apellido: ",msgE,2) == 0))
    {
        strncpy(pPublicidades[pIndex].name,bufferN,20);
        //*pPublicidades[pIndex].name=bufferN;
        strncpy(pPublicidades[pIndex].surname,bufferS,20);
        //*pPublicidades[pIndex].surname=bufferS;
        pPublicidades[pIndex].isEmpty=0;
    }
    else
    {
        printf(msgE);
    }
    return 0;
}

int pub_searchFreeSpace(Publicidad* pPublicidades, int len, int* pIndex)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pPublicidades[i].isEmpty==1)
        {
            *pIndex = i;
            ret = 0;
            break;
        }
    }
    return ret;
}
