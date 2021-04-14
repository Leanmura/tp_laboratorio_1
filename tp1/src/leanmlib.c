/*
 * leanmlib.c
 *
 *  Created on: 13 abr. 2021
 *      Author: Leandro
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void menu(int x, int y, int fNum1, int fNum2)
{
    printf("*********** MENU ************\n");
    if (fNum1 != 0)
    {
        printf("1. Ingresar 1er operando (A=%d)\n", x);
    }
    else
    {
        printf("1. Ingresar 1er operando (A=x)\n");
    }
    if (fNum2 != 0)
    {
        printf("2. Ingresar 2do operando (B=%d)\n", y);
    }
    else
    {
        printf("2. Ingresar 2do operando (B=y)\n");
    }

    printf("3. Calcular todas las operaciones\n");
    printf("   a) Calcular la suma (A+B)\n");
    printf("   b) Calcular la resta (A-B)\n");
    printf("   c) Calcular la division (A/B)\n");
    printf("   d) Calcular la multiplicacion (A*B)\n");
    printf("   e) Calcular el factorial (A!)\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n\n");
}

int ingresoOpcion()
{
    int opcion;
    printf("Ingrese lo que desea hacer: ");
    fflush(stdin);

    while (!scanf("%d", &opcion) || opcion < 1 || opcion > 5)
    {
        printf("Error. Ingrese lo que desea hacer: ");
        fflush(stdin);
    }
    return opcion;
}

int ingresoNumero(int *pResultado, int min, int max, char textoIngreso[], char textoError[], int x)
{
    int numero;
    int retorno = 1;

    if (pResultado == NULL)
    {
        retorno = 0;
    }

    printf(textoIngreso, x);
    while (!(scanf("%d", &numero)) || numero > max || numero < min)
    {
        printf(textoError, x);
        fflush(stdin);
    }
    *pResultado = numero;
    return retorno;
}

int suma(int a, int b)
{
    int resultado;

    resultado = a + b;
    return resultado;
}

int resta(int a, int b)
{
    int resultado;

    resultado = a - b;
    return resultado;
}

int multiplicacion(int a, int b)
{
    int resultado;

    resultado = a * b;
    return resultado;
}

int division(int dividendo, int divisor, float *pResultado)
{
    int retorno = 1;

    if (divisor == 0)
    {
        retorno = 0;
    }
    else
    {
        *pResultado = (float)dividendo / divisor;
    }
    return retorno;
}

/* int factorial(int a)
{
    int factorial = 1;

    for (int x = 1; x <= a; x++)
    {
        factorial = factorial * x;
    }
    return factorial;
} */

int factorialRecursivo(int n) // se llama a si misma para hacer el factorial  n! = n * (n-1)!
{
    int factorial = 1;
    if (n > 12 || n < 0)
    {
        factorial = 0;
    }
    else
    {
        if (n > 1)
        {
            factorial = n * factorialRecursivo(n - 1);
        }
    }

    return factorial;
}

void activarFlag(int *x)
{
    *x = 1;
}

void resetFlag(int *x)
{
    *x = 0;
}
