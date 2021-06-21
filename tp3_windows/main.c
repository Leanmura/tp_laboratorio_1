#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs_lean.h"
#include "menu.h"
#define INTENTOS 3

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    char respuesta;
    char salir;
    int guardado = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados == NULL)
    {
        printf("No se pudo crear la linkedList.\n");
        exit(1);
    }

    do
    {
        menu();
        printf("\n");
        if(!getInt(&option, 1,10, INTENTOS, "Ingrese opcion: ", "Error. "))
        {
            printf("Ha excedido el limite de intentos...\nSe finalizara el programa.\n");
            exit(1);
        }
        respuesta = 's';
        switch(option)
        {
        case 1:
            //system("cls");
            if(ll_len(listaEmpleados)>0)
            {
                if(!getLetra(&respuesta, INTENTOS, "Tiene empleados cargados en la lista y van a ser elminados.\nEsta seguro que quiere cargar otro archivo?", "Error. "))
                {
                    printf("Ha exedido el limite de intentos.\n");
                    respuesta ='n';
                }
                if(respuesta == 's')
                {
                    ll_clear(listaEmpleados);
                }
            }
            if(respuesta != 'n')
            {
                    if(controller_loadFromText("data.csv",listaEmpleados))
                    {
                        printf("Archivo de texto (.csv) cargado con exito.\n");
                    }
                    else
                    {
                        printf("Hubo un error.\n");
                    }
            }

            system("pause");

            break;

        case 2:
            //system("cls");
            if(ll_len(listaEmpleados)>0)
            {
                if(!getLetra(&respuesta, INTENTOS, "Tiene empleados cargados en la lista y van a ser elminados.\nEsta seguro que quiere cargar otro archivo?", "Error. "))
                {
                    printf("Ha exedido el limite de intentos.\n");
                    respuesta ='n';
                }
                if(respuesta == 's')
                {
                    ll_clear(listaEmpleados);
                }
            }
            if(respuesta != 'n')
            {

                    if(controller_loadFromBinary("data.bin",listaEmpleados))
                    {
                        printf("Archivo binario (.bin) cargado con exito.\n");
                    }
                    else
                    {
                        printf("Hubo un error.\n");
                    }

            }
            system("PAUSE");
            break;


        case 3:
            //system("cls");
            printf("------- Alta empleado -------\n");
            if(controller_addEmployee(listaEmpleados))
            {
                guardado = 0;
                printf("Empleado cargado con exito.\n");
            }
            else
            {
                printf("Hubo un error.\n");
            }

            system("PAUSE");
            break;

        case 4:
            //system("cls");
            printf("------ Modificar Empleado ------\n");
            if(controller_editEmployee(listaEmpleados))
            {
                guardado = 0;
                printf("Empleado modificado con exito.\n");
            }
            else
            {
                printf("Hubo un error.\n");
            }
            system("PAUSE");
            break;

        case 5:
            //system("cls");
            if(controller_removeEmployee(listaEmpleados))
            {
                guardado = 0;
                printf("Empleado eliminado con exito.\n");
            }
            else
            {
                printf("No se pudo eliminar el empleado.\n");
            }
            system("pause");
            break;

        case 6:
            //system("cls");
            if(controller_ListEmployee(listaEmpleados))
            {
                printf("Se cargaron todos los empleados con exito.\n");
            }
            else
            {
                printf("No se pudieron cargar todos los empleados.\n");
            }
            system("pause");
            break;

        case 7:
            //system("cls");
            if(controller_sortEmployee(listaEmpleados))
            {
                printf("Se ordenaron todos los empleados con exito.\n");
            }
            else
            {
                printf("No se pudieron ordenar los empleados.\n");
            }
            system("pause");
            break;

        case 8:
            //system("cls");

            if(ll_len(listaEmpleados)>0)
            {
                if(controller_saveAsText("data.csv",listaEmpleados))
                {
                    guardado = 1;
                    printf("Archivo de texto (.csv) cargado con exito.\n");
                }
            }
            else
            {
                printf("No se puede guardar si no ha ingresado ningun empleado.\n");
            }
            system("pause");
            break;

        case 9:
            //system("cls");

            if(ll_len(listaEmpleados)>0)
            {
                if(controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    guardado = 1;
                    printf("Archivo binario (.bin) cargado con exito.\n");
                }
            }
            else
            {
                printf("No se puede guardar si no ha ingresado ningun empleado.\n");
            }

            system("pause");
            break;

        case 10:
            //system("cls");

            if(guardado == 0)
            {
                if(!getLetra(&salir, INTENTOS, "Esta seguro que quiere salir sin guardar?(s/n) ", "Error. "))
                {
                    printf("Ha excedido el limite de intentos.\n");
                }
                system("pause");
            }
            else
            {
                salir = 's';
            }
        }
    }
    while(salir != 's');
    ll_deleteLinkedList(listaEmpleados);

    return 0;
}



