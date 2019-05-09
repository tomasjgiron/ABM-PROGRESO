#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#define TEXT_SIZE 31

typedef struct
{
    int idSocio;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char sexo;
    char apellido[TEXT_SIZE];
    char telephone[TEXT_SIZE];
    char mail[TEXT_SIZE];
    char fechaAsociado[TEXT_SIZE];

}Socio;


#endif // SOCIO_H_INCLUDED

int socio_Inicializar(Socio array[], int size);                                    //cambiar socio
int socio_buscarEmpty(Socio array[], int size, int* posicion);                    //cambiar socio
int socio_buscarID(Socio array[], int size, int valorBuscado, int* posicion);                    //cambiar socio
int socio_buscarInt(Socio array[], int size, int valorBuscado, int* posicion);                    //cambiar socio
int socio_buscarString(Socio array[], int size, char* valorBuscado, int* indice);                    //cambiar socio
int socio_alta(Socio array[], int size, int* contadorID);                          //cambiar socio
int socio_baja(Socio array[], int sizeArray);                                      //cambiar socio
int socio_bajaValorRepetidoInt(Socio array[], int sizeArray, int valorBuscado);
int socio_modificar(Socio array[], int sizeArray);                                //cambiar socio
int socio_ordenarPorString(Socio array[],int size);                              //cambiar socio
int socio_listar(Socio array[], int size);                      //cambiar socio


