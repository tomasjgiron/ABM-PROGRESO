#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "libro.h"

static int generateID(void);

int libro_menu(Libro* pLibros,int len,char* textMenu,char* msgE,int escape,int tries)
{

    int opcion = 0;
    int posLibre;
    int flag = 0;

    if(pLibros != NULL && len > 0)
    {
        libro_initArray(pLibros,len);
        while(opcion!=5)
        {
            printf(textMenu);

            getIntInRange(&opcion,"\n Ingrese opcion: ","Informacion invalida\n",
                          1,escape,tries);

            switch(opcion)
            {
                case 1:
                {
                    posLibre = libro_searchFreeSpace(pLibros,len);
                    if(posLibre >= 0)
                    {
                        printf("\n\t~~~~Se encontro lugar~~~~\t\n");
                        if(libro_addLibro(pLibros,len,"Informacion invalida",tries) == 0)
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
                        if(libro_modifyLibro(pLibros,len,"Informacion invalida",5,tries) == 0)
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
                        if(libro_removeLibro(pLibros,len,"Informacion invalida",tries) == 0)
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
                            if(libro_sortLibroSurnameSector(pLibros,len) == 0);
                            {
                                libro_printLibro(pLibros,len);
                            }
                            if(libro_printTotalPromAboveSalary(pLibros,len) == 0)
                            {
                                libro_printTotalPromAboveSalary(pLibros,len);
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

int libro_initArray(Libro* pLibros, int len)
{
    int i;

    if(pLibros != NULL && len > 0)
    {
       for(i=0; i<len;i++)
        {
            pLibros[i].isEmpty = 1;
        }
    }
    return 0;
}

int libro_addLibro(Libro* pLibros,int len, char* msgE,int tries) ///similar al pub_create con dos arrays
{
    int auxiliarIDLibro;
    int posOfID;
    int indexFree;
    char bufferTitulo[31];
    int ret = -1;

    if(pLibros != NULL && len > 0) ///SIEMPRE VALIDAR AL USAR ARRAYS
    {
        auxiliarIDLibro = libro_getID(pLibros,len,msgE,tries);
        indexFree = libro_searchFreeSpace(pLibros,len);
        posOfID = libro_findPosID(pLibros,len,auxiliarIDLibro);

        if((auxiliarIDLibro >= 1) && (posOfID != -1))
        {
            if(getStringLetras(bufferTitulo,"Ingrese titulo: ",msgE,tries) == 0)
            {
                strncpy(pLibros[indexFree].titulo,bufferTitulo,sizeof(bufferTitulo));
                pLibros[indexFree].isEmpty = 0;
                pLibros[indexFree].idLibro = generateID();
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

int libro_searchFreeSpace(Libro* pLibros, int len)
{
    int i;
    int ret=-1;

    if(pLibros != NULL && len > 0)
    {
       for(i=0;i<len;i++)
        {
            if(pLibros[i].isEmpty==1)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int libro_findPosID(Libro* pLibros, int len,int idEmp)
{
    int i;
    int ret=-1;

    if(pLibros != NULL && len > 0)
    {
      for(i = 0;i < len;i++)
        {
            if(pLibros[i].idLibro == idEmp)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int libro_removeLibro(Libro* pLibros, int len,char* msgE,int tries)
{
    int auxiliarID;
    int posID;
    int ret = -1;

    if(pLibros != NULL && len > 0)
    {
       auxiliarID = libro_getID(pLibros,len,msgE,tries);
       if(auxiliarID >= 1)
       {
            posID = libro_findPosID(pLibros,len,auxiliarID);
            if(posID != -1)
            {
                pLibros[posID].isEmpty = 1;
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

int libro_getID(Libro * pPublicidad, int len, char* msgE, int tries)
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

int libro_printLibro(Libro* pLibros,int len)
{
    int i;
    int flag = -1;

    if(pLibros != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pLibros[i].isEmpty == 0)
            {
                printf("ID Libro: %d\nTitulo: %s\n--------"
                ,pLibros[i].idLibro,pLibros[i].titulo);
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

/*int libro_sortLibroSurnameSector(Libro* pLibros,int len)
{
    int i;
    int j;
    Libro buffer;

    if(pLibros != NULL && len > 0)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if((pLibros[i].surname > pLibros[j].surname) &&(pLibros[i].sector > pLibros[j].sector))
                {
                    buffer = pLibros[i];
                    pLibros[i] = pLibros[j];
                    pLibros[j] = buffer;
                }
            }
        }
    }
    return 0;
}

int libro_printTotalPromAboveSalary(Libro* pLibros, int len)
{
    int i;
    float acumuladorTotal = 0;
    float prom;
    int contador = 0;
    int auxiliarAboveSalary;

    if(pLibros != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pLibros[i].isEmpty == 0)
            {
            acumuladorTotal += pLibros[i].salary;
            contador += pLibros[i].salary;
            }
        }
        prom = acumuladorTotal/contador;

        auxiliarAboveSalary = libro_aboveSalary(pLibros,len,prom);

        printf("El salario total es: %.2f\n",acumuladorTotal);
        printf("El promedio es: %.2f\n",prom);
        printf("La cantidad de empleados con salario por encima del promedio es: %d",auxiliarAboveSalary);
    }
    return 0;
}

int libro_aboveSalary(Libro* pLibros, int len, float prom)
{
    int contador = 0;
    int i;
    int ret = -1;

    if(pLibros != NULL && len > 0)
    {

        for(i=0;i<len;i++)
        {
            if(pLibros[i].salary > prom)
            {
                contador++;
                ret = contador;
            }
        }
    }
    return ret;
}*/

int libro_modifyLibro(Libro* pLibros,int len,char* msgE,int escape,int tries)
{
    char bufferTitulo[31];
    int auxiliarID;
    int posID;
    int ret = -1;
    int opcion = 0;


    if(pLibros != NULL && len > 0)
    {
       auxiliarID = libro_getID(pLibros,len,msgE,tries);
       if(auxiliarID >= 1)
       {
            posID = libro_findPosID(pLibros,len,auxiliarID);
            if(posID != -1)
            {
                pLibros[posID].isEmpty = 1;
                ret = 0;
            }
            else
            {
                printf("\n\tID inexistente\t\n");
            }

        }
        do
        {
            getIntInRange(&opcion,"\n1)Ingrese nuevo titulo\n2)Salir\n\n~~~~~~~~~~~~~~~~~~~~~~\n"
                          ,msgE,1,escape,tries);
            switch(opcion)
            {
                case 1:
                {
                    if(getStringLetras(bufferTitulo,"\nIngrese titulo: ",msgE,tries) == 0)
                       {
                           strncpy(pLibros[posID].titulo,bufferTitulo,sizeof(bufferTitulo));
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
    static int idLib = 0;
    return idLib++;
}
