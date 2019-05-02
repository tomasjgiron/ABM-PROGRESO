#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "Pantallas.h"
#include "Publicidades.h"
#define  CANT_PAN 6
#define  CANT_PUB 6
#define TRIES 3

int main()
{
    Pantalla pantallas[CANT_PAN];
    Publicidad publicidades[CANT_PUB];
    int opcion = 0;
    int posLibre;
    int flag = 0;

    pan_initializeArray(pantallas,CANT_PAN);
    while(opcion!=11)
    {
        getIntInRange(&opcion,
                      "\n1)Alta de pantalla\n2)Listar\n3)Modificar pantalla\n4)Baja de pantalla\n5)Alta publicidad\n"
                      "6)Modificar publicidad\n7)Baja publicidad\n8)\n9)Mostrar publicidades\n"
                      "10)Mostrar pantallas\n11a)Informar una cosa\n11b)Informar otra cosa\n12)Salir\n\n~~~~~~~~~~~~~~~~~~~~~~\n",
                      "NO!",
                      1,10,2);

        switch(opcion)
        {
            case 1:
            {
                posLibre = pan_searchFreeSpace(pantallas,CANT_PAN);
                if(posLibre>=0)
                {
                    printf("\n\t~~~~Se encontró lugar~~~~\t\n");
                    if(pan_create(pantallas,CANT_PAN,posLibre,"Informacion invalida",TRIES) == 0)
                    {
                        pan_showArray(pantallas,CANT_PAN);
                        flag = 1;
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
                   pan_showArray(pantallas,CANT_PAN);
                }
                printf("\n~~~~No hay nada para mostrar~~~~\n");
                break;
            }
            case 3:
            {
                if(flag == 1)
                {
                    if(pan_modifyByID(pantallas,CANT_PAN,"Informacion invalida",TRIES))
                    {
                        printf("\n\t~~~~Se pudo modificar el listado~~~~\t\n");
                    }
                }
                printf("\n~~~~No hay registros para modificar~~~~\n");
                break;
            }
            case 4:
                {
                    if(pan_bajaLogica(pantallas,CANT_PAN,"Informacion invalida",TRIES))
                    {
                        printf("\n\t~~~~Se pudo dar de baja~~~~");
                    }
                    break;
                }
            case 5:
                {
                    break;
                }
            case 6:
                {
                    break;
                }
            case 7:
                {
                    break;
                }
            case 8:
                {
                    break;
                }
            case 9:
                {
                    break;
                }
            case 10:
                {
                    break;
                }
        }
    }

    return 0;
}



