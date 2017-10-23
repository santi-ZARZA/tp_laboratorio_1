#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"


void setearestados(EMovie* movie)
{
    int i;

    for(i=0; i<MAX; i++)
    {
        (movie+i)->estado = 0;
    }
}

void NEWpelicula(EMovie* movie,char titulo[],char genero[],int duracion,char descripcion[],int puntaje,char linkImagen[],int estado)
{
    strcpy(movie->titulo,titulo);
    strcpy(movie->genero,genero);
    movie->duracion = duracion;
    strcpy(movie->descripcion,descripcion);
    movie->puntaje = puntaje;
    strcpy(movie->linkImagen,linkImagen);
    movie->estado = estado;
}

int espacioLibre(EMovie* movie)
{
    int i;
    int retorno;
    int bandera = -1;

    for(i=0; i<MAX; i++)
    {
        if((movie+i)->estado == 0)
        {
            retorno = i;
            bandera = 1;
            break;
        }
    }
    if(bandera == -1)
    {
        retorno = bandera;
    }
    return retorno;
}

int agregarPelicula(EMovie* movie)
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[100];
    int estado;

    int ubicacion;
    int bandera = 0;

    int retorno = 0;

    if(bandera == 0)
    {
        setearestados(movie);
        bandera = 1;
    }

            system("cls");

            ubicacion = espacioLibre(movie);
            if(ubicacion != -1)
            {
                printf("ingrese el titulo: ");
                fflush(stdin);
                gets(titulo);
                printf("ingrese el genero: ");
                fflush(stdin);
                gets(genero);
                printf("ingrese la duracion: ");
                scanf("%d",&duracion);
                printf("ingrese la descripcion: ");
                fflush(stdin);
                gets(descripcion);
                printf("ingrese un puntaje: ");
                scanf("%d",&puntaje);
                printf("ingrese el Link a la imagen: ");
                fflush(stdin);
                gets(linkImagen);
                estado = 1;
                retorno = 1;

                NEWpelicula((movie+ubicacion),titulo,genero,duracion,descripcion,puntaje,linkImagen,estado);
            }

    return retorno;
}

int borrarPelicula(EMovie* movie)
{
    int valida= 0;
    int retorno= 0;
    int i;

    char tituloborrar[30];
    char opcion;

        for(i=0;i<MAX;i++)
        {
            if((movie+i)->estado == 1)
            {
                valida = 1;
                break;
            }
        }

        if(valida == 1)
        {
            system("cls");
            printf("PELICULAS CARGADAS:\n\n");
            for(i=0;i<MAX;i++)
            {
                if((movie+i)->estado == 1)
                {
                    printf("TITULO %d :  %s\n",i,(movie+i)->titulo);
                }
            }

            printf("\n\nIngrese el titulo a borrar: ");
            fflush(stdin);
            gets(tituloborrar);

            for(i=0;i<MAX;i++)
            {
                if(strcmp((movie+i)->titulo,tituloborrar)== 0)
                {
                    system("cls");
                    printf("TITULO A BORRAR:    %s\n\n",(movie+i)->titulo);
                    printf("Desea Borrar la pelicula (S/N): ");
                    fflush(stdin);
                    opcion = tolower(getch());

                    if(opcion == 's')
                    {
                        (movie+i)->estado = 0;
                    }
                    else
                    {
                        printf("\n\nse cancelo la baja.\n\n");
                        system("pause");
                    }
                    retorno = 1;
                }
            }

        }

    return retorno;
}

void generarPagina(EMovie* lista)
{
    FILE* pArchivo;
    int i;
    int valida = 0;
    int valida2 = 0;

    char buffer[2000];
    char nombre[30];
    char puntaje[3];
    char duracion[3];

    for(i=0;i<MAX;i++)
    {
        if((lista+i)->estado == 1)
        {
            valida = 1;
            break;
        }
    }

    if(valida != 0)
    {
        system("cls");
        printf("PELICULAS A CARGAR EN EL ARCHIVO: \n\n");
        for(i=0;i<MAX;i++)
        {
            if((lista+i)->estado == 1)
            {
                printf("TITULO: %s\n",(lista+i)->titulo);
            }
        }

        printf("Ingrese nombre de la pagina a crear: ");
        fflush(stdin);
        gets(nombre);

        strcat(nombre,".html");

        pArchivo = fopen(nombre,"w");
            if(pArchivo != NULL)
            {
                valida2 = 1;
                for(i=0;i<MAX;i++)
                {
                    if((lista+i)->estado == 1)
                    {
                        strcat(buffer,"<html><head></head><body>");
                        strcat(buffer,"<article class='col-md-4 article-intro'> <a href='#'> <img class='img-responsive img-rounded' src='");
                        strcat(buffer,(lista+i)->linkImagen);
                        strcat(buffer,"' alt=''>                </a>                <h3>                    <a href='#'>");
                        strcat(buffer,(lista+i)->titulo);
                        strcat(buffer,"</a>                </h3> <ul> <li>Género:");
                        strcat(buffer,(lista+i)->genero);
                        strcat(buffer,"</li> <li>Puntaje:");
                        itoa((lista+i)->puntaje,puntaje,10);
                        strcat(buffer,puntaje);
                        strcat(buffer,"</li> <li>Duración:");
                        itoa((lista+i)->duracion,duracion,10);
                        strcat(buffer,duracion);
                        strcat(buffer,"</li> </ul>                <p>");
                        strcat(buffer,(lista+i)->descripcion);
                        strcat(buffer,"</p> </article> ");
                        strcat(buffer,"</body></html>");

                        fwrite(buffer,sizeof(char),strlen(buffer),pArchivo);
                    }
                }
            }
            else
            {
                system("cls");
                printf("\nLa pagina no pudo ser creada.\n\n");
                system("pause");
            }
            fclose(pArchivo);

            if(valida2 == 1)
            {
                system("cls");
                printf("pagina creada con exito.\n\n");
                system("pause");
            }

    }
    else
    {
        system("cls");
        printf("No hay peliculas cargadas.\n\n");
        system("pause");
    }




}

void creaArchivoBinario(EMovie* movie)
{
    FILE* Elarchivo;
    int i;

        Elarchivo = fopen("archivo-binario.o","rb");
        if(Elarchivo != NULL)
        {
            Elarchivo = fopen("archivo-binario.o","wb");
            if(Elarchivo != NULL)
            {
                for(i=0;i<MAX;i++)
                {
                    if((movie+i)->estado == 1)
                    {
                        fwrite((movie+i),sizeof(EMovie),1,Elarchivo);
                    }
                }
            }
            else
            {
                printf("No se pudo generar el archivo.\n");
                system("pause");
            }
            fclose(Elarchivo);
        }
        else
        {
            Elarchivo = fopen("archivo-binario.o","wb");
            if(Elarchivo != NULL)
            {
                for(i=0;i<MAX;i++)
                {
                    if((movie+i)->estado == 1)
                    {
                        fwrite((movie+i),sizeof(EMovie),1,Elarchivo);
                    }
                }
            }
            else
            {
                printf("No se pudo generar el archivo.\n");
                system("pause");
            }
            fclose(Elarchivo);
        }
        fclose(Elarchivo);
}

