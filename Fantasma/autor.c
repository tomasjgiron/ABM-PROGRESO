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
        while(opcion!=5)
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
                        if(autor_modifyAutor(pAutores,len,"Informacion invalida",5,tries) == 0)
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
                        if(autor_removeAutor(pAutores,len,"Informacion invalida",tries) == 0)
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
/*                case 4:
                    {
                        if(flag == 1)
                        {
                            if(autor_sortAutorSurnameSector(pAutores,len) == 0);
                            {
                                autor_printAutor(pAutores,len);
                            }
                            if(autor_printTotalPromAboveSalary(pAutores,len) == 0)
                            {
                                autor_printTotalPromAboveSalary(pAutores,len);
                            }

                        }
                        printf("\n~~~~No hay registros para mostrar~~~~\n");
                        break;
                    }*/
                case 5:
                    {
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
    int auxiliarIDAutor;
    int posOfID;
    int indexFree;
    char bufferName[51];
    char bufferSurname[51];
    int ret = -1;

    if(pAutores != NULL && len > 0) ///SIEMPRE VALIDAR AL USAR ARRAYS
    {
        auxiliarIDAutor = autor_getID(pAutores,len,msgE,tries);
        indexFree = autor_searchFreeSpace(pAutores,len);
        posOfID = autor_findPosID(pAutores,len,auxiliarIDAutor);

        if((auxiliarIDAutor >= 1) && (posOfID != -1))
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

int autor_findPosID(Autor* pAutores, int len,int idEmp)
{
    int i;
    int ret=-1;

    if(pAutores != NULL && len > 0)
    {
      for(i = 0;i < len;i++)
        {
            if(pAutores[i].idAutor == idEmp)
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
       if(auxiliarID >= 1)
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

int autor_getID(Autor * pPublicidad, int len, char* msgE, int tries)
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
                printf("ID Autor: %d\nNombre: %s\nApellido: %s\n--------"
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

int autor_sortAutorSurnameSector(Autor* pAutores,int len)
{
    int i;
    int j;
    Autor buffer;

    if(pAutores != NULL && len > 0)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(pAutores[i].surname > pAutores[j].surname)
                {
                    buffer = pAutores[i];
                    pAutores[i] = pAutores[j];
                    pAutores[j] = buffer;
                }
            }
        }
    }
    return 0;
}

/*int autor_printTotalPromAboveSalary(Autor* pAutores, int len)
{
    int i;
    float acumuladorTotal = 0;
    float prom;
    int contador = 0;
    int auxiliarAboveSalary;

    if(pAutores != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pAutores[i].isEmpty == 0)
            {
            acumuladorTotal += pAutores[i].salary;
            contador += pAutores[i].salary;
            }
        }
        prom = acumuladorTotal/contador;

        auxiliarAboveSalary = autor_aboveSalary(pAutores,len,prom);

        printf("El salario total es: %.2f\n",acumuladorTotal);
        printf("El promedio es: %.2f\n",prom);
        printf("La cantidad de empleados con salario por encima del promedio es: %d",auxiliarAboveSalary);
    }
    return 0;
}

int autor_aboveSalary(Autor* pAutores, int len, float prom)
{
    int contador = 0;
    int i;
    int ret = -1;

    if(pAutores != NULL && len > 0)
    {

        for(i=0;i<len;i++)
        {
            if(pAutores[i].salary > prom)
            {
                contador++;
                ret = contador;
            }
        }
    }
    return ret;
}*/

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
       if(auxiliarID >= 1)
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
        do
        {
            getIntInRange(&opcion,"\n1)Ingrese nuevo nombre\n2)Ingrese nuevo apellido\n3)Salir\n\n~~~~~~~~~~~~~~~~~~~~~~\n",msgE,1,escape,tries);
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
    static int idAut = 0;
    return idAut++;
}
