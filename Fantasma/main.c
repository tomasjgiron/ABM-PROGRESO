#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "arraynuevo.h"
#include "autor.h"
#include "libro.h"
#include "socio.h"

#define TRIES 3
#define LEN_LIBRO 3
#define LEN_AUTOR 3

int main()
{
    Autor autores[LEN_AUTOR];
    Libro libros[LEN_LIBRO];

    int opcion = 0;
    int escape = 5;
    int flagAutor = -1;
    int flagLibro = -1;
    int flagSocio = -1;

    while(opcion != escape)
    {
        printf("\n1.Autores\n2.Libros\n3.Socios\n4.Prestamos\n5.Salir\n");
        getIntInRange(&opcion,"\nIngrese opcion: ",
                      "Informacion invalida",1,escape,TRIES);
        switch(opcion)
        {
        case 1:
            {
                if(autor_menu(autores,LEN_AUTOR,
                    "\n1.Alta\n2.Modificar\n3.Baja logica\n4.Listar\n5.Salir\n","Informacion invalida",escape,TRIES)== 0)
                {
                    flagAutor = 1;
                }
                else
                {
                    printf("\n\t~~~~No se realizo el alta~~~~\t\n");
                }
                break;
            }
        case 2:
            {
                if(flagAutor == 1)
                {
                    if(libro_menu(libros,LEN_LIBRO,
                                  autores,LEN_AUTOR,
                                  "\n1.Alta\n2.Modificar\n3.Baja logica\n4.Listar\n5.Salir\n",
                                  "Informacion invalida",escape,TRIES)== 0)
                    {
                        ///usar el flag de libro y seguir con los demas case
                        ///al momento de hacer socio se debera cambiar su respectiva flag a 1, al igual que las anteriores
                    }
                }
            }

        }
    }

    return 0;
}
