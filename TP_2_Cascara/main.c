#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int main()
{
    char seguir = 's';
    int opcion = 0;
    int tam = 20;
    EPersona gente[tam];

    inicializarPersonas(gente, tam);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Guardar las personas en archivo\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPersona(&gente, tam);
                break;
            case 2:
                system("cls");
                borrarPersona(&gente, tam);
                break;
            case 3:
                system("cls");
                listar(&gente, tam);
                break;
            case 4:
                system("cls");
                grafico(&gente, tam);
                break;
            case 5:
                system("cls");
                archivoPersonas(&gente, tam);
                break;
            case 6:
                seguir = 'n';
                break;
            default:
                printf("El numero ingresado es incorrecto");
        }
    }

    return 0;
}
