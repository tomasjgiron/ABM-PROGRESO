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
    char bufferD[20];
    char bufferStrPrecio[20];
    char bufferStrTipo[20];
    int bufferT;
    float bufferP;

    if((getStringLetras(bufferN,"Ingrese nombre: ",msgE,2) == 0) && (getStringLetras(bufferD,"Ingrese direccion: ",msgE,2) == 0))
    {
        strncpy(pPantallas[pIndex].nombre,bufferN,sizeof(bufferN));
        //*pPantallas[pIndex].name=bufferN;
        strncpy(pPantallas[pIndex].direccion,bufferD,sizeof(bufferD));
        //*pPantallas[pIndex].surname=bufferS;
        if(!getString(bufferStrPrecio,"Ingrese precio: ",msgE) && isNumber(bufferStrPrecio))
        {
            bufferP = atof(bufferStrPrecio);
            if(!getString(bufferStrTipo,"Ingrese tipo: ",msgE) && isNumber(bufferStrTipo))
            {
                bufferT = atoi(bufferStrTipo);
                pPantallas[pIndex].isEmpty=0;
            }
        }
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




int pan_buscarEnArray (Pantalla* pPantallas, int cantidad, int* pantallaEncontrada,char* msgE)
{
    int ret=1;
    int posPantalla;
    Pantalla auxPantallas;

    if (getString(auxPantallas,"ingrese el ID de la pantalla que quiera eliminar: ",msgE)==0)
    {
        //auxEmpleados.nombre=tolower(auxEmpleados.nombre);
        ret=-1;
        for(int i=0;i<cantidad;i++)
        {
            //empleados[i].nombre=tolower(empleados[i].nombre);
            if (pPantallas[posPantalla].isEmpty==0 && strcmp(pPantallas[i].idPantalla, auxPantallas.idPantalla)==0)
            {
                ret=0;
                *pantallaEncontrada=i;
                break;
            }
        }
    }
    return ret;
}

int pan_delete(Pantalla * pPantallas, int cantidad,char* msgE)
{
    int posPantalla;
    if (pan_buscarEnArray(pPantallas,cantidad,&posPantalla,msgE) == 0)
    {
        printf("hubo coincidencia\n\n");
        pPantallas[posPantalla].isEmpty=0;
        printf("La pantalla a borrar es: %d\n\n",pPantallas[posPantalla].idPantalla);
    }

    return 0;
}
