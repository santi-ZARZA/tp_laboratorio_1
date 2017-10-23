#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    EMovie peliculas[MAX];


    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if(agregarPelicula(peliculas))
                {
                    creaArchivoBinario(peliculas);
                }
                else
                {
                    printf("\nno pudo ser cargada la pelicula.\n\n");
                    system("pause");
                }
                break;
            case 2:
                if(borrarPelicula(peliculas))
                {
                    creaArchivoBinario(peliculas);
                }
                else
                {
                    printf("\nno pudo ser borrada la pelicula.\n\n");
                    system("pause");
                }
                break;
            case 3:
                generarPagina(peliculas);
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
