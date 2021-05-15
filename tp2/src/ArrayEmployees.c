/*
 * ArrayEmployees.c
 *
 *  Created on: May 15, 2021
 *      Author: Leandro
 */

#include "arrayEmployees.h"

int initEmployees(Employee *list, int len)
{
    int todoOk = -1;
    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        todoOk = 0;
    }
    return todoOk;
}

int addEmployee(Employee *list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int todoOk = -1;
    int indice;

    if (list != NULL && len >= 0 && id > 0)
    {
        indice = findEmpty(list, len);
        if (indice != -1)
        {
            strcpy(list[indice].name, name);

            strcpy(list[indice].lastName, lastName);

            list[indice].salary = salary;

            list[indice].sector = sector;

            list[indice].isEmpty = 0;

            list[indice].id = id;

            todoOk = 1;
        }
    }
    return todoOk;
}

int findEmpty(Employee *list, int len)
{
    int indice = -1;
    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            if (list[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int getEmployee(char name[], char lastName[], float *salary, int *sector, int nextId)
{

    int todoOk = 0;

    if (name != NULL && lastName != NULL && salary != NULL && sector != NULL)
    {
        printf("ID #%d\n", nextId);
        if (!getString(name, 51, 3, "Ingrese el nombre: ", "Error."))
        {
            printf("Ha excedido el limite de intentos.\n\n");
        }
        else
        {
            if (!getString(lastName, 51, 3, "Ingrese el apellido: ", "Error."))
            {
                printf("Ha excedido el limite de intentos.\n\n");
            }
            else
            {
                if (!getFloat(salary, 1, 10000000, 3, "Ingrese el salario: ", "Error. "))
                {
                    printf("Ha excedido el limite de intentos.\n\n");
                }
                else
                {
                    menuSectors();

                    if (!getInt(sector, 500, 504, 3, "Ingrese el sector al que corresponde: ", "Error. "))
                    {
                        printf("Ha excedido el limite de intentos.\n\n");
                    }
                    else
                    {
                        formatSustP(lastName);
                        formatSustP(name);
                        todoOk = 1;
                    }
                }
            }
        }
    }
    return todoOk;
}

int printEmployees(Employee *list, int length)
{
    int flagIsEmpty = 1;
    int todoOk = -1;
    if (list != NULL && length > 0)
    {

        printf("\n************** List of employees **************\n");
        printf("  ID     Name      Lastname    Salary    Sector\n");
        for (int i = 0; i < length; i++)
        {
            if (!(list[i].isEmpty))
            {
                printEmployee(list[i]);
                flagIsEmpty = 0;
            }
        }
        if (flagIsEmpty)
        {
            printf("No hay ningun empleado.\n\n");
        }
        printf("\n");
        todoOk = 0;
    }
    return todoOk;
}

void printEmployee(Employee emp)
{
    printf("#%05d  %-10s %-10s %-10.2f  %d\n",
           emp.id,
           emp.name,
           emp.lastName,
           emp.salary,
           emp.sector);
}

int findEmployeeById(Employee *list, int len, int id)
{
    int index = -1;
    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            if (list[i].id == id && !list[i].isEmpty)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

int modificarEmpleado(Employee lista[], int tam)
{
    int legajo;
    int indice;
    int todoOk = 0;
    int opcion;
    Employee auxEmpleado;

    if (lista != NULL && tam >= 0)
    {
        getInt(&legajo, 20000, 21000, 3, "Ingrese el ID del empleado: #", "Error. ");
        indice = findEmployeeById(lista, tam, legajo);
        if (indice != -1)
        {
            menuModificar();
            if (!getInt(&opcion, 1, 4, 3, "Ingrese lo que desea modificar: ", "Error. "))
            {
                printf("Ha excedido el limite de intentos.\n");
            }

            switch (opcion)
            {
            case 1:
                printf("Nombre a modificar: %s\n", lista[indice].name);
                if (getString(auxEmpleado.name, 51, 3, "Ingrese el nuevo nombre: ", "Error. "))
                {
                    formatSustP(auxEmpleado.name);
                    strcpy(lista[indice].name, auxEmpleado.name);
                    printf("Nombre modificado con exito!\n");
                    todoOk = 1;
                }
                else
                {
                    printf("Modificar nombre ha fallado.\n");
                }
                break;

            case 2:
                printf("Apellido a modificar: %s\n", lista[indice].lastName);
                if (getString(auxEmpleado.lastName, 51, 3, "Ingrese el nuevo apellido: ", "Error. "))
                {
                    formatSustP(auxEmpleado.lastName);
                    strcpy(lista[indice].lastName, auxEmpleado.lastName);
                    printf("Apellido modificado con exito!\n");
                    todoOk = 1;
                }
                else
                {
                    printf("Modificar apellido ha fallado.\n");
                }
                break;

            case 3:
                printf("Sueldo a modificar: %.2f\n", lista[indice].salary);
                if (getFloat(&auxEmpleado.salary, 1, 100000000, 3, "Ingrese el nuevo sueldo: ", "Error. \n"))
                {
                    lista[indice].salary = auxEmpleado.salary;
                    printf("Sueldo modificado con exito!\n");
                    todoOk = 1;
                }
                else
                {
                    printf("Modificar sueldo ha fallado.\n");
                }
                break;
            case 4:
                printf("Sector a modificar: %d\n", lista[indice].sector);
                if (getInt(&auxEmpleado.sector, 500, 504, 3, "Ingrese el nuevo Sector: ", "Error. \n"))
                {
                    lista[indice].sector = auxEmpleado.sector;
                    printf("Sector modificado con exito!\n");
                    todoOk = 1;
                }
                else
                {
                    printf("Modificar Sector ha fallado.\n");
                }
                break;
            }
        }
        else
        {
            printf("No se encontro el ID.\n");
        }
    }
    printf("\n");

    return todoOk;
}

int removeEmployee(Employee *list, int len, int id)
{
    int index;
    int todoOk = -1;
    char confirm;
    if (list != NULL && len > 0)
    {
        index = findEmployeeById(list, len, id);
        if (index != -1)
        {
            printf("  ID     Name      Lastname    Salary    Sector\n");
            printEmployee(list[index]);
            printf("\nEsta seguro que quiere eliminar este id? (ingrese 's' para confirmar)");
            fflush(stdin);
            scanf("%c", &confirm);
            if (confirm == 's')
            {
                list[index].isEmpty = 1;
                todoOk = 0;
            }
            else
            {
                printf("Operacion abortada.\n");
            }
        }
        else
        {
            printf("No se encontro el id.\n\n");
        }
    }
    return todoOk;
}

int sortEmployees(Employee *list, int len, int order)
{
    int todoOk = -1;
    Employee aux;
    if(list != NULL && len > 0)
    {
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (order == 1)
                {
                    if (list[i].sector > list[j].sector || (list[i].sector == list[j].sector && (stricmp(list[i].lastName, list[j].lastName)) > 0 ))
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
                else
                {
                    if (list[i].sector > list[j].sector || (list[i].sector == list[j].sector && (stricmp(list[i].lastName, list[j].lastName)) < 0 ))
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
        }
        todoOk =0;
    }
    return todoOk;
}
