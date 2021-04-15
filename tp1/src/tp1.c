/*
 ============================================================================
 Name        : tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "leanmlib.h"

int main()
{
	setbuf(stdout,NULL);
    int num1 = 0;
    int num2 = 0;
    int rSuma;
    int rResta;
    int rMultiplicacion;
    float rDivision;
    int rFactorial1;
    int rFactorial2;
    int opcion;
    int salir = 0;
    int fNum1 = 0;
    int fNum2 = 0;
    int fCalculos = 0;
    int contNum = 0;

    do
    {
        menu(num1, num2, fNum1, fNum2);
        ingresoNumero(&opcion, 1, 5, "Ingrese lo que desea hacer: ", "Error. Ingrese lo que desea hacer: ", 1);

        switch (opcion)
        {
        case 1:
            contNum++;
            ingresoNumero(&num1, -1000000, 1000000, "Ingrese numero #%d: ", "Error. Ingrese numero #%d: ", 1);
            activarFlag(&fNum1);
            break;
        case 2:
            contNum++;
            ingresoNumero(&num2, -1000000, 1000000, "Ingrese numero #%d: ", "Error. Ingrese numero #%d: ", 2);
            activarFlag(&fNum2);
            contNum = 0;
            break;
        case 3:
            if (fNum1 == 0 || fNum2 == 0)
            {
                printf("\nNo se pueden hacer los calculos, sin haber ingresado antes los numeros.\n\n");
                system("PAUSE");
            }
            else
            {
                rSuma = suma(num1, num2);
                rResta = resta(num1, num2);
                rMultiplicacion = multiplicacion(num1, num2);
                rFactorial1 = factorial(num1);
                rFactorial2 = factorial(num2);
                if (division(num1, num2, &rDivision) == 0 || rFactorial1 == 0 || rFactorial2 == 0)
                {
                    printf("Algunos calculos no se pudieron realizar.\n\n");
                }
                else
                {
                    printf("Calculos realizados con exito.\n\n");
                }

                activarFlag(&fCalculos);
                system("PAUSE");
            }
            break;
        case 4:
            if (fCalculos == 0)
            {
                printf("\nNo se pueden mostrar los resultados sin haber hecho los calculos.\n\n");
                system("PAUSE");
            }
            else
            {
                printf("   a) 'El resultado de A+B es: %d'\n", rSuma);
                printf("   b) 'El resultado de A-B es: %d'\n", rResta);
                if (num2 == 0)
                {
                    printf("   c) No se puede dividir por 0.\n");
                }
                else
                {
                    printf("   c) 'El resultado de A/B es: %.2f'\n", rDivision);
                }
                printf("   d) 'El resultado de A*B es: %d'\n", rMultiplicacion);

                if (rFactorial1 == 0)
                {
                    printf("   e) No pude hacer el factorial de A ");
                }
                else
                {
                    printf("   e) El factorial de A es: %d ", rFactorial1);
                }
                if (rFactorial2 == 0)
                {
                    printf("y no pude hacer el factorial de B.\n\n");
                }
                else
                {
                    printf("y el factorial de B es: %d\n\n", rFactorial2);
                }

                resetFlag(&fNum1);
                resetFlag(&fNum2);
                resetFlag(&fCalculos);

                system("PAUSE");
            }

            break;
        case 5:
            salir = 1;
            break;
        }
    } while (salir == 0);

	return EXIT_SUCCESS;
}
