#ifndef AUTOR_H_INCLUDED
#define AUTOR_H_INCLUDED

typedef struct
{
    int idAutor; /// se va autoincrementando
    char name[31];
    char surname[31];
    int isEmpty; /// lleno=0 ; vacio=1
}Autor;

int autor_menu(Autor* pAutores,int len,char* textMenu,char* msgE,int escape,int tries);

int autor_initArray(Autor* pAutores, int len);

int autor_addAutor(Autor* pAutores,int len, char* msgE,int tries);

int autor_removeAutor(Autor* pAutores, int len,char* msgE,int tries);

int autor_printAutor(Autor* pAutores,int len);

int autor_sortAutorSurnameName(Autor* pAutores,int len,int order);

int autor_printTotalPromAboveSalary(Autor* pAutores, int len);

int autor_modifyAutor(Autor* pAutores,int len,char* msgE,int escape,int tries);


int autor_searchFreeSpace(Autor* pAutores, int len);

int autor_findPosID(Autor* pAutores, int len,int idAut);

int autor_getID(Autor* pAutores, int len, char* msgE, int tries);

int autor_aboveSalary(Autor* pAutores, int len, float prom);

#endif // AUTOR_H_INCLUDED
