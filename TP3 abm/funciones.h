#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[100];
    int puntaje;
    char linkImagen[100];
    int id;
}EMovie;


/**
 * \brief Obtiene el primer indice libre del array.
 * \param pelicula: el array se pasa como parametro.
 * \return Devuelve el indice libre.
 */
int ObtenerEspacioLibre(EMovie*, int);
/**
 * \brief Obtiene el indice que coincide con el id pasado por parametro.
 * \param pelicula: el array se pasa como parametro.
 * \param id: el id a ser buscado en el array.
 * \return Devuelve el indice donde se encuentra el id.
 */
int BuscarPorId(EMovie*, int , int);

/**
 * \brief Cambia la duracion de las personas a 0 (vacio).
 * \param pelicula: el array se pasa como parametro.
 * \param tam: el tamaño del array.
 */
void inicializarPeliculas(EMovie*, int);

/**
 * \brief Agrega una estructura al array de estructuras.
 * \param pelicula: el array se pasa como parametro.
 * \param tam: el tamaño del array.
 */
void agregarPelicula(EMovie*, int);

/**
 * \brief Borra una estructura al array de estructuras.
 * \param pelicula: el array se pasa como parametro.
 * \param tam: el tamaño del array.
 */
void borrarPelicula(EMovie*, int);

/**
 * \brief Imprime una variable del array.
 * \param pelicula: una variable del array se pasa como parametro.
 */
void mostrarPelicula(EMovie*);

/**
 * \brief Imprime varias variables del array
 * \param pelicula: el array se pasa como parametro
 * \param tam: el tamaño del array
 */
void mostrarPeliculas(EMovie*, int);

