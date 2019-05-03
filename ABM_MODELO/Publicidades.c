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

int pub_printContrataciones(Publicidad* pPublicidades,int len)
{
    int i;
    int flag = -1;

    if(pPublicidades != NULL && len > 0)
    {
        for(i = 0;i < len;i++)
        {
            if(pPublicidades[i].isEmpty == 0)
            {
                printf("\nID Publicidad: %d\nCuit de cliente: %s\n"
                "Nombre de archivo: %s\nCantidad de dias: %d\nID Pantalla: %d\n--------",
                                                            pPublicidades[i].idPublicidad,
                                                            pPublicidades[i].cuitCliente,
                                                            pPublicidades[i].archivo,
                                                            pPublicidades[i].dias,
                                                            pPublicidades[i].idPantalla);
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

int pub_create(Publicidad* pPublicidades,Pantalla* pPantallas,int len, char* msgE,int tries)
{
    int auxiliarIDPantalla;
    int posOfID;
    int indexFree;
    char bufferCuCli[20];
    char bufferNaFi[20];
    char bufferStrDia[20];
    int bufferDia;
    int ret = -1;

    if(pPublicidades != NULL && len > 0) ///SIEMPRE VALIDAR AL USAR ARRAYS
    {
        auxiliarIDPantalla = pub_getID(pPublicidades,len,msgE,tries);
        indexFree = pub_searchFreeSpace(pPublicidades,len);
        posOfID = pan_findPosID(pPantallas,len,auxiliarIDPantalla);

        if((auxiliarIDPantalla >= 1) && (posOfID != -1))
        {
            if((getCuit(bufferCuCli,"Ingrese cuit de cliente: ",msgE,tries) == 0) &&
            (getStringAlphanumeric(bufferNaFi,"Ingrese nombre de archivo: ",msgE,tries) == 0))
            {
                if(getStringNumerosInt(bufferStrDia,"Ingrese cantidad de dias: ",msgE,tries) == 0)
                {
                    bufferDia = atoi(bufferStrDia);
                    strncpy(pPublicidades[indexFree].cuitCliente,bufferCuCli,sizeof(bufferCuCli));
                    strncpy(pPublicidades[indexFree].archivo,bufferNaFi,sizeof(bufferNaFi));
                    pPublicidades[indexFree].dias = bufferDia;
                    pPublicidades[indexFree].isEmpty = 0;
                    pPublicidades[indexFree].idPantalla = auxiliarIDPantalla;
                    pPublicidades[indexFree].idPublicidad = generateID();
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

int pub_printPublicidades(Publicidad* pPublicidades,Pantalla* pPantallas,int lenPan,int lenPub)
{
    int i;
    int flag = -1;
    int posPant;

    if((pPublicidades != NULL) && (pPantallas != NULL) && (lenPan > 0) && (lenPub > 0))
    {
    for(i=0;i<lenPub;i++)
    {
        if(pPublicidades[i].isEmpty == 0)
        {
            posPant = pan_findPosID(pPantallas,lenPan,pPublicidades[i].idPantalla);
            if(posPant >= 0)
            {
            printf("ID Publicidad: %d\nNombre Pantalla: %s\nNombre archivo: %s\n"
            "Cantidad de dias: %d\nCuit Cliente: %s\n--------"
            ,pPublicidades[i].idPublicidad,pPantallas[posPant].nombre,
            pPublicidades[i].archivo,pPublicidades[i].dias,pPublicidades[i].cuitCliente);

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

int pub_printPantallaByCuit(Pantalla* pPantallas,Publicidad* pPublicidades,int lenPan,int lenPub,char* valor)
{
    int i;
    int posPant;

    for(i=0;i<lenPub;i++)
    {
        if((pPublicidades[i].isEmpty == 0) && (strncmp(pPublicidades[i].cuitCliente,valor,sizeof(valor)) == 0))
        {
            posPant = pan_findPosID(pPantallas,lenPan,pPublicidades[i].idPantalla);
            if(posPant >= 0)
            {
                printf("\nCuit Cliente: %s\nID Pantalla: %d\n"
                "Nombre: %s\nDireccion: %s\nPrecio: %.2f\nTipo 1 LCD / 2 LED: %d",pPublicidades[i].cuitCliente,
                pPantallas[posPant].idPantalla,pPantallas[posPant].nombre,pPantallas[posPant].direccion,
                pPantallas[posPant].precio,pPantallas[posPant].tipo);
            }
        }
    }
}

int pub_printContratDiasMenoresA(Publicidad* listaPub,
                                  int lenPub,
                                  Pantalla* listaPan,
                                  int lenPan,
                                  int valor)
{
    int i;
    int posPan;
    float total;
    for(i=0; i<lenPub;i++)
    {
        if(listaPub[i].isEmpty==0)
        {
            if(listaPub[i].dias<=valor)
            {
                // imprimo todocomoloco
                posPan = pan_findPanById(listaPan,
                                         lenPan,
                                        listaPub[i].idPantalla);
                if(posPan>=0)
                {
                    // nombre precio dias total
                    total = listaPan[posPan].precio * listaPub[i].dias;

                    printf("%s %f %d %f",listaPan[posPan].nombre,
                                         listaPan[posPan].precio,
                                         listaPub[i].dias,
                                         total);
                }
            }
        }
    }
    return 0;
}

int pub_sortByPrice(Publicidad* pPublicidades,int len)
{
    int i;
    int j;
    Publicidad buffer;

    if(pPublicidades != NULL && len > 0)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(pPublicidades[i].dias>pPublicidades[j].precio)
                {
                    buffer = pPublicidades[i];
                    pPublicidades[i] = pPublicidades[j];
                    pPublicidades[j] = buffer;
                }
            }
        }
    }
    return 0;
}
