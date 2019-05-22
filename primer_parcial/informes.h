#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int informe_instrumentoMasUsadoPorMusico(Musico* pMusicos,int lenMus,Instrumento* pInstrumentos,int lenIns)

int informe_cantidadTotalPromedioEdadesDeMusico(Musico* pMusicos,int len);

int informe_contarCantidadMusicosPorOrquesta(Orquesta* pOrquestas,int lenOrquesta,Musico* pMusicos,int lenMusico);

int informe_ordenarPorCantidadMusicos(Orquesta* pOrquestas,int lenOrquesta,Musico* pMusicos,int lenMusico,int orden);

#endif // INFORMES_H_INCLUDED
