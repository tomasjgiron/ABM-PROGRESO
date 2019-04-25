#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "pantallas.h"
#define LCD 1
#define LED 2

int pan_initializeArray(Pantalla* pPantallas, int len)
{
    int i;
    for(i=0; i<len;i++)
    {
        pPantallas[i].isEmpty = 1;
    }
    return 0;
}

int pan_showArray(Pantalla* pPantallas,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        //if(pPantallas[i].isEmpty == 0)
        //{
            printf("Pantalla %d:%s %s %f %d\n",i,pPantallas[i].nombre,pPantallas[i].direccion,pPantallas[i].precio,pPantallas[i].tipo);
        //}
    }
    return 0;
}

int pan_create(Pantalla* pPantallas,int len, int pIndex, char* msgE)
{
    char bufferN[20];
    char bufferS[20];

    if((getStringLetras(bufferN,"Ingrese nombre: ",msgE,2) == 0) && (getStringLetras(bufferS,"Ingrese apellido: ",msgE,2) == 0))
    {
        strncpy(pPantallas[pIndex].name,bufferN,20);
        //*pPantallas[pIndex].name=bufferN;
        strncpy(pPantallas[pIndex].surname,bufferS,20);
        //*pPantallas[pIndex].surname=bufferS;
        pPantallas[pIndex].isEmpty=0;
    }
    else
    {
        printf(msgE);
    }
    return 0;
}

int pan_searchFreeSpace(Pantalla* pPantallas, int len, int* pIndex)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pPantallas[i].isEmpty==1)
        {
            *pIndex = i;
            ret = 0;
            break;
        }
    }
    return ret;
}
