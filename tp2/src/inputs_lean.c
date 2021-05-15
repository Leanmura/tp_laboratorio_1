/*
 * inputs_lean.c
 *
 *  Created on: May 15, 2021
 *      Author: Leandro
 */


#include "inputs_lean.h"

int getInt(int *pResultado, int minimo, int maximo, int intentos, char mensaje[], char mensajeError[])
{
    int numero;
    int todoOk = 0;

    if (pResultado != NULL && mensajeError != NULL && minimo <= maximo && intentos > 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            if (scanf("%d", &numero))
            {
                if (numero >= minimo && numero <= maximo)
                {
                    *pResultado = numero;
                    break;
                }
            }
            printf("%s", mensajeError);
            intentos--;
        } while (intentos);

        if (intentos > 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int getFloat(float *pResultado, float minimo, float maximo, int intentos, char mensaje[], char mensajeError[])
{
    float numero;
    int todoOk = 0;

    if (pResultado != NULL && mensajeError != NULL && minimo <= maximo && intentos > 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            if (scanf("%f", &numero))
            {
                if (numero >= minimo && numero <= maximo)
                {
                    *pResultado = numero;
                    break;
                }
            }
            printf("%s", mensajeError);
            intentos--;
        } while (intentos);

        if (intentos > 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int getString(char cadena[], int len, int intentos, char mensaje[], char mensajeError[])
{
    int i;
    char auxCadena[100];
    int todoOk = 0;
    int flag = 0;
    if (cadena != NULL && mensajeError != NULL && intentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            gets(auxCadena);

            i = 0;
            while (auxCadena[i] != '\0')
            {
                if ((auxCadena[i] != ' ') && (auxCadena[i] < 'a' || auxCadena[i] > 'z') && (auxCadena[i] < 'A' || auxCadena[i] > 'Z'))
                {
                    flag = 1;
                    break;
                }
                else
                {
                    flag = 0;
                    i++;
                }
            }

            if (strlen(auxCadena) <= len && !flag)
            {
                strcpy(cadena, auxCadena);
                break;
            }

            printf("%s", mensajeError);
            intentos--;
        } while (intentos);

        if (intentos > 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
