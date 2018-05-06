#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * \brief Obtiene el primer indice libre del array.
 * \param lista: el array se pasa como parametro.
 * \return Devuelve el indice libre.
 */
int ObtenerEspacioLibre(EPersona [], int);
/**
 * \brief Obtiene el indice que coincide con el dni pasado por parametro.
 * \param lista: el array se pasa como parametro.
 * \param dni: el dni a ser buscado en el array.
 * \return Devuelve el indice donde se encuentra el dni.
 */
int BuscarPorDni(EPersona [], int , int);

/**
 * \brief Cambia el estado de las personas a 0 (vacio).
 * \param lista: el array se pasa como parametro.
 * \param tam: el tamaño del array.
 */
void inicializarPersonas(EPersona [], int);

/**
 * \brief Agrega una estructura al array de estructuras.
 * \param lista: el array se pasa como parametro.
 * \param tam: el tamaño del array.
 */
void agregarPersona(EPersona [], int);

/**
 * \brief Borra una estructura al array de estructuras.
 * \param lista: el array se pasa como parametro.
 * \param tam: el tamaño del array.
 */
void borrarPersona(EPersona [], int);

/**
 * \brief Muestra todas las estructuras en orden alfabetico.
 * \param lista: el array se pasa como parametro.
 * \param tam: el tamaño del array.
 */
void listar(EPersona [], int);

/**
 * \brief Muestra un grafico de las edades menores a 18, entre 19 y 35 y mayores a 35.
 * \param lista: el array se pasa como parametro.
 * \param tam: el tamaño del array.
 */

void grafico(EPersona [], int);

/**
 * \brief Imprime una variable del array.
 * \param lista: una variable del array se pasa como parametro.
 */
void mostrarPersona(EPersona);

/**
 * \brief Imprime varias variables del array
 * \param lista: el array se pasa como parametro
 * \param tam: el tamaño del array
 */
void mostrarPersonas(EPersona [], int);

/**
 * \brief Verifica si el valor recibido es numerico.
 * \param texto: Array con la cadena a ser analizada.
 * \return 1 si es numerico y 0 si no lo es.
 */
int numerico(char []);

/**
 * \brief Verifica si el valor recibido contiene solo letras.
 * \param texto: Array con la cadena a ser analizada.
 * \return 1 si tiene solo letras y 0 si no las tiene.
 */
int alfabetico(char []);
