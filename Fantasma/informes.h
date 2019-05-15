#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "arraynuevo.h"
#include "libro.h"
#include "autor.h"
#include "socio.h"
#include "prestamo.h"

int emp_printTotalPrestamosPromedioDiario(Prestamo* pPrestamos, int len);
int informe_printLibroPorSocioDeterminado(Prestamo* pPrestamos,int lenPres,Socio* pSocios,int lenSoc,Libro* pLibros,int lenLib,char* msgE);

#endif // INFORMES_H_INCLUDED
