#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


float Numero_A ()
{
    float A;

            system("cls");
        printf("ingrese el primer operador: ");
        scanf("%f",&A);

    return A;
}

 float Numero_B ()
 {
    float B;

            system("cls");
        printf("ingrese el segundo operador: ");
        scanf("%f",&B);

    return B;
 }

  void Sumador (float primer_numero ,float segundo_numero)
  {
      float resultado;

                system("cls");
            resultado = primer_numero + segundo_numero;

            printf("el resultado de la suma es: %.2f\n\n",resultado);
            system("pause");
  }

  void Diferencial (float primer_numero ,float segundo_numero)
  {
      float resultado;

                system("cls");
            resultado = primer_numero - segundo_numero;

            printf("el resultado de la resta es: %.2f\n\n",resultado);
            system("pause");
  }

  void Division (float primer_numero ,float segundo_numero)
  {
      float resultado;

                system("cls");

        if(segundo_numero != 0 && primer_numero != 0)
        {
            resultado = primer_numero / segundo_numero;

            printf("el resultado de la Division es: %.2f\n\n",resultado);
            system("pause");
        }
        else
        {
            printf("Error, esta operacion no es posible.\n\n");
            system("pause");
        }
  }

  void Multiplicacion (float primer_numero ,float segundo_numero)
  {
      float resultado;

                system("cls");
            resultado = primer_numero * segundo_numero;

            printf("el resultado de la multiplicacion es: %.2f\n\n",resultado);
            system("pause");
  }

  void Factorial (float primer_numero )
  {
      int i;

      int factorial= 1;
     long long int resultado;

                system("cls");
            for(i=1;i<=primer_numero;i++)
            {
                factorial = i*factorial;
            }
            resultado = factorial;

            printf("el resultado del factorial de %.0f es: %lld\n\n",primer_numero,resultado);
            system("pause");

  }

  void Todas_Funciones (float primer_numero ,float segundo_numero)
  {
      int i;
      int bandera;
      int segunda_bandera;

      int factorial= 1;

      float resultado_suma;
      float resultado_resta;
      float resultado_division;
      float resultado_multiplicacion;
      long long int resultado_factorial;

            system("cls");
        resultado_suma = primer_numero + segundo_numero;
        resultado_resta = primer_numero - segundo_numero;

        if(segundo_numero != 0 && primer_numero != 0)
        {
            resultado_division = primer_numero / segundo_numero;
            resultado_multiplicacion = primer_numero * segundo_numero;
            bandera = 1;
        }
        else
        {
            bandera = -1;
        }
        if(primer_numero != 0)
            {
                for(i=1;i<=primer_numero;i++)
                {
                    factorial = i*factorial;
                }
                resultado_factorial = factorial;
                segunda_bandera = 1;
            }
        else
        {
            segunda_bandera = -1;
        }

            printf("el resultado de la suma entre %.2f y %.2f es: %.2f\n\n",primer_numero,segundo_numero,resultado_suma);
            printf("el resultado de la resta entre %.2f y %.2f es: %.2f\n\n",primer_numero,segundo_numero,resultado_resta);
        if(bandera != -1)
        {
            printf("el resultado de la division entre %.2f y %.2f es: %.2f\n\n",primer_numero,segundo_numero,resultado_division);
            printf("el resultado de la multiplicacion entre %.2f y %.2f es: %.2f\n\n",primer_numero,segundo_numero,resultado_multiplicacion);
        }
        else
        {
            printf("las operaciones de multiplicacion y division no fueron posibles de realizarse.\n\n");
        }
            if(segunda_bandera != -1)
            {
                 printf("el resultado de el factorial de %.0f es: %d\n\n",primer_numero,resultado_factorial);
            }
            else
            {
                printf("La operacion de Factorizacion no fue posible de ser realizada.\n\n");
            }

        system("pause");
  }
