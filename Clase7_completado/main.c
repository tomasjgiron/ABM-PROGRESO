#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "Pantallas.h"
#include "Publicidades.h"
#define  CANT_PAN 100
#define  CANT_PUB 1000

int main()
{
    Pantalla pantallas[CANT_PAN];
    Publicidad publicidades[CANT_PUB];
    int posLibre;
    int opcion=0;

    ///inicializar los arrays
    while(opcion!=10)
    {
        getIntInRange(&opcion,
                      "1)Alta de pantalla\n2)Modificar pantalla\n3)Baja de pantalla\n4)Alta publicidad\n5)Modificar publicidad\n6)Baja publicidad\n7)\n8)Mostrar publicidades\n9)Mostrar pantallas\n10a)Informar una cosa\n10b)Informar otra cosa\n11)Salir",
                      "NO!",
                      1,10,2);

        switch(opcion)
        {
            case 1:
            {
                if(pan_searchFreeSpace(pantallas ,CANT_PAN,&posLibre) == 0)
                {
                    printf("se encontro lugar en: %d\n",posLibre);
                    pan_create(pantallas ,CANT_PAN,posLibre,"Error");
                    pan_showArray(pantallas ,CANT_PAN);
                }
                break;
            }
            case 2:
            {
                pan_showArray(pantallas ,CANT_PAN);
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



