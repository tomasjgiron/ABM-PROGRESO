#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "autor.h"

static int generateID(void);

int autor_menu(Autor* pAutores,int len,char* textMenu,char* msgE,int escape,int tries)
{

    int opcion = 0;
    int posLibre;
    int flag = 0;

    if(pAutores != NULL && len > 0)
    {
        autor_initArray(pAutores,len);
        while(opcion!=escape)
        {
            printf(textMenu);

            getIntInRange(&opcion,"\n Ingrese opcion: ","Informacion invalida\n",
                          1,escape,tries);

            switch(opcion)
            {
                case 1:
                {
                    posLibre = autor_searchFreeSpace(pAutores,len);
                    if(posLibre >= 0)
                    {
                        printf("\n\t~~~~Se encontro lugar~~~~\t\n");
                        if(autor_addAutor(pAutores,len,"Informacion invalida",tries) == 0)
                        {
                            flag = 1;
                            printf("\n\t~~~~Se realizo el alta de manera correcta~~~~\t\n");
                            autor_printAutor(pAutores,len);
                        }
                        else
                        {
                            printf("\n\t~~~~No se realizo el alta~~~~\t\n");
                        }
                    }
                    else
                    {
                        printf("\n\t~~~~No hay lugar libre~~~~\t\n");
                    }
                    break;
                }
                case 2:
                {
                    if(flag == 1)
                    {
                        autor_printAutor(pAutores,len);
                        if(autor_modifyAutor(pAutores,len,"Informacion invalida",3,tries) == 0)
                        {
                            printf("\n\t~~~~Se pudo modificar el listado~~~~\t\n");
                        }
                        else
                        {
                            printf("\n\t~~~~No se pudo modificar el listado~~~~\t\n");
                        }
                    }
                    else
                    {
                        printf("\n~~~~No hay registros para modificar~~~~\n");
                    }
                    break;
                }
                case 3:
                {
                    if(flag == 1)
                    {
                        if(autor_removeAutor(pAutores,len,"Informacion invalida",tries) == 0)
                        {
                            printf("\n\t~~~~Se pudo dar de baja~~~~");
                        }
                        else
                        {
                            printf("\n\t~~~~No se logro dar de baja~~~~\t\n");
                        }
                    }
                    else
                    {
                        printf("\n~~~~No hay registros para dar de baja~~~~\n");
                    }
                    break;
                }
                case 4:
                    {
                        if(flag == 1)
                        {
                           autor_sortAutorSurnameName(pAutores,len,1); // 1 ascendende y 0 descendente
                           autor_printAutor(pAutores,len);
                        }
                        else
                        {
                            printf("\n~~~~No hay registros para mostrar~~~~\n");
                        }
                        break;
                    }
            }
        }
    }

    return 0;
}

int autor_initArray(Autor* pAutores, int len)
{
    int i;

    if(pAutores != NULL && len > 0)
    {
       for(i=0; i<len;i++)
        {
            pAutores[i].isEmpty = 1;
        }
    }
    return 0;
}

int autor_addAutor(Autor* pAutores,int len, char* msgE,int tries)
{
    int indexFree;
    char bufferName[31];
    char bufferSurname[31];
    int ret = -1;

    if(pAutores != NULL && len > 0) ///SIEMPRE VALIDAR AL USAR ARRAYS
    {
        indexFree = autor_searchFreeSpace(pAutores,len);

        if(indexFree >= 0)
        {
            if((getStringLetras(bufferName,"Ingrese nombre: ",msgE,tries) == 0) &&
            (getStringLetras(bufferSurname,"Ingrese apellido: ",msgE,tries) == 0))
            {
                        strncpy(pAutores[indexFree].name,bufferName,sizeof(bufferName));
                        strncpy(pAutores[indexFree].surname,bufferSurname,sizeof(bufferSurname));
                        pAutores[indexFree].isEmpty = 0;
                        pAutores[indexFree].idAutor = generateID();
                        ret = 0;

            }
        }
    }
    else
    {
        printf("\n~~~~El ID es invalido~~~~\n");
    }

    return ret;
}

