#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"

static int generateID(void);

int musico_initArray(Musico* pMusicos, int len)
{
    int i;

    if(pMusicos != NULL && len > 0)
    {
       for(i=0; i<len;i++)
        {
            pMusicos[i].isEmpty = 1;
        }
    }
    return 0;
}

int musico_addMusico(Musico* pMusicos,int lenMus,
                         Orquesta* pOrquestas,int lenOrq,
                         Instrumento* pInstrumentos,int lenIns,
                         char* msgE,int tries)
{
    int indexFree;
    char bufferName[50];
    char bufferSurname[50];
    int auxiliarEdad;
    int auxiliarIDOrquesta;
    int auxiliarIDInstrumento;
    int posIDOrquesta;
    int posIDInstrumento;
    int ret = -1;

    if(pMusicos != NULL && pOrquestas != NULL && pMusicos != NULL && lenMus > 0
       && lenOrq > 0 && lenMus > 0)
    {
        indexFree = musico_searchFreeSpace(pMusicos,lenMus);
        auxiliarIDOrquesta = orquesta_getID(pOrquestas,lenOrq,msgE,tries);
        auxiliarIDInstrumento = instrumento_getID(pInstrumentos,lenIns,msgE,tries);
        posIDOrquesta = orquesta_findPosID(pOrquestas,lenOrq,auxiliarIDOrquesta);
        posIDInstrumento = instrumento_findPosID(pInstrumentos,lenIns,auxiliarIDInstrumento);

        if((indexFree >= 0) && (auxiliarIDOrquesta >= 0) && (posIDOrquesta != -1)
           && (auxiliarIDInstrumento >= 0) && (posIDInstrumento != -1) &&
            ((getStringLetras(bufferName,"Ingrese nombre: ",msgE,tries) == 0) &&
            (getStringLetras(bufferSurname,"Ingrese apellido: ",msgE,tries) == 0)))
        {
            if((getInt(&auxiliarEdad,"Ingrese edad: ",msgE) == 0))
                {
                    pMusicos[indexFree].idOrquesta = auxiliarIDOrquesta;
                    pMusicos[indexFree].idInstrumento = auxiliarIDInstrumento;
                    strncpy(pMusicos[indexFree].name,bufferName,sizeof(bufferName));
                    strncpy(pMusicos[indexFree].surname,bufferSurname,sizeof(bufferSurname));
                    pMusicos[indexFree].edad = auxiliarEdad;
                    pMusicos[indexFree].idMusico = generateID();
                    pMusicos[indexFree].isEmpty = 0;
                    ret = 0;
                }
        }
    }
    return ret;
}

