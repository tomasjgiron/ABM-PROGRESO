#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


int getString(char* pResultado, char* msg, char*msgE)
{
    char bufferStr[50];
    printf("%s",msg);
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0';
    if(pResultado!=NULL)
    {
        strncpy(pResultado,bufferStr,50);
    }
    else
    {
        printf("%s",msgE);
    }
    return 0;
}

int getStringLetras (char* pResultado, char* msg, char* msgE,int reintentos)
{
    char bufferStr[50];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pResultado!=NULL)&&(isLetter(bufferStr)))
        {
            strncpy(pResultado,bufferStr,50);
            ret=0;
        }
        else
        {
            printf("%s",msgE);
            reintentos--;
        }
    }
    return ret;
}

int utn_isValidIntNumber(char* cadena)
{
    int i = 0;
    int ret = 1;

    if(cadena[i] == '-')
    {
        i++;
    }
    for(;cadena[i] != '\0'; i++)
    {
        if(cadena[i] < '0' || cadena[i] > '9')
        {
            ret = 0;
            break;
        }

    }
    return ret;
}

int utn_getNumber(int* pResultado,char* msg,char* msgError,int minimo,int maximo,int reintentos)
{
    int ret = -1;
    char bufferStr[4000];
    int bufferInt;

    if(pResultado != NULL &&
        reintentos >= 0) //FALTAN LOS DEMAS
    {
        if(!utn_getString(bufferStr,msg,msgError,1,6,1) &&
            utn_isValidIntNumber(bufferStr))// maximo y minimo van a estar determinados por la funcion principal
        {
            bufferInt = atoi(bufferStr);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                ret = 0;
            }
        }
    }

    return ret;
}
