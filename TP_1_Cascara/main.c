#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    float A= 0;
    float B= 0;
    int BanderaA= 0;
    int BanderaB= 0;

    while(seguir=='s')
    {
        system("cls");
        printf("1- Ingresar 1er operando (A=%.2f)\n",A);
        printf("2- Ingresar 2do operando (B=%.2f)\n",B);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                    A = Numero_A();
                    BanderaA= 1;
                break;
            case 2:
                    B = Numero_B();
                    BanderaB= 1;
                break;
            case 3:
                if(BanderaA == 1 && BanderaB == 1)
                {
                    Sumador(A,B);
                }
                else
                {
                    printf("No se ha ingresado uno o ninguno de los operadores.\npor favor ingrese el/los falte/s.\n\n");
                    system("pause");
                }
                break;
            case 4:
                 if(BanderaA == 1 && BanderaB == 1)
                {
                    Diferencial(A,B);
                }
                else
                {
                    printf("No se ha ingresado uno o ninguno de los operadores.\npor favor ingrese el/los falte/s.\n\n");
                    system("pause");
                }
                break;
            case 5:
                 if(BanderaA == 1 && BanderaB == 1)
                {
                    Division(A,B);
                }
                else
                {
                    printf("No se ha ingresado uno o ninguno de los operadores.\npor favor ingrese el/los falte/s.\n\n");
                    system("pause");
                }
                break;
            case 6:
                 if(BanderaA == 1 && BanderaB == 1)
                {
                    Multiplicacion(A,B);
                }
                else
                {
                    printf("No se ha ingresado uno o ninguno de los operadores.\npor favor ingrese el/los falte/s.\n\n");
                    system("pause");
                }
                break;
            case 7:
                  if(BanderaA == 1 )
                {
                    Factorial(A);
                }
                else
                {
                    printf("No se ha ingresado uno o ninguno de los operadores.\npor favor ingrese el/los falte/s.\n\n");
                    system("pause");
                }
                break;
            case 8:
                 if(BanderaA == 1 && BanderaB == 1)
                {
                    Todas_Funciones(A,B);
                }
                else
                {
                    printf("No se ha ingresado uno o ninguno de los operadores.\npor favor ingrese el/los falte/s.\n\n");
                    system("pause");
                }
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;


}
