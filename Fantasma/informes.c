#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "informes.h"

int emp_printTotalPrestamosPromedioDiario(Prestamo* pPrestamos, int len)
{
    int i;
    float prom;
    int contadorTotal = 0;
    int contadorDiaDiferente = 0;

    if(pPrestamos != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pPrestamos[i].isEmpty == 0)
            {
                contadorTotal++;
                prestamo_sortPrestamoDia(pPrestamos,len,1);
                if(pPrestamos[i].dia != pPrestamos[i-1].dia)
                {
                    contadorDiaDiferente++;
                }

            }
        }
        prom = contadorTotal/contadorDiaDiferente;

        printf("\nEl total de prestamos es: %d\n",contadorTotal);
        printf("El promedio diario es: %.2f\n",prom);
    }
    return 0;
}

int informe_printLibroPorSocioDeterminado(Prestamo* pPrestamos,int lenPres,Socio* pSocios,int lenSoc,Libro* pLibros,int lenLib,char* msgE)
{
    int i;
    int auxiliarIDLibro;
    int posLibro;
    int posSocio;
    int ret = -1;

    auxiliarIDLibro = libro_getID(pLibros,lenLib,msgE,2);
    posLibro = libro_findPosID(pLibros,lenLib,auxiliarIDLibro);
    if((auxiliarIDLibro >= 0) && (posLibro != -1))
    {
        for(i=0;i<lenPres;i++)
        {
            if((pPrestamos[i].isEmpty == 0) && (pPrestamos[i].idLibro == auxiliarIDLibro))
            {
                posLibro = libro_findPosID(pLibros,lenLib,pPrestamos[i].idLibro);
                posSocio = socio_findPosID(pSocios,lenSoc,pPrestamos[i].idSocio);
                if((posLibro >= 0) && (posSocio >= 0))
                {
                    printf("\nNombre y apellido de socio: %s %s\n"
                           "Titulo de libro: %s\nID Socio: %d\nID Prestamo: %d\n"
                           "ID Libro: %d\n-------\n",
                           pSocios[posSocio].name,
                           pSocios[posSocio].surname,
                           pLibros[posLibro].titulo,
                           pPrestamos[i].idSocio,
                           pPrestamos[i].idPrestamo,
                           pLibros[posLibro].idLibro);
                            ret=0;
                }
            }
        }
    }
    return ret;
}
