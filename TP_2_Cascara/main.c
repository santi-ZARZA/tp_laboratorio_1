#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;

    EPersona personas[MAXPERSONAS];

    int bandera = 0;


    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if(bandera == 0)
                {
                    seteadorDeEstados(personas);
                    bandera = 1;
                }
                cargarPersona(personas);
                break;
            case 2:
                bajaPersona(personas);
                break;
            case 3:
                mostrarPersonas(personas);
                break;
            case 4:
                grafico(personas);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
