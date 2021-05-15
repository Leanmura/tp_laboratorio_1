/*
 ============================================================================
 Name        : tp2.c
 Author      : Murakoshi Leandro
 Version     :
 Copyright   : Your copyright notice
 Description : tp2 in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"

#define LEN 1000

int main(void) {
	setbuf(stdout,NULL);
    int opcion;
    int opcionInforme;
    int salir = 0;

    int nextId = 20000;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    int idRemove;
    int order;

    float total;
    int contadorEmpleados;
    float promedio;
    int contEmpMasPromedio;

    int flag=0;

    Employee arrayEmployees[LEN];
    initEmployees(arrayEmployees, LEN);

    do
    {
        idRemove =0;
        total = 0;
        contadorEmpleados =0;
        contEmpMasPromedio=0;
        menu();

        if (!getInt(&opcion, 1, 5, 2, "Ingrese opcion: ", "Error. "))
        {
            printf("Ha fallado demasiadas veces, se finalizara el programa.\n\n");
            return 0;
        }

        switch (opcion)
        {
        case 1:
            //system("cls");
            printf("------- Alta empleado -------\n");

            if (findEmpty(arrayEmployees, LEN) != -1) // se fija si hay algun lugar vacio en el array de empleados
            {
                if(getEmployee(name, lastName, &salary, &sector, nextId)) // pide los datos al usuario
                {
                    if (addEmployee(arrayEmployees, LEN, nextId, name, lastName, salary, sector) == -1)
                    {
                        printf("\nError.\n\n");
                    }
                    else
                    {
                        printf("\nAlta exitosa!\n\n");
                        flag =1;
                        nextId++;
                    }
                }
            }
            else
            {
                printf("No hay lugar disponible.\n\n");
            }


            system("PAUSE");
            break;

        case 2:
            if(flag)
            {
                //system("cls");
                printf("------ Modificar Empleado ------\n");
                printEmployees(arrayEmployees, LEN);
                modificarEmpleado(arrayEmployees, LEN);
            }
            else
            {
                printf("\nNo puede modificar un empleado sin haber dado de alta al menos un empleado.\n\n");
            }
            system("PAUSE");
            break;

        case 3:
            if(flag)
            {
                //system("cls");
                printf("-------- Baja empleado --------\n");
                printEmployees(arrayEmployees, LEN);
                if (!getInt(&idRemove, 20000, 21000, 3, "Ingrese el id del empleado: #", "Error. "))
                {
                    printf("Ha excedido el limite de intentos.\n");
                }
                if(removeEmployee(arrayEmployees, LEN, idRemove) == 0)
                {
                    printf("Baja realizada con exito!\n\n");
                }
            }
            else
            {
                printf("\nNo puede dar de baja un empleado sin haber dado de alta al menos un empleado.\n\n");
            }

            system("PAUSE");
            break;

        case 4:
            if(flag)
            {
                menuInformes();

                if (!getInt(&opcionInforme, 1, 3, 5, "Ingrese opcion: ", "Error. "))
                {
                    printf("Ha fallado muchas veces, intente mas tarde. \n\n");
                    system("PAUSE");
                    break;
                }
                switch (opcionInforme)
                {
                case 1:
                    //system("cls");
                    printf("Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n\n");
                    if(!getInt(&order, 0,1, 3, "Desea Ordenarlos de forma ascendente(1) o descendente(0): ", "Error. "))
                    {
                        printf("Ha excedido el limite de intentos.\n");
                    }
                    else
                    {
                        if(sortEmployees(arrayEmployees, LEN, order) == 0)
                        {
                            printEmployees(arrayEmployees, LEN);
                        }
                        else
                        {
                            printf("Hubo un error.\n\n");
                        }
                    }
                    break;

                case 2:
                    //system("cls");
                    printf("Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
                    for(int i=0; i<LEN; i++)
                    {
                        if(!arrayEmployees[i].isEmpty)
                        {
                            total = total + arrayEmployees[i].salary;
                            contadorEmpleados++;
                        }
                    }
                    printf("TOTAL salarios: %.2f\n", total);
                    promedio = total / contadorEmpleados;
                    printf("PROMEDIO salarios: %.2f\n", promedio);
                    for(int j=0; j<LEN; j++)
                    {
                        if(!arrayEmployees[j].isEmpty && arrayEmployees[j].salary > promedio)
                        {
                            contEmpMasPromedio++;
                        }
                    }
                    printf("Cantidad de empleados que superan el salario promedio: %d\n\n", contEmpMasPromedio);
                    break;
                }
            }
            else
            {
                printf("\nNo puede informar sin haber dado de alta al menos un empleado.\n\n");
            }
            system("PAUSE");
            break;

        case 5:
            salir = 1;
            break;
        }
    }
    while (!salir);
	return EXIT_SUCCESS;
}
