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
}EMovie;

int agregarPelicula(EMovie movie, int contadorPeliculas)
{
    int retorno = 0;
    FILE* archivo;
    int i;
    int flag = 0;
    EMovie pelicula[50];
    char nombreArchivo[20];

    strcpy(nombreArchivo, "Movies.txt");

    parseDatos(nombreArchivo, &pelicula, contadorPeliculas);

    printf("Ingrese el titulo de la pelicula\n");
    fflush(stdin);
    gets(movie.titulo);

    for(i=0;i<contadorPeliculas;i++)
    {
        printf("%s", pelicula[i].titulo);
        if(strcmp(movie.titulo, pelicula[i].titulo) == 0)
        {
            printf("La pelicula ya fue cargada\n");
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("Ingrese el link de la imagen\n");
        fflush(stdin);
        gets(movie.linkImagen);

        printf("Ingrese el genero de la pelicula\n");
        fflush(stdin);
        gets(movie.genero);

        printf("Ingrese el puntaje de la pelicula\n");
        scanf("%d", &movie.puntaje);

        printf("ingrese la duracion de la pelicula\n");
        scanf("%d", &movie.duracion);

        printf("Ingrese la descripcion de la pelicula\n");
        fflush(stdin);
        gets(movie.descripcion);


        archivo = fopen("Movies.txt", "ab");

        if(archivo != NULL)
        {
            fprintf(archivo, "%s,", movie.linkImagen);
            fprintf(archivo, "%s,", movie.titulo);
            fprintf(archivo, "%s,", movie.genero);
            fprintf(archivo, "%d,", movie.puntaje);
            fprintf(archivo, "%d,", movie.duracion);
            fprintf(archivo, "%s,", movie.descripcion);

            fclose(archivo);

            retorno = 1;
        }
        else
        {
            printf("Imposible abrir el archivo\n");
        }
    }

    return retorno;

}

int borrarPelicula(EMovie movie, int contadorPeliculas)
{
    int retorno = 0;
    FILE* archivo;
    EMovie* pelicula;

    archivo = fopen("movie.txt","rb");
    pelicula = (EMovie*) malloc(sizeof(EMovie) * 50);

    if(archivo != NULL)
    {
        fread(pelicula, sizeof(EMovie), contadorPeliculas, archivo);
        fclose(archivo);
    }


    return retorno;
}

int parseDatos(char* nombreArchivo, EMovie* peliculas, int tam)
{
    FILE* archivo;
    int r;
    int i = 0;
    char var1[100];
    char var2[50];
    char var3[50];
    char var4[50];
    char var5[50];
    char var6[100];

    archivo = fopen(nombreArchivo,"rb");

    if(archivo == NULL)
    {
        return -1;
    }

    do
    {
         r = fscanf(archivo,"%[^,] %[^,] %[^,] %[^,] %[^,]%[^,]\n",var1,var2,var3,var4, var5, var6);
         if(r==4)
        {
            strcpy(peliculas[i].linkImagen, var1);
            strcpy(peliculas[i].titulo, var2);
            strcpy(peliculas[i].genero, var3);
            peliculas[i].puntaje = atoi(var4);
            peliculas[i].duracion = atoi(var5);
            strcpy(peliculas[i].descripcion, var6);
            i ++;
        }
        else
        {
            break;
        }

    }while(!feof(archivo) && i<tam);

    fclose(archivo);

    return i;
}

