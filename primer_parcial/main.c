#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"

#define TRIES 3
#define LEN_ORQ 5
#define LEN_INS 5
#define LEN_MUS 5

int main()
{
    Orquesta orquestas[LEN_ORQ];
    Musico musicos[LEN_MUS];
    Instrumento instrumentos[LEN_INS];
    int flagOrquesta = 0;
    int flagMusico = 0;
    int flagInstrumento = 0;
    int contadorOrquesta = 0;
    int contadorMusico = 0;
    int opcion = 0;
    int escape = 10;
    int auxiliarIdBorrado;
    int auxiliarIdAltaOrquesta;
    int auxiliarIdAltaInstrumento;


        orquesta_initArray(orquestas,LEN_ORQ);
        musico_initArray(musicos,LEN_MUS);
        instrumento_initArray(instrumentos,LEN_INS);
        while(opcion!=escape)
        {
            printf("\n1.ALTA ORQUESTA\n2.BAJA ORQUESTA\n3.IMPRIMIR ORQUESTAS\n~~~"
                    "\n4.ALTA MUSICO\n5.MODIFICAR MUSICO\n6.BAJA MUSICO\n7.IMPRIMIR MUSICOS\n~~~"
                    "\n8.ALTA INSTRUMENTO\n9.IMPRIMIR INSTRUMENTOS\n10.SALIR\n");

            getIntInRange(&opcion,"\nIngrese opcion: ",
                          "Informacion invalida\n",1,escape,TRIES);

            switch(opcion)
            {
                case 1:
                {
                    if(orquesta_addOrquesta(orquestas,LEN_ORQ,&auxiliarIdAltaOrquesta,"Informacion invalida",TRIES) == 0)
                       {
                           flagOrquesta = 1;
                           contadorOrquesta++;
                           orquesta_printValorRepetidoInt(orquestas,LEN_ORQ,auxiliarIdAltaOrquesta);
                       }
                    break;
                }
                case 2:
                {
                    if(flagOrquesta)
                    {
                        orquesta_printOrquesta(orquestas,LEN_ORQ);
                        if(orquesta_removeOrquesta(orquestas,LEN_ORQ,&auxiliarIdBorrado,"Informacion invalida",TRIES) == 0)
                        {
                            contadorOrquesta--;
                            musico_bajaValorRepetidoInt(musicos,LEN_MUS,auxiliarIdBorrado);
                            if(contadorOrquesta == 0)
                            {
                                flagOrquesta = 0;
                            }
                        }
                    }
                    else
                    {
                        printf("\n\tNo hay orquestas para mostrar\t\n");
                    }
                    break;
                }
                case 3:
                {
                    if(flagOrquesta)
                    {
                        orquesta_printOrquesta(orquestas,LEN_ORQ);
                    }
                    else
                    {
                        printf("\n\tNo hay orquestas para mostrar\t\n");
                    }
                    break;
                }
                case 4:
                {
                    if(flagOrquesta && flagInstrumento)
                    {
                        musico_addMusico(musicos,LEN_MUS,
                         orquestas,LEN_ORQ,
                         instrumentos,LEN_INS,
                         "Informacion invalida",TRIES);
                         flagMusico = 1;
                         contadorMusico++;
                    }
                    else
                    {
                        printf("\n\tNo hay orquestas y/o instrumentos para mostrar\t\n");
                    }
                    break;
                }
                case 5:
                {
                    if(flagMusico)
                    {
                        musico_printMusico(musicos,instrumentos,LEN_MUS,LEN_INS);
                        musico_modifyMusico(musicos,LEN_MUS,orquestas,LEN_ORQ,"Informacion invalida",3,TRIES);

                    }
                    else
                    {
                        printf("\n\tNo hay musicos para mostrar\t\n");
                    }
                    break;
                }
                case 6:
                {
                    if(flagMusico)
                    {
                        musico_printMusico(musicos,instrumentos,LEN_MUS,LEN_INS);
                        if(musico_removeMusico(musicos,LEN_MUS,"Informacion invalida",TRIES))
                        {
                            contadorMusico--;
                            if(contadorMusico == 0)
                            {
                                flagMusico = 0;
                            }
                        }
                    }
                    else
                    {
                        printf("\n\tNo hay musicos para mostrar\t\n");
                    }
                    break;
                }
                case 7:
                {
                    if(flagMusico)
                    {
                        musico_printMusico(musicos,instrumentos,LEN_MUS,LEN_INS);
                    }
                    else
                    {
                        printf("\n\tNo hay musicos para mostrar\t\n");
                    }
                    break;
                }
                case 8:
                {
                    if(flagOrquesta)
                    {
                        if(instrumento_addInstrumento(instrumentos,LEN_INS,&auxiliarIdAltaInstrumento,"Informacion invalida",TRIES) == 0)
                       {
                           flagInstrumento = 1;
                           instrumento_printValorRepetidoInt(instrumentos,LEN_INS,auxiliarIdAltaInstrumento);
                       }
                    }
                    else
                    {
                        printf("\n\tNo hay orquestas para mostrar\t\n");
                    }
                    break;
                }
                case 9:
                {
                    if(flagInstrumento)
                    {
                        instrumento_printInstrumento(instrumentos,LEN_INS);
                    }
                    else
                    {
                        printf("\n\tNo hay instrumentos para mostrar\t\n");
                    }
                    break;
                }
            }
            fflush(stdin);
        }
    return 0;
}
