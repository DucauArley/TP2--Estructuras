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


void inicializarPeliculas(EMovie* peliculas, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        (peliculas + i)->duracion = 0;
    }

}

int ObtenerEspacioLibre(EMovie* peliculas, int tam)
{
    int indice = -1;
    int i;

    for(i=0;i<tam;i++)
    {
        if((peliculas + i)->duracion == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int BuscarPorId(EMovie* peliculas, int tam, int id)
{
    int i;
    int indice = -1;

    for(i=0;i<tam;i++)
    {
        if((peliculas + i)->id == id && (peliculas + i)->duracion != 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void agregarPelicula(EMovie* peliculas, int tam)
{
    EMovie aux;
    int indice;
    int id;
    int flag = 0;
    int i;

    indice = ObtenerEspacioLibre(peliculas, tam);

    if(indice == -1)
    {
        printf("No se pueden ingresar mas peliculas\n");
    }
    else
    {
        id = indice + 1;

        aux.id = id;

        printf("Ingrese el titulo de la pelicula\n");
        fflush(stdin);
        gets(aux.titulo);


        for(i=0;i<tam;i++)
        {
            if(strcmp(aux.titulo, peliculas[i].titulo) == 0 && peliculas[i].duracion != 0)
            {
                printf("Esa pelicula ya existe\n");
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            printf("Ingrese el link de la imagen\n");
            fflush(stdin);
            gets(aux.linkImagen);

            printf("Ingrese el genero de la pelicula\n");
            fflush(stdin);
            gets(aux.genero);

            printf("Ingrese el puntaje de la pelicula\n");
            scanf("%d", &aux.puntaje);

            printf("ingrese la duracion de la pelicula\n");
            scanf("%d", &aux.duracion);

            printf("Ingrese la descripcion de la pelicula\n");
            fflush(stdin);
            gets(aux.descripcion);


            *(peliculas + indice) = aux;


            printf("----------SE AGREGO UNA PELICULA EXITOSAMENTE--------\n");
        }
    }

}

void borrarPelicula(EMovie* peliculas, int tam)
{
    int id;
    int esta;
    char respuesta;

    printf("Ingrese la id de la pelicula que desea eliminar\n");
    scanf("%d", &id);

    esta = BuscarPorId(peliculas, tam, id);

    if(esta != -1)
    {
        mostrarPelicula(peliculas + esta);

        printf("Seguro que desea eliminar esta pelicula/n\n");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta == 's')
        {
            (peliculas + esta)->duracion = 0;
            printf("----------SE ELIMINO EXITOSAMENTE---------\n");
        }
        else
        {
            printf("Se cancelo la operacion\n");
        }
    }
    else
    {
        printf("La pelicula no existe\n");
    }

}

void mostrarPelicula(EMovie* pelicula)
{
    printf("Titulo: %s\n", pelicula->titulo);
    printf("Genero: %s\n", pelicula->genero);
    printf("Puntaje: %d\n", pelicula->puntaje);
    printf("Duracion: %d\n", pelicula->duracion);
    printf("Descripcion: %s\n\n", pelicula->descripcion);
}

void mostrarPeliculas(EMovie* peliculas, int tam)
{
    int i;
    int flag = 0;

    for(i=0;i<tam;i++)
    {
        if((peliculas + i)->duracion != 0)
        {
            mostrarPelicula(peliculas + i);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay peliculas\n");
    }

}








