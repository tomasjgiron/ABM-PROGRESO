#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "arraynuevo.h"
#include "autor.h"
#include "libro.h"
#include "socio.h"
#include "prestamo.h"

#define TRIES 3
#define LEN_LIBRO 3
#define LEN_AUTOR 3
#define LEN_SOCIO 3
#define LEN_PRES 3

int main()
{
    Autor autores[LEN_AUTOR];
    Libro libros[LEN_LIBRO];
    Socio socios[LEN_SOCIO];
    Prestamo prestamos[LEN_PRES];
    int flagAutor = 0;
    int flagLibro = 0;
    int flagSocio = 0;
    int contadorAutor = 0;
    int contadorLibro = 0;
    int contadorSocio = 0;
    int opcion = 0;
    int escape = 22;

        autor_initArray(autores,LEN_AUTOR);
        libro_initArray(libros,LEN_LIBRO);
        socio_initArray(socios,LEN_SOCIO);
        prestamo_initArray(prestamos,LEN_PRES);
        while(opcion!=escape)
        {
            printf("\n1.ALTA AUTOR\n2.MODIFICAR AUTOR\n3.BAJA AUTOR\n"
                    "4.LISTAR AUTOR\n~~~\n5.ALTA LIBRO\n6.MODIFICAR LIBRO\n7.BAJA LIBRO\n"
                    "8.LISTAR LIBRO\n~~~\n9.ALTA SOCIO\n10.MODIFICAR SOCIO\n11.BAJA SOCIO"
                    "\n12.LISTAR SOCIO\n~~~\n13.ALTA PRESTAMOS\n~~~\n22.SALIR\n");

            getIntInRange(&opcion,"\nIngrese opcion: ",
                          "Informacion invalida\n",1,escape,TRIES);

            switch(opcion)
            {
                case 1:
                {
                    if(autor_addAutor(autores,LEN_AUTOR,"Informacion invalida",TRIES) == 0)
                       {
                           flagAutor = 1;
                           contadorAutor++;
                       }
                    break;
                }
                case 2:
                {
                    if(flagAutor)
                    {
                        autor_printAutor(autores,LEN_AUTOR);
                        autor_modifyAutor(autores,LEN_AUTOR,"Informacion invalida",3,TRIES);
                    }
                    else
                    {
                        printf("\n\tNo hay autores para mostrar\t\n");
                    }
                    break;
                }
                case 3:
                {
                    if(flagAutor)
                    {
                        if(autor_removeAutor(autores,LEN_AUTOR,"Informacion invalida",TRIES) == 0)
                        {
                            contadorAutor--;
                            if(contadorAutor == 0)
                            {
                                flagAutor = 0;
                            }
                        }
                    }
                    else
                    {
                        printf("\n\tNo hay autores para mostrar\t\n");
                    }
                    break;
                }
                case 4:
                {
                    if(flagAutor)
                    {
                        autor_sortAutorSurnameName(autores,LEN_AUTOR,1);
                        autor_printAutor(autores,LEN_AUTOR);
                    }
                    else
                    {
                        printf("\n\tNo hay autores para mostrar\t\n");
                    }
                    break;
                }
                case 5:
                {
                    if(flagAutor)
                    {
                        autor_printAutor(autores,LEN_AUTOR);
                        if(libro_addLibro(libros,LEN_LIBRO,autores,LEN_AUTOR,"Informacion invalida",TRIES) == 0)
                        {
                            flagLibro = 1;
                            contadorLibro++;
                        }
                    }
                    else
                    {
                        printf("\n\tNo hay autores para mostrar\t\n");
                    }
                    break;
                }
                case 6:
                {
                    if(flagLibro)
                    {
                        libro_printLibro(libros,autores,LEN_AUTOR,LEN_LIBRO);
                        libro_modifyLibro(libros,LEN_LIBRO,"informacion invalida",2,TRIES);
                    }
                    else
                    {
                        printf("\n\tNo hay libros para mostrar\t\n");
                    }
                    break;
                }
                case 7:
                {
                    if(flagLibro)
                    {
                        if(libro_removeLibro(libros,LEN_LIBRO,"informacion invalida",TRIES) == 0)
                        {
                            contadorLibro--;
                            if(contadorLibro == 0)
                            {
                                flagLibro = 0;
                            }
                        }
                    }
                    else
                    {
                        printf("\n\tNo hay libros para mostrar\t\n");
                    }
                    break;
                }
                case 8:
                {
                    if(flagLibro)
                    {
                        libro_sortLibroTitulo(libros,LEN_LIBRO);
                        libro_printLibro(libros,autores,LEN_AUTOR,LEN_LIBRO);
                    }
                    else
                    {
                        printf("\n\tNo hay libros para mostrar\t\n");
                    }
                    break;
                }
                case 9:
                {
                    if(socio_addSocio(socios,LEN_SOCIO,"informacion invalida",TRIES) == 0)
                    {
                        flagSocio = 1;
                        contadorSocio++;
                    }
                    break;
                }
                case 10:
                {
                    if(flagSocio)
                    {
                        socio_printSocio(socios,LEN_SOCIO);
                        socio_modifySocio(socios,LEN_SOCIO,"informacion invalida",3,TRIES);
                    }
                    else
                    {
                        printf("\n\tNo hay socios para mostrar\t\n");
                    }
                    break;
                }
                case 11:
                {
                    if(flagSocio)
                    {
                        if(socio_removeSocio(socios,LEN_SOCIO,"informacion invalida",TRIES) == 0)
                        {
                            contadorSocio--;
                            if(contadorSocio == 0)
                            {
                                flagSocio = 0;
                            }
                        }
                    }
                    else
                    {
                        printf("\n\tNo hay socios para mostrar\t\n");
                    }
                    break;
                }
                case 12:
                {
                    if(flagSocio)
                    {
                        socio_sortSocioSurnameName(socios,LEN_SOCIO,1);
                        socio_printSocio(socios,LEN_SOCIO);
                    }
                    else
                    {
                        printf("\n\tNo hay socios para mostrar\t\n");
                    }
                    break;
                }
                case 13:
                {
                    if(flagLibro && flagSocio)
                    {
                      prestamo_addPrestamo(prestamos,LEN_PRES,socios,LEN_SOCIO,libros,LEN_LIBRO,"informacion invalida",TRIES);
                    }
                    else
                    {
                        printf("\n\tNo hay libros y/o socios para mostrar\t\n");
                    }
                    break;
                }
            }
        }
    return 0;
}
