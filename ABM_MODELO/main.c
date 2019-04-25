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
    char num;
    fgets(num,20,stdin);
    if(isNumberFloat(num))
    {
        printf("es valido");
    }
    else
    {
        printf("es invalido");
    }

    return 0;
    Pantalla pantallas[CANT_PAN];
    int opcion = 0;
    int posLibre;
    int idPan = 1;

    pan_initializeArray(pantallas,CANT_PAN);
    while(opcion!=10)
    {
        getIntInRange(&opcion,
                      "1)Alta de pantalla\n2)Modificar pantalla\n3)Baja de pantalla\n4)Alta publicidad\n"
                      "5)Modificar publicidad\n6)Baja publicidad\n7)\n8)Mostrar publicidades\n"
                      "9)Mostrar pantallas\n10a)Informar una cosa\n10b)Informar otra cosa\n11)Salir\n\n~~~~~~~~~~~~~~~~~~~~~~\n",
                      "NO!",
                      1,10,2);

        switch(opcion)
        {
            case 1:
            {
                posLibre = pan_searchFreeSpace(pantallas,CANT_PAN);
                if(posLibre>=0)
                {
                    printf("\n\tSe encontró lugar\t\n");
                    if(pan_create(pantallas,CANT_PAN,posLibre,idPan,"Informacion invalida",TRIES))
                    {
                        idPan++;
                        pan_showArray(pantallas,CANT_PAN);
                    }
                }
                else
                {
                    printf("\n\tNo hay lugar libre\t\n");
                }
                break;
            }
            case 2:
            {
                break;
            }
            case 4:
            {

                break;
            }
        }
    }

    return 0;
}



