#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

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

            while(alfabetico(aux.nombre) == 0)
            {
                printf("Reingrese el nombre\n");
                fflush(stdin);
                gets(aux.nombre);
            }

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
    int j;
    int mayor = 0;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].edad <= 18)
            {
                edades[0] ++;
            }
            else
            {
                if(lista[i].edad > 18 && lista[i].edad <= 35)
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
    }

    for(i=0;i<3;i++)
    {
        if(mayor < edades[i])
        {
            mayor = edades[i];
        }

    }

    for(i=mayor;i>0;i--)
    {
        for(j=0;j<3;j++)
        {
            if(i <= edades[j])
            {
                printf(" *   ");
            }
            else
            {
                printf("     ");
            }
        }
        printf("\n");

    }


    printf("<18 19-35 >35\n");
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

int numerico(char texto[])
{
    int i = 0;

    while(texto[i] != '\0')
    {
        if(texto[i] < 0 || texto[i] > 9)
        {
            return 0;
        }

        i ++;
    }

    return 1;
}

int alfabetico(char texto[])
{
    int i = 0;

    while(texto[i] != '\0')
    {
        if((texto[i] != ' ') && (texto[i] < 'a' || texto[i] > 'z') && (texto[i] < 'A' || texto[i] > 'Z'))
        {
            return 0;
        }

        i++;
    }

    return 1;
}
