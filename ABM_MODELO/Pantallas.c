#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "Pantallas.h"
#include "Publicidades.h"
#define LCD 1
#define LED 2

static int generateID(void);

int pan_initializeArray(Pantalla* pPantallas, int len)
{
    int i;

    if(pPantallas != NULL && len > 0)
    {
       for(i=0; i<len;i++)
        {
            pPantallas[i].isEmpty = 1;
        }
    }
    return 0;
}

int pan_showArray(Pantalla* pPantallas,int len)
{
    int i;
    int flag=1;

    if (pPantallas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pPantallas[i].isEmpty == 0)
            {
                printf("\nID: %d\nNombre: %s\nDireccion: %s\nPrecio: %.2f\nTipo 1 LCD / 2 LED: %d\n~~~~~~~~",
                pPantallas[i].idPantalla,pPantallas[i].nombre,pPantallas[i].direccion,pPantallas[i].precio,pPantallas[i].tipo);
                flag=0;
            }
        }
        if(flag)
        {
            printf("\n\tNo se encontraron valores\t\n");
        }
    }
    return 0;
}

int pan_create(Pantalla* pPantallas,int len, int pIndex,char* msgE,int tries)
{
    char bufferN[20];
    char bufferD[20];
    char bufferStrPrecio[20];
    char bufferStrTipo[20];
    int bufferT;
    float bufferP;
    int ret= -1;

    if(pPantallas != NULL && len > 0)///SIEMPRE VALIDAR AL USAR ARRAYS
    {
        if((getStringLetras(bufferN,"\nIngrese nombre: ",msgE,tries) == 0) && (getStringAlphanumeric(bufferD,"\nIngrese direccion: ",msgE,tries) == 0))
        {
            if(!getStringNumerosFloat(bufferStrPrecio,"\nIngrese precio: ",msgE,tries) && isNumberFloat(bufferStrPrecio))
            {
                bufferP = atof(bufferStrPrecio);
                if(!getStringNumerosInt(bufferStrTipo,"\nIngrese tipo 1 LCD / 2 LED: ",msgE,tries) && isNumberInt(bufferStrTipo))
                {
                    bufferT = atoi(bufferStrTipo);
                    if(bufferT == 1 || bufferT == 2)
                    {
                        strncpy(pPantallas[pIndex].nombre,bufferN,sizeof(bufferN));
                        strncpy(pPantallas[pIndex].direccion,bufferD,sizeof(bufferD));
                        pPantallas[pIndex].precio = bufferP;
                        pPantallas[pIndex].tipo = bufferT;
                        pPantallas[pIndex].isEmpty = 0;
                        pPantallas[pIndex].idPantalla = generateID();
                        ret = 0;
                    }

                }
            }
        }
    }
    else
    {
        printf(msgE);
    }
    return ret;
}

int pan_searchFreeSpace(Pantalla* pPantallas, int len)
{
    int i;
    int ret=-1;

    if(pPantallas != NULL && len > 0)
    {
       for(i=0;i<len;i++)
        {
            if(pPantallas[i].isEmpty==1)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int pan_findPosID(Pantalla* pPantallas, int len,int idPan)
{
    int i;
    int ret=-1;

    if(pPantallas != NULL && len > 0)
    {
      for(i=0;i<len;i++)
        {
            if(pPantallas[i].idPantalla == idPan)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int pan_bajaLogica(Pantalla* pPantallas, int len,char* msgE,int tries)
{
    int auxiliarID;
    int posID;
    int ret = -1;

    if(pPantallas != NULL && len > 0)
    {
       auxiliarID = pan_getID(pPantallas,len,msgE,tries);
       if(auxiliarID >= 1)
       {
            posID = pan_findPosID(pPantallas,len,auxiliarID);
            if(posID != -1)
            {
                pPantallas[posID].isEmpty = 1;
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

int pan_modifyByID(Pantalla* pPantallas,int len, char* msgE,int tries)
{
    char bufferN[50];
    char bufferD[250];
    char bufferStrPrecio[20];
    char bufferStrTipo[20];
    int bufferT;
    float bufferP;
    int auxiliarID;
    int posID;
    int ret = -1;

    if(pPantallas != NULL && len > 0)
    {
        do
        {
            auxiliarID = pan_getID(pPantallas,len,msgE,tries);
            if(auxiliarID >= 1)
            {
                posID = pan_findPosID(pPantallas,len,auxiliarID);
                if(posID != -1)
                {
                    pPantallas[posID].isEmpty = 1;
                    ret = 0;
                }
                else
                {
                    printf("\n\tID inexistente\t\n");
                }
            }
            if((getStringLetras(bufferN,"\nIngrese nombre: ",msgE,tries) == 0) && (getStringAlphanumeric(bufferD,"\nIngrese direccion: ",msgE,tries) == 0))
            {
                if(!getStringNumerosFloat(bufferStrPrecio,"\nIngrese precio: ",msgE,tries) && isNumberFloat(bufferStrPrecio))
                {
                    bufferP = atof(bufferStrPrecio);
                    if(!getStringNumerosInt(bufferStrTipo,"\nIngrese tipo 1 LCD / 2 LED: ",msgE,tries) && isNumberInt(bufferStrTipo))
                    {
                        bufferT = atoi(bufferStrTipo);
                        if(bufferT == 1 || bufferT == 2)
                        {
                            strncpy(pPantallas[posID].nombre,bufferN,sizeof(bufferN));
                            strncpy(pPantallas[posID].direccion,bufferD,sizeof(bufferD));
                            pPantallas[posID].precio = bufferP;
                            pPantallas[posID].tipo = bufferT;
                            pPantallas[posID].isEmpty = 0;
                            ret = 0;
                        }

                    }
                }
            }
        }while(ret == -1);
    }
    return ret;
}

int pan_sortByPrice(Pantalla* pPantallas,int len)
{
    int i;
    int j;
    Pantalla buffer;

    if(pPantallas != NULL && len > 0)
    {
        for(i=0;i<len-1;i++)
        {
            if(pPantallas[i].isEmpty == 1)
            {
                continue;
            }
            for(j=i+1;j<len;j++)
            {
                if(pPantallas[j].isEmpty == 1)
                {
                    continue;
                }
                if(pPantallas[i].precio>pPantallas[j].precio)
                {
                    buffer = pPantallas[i];
                    pPantallas[i] = pPantallas[j];
                    pPantallas[j] = buffer;
                }
            }
        }
    }
    return 0;
}

int pan_sortByID(Pantalla* pPantallas,int len)
{
    int i;
    int j;
    Pantalla auxiliar;

    if(pPantallas != NULL && len > 0)
    {
        for(i = 0;i < len-1;i++)
        {
            if(pPantallas[i].isEmpty == 1)
            {
                continue;
            }
            for(j = i+1;j < len;j++)
            {
                if(pPantallas[j].isEmpty == 1)
                {
                    continue;
                }
                if(pPantallas[i].idPantalla > pPantallas[j].idPantalla)
                {
                    auxiliar = pPantallas[i];
                    pPantallas[i] = pPantallas[j];
                    pPantallas[j] = auxiliar;
                }
            }
        }
    }
    return 0;
}

int pan_getID(Pantalla * pPantallas, int len, char* msgE, int tries)
{
    char bufferID[20];
    int auxiliarID;
    int ret = -1;

    if(pPantallas != NULL && len > 0)
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
    static int idPan = 0;
    return idPan++;
}
