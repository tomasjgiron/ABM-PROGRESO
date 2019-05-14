#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED

#include "socio.h"
#include "libro.h"

typedef struct
{
    int idPrestamo; /// se va autoincrementando
    int idLibro;
    int idSocio;
    int dia;
    int mes;
    int anio;
    int isEmpty; /// lleno=0 ; vacio=1
}Prestamo;

int prestamo_menu(Prestamo* pPrestamos,int lenPres,
                         Socio* pSocios,int lenSoc,
                         Libro* pLibros,int lenLib,char* textMenu,char* msgE,
                         int escape,int tries);

int prestamo_initArray(Prestamo* pPrestamos, int len);

int prestamo_addPrestamo(Prestamo* pPrestamos,int lenPres,
                         Socio* pSocios,int lenSoc,
                         Libro* pLibros,int lenLib,
                         char* msgE,int tries);

int prestamo_removePrestamo(Prestamo* pPrestamos, int len,char* msgE,int tries);

int prestamo_printPrestamo(Prestamo* pPrestamos,int len);

int prestamo_sortPrestamoSurnameSector(Prestamo* pPrestamos,int len);

int prestamo_printTotalPromAboveSalary(Prestamo* pPrestamos, int len);

int prestamo_modifyPrestamo(Prestamo* pPrestamos,int len,char* msgE,int escape,int tries);


int prestamo_searchFreeSpace(Prestamo* pPrestamos, int len);

int prestamo_findPosID(Prestamo* pPrestamos, int len,int idPres);

int prestamo_getID(Prestamo* pPrestamos, int len, char* msgE, int tries);

int prestamo_aboveSalary(Prestamo* pPrestamos, int len, float prom);

#endif // PRESTAMO_H_INCLUDED
