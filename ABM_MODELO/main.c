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
    int opcion = 0;
    int posLibre;
    int idPan = 1;

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
                    if(pan_create(pantallas,CANT_PAN,posLibre,idPan,"Informacion invalida",TRIES))
                    {
                        idPan++;
                        pan_showArray(pantallas,CANT_PAN);
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
                pan_showArray(pantallas,CANT_PAN);
                break;
            }
            case 3:
            {
                if(pan_modifyByID(pantallas,CANT_PAN,"Informacion invalida",TRIES))
                {
                    printf("\n\t~~~~Se pudo modificar el listado~~~~\t\n");
                }
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



