#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "empleado.h"

int Employee_initializeArray(Employee* pEmployee, int len)
{
    int i;
    for(i=0; i<len;i++)
    {
        pEmployee[i].isEmpty = 1;
    }
    return 0;
}

int Employee_showArray(Employee* pEmployee,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        //if(pEmployee[i].isEmpty == 0)
        //{
            printf("Empleado %d:%s %s\n",i,pEmployee[i].name,pEmployee[i].surname);
        //}
    }
    return 0;
}

int Employee_create(Employee* pEmployee,int len, int pIndex, char* msgE)
{
    char bufferN[20];
    char bufferS[20];

    if((getStringLetras(bufferN,"Ingrese nombre: ",msgE,2) == 0) && (getStringLetras(bufferS,"Ingrese apellido: ",msgE,2) == 0))
    {
        strncpy(pEmployee[pIndex].name,bufferN,20);
        //*pEmployee[pIndex].name=bufferN;
        strncpy(pEmployee[pIndex].surname,bufferS,20);
        //*pEmployee[pIndex].surname=bufferS;
        pEmployee[pIndex].isEmpty=0;
    }
    else
    {
        printf(msgE);
    }
    return 0;
}

int Employee_searchFreeSpace(Employee* pEmployee, int len, int* pIndex)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pEmployee[i].isEmpty==1)
        {
            *pIndex = i;
            ret = 0;
            break;
        }
    }
    return ret;
}
