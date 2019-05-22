#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "orquesta.h"

#define TIPO_SINFO 1
#define TIPO_FILA 2
#define TIPO_CAMARA 3



static int generateID(void);
/** \brief Indica que todas las posiciones del array están vacías al colocar el isEmpty como 1
* \param lista puntero de orquesta al array de orquesta
* \param len del array
* \return retorna 0 diciendo que no hay error
*/
int orquesta_initArray(Orquesta* pOrquestas, int len)
{
    int i;

    if(pOrquestas != NULL && len > 0)
    {
       for(i=0; i<len;i++)
        {
            pOrquestas[i].isEmpty = 1;
            pOrquestas[i].cantMusicos = 0;
        }
    }
    return 0;
}
/** \brief Realiza la funcion de carga de orquestas dentro del array
* \param lista puntero de orquesta al array de orquesta
* \param tamaño del array
* \param msgE mensajes de error de las funciones
* \param tries reintentos a la hora de volver a cargar algo
* \return retorna 0 diciendo que no hay error o -1 si encuentra un error
*/
int orquesta_addOrquesta(Orquesta* pOrquestas,int len,int* idAlta, char* msgE,int tries)
{
    int indexFree;
    char bufferName[50];
    char bufferPlace[50];
    int auxiliarType;
    int ret = -1;

    if(pOrquestas != NULL && len > 0) ///SIEMPRE VALIDAR AL USAR ARRAYS
    {
        indexFree = orquesta_searchFreeSpace(pOrquestas,len);

        if(indexFree >= 0)
        {
            if((getStringLetras(bufferName,"Ingrese nombre: ",msgE,tries) == 0) &&
            (getStringLetras(bufferPlace,"Ingrese lugar: ",msgE,tries) == 0))
            {
                if((getIntInRange(&auxiliarType,"Ingrese tipo (1-Sinfonica|2-Filarmonica|3-Camara): ",
                msgE,1,3,tries) == 0))
                    {
                        strncpy(pOrquestas[indexFree].name,bufferName,sizeof(bufferName));
                        strncpy(pOrquestas[indexFree].place,bufferPlace,sizeof(bufferPlace));
                        pOrquestas[indexFree].type = auxiliarType;
                        pOrquestas[indexFree].isEmpty = 0;
                        pOrquestas[indexFree].idOrquesta = generateID();
                        *idAlta = indexFree;
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
/** \brief Busca el espacio en el array donde haya espacio (-1)
* \param lista puntero de Empleado al array de empleados
* \param tamaño del array
* \return retorna la posicion o -1 si encuentra un error
*/
int orquesta_searchFreeSpace(Orquesta* pOrquestas, int len)
{
    int i;
    int ret=-1;

    if(pOrquestas != NULL && len > 0)
    {
       for(i=0;i<len;i++)
        {
            if(pOrquestas[i].isEmpty==1)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}
/** \brief Busca la posicion de un ID comparandolo con otro
* \param lista puntero de Empleado al array de empleados
* \param tamaño del array
* \param idEmp usa para comparar un id con otro
* \return retorna la posicion o -1 si encuentra un error
*/
int orquesta_findPosID(Orquesta* pOrquestas, int len,int idOrq)
{
    int i;
    int ret=-1;

    if(pOrquestas != NULL && len > 0)
    {
      for(i = 0;i < len;i++)
        {
            if(pOrquestas[i].idOrquesta == idOrq)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}
/** \brief Realiza la baja lógica de orquestas dentro de la nómina
* \param lista puntero de orquesta al array de orquesta
* \param tamaño del array
* \param msgE mensajes de errores
* \param tries reintentos de la función
* \return retorna 0 diciendo que no hay error
*/
int orquesta_removeOrquesta(Orquesta* pOrquestas, int len, int* idBorrado,char* msgE,int tries)
{
    int auxiliarID;
    int posID;
    int ret = -1;

    if(pOrquestas != NULL && len > 0)
    {
       auxiliarID = orquesta_getID(pOrquestas,len,msgE,tries);
       if(auxiliarID >= 0)
       {
            posID = orquesta_findPosID(pOrquestas,len,auxiliarID);
            if(posID != -1)
            {
                pOrquestas[posID].isEmpty = 1;
                *idBorrado = posID;
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
/** \brief Le deja ingresar al usuario un ID
* \param lista puntero de orquesta al array de orquestas
* \param tamaño del array
* \param msgE mensajes de errores
* \param tries reintentos de la función
* \return retorna el ID que el usuario ingresa o -1 si hay un error
*/
int orquesta_getID(Orquesta* pOrquestas, int len, char* msgE, int tries)
{
    char bufferID[20];
    int auxiliarID;
    int ret = -1;

    if(pOrquestas != NULL && len > 0)
    {
        if(getStringNumerosInt(bufferID,"\nIngrese ID Orquesta: ",msgE,tries) == 0)
        {
            auxiliarID = atoi(bufferID);
            ret = auxiliarID;
        }
    }
    return ret;
}
/** \brief Permite imprimir el array completo de orquesta
* \param lista puntero de orquesta al array de orquesta
* \param tamaño del array
* \return retorna 0 diciendo que no hay error o -1 si lo hay
*/
int orquesta_printOrquesta(Orquesta* pOrquestas,int len)
{
    int i;
    int flag = -1;

    if(pOrquestas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pOrquestas[i].isEmpty == 0)
            {
                printf("\nID Orquesta: %d\nNombre: %s\nLugar: %s"
                "\nTipo (1-Sinfonica|2-Filarmonica|3-Camara): %d\n--------"
                ,pOrquestas[i].idOrquesta,pOrquestas[i].name,
                pOrquestas[i].place,pOrquestas[i].type);
                flag = 0;
            }
        }
    if(flag)
        {
            printf("\n\tNo se encontraron valores\t\n");
        }
    }
    return 0;
}
/** \brief Permite imprimir el id del array de orquesta
* \param lista puntero de  al array de orquesta
* \param tamaño del array
* \return retorna 0 diciendo que no hay error o -1 si lo hay
*/
int orquesta_printValorRepetidoInt(Orquesta* pOrquestas,int len,int valorBuscado)
{
    int i;
    int flag = -1;

    if(pOrquestas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pOrquestas[i].idOrquesta == valorBuscado)
            {
                printf("\nID Orquesta: %d\n--------"
                ,pOrquestas[i].idOrquesta);
                flag = 0;
            }
        }
    if(flag)
        {
            printf("\n\tNo se encontraron valores\t\n");
        }
    }
    return 0;
}

int orquesta_printOrquestaID(Orquesta* pOrquestas,int len)
{
    int i;
    int flag = -1;

    if(pOrquestas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pOrquestas[i].isEmpty == 0)
            {
                printf("\nID Orquesta: %d\n--------"
                ,pOrquestas[i].idOrquesta);
                flag = 0;
            }
        }
    if(flag)
        {
            printf("\n\tNo se encontraron valores\t\n");
        }
    }
    return 0;
}

int orquesta_sortOrquestaNameType(Orquesta* pOrquestas,int len,int order)
{
    int i;
    int j;
    Orquesta buffer;
    int ret = -1;

    if(pOrquestas != NULL && len > 0)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(order == 1 && (strcmp(pOrquestas[j].name,pOrquestas[i].name) < 0))
                {
                    buffer = pOrquestas[i];
                    pOrquestas[i] = pOrquestas[j];
                    pOrquestas[j] = buffer;
                    ret = 0;
                }
                else if(order == 0 && (strcmp(pOrquestas[j].name,pOrquestas[i].name) > 0))
                {
                    buffer = pOrquestas[i];
                    pOrquestas[i] = pOrquestas[j];
                    pOrquestas[j] = buffer;
                    ret = 0;
                }
                else if(strcmp(pOrquestas[j].name,pOrquestas[i].name) == 0)
                {
                    if(pOrquestas[i].type > pOrquestas[j].type)
                    {
                        buffer = pOrquestas[i];
                        pOrquestas[i] = pOrquestas[j];
                        pOrquestas[j] = buffer;
                        ret = 0;
                    }
                }
            }
        }
    }
    return ret;
}

static int generateID(void)
{
    static int idOrq = 0;
    return idOrq++;
}

