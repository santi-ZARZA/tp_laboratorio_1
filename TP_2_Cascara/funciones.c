#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"


int obtenerEspacioLibre(EPersona lista[])
{
    int i;
    int bandera=0;

    int retorno;

        for(i=0;i<MAXPERSONAS;i++)
        {
            if(lista[i].estado == 0)
            {
                retorno = i;
                bandera = 1;
                break;
            }
        }

        if(bandera == 0)
        {
            retorno = -1;
        }

    return retorno;
}

int buscarPorDni(EPersona lista[], int dni)
{
    int i;
    int bandera=0;

    int retorno;

        for(i=0;i<MAXPERSONAS;i++)
        {
            if(lista[i].dni == dni)
            {
                retorno = i;
                bandera = 1;
                break;
            }
        }

        if(bandera == 0)
        {
            retorno = -1;
        }

    return retorno;
}

void seteadorDeEstados(EPersona estados[])
{
    int i;

        for(i=0;i<MAXPERSONAS;i++)
        {
            estados[i].estado = 0;
        }
}

void cargarPersona(EPersona personas[])
{
    int ubicacion;

        system("cls");
        ubicacion = obtenerEspacioLibre(personas);

    if(ubicacion != -1)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(personas[ubicacion].nombre);
        printf("Ingrese la edad: ");
        scanf("%d",&personas[ubicacion].edad);

            while(personas[ubicacion].edad < 1 || personas[ubicacion].edad > 110)
            {
                 printf("la edad ingresada es invalida\nReingrese la edad: ");
                 scanf("%d",&personas[ubicacion].edad);
            }
        printf("Ingrese el DNI: ");
        scanf("%d",&personas[ubicacion].dni);

            while(personas[ubicacion].dni < 10000000 || personas[ubicacion].dni > 99000000)
            {
                 printf("el DNI ingresado es invalido\nReingrese el DNI: ");
                 scanf("%d",&personas[ubicacion].dni);
            }

        personas[ubicacion].estado = 1;
    }

    else
    {
        system("cls");
        printf("\nNo hay espacio para cargar.\n\n");
        system("pause");
    }

}

void bajaPersona(EPersona persona[])
{
    int DNI_a_buscar;

    int confirmador;

    int ubicacion;

    char confirmacion;


        system("cls");

        confirmador = hayPersonas(persona);


        if(confirmador != -1)
        {
                printf("Ingrese el DNI a dar de baja: ");
                scanf("%d",&DNI_a_buscar);

                    ubicacion = buscarPorDni(persona,DNI_a_buscar);

                if(ubicacion != -1)
                {
                    printf("DNI     NOMBRE      EDAD\n\n");
                    printf("%d      %s      %d\n\n",persona[ubicacion].dni,persona[ubicacion].nombre,persona[ubicacion].edad);
                    printf("¿Desea dar de baja a la persona? (s/n)");
                    fflush(stdin);
                    confirmacion = getch();


                        if(confirmacion == 's')
                        {
                            persona[ubicacion].estado = 0;
                        }
                        else
                        {
                            printf("\n\nSe a cancelado la operacion.\n\n");
                            system("pause");
                        }
                }
                else
                {
                    printf("\n\nNo se a encontrado el DNI ingresado.\n\n");
                    system("pause");
                }
        }

        else
        {
            printf("\n\nno hay personas a dar de baja.\n");
            system("pause");
        }
}

void mostrarPersonas(EPersona personas[])
{
    int i,j;

    int activo;

    EPersona aux;

    system("cls");

        activo = hayPersonas(personas);

    if(activo != -1)
    {
         for(i=0;i<MAXPERSONAS-1;i++)
        {
            for(j=i+1;j<MAXPERSONAS;j++)
            {
                if(strcmp(personas[i].nombre,personas[j].nombre) > 0)
                {
                    aux = personas[i];
                    personas[i] = personas[j];
                    personas[j] = aux;
                }
            }
        }


        printf("DNI\t\t\t\tNOMBRE\t\t\t\tEDAD\n\n");
        for(i=0;i<MAXPERSONAS;i++)
        {
            if(personas[i].estado == 1)
            {
                printf("%d\t\t\t%s\t\t\t%d\n",personas[i].dni,personas[i].nombre,personas[i].edad);
            }

        }
        system("pause");
    }

    else
    {
        printf("\n\nno hay personas las cuales mostrar\n");
        system("pause");
    }

}

void grafico(EPersona grafico[])
{
    int i;

    int bandera1= 0;
    int bandera2= 0;
    int mayor;

    int menores_18= 0;
    int de_19_a_35= 0;
    int mayores_35= 0;


        system("cls");

        bandera1 = hayPersonas(grafico);

    if(bandera1 != -1)
    {
        for(i=0;i<MAXPERSONAS;i++)
        {
           if(grafico[i].estado == 1)
           {
                if(grafico[i].edad < 18)
                {
                    menores_18++;
                }
                else if(grafico[i].edad > 18 && grafico[i].edad < 35)
                {
                    de_19_a_35++;
                }
                else
                {
                    mayores_35++;
                }
           }
        }

        if(menores_18 >= de_19_a_35 && menores_18 >= mayores_35)
        {
            mayor = menores_18;
        }
        else if(menores_18 <= de_19_a_35 && de_19_a_35 >= mayores_35)
        {
            mayor = de_19_a_35;
        }
        else
        {
            mayor = mayores_35;
        }

        for(i=mayor;i>0;i--)
        {
            printf("%02d|",i);

                if(i <= menores_18)
                {
                    printf("\t*");
                }
                if(i <= de_19_a_35)
                {
                    bandera2=1;
                    printf("\t*");
                }
                if(i <= mayores_35)
                {
                    if(bandera2 == 0)
                    {
                        printf("\t\t*");
                    }
                    else
                    {
                        printf("\t*");
                    }

                }
                printf("\n");
        }
        printf("----------------------------------");
        printf("\n    |<18     19-35     >35");
        printf("\n    |%d          %d         %d\n",menores_18,de_19_a_35,mayores_35);
         system("pause");
    }

    else
    {
        printf("\n\nno hay personas ingresadas para mostrar el grafico\n");
        system("pause");
    }
}

int hayPersonas(EPersona personas[])
{
    int i;

    int bandera = 0;

    int retorno;

        for(i=0;i<MAXPERSONAS;i++)
        {
            if(personas[i].estado == 1)
            {
                retorno = bandera = 1;
                break;
            }
        }

    if(bandera == 0)
    {
        retorno = -1;
    }

    return retorno;
}
