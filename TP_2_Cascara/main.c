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
 * Obtiene el primer indice libre del array.
 * param lista: el array se pasa como parametro.
 */
int ObtenerEspacioLibre(EPersona [], int);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * param lista: el array se pasa como parametro. dni: el dni a ser buscado en el array.
 */
int BuscarPorDni(EPersona [], int , int);

void inicializarPersonas(EPersona [], int);

void agregarPersona(EPersona [], int);

void borrarPersona(EPersona [], int);

void listar(EPersona [], int);

void grafico(EPersona [], int);

void mostrarPersona(EPersona);

void mostrarPersonas(EPersona [], int);


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
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPersona(gente, tam);
                break;
            case 2:
                system("cls");
                borrarPersona(gente, tam);
                break;
            case 3:
                system("cls");
                listar(gente, tam);
                break;
            case 4:
                system("cls");
                grafico(gente, tam);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

void inicializarPersonas(EPersona lista[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        lista[i].estado = 0;
    }

}

int ObtenerEspacioLibre(EPersona lista[], int tam)
{
    int indice = -1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int BuscarPorDni(EPersona lista[], int tam, int dni)
{
    int i;
    int indice = -1;

    for(i=0;i<tam;i++)
    {
        if(lista[i].dni == dni && lista[i].estado == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void agregarPersona(EPersona lista[], int tam)
{
    EPersona aux;
    int indice;
    int dni;
    int esta;

    indice = ObtenerEspacioLibre(lista, tam);

    if(indice == -1)
    {
        printf("No se pueden ingresar mas personas\n");
    }
    else
    {
        printf("Ingrese el dni\n");
        scanf("%d", &dni);

        while(dni < 1)
        {
            printf("Reingrese el dni\n");
            scanf("%d", &dni);
        }

        esta = BuscarPorDni(lista, tam, dni);

        if(esta != -1)
        {
            printf("La persona ya existe\n");
            mostrarPersona(lista[esta]);
        }
        else
        {
            aux.dni = dni;

            aux.estado = 1;

            printf("Ingrese el nombre\n");
            fflush(stdin);
            gets(aux.nombre);

            printf("Ingrese la edad\n");
            scanf("%d", &aux.edad);

            while(aux.edad < 1 || aux.edad > 100)
            {
                printf("Reingrese la edad\n");
                scanf("%d", &aux.edad);
            }

            lista[indice] = aux;


            printf("----------SE AGREGO UNA PERSONA EXITOSAMENTE--------\n");
        }

    }

}

void borrarPersona(EPersona lista[], int tam)
{
    int dni;
    int esta;
    char respuesta;

    printf("Ingrese el dni\n");
    scanf("%d", &dni);

    esta = BuscarPorDni(lista, tam, dni);

    if(esta != -1)
    {
        mostrarPersona(lista[esta]);

        printf("Seguro que desea eliminar a esta persona s/n\n");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta == 's')
        {
            lista[esta].estado = 0;
            printf("----------SE ELIMINO EXITOSAMENTE---------\n");
        }
        else
        {
            printf("Se cancelo la operacion\n");
        }
    }
    else
    {
        printf("La persona no existe\n");
    }

}

void listar(EPersona lista[], int tam)
{
    EPersona aux;
    int i;
    int j;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(lista[i].estado == 1 && lista[j].estado == 1)
            {
                if(strcmp(lista[i].nombre, lista[j].nombre) == 1)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }
    }

    mostrarPersonas(lista, tam);
}

void grafico(EPersona lista[], int tam)
{
    int edades[] = {0, 0, 0};
    int i;

    for(i=0;i<tam;i++)
    {
        if(lista[i].edad < 18)
        {
            edades[0] ++;
        }
        else
        {
            if(lista[i].edad > 18 && lista[i].edad < 35)
            {
                edades[1] ++;
            }
            else
            {
                if(lista[i].edad > 35)
                {
                    edades[2] ++;
                }
            }
        }
    }

    printf("\n<18:");
    for(i=0;i<edades[0];i++)
    {
        printf("*");
    }

    printf("\n19-35:");
    for(i=0;i<edades[1];i++)
    {
        printf("*");
    }

    printf("\n>35:");
    for(i=0;i<edades[2];i++)
    {
        printf("*");
    }
    printf("\n");
}

void mostrarPersona(EPersona lista)
{
    printf("Nombre: %s\n", lista.nombre);
    printf("Edad: %d\n", lista.edad);
    printf("DNI: %d\n\n", lista.dni);

}

void mostrarPersonas(EPersona lista[], int tam)
{
    int i;
    int flag = 0;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado == 1)
        {
            mostrarPersona(lista[i]);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay personas\n");
    }


}