int musico_searchFreeSpace(Musico* pMusicos, int len)
{
    int i;
    int ret=-1;

    if(pMusicos != NULL && len > 0)
    {
       for(i=0;i<len;i++)
        {
            if(pMusicos[i].isEmpty==1)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int musico_findPosID(Musico* pMusicos, int len,int idIns)
{
    int i;
    int ret=-1;

    if(pMusicos != NULL && len > 0)
    {
      for(i = 0;i < len;i++)
        {
            if(pMusicos[i].idInstrumento == idIns)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int musico_removeMusico(Musico* pMusicos, int len,char* msgE,int tries)
{
    int auxiliarID;
    int posID;
    int ret = -1;

    if(pMusicos != NULL && len > 0)
    {
       auxiliarID = musico_getID(pMusicos,len,msgE,tries);
       if(auxiliarID >= 0)
       {
            posID = musico_findPosID(pMusicos,len,auxiliarID);
            if(posID != -1)
            {
                pMusicos[posID].isEmpty = 1;
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

int musico_bajaValorRepetidoInt(Musico* pMusicos, int len, int valorBuscado)
{
    int ret=-1;
    int i;
    if(pMusicos != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pMusicos[i].idOrquesta == valorBuscado)
            {
                pMusicos[i].isEmpty=1;
            }
        }
        ret = 0;
    }
    return ret;
}

int musico_getID(Musico* pMusicos, int len, char* msgE, int tries)
{
    char bufferID[20];
    int auxiliarID;
    int ret = -1;

    if(pMusicos != NULL && len > 0)
    {
        if(getStringNumerosInt(bufferID,"\nIngrese ID Instrumento: ",msgE,tries) == 0)
        {
            auxiliarID = atoi(bufferID);
            ret = auxiliarID;
        }
    }
    return ret;
}

int musico_printMusico(Musico* pMusicos,Instrumento* pInstrumento,int lenMus,int lenIns)
{
    int i;
    int flag = -1;
    int posInstrumento;

    if(pMusicos != NULL && pInstrumento != NULL && lenMus > 0 && lenIns > 0)
    {
        for(i=0;i<lenMus;i++)
        {
            if(pMusicos[i].isEmpty == 0)
            {
                posInstrumento = instrumento_findPosID(pInstrumento,lenIns,pMusicos[i].idInstrumento);
                if(posInstrumento >= 0)
                {
                    printf("\nID Musico: %d\nNombre: %s\nApellido: %s\nNombre Instrumento: %s\n"
                    "Tipo (1-Cuerda|2-Viento Madera|3-Viento Metal|4-Percusion): %d\n--------"
                    ,pMusicos[i].idMusico,pMusicos[i].name,pMusicos[i].surname,pInstrumento[posInstrumento].name,pInstrumento[posInstrumento].type);
                    flag = 0;
                }
            }
        }
        if(flag)
        {
            printf("\n\tNo se encontraron valores\t\n");
        }
    }
    return 0;
}

int musico_modifyMusico(Musico* pMusicos,int lenMus,Orquesta* pOrquestas,int lenOrq,char* msgE,int escape,int tries)
{
    int auxiliarEdad;
    int auxiliarIDOrquesta;
    int indexFree;
    int posIDOrquesta;
    int ret = -1;
    int opcion = 0;


    if(pMusicos != NULL && pOrquestas != NULL && lenMus > 0 && lenOrq > 0)
    {
        indexFree = musico_searchFreeSpace(pMusicos,lenMus);
        auxiliarIDOrquesta = orquesta_getID(pOrquestas,lenOrq,msgE,tries);
        posIDOrquesta = orquesta_findPosID(pOrquestas,lenOrq,auxiliarIDOrquesta);
        if((indexFree >= 0) && (auxiliarIDOrquesta >= 0) && (posIDOrquesta != -1))
        {
                do
                {
                    getIntInRange(&opcion,"\n1)Ingrese nueva edad"
                          "\n2)Ingrese nuevo ID Orquesta"
                          "\n3)Salir\n~~~~~~~~~~~~~~~~~~~~~~\n",msgE,1,escape,tries);

                    switch(opcion)
                    {
                        case 1:
                        {
                            if(getInt(&auxiliarEdad,"Ingrese edad: ",msgE) == 0)
                            {
                                pMusicos[indexFree].edad = auxiliarEdad;
                                ret = 0;
                            }
                            break;
                        }
                        case 2:
                        {
                            if(getInt(&auxiliarIDOrquesta,"Ingrese nuevo ID Orquesta: ",msgE) == 0)
                            {
                                pOrquestas[posIDOrquesta].idOrquesta = auxiliarIDOrquesta;
                                ret = 0;
                            }
                            break;
                        }
                    }
                }while(opcion != escape);
            }
            else
            {
                printf("\n\tID inexistente\t\n");
            }


        }
    return ret;
}

/*int emp_sortEmployeeSurnameSector(Employee* pEmployees,int len,int order)
{
    int i;
    int j;
    Employee buffer;
    int ret = -1;

    if(pEmployees != NULL && len > 0)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(order == 1 && (strcmp(pEmployees[j].surname,pEmployees[i].surname) < 0))
                {
                    buffer = pEmployees[i];
                    pEmployees[i] = pEmployees[j];
                    pEmployees[j] = buffer;
                    ret = 0;
                }
                else if(order == 0 && (strcmp(pEmployees[j].surname,pEmployees[i].surname) > 0))
                {
                    buffer = pEmployees[i];
                    pEmployees[i] = pEmployees[j];
                    pEmployees[j] = buffer;
                    ret = 0;
                }
                else if(strcmp(pEmployees[j].surname,pEmployees[i].surname) == 0)
                {
                    if(pEmployees[i].sector > pEmployees[j].sector)
                    {
                        buffer = pEmployees[i];
                        pEmployees[i] = pEmployees[j];
                        pEmployees[j] = buffer;
                        ret = 0;
                    }
                }
            }
        }
    }
    return ret;
}
*/
int musico_bubbleSortEficiente(Musico* pMusicos, int len,int order)///1up 0down
{
    int i;
    int flagNoEstaOrdenado=1;
    int retorno=-1;
    Musico buffer;
    if(pMusicos != NULL && len > 0 && (order == 0 || order == 1))
    {
        while(flagNoEstaOrdenado == 1)
        {
            flagNoEstaOrdenado=0;
            for(i=1;i<len;i++)
            {
                if((order == 1)&&(strcmp(pMusicos[i-1].surname,pMusicos[i].surname) > 0))///Creciente
                {
                    buffer=pMusicos[i-1];
                    pMusicos[i-1]=pMusicos[i];
                    pMusicos[i]=buffer;
                    flagNoEstaOrdenado=1;
                    retorno=0;
                }
                else if((order == 0)&&(strcmp(pMusicos[i-1].surname,pMusicos[i].surname) < 0))///Decreciente
                {
                    buffer=pMusicos[i-1];
                    pMusicos[i-1]=pMusicos[i];
                    pMusicos[i]=buffer;
                    flagNoEstaOrdenado=1;
                    retorno=0;
                }
            }
        }
        if(flagNoEstaOrdenado==0)
        {
            musico_sortMusicoEdad(pMusicos,len,order);
        }
    }
    return retorno;
}

int musico_sortMusicoEdad(Musico* pMusicos,int len,int order)
{
    int i;
    Musico buffer;

    for(i=1;i<len;i++)
    {
        if(pMusicos[i-1].edad == pMusicos[i].edad)
        {
            if((order == 1)&&(pMusicos[i-1].edad > pMusicos[i].edad))
            {
                buffer=pMusicos[i-1];
                pMusicos[i-1]=pMusicos[i];
                pMusicos[i]=buffer;
            }
            else if((order == 0)&&(pMusicos[i-1].edad < pMusicos[i].edad))
            {
                buffer=pMusicos[i-1];
                pMusicos[i-1]=pMusicos[i];
                pMusicos[i]=buffer;
            }
        }
    }
    return 0;
}

static int generateID(void)
{
    static int idIns = 0;
    return idIns++;
}