int autor_searchFreeSpace(Autor* pAutores, int len)
{
    int i;
    int ret=-1;

    if(pAutores != NULL && len > 0)
    {
       for(i=0;i<len;i++)
        {
            if(pAutores[i].isEmpty==1)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int autor_findPosID(Autor* pAutores, int len,int idAut)
{
    int i;
    int ret=-1;

    if(pAutores != NULL && len > 0)
    {
      for(i = 0;i < len;i++)
        {
            if(pAutores[i].idAutor == idAut)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int autor_removeAutor(Autor* pAutores, int len,char* msgE,int tries)
{
    int auxiliarID;
    int posID;
    int ret = -1;

    if(pAutores != NULL && len > 0)
    {
       auxiliarID = autor_getID(pAutores,len,msgE,tries);
       if(auxiliarID >= 0)
       {
            posID = autor_findPosID(pAutores,len,auxiliarID);
            if(posID != -1)
            {
                pAutores[posID].isEmpty = 1;
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

int autor_getID(Autor* pAutores, int len, char* msgE, int tries)
{
    char bufferID[20];
    int auxiliarID;
    int ret = -1;

    if(pAutores != NULL && len > 0)
    {
        if(getStringNumerosInt(bufferID,"\nIngrese ID Autor: ",msgE,tries) == 0)
        {
            auxiliarID = atoi(bufferID);
            ret = auxiliarID;
        }
    }
    return ret;
}

int autor_printAutor(Autor* pAutores,int len)
{
    int i;
    int flag = -1;

    if(pAutores != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pAutores[i].isEmpty == 0)
            {
                printf("\nID Autor: %d\nNombre: %s\nApellido: %s\n--------"
                ,pAutores[i].idAutor,pAutores[i].name,
                pAutores[i].surname);
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

int autor_sortAutorSurnameName(Autor* pAutores,int len,int order)
{
    int i;
    int j;
    Autor buffer;
    int ret = -1;

    if(pAutores != NULL && len > 0)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(order == 1 && (strcmp(pAutores[j].surname,pAutores[i].surname) < 0))
                {
                    buffer = pAutores[i];
                    pAutores[i] = pAutores[j];
                    pAutores[j] = buffer;
                    ret = 0;
                }
                else if(order == 0 && (strcmp(pAutores[j].surname,pAutores[i].surname) > 0))
                {
                    buffer = pAutores[i];
                    pAutores[i] = pAutores[j];
                    pAutores[j] = buffer;
                    ret = 0;
                }
                else if(strcmp(pAutores[j].surname,pAutores[i].surname) == 0)
                {
                    if(pAutores[i].name > pAutores[j].name)
                    {
                        buffer = pAutores[i];
                        pAutores[i] = pAutores[j];
                        pAutores[j] = buffer;
                        ret = 0;
                    }
                }
            }
        }
    }
    return ret;
}

int autor_modifyAutor(Autor* pAutores,int len,char* msgE,int escape,int tries)
{
    char bufferName[31];
    char bufferSurname[31];
    int auxiliarID;
    int posID;
    int ret = -1;
    int opcion = 0;


    if(pAutores != NULL && len > 0)
    {
       auxiliarID = autor_getID(pAutores,len,msgE,tries);
       if(auxiliarID >= 0)
       {
            posID = autor_findPosID(pAutores,len,auxiliarID);
            if(posID != -1)
            {
                do
                {
                    getIntInRange(&opcion,"\n1)Ingrese nuevo nombre"
                          "\n2)Ingrese nuevo apellido"
                          "\n3)Salir\n~~~~~~~~~~~~~~~~~~~~~~\n",msgE,1,escape,tries);

                    switch(opcion)
                    {
                        case 1:
                        {
                            if(getStringLetras(bufferName,"\nIngrese nombre: ",msgE,tries) == 0)
                            {
                                strncpy(pAutores[posID].name,bufferName,sizeof(bufferName));
                                ret = 0;
                            }
                            break;
                        }
                        case 2:
                        {
                            if((getStringLetras(bufferSurname,"\nIngrese apellido: ",msgE,tries) == 0))
                            {
                                strncpy(pAutores[posID].surname,bufferSurname,sizeof(bufferSurname));
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
    }
    return ret;
}

static int generateID(void)
{
    static int idAut = 0;
    return idAut++;
}
