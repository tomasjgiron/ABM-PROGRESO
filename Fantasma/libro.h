#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED
#include "autor.h"
typedef struct
{
    int idLibro; /// se va autoincrementando
    char titulo[51];
    int idAutor;
    int isEmpty; /// lleno=0 ; vacio=1
}Libro;

int libro_menu(Libro* pLibros,int lenLib,Autor* pAutores,int lenAut,char* textMenu,char* msgE,int escape,int tries);

int libro_initArray(Libro* pLibros, int len);

int libro_addLibro(Libro* pLibros,int lenLib,Autor* pAutores,int lenAut, char* msgE,int tries);

int libro_removeLibro(Libro* pLibros, int len,char* msgE,int tries);

int libro_printLibro(Libro* pLibros,Autor* pAutores,int lenAut,int lenLib);

int libro_sortLibroTitulo(Libro* pLibros,int len);

int libro_printTotalPromAboveSalary(Libro* pLibros, int len);

int libro_modifyLibro(Libro* pLibros,int len,char* msgE,int escape,int tries);


int libro_searchFreeSpace(Libro* pLibros, int len);

int libro_findPosID(Libro* pLibros, int len,int idLib);

int libro_getID(Libro* pLibros, int len, char* msgE, int tries);

int libro_aboveSalary(Libro* pLibros, int len, float prom);

#endif // LIBRO_H_INCLUDED
