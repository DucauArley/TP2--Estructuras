#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    EMovie peliculas[50];
    int tam = 50;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPelicula(peliculas, tam);
                break;
            case 2:
                system("cls");
                borrarPelicula(peliculas, tam);
                break;
            case 3:
                system("cls");
                break;
            case 4:
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("El numero ingresado es incorrecto\n");
        }
    }
}

