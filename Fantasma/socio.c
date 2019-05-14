#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "socio.h"
#include "autor.h"
#include "libro.h"

static int generateID(void);

int socio_menu(Socio* pSocios,int lenSoc,Autor* pAutores,int lenAut,Libro* pLibros,int lenLib,char* textMenu,char* msgE,int escape,int tries)
{

    int opcion = 0;
    int posLibre;
    int flag = 0;

    if(pSocios != NULL && lenSoc > 0)
    {
        socio_initArray(pSocios,lenSoc);
        while(opcion!=6)
        {
            printf(textMenu);

            getIntInRange(&opcion,"\n Ingrese opcion: ","Informacion invalida\n",
                          1,escape,tries);

            switch(opcion)
            {
                case 1:
                {
                    posLibre = socio_searchFreeSpace(pSocios,lenSoc);
                    if(posLibre >= 0)
                    {
                        printf("\n\t~~~~Se encontro lugar~~~~\t\n");
                        if(socio_addSocio(pSocios,lenSoc,"Informacion invalida",tries) == 0)
                        {
                            flag = 1;
                            printf("\n\t~~~~Se realizo el alta de manera correcta~~~~\t\n");
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
                        if(socio_modifySocio(pSocios,lenSoc,"Informacion invalida",5,tries) == 0)
                        {
                            printf("\n\t~~~~Se pudo modificar el listado~~~~\t\n");
                        }
                        else
                        {
                            printf("\n\t~~~~No se pudo modificar el listado~~~~\t\n");
                        }
                    }
                    printf("\n~~~~No hay registros para modificar~~~~\n");
                    break;
                }
                case 3:
                {
                    if(flag == 1)
                    {
                        if(socio_removeSocio(pSocios,lenSoc,"Informacion invalida",tries) == 0)
                        {
                            printf("\n\t~~~~Se pudo dar de baja~~~~");
                        }
                        else
                        {
                            printf("\n\t~~~~No se logro dar de baja~~~~\t\n");
                        }
                    }
                    printf("\n~~~~No hay registros para dar de baja~~~~\n");
                    break;
                }
                case 4:
                    {
                        if(flag == 1)
                        {
                           socio_sortSocioSurnameName(pSocios,lenSoc,1); // 1 ascendende y 0 descendente
                           socio_printSocio(pSocios,lenSoc);
                        }
                        else
                        {
                            printf("\n~~~~No hay registros para mostrar~~~~\n");
                        }
                        break;
                    }
                case 5:
                    {
                        if(flag == 1)
                        {
                            libro_printLibro(pLibros,pAutores,lenAut,lenLib);
                        }
                        else
                        {
                            printf("\n~~~~No hay registros para mostrar~~~~\n");
                        }
                        break;
                    }
                case 6:
                    {
                        if(flag == 1)
                        {
                            autor_printAutor(pAutores,lenAut);
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

int socio_initArray(Socio* pSocios, int len)
{
    int i;

    if(pSocios != NULL && len > 0)
    {
       for(i=0; i<len;i++)
        {
            pSocios[i].isEmpty = 1;
        }
    }
    return 0;
}

int socio_addSocio(Socio* pSocios,int len,char* msgE,int tries)
{
    int indexFree;
    char bufferName[31];
    char bufferSurname[31];
    char bufferSexo[2]; ///consultar
    char bufferTelephone[16];
    char bufferMail[31];
    int ret = -1;

    if(pSocios != NULL && len > 0) ///SIEMPRE VALIDAR AL USAR ARRAYS
    {
        indexFree = socio_searchFreeSpace(pSocios,len);

        if(indexFree >= 0)
        {
            if((getStringLetras(bufferName,"Ingrese nombre: ",msgE,tries) == 0) &&
            (getStringLetras(bufferSurname,"Ingrese apellido: ",msgE,tries) == 0))
            {
                if(getSexo(bufferSexo,"Ingrese sexo: ",msgE,tries)==0)
                {
                    if((getTelephone(bufferTelephone,"Ingrese telefono: ",msgE,tries)==0))
                    {
                        if((getMail(bufferMail,"Ingrese email: ",msgE,tries)==0))
                        {
                            strncpy(pSocios[indexFree].name,bufferName,sizeof(bufferName));
                            strncpy(pSocios[indexFree].surname,bufferSurname,sizeof(bufferSurname));
                            strncpy(pSocios[indexFree].sexo,bufferSexo,sizeof(bufferSexo));
                            strncpy(pSocios[indexFree].telephone,bufferTelephone,sizeof(bufferTelephone));
                            strncpy(pSocios[indexFree].email,bufferMail,sizeof(bufferMail));
                            pSocios[indexFree].isEmpty = 0;
                            pSocios[indexFree].idSocio = generateID();
                            ret = 0;
                        }
                    }
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

int socio_searchFreeSpace(Socio* pSocios, int len)
{
    int i;
    int ret=-1;

    if(pSocios != NULL && len > 0)
    {
       for(i=0;i<len;i++)
        {
            if(pSocios[i].isEmpty==1)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int socio_findPosID(Socio* pSocios, int len,int idSoc)
{
    int i;
    int ret=-1;

    if(pSocios != NULL && len > 0)
    {
      for(i = 0;i < len;i++)
        {
            if(pSocios[i].idSocio == idSoc)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int socio_removeSocio(Socio* pSocios, int len,char* msgE,int tries)
{
    int auxiliarID;
    int posID;
    int ret = -1;

    if(pSocios != NULL && len > 0)
    {
       auxiliarID = socio_getID(pSocios,len,msgE,tries);
       if(auxiliarID >= 1)
       {
            posID = socio_findPosID(pSocios,len,auxiliarID);
            if(posID != -1)
            {
                pSocios[posID].isEmpty = 1;
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

int socio_getID(Socio * pSocios, int len, char* msgE, int tries)
{
    char bufferID[20];
    int auxiliarID;
    int ret = -1;

    if(pSocios != NULL && len > 0)
    {
        if(getStringNumerosInt(bufferID,"\nIngrese ID: ",msgE,tries) == 0)
        {
            auxiliarID = atoi(bufferID);
            ret = auxiliarID;
        }
    }
    return ret;
}

int socio_printSocio(Socio* pSocios,int len)
{
    int i;
    int flag = -1;

    if(pSocios != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pSocios[i].isEmpty == 0)
            {
                printf("ID Socio: %d\nNombre: %s\nApellido: %s\nSexo: %s\nTelefono: %s\neMail: %s\n--------"
                ,pSocios[i].idSocio,pSocios[i].name,
                pSocios[i].surname,pSocios[i].sexo,pSocios[i].telephone
                ,pSocios[i].email);
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

int socio_sortSocioSurnameName(Socio* pSocios,int len,int order)
{
    int i;
    int j;
    Socio buffer;
    int ret = -1;

    if(pSocios != NULL && len > 0)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(order == 1 && (strcmp(pSocios[j].surname,pSocios[i].surname) < 0))
                {
                    buffer = pSocios[i];
                    pSocios[i] = pSocios[j];
                    pSocios[j] = buffer;
                    ret = 0;
                }
                else if(order == 0 && (strcmp(pSocios[j].surname,pSocios[i].surname) > 0))
                {
                    buffer = pSocios[i];
                    pSocios[i] = pSocios[j];
                    pSocios[j] = buffer;
                    ret = 0;
                }
                else if(strcmp(pSocios[j].surname,pSocios[i].surname) == 0)
                {
                    if(pSocios[i].name > pSocios[j].name)
                    {
                        buffer = pSocios[i];
                        pSocios[i] = pSocios[j];
                        pSocios[j] = buffer;
                        ret = 0;
                    }
                }
            }
        }
    }
    return ret;
}

int socio_modifySocio(Socio* pSocios,int len,char* msgE,int escape,int tries)
{
    char bufferName[31];
    char bufferSurname[31];
    int auxiliarID;
    int posID;
    int ret = -1;
    int opcion = 0;


    if(pSocios != NULL && len > 0)
    {
       auxiliarID = socio_getID(pSocios,len,msgE,tries);
       if(auxiliarID >= 1)
       {
            posID = socio_findPosID(pSocios,len,auxiliarID);
            if(posID != -1)
            {
                pSocios[posID].isEmpty = 1;
                ret = 0;
            }
            else
            {
                printf("\n\tID inexistente\t\n");
            }

        }
        do
        {
            getIntInRange(&opcion,"\n1)Ingrese nuevo nombre\n2)Ingrese nuevo apellido\n3)Salir\n\n~~~~~~~~~~~~~~~~~~~~~~\n",msgE,1,escape,tries);
            switch(opcion)
            {
                case 1:
                {
                    if(getStringLetras(bufferName,"\nIngrese nombre: ",msgE,tries) == 0)
                       {
                           strncpy(pSocios[posID].name,bufferName,sizeof(bufferName));
                           ret = 0;
                       }
                       break;
                }
                case 2:
                {
                   if((getStringLetras(bufferSurname,"\nIngrese apellido: ",msgE,tries) == 0))
                   {
                       strncpy(pSocios[posID].surname,bufferSurname,sizeof(bufferSurname));
                       ret = 0;
                   }
                   break;
                }
                default:
                {
                    ret = -1;
                }
            }
        }while(ret == -1 || opcion != escape);
    }
    return ret;
}

static int generateID(void)
{
    static int idSoc = 0;
    return idSoc++;
}
