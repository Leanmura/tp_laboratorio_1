#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "inputs_lean.h"
#include "biblioteca_lean.h"
#include "menu.h"
#define INTENTOS 3


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path,"r");
        if(f==NULL)
        {
            printf("No se pudo abrir el archivo.\n");
        }
        else
        {
            if(parser_EmployeeFromText(f, pArrayListEmployee))
            {
                todoOk=1;
            }
        }
        fclose(f);
    }
    return todoOk;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path,"rb");
        if(f==NULL)
        {
            printf("No se pudo abrir el archivo.\n");
        }
        else
        {
            if(parser_EmployeeFromBinary(f, pArrayListEmployee))
            {
                todoOk=1;
            }
        }
        fclose(f);
    }
    return todoOk;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int nextId;
    char nombre[128];
    int horas;
    int sueldo;
    Employee* newEmployee = NULL;
    int todoOk=0;
    if(pArrayListEmployee != NULL)
    {
        employee_buscarMayorId(pArrayListEmployee, &nextId);
        if (!getNombre(nombre, 128, INTENTOS, "Ingrese el nombre: ", "Error."))
        {
            printf("Ha excedido el limite de intentos.\n\n");
        }
        else
        {
            if (!getInt(&sueldo, 1, 10000000, 3, "Ingrese el salario: ", "Error. "))
            {
                printf("Ha excedido el limite de intentos.\n\n");
            }
            else
            {

                if (!getInt(&horas, 1, 10000, 3, "Ingrese horas trabajadas: ", "Error. "))
                {
                    printf("Ha excedido el limite de intentos.\n\n");
                }
                else
                {
                    formatSustP(nombre);
                    newEmployee = employee_new();
                    if(employee_setId(newEmployee, nextId) &&
                            employee_setNombre(newEmployee, nombre) &&
                            employee_setHorasTrabajadas(newEmployee, horas) &&
                            employee_setSueldo(newEmployee, sueldo))
                    {
                        ll_add(pArrayListEmployee, newEmployee);
                        todoOk = 1;
                    }
                    else
                    {
                        employee_delete(newEmployee);
                    }
                }
            }
        }
    }
    return todoOk;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int id;
    char nombre [128];
    int horas;
    int sueldo;
    int auxId;
    int len;
    int opcion;
    Employee* empleado = NULL;
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        if(len >0)
        {
            if(getInt(&id, 1, 10000, INTENTOS, "Ingrese ID del empleado que desae modificar: ", "Error. "))
            {
                for(int i=0; i<len; i++)
                {
                    empleado = (Employee*)ll_get(pArrayListEmployee, i);
                    if(employee_getId(empleado, &auxId))
                    {
                        if(auxId == id)
                        {
                            if( employee_getNombre(empleado, nombre) &&
                                    employee_getHorasTrabajadas(empleado, &horas) &&
                                    employee_getSueldo(empleado, &sueldo))
                            {

                                menuModificar();
                                printf("  ID     NOMBRE        HORAS      SUELDO\n");
                                printf(" %04d    %-15s%-3d      %d\n\n", id, nombre, horas, sueldo);
                                if (!getInt(&opcion, 1, 5, 3, "Ingrese lo que desea modificar: ", "Error. "))
                                {
                                    printf("Ha excedido el limite de intentos.\n");
                                }

                                switch (opcion)
                                {
                                case 1:
                                    printf("Nombre a modificar: %s\n", empleado->nombre);
                                    if (getNombre(nombre, 128, INTENTOS, "Ingrese el nuevo nombre: ", "Error. "))
                                    {
                                        formatSustP(nombre);
                                        strcpy(empleado->nombre, nombre);
                                        printf("Nombre modificado con exito!\n");
                                        todoOk = 1;
                                    }
                                    else
                                    {
                                        printf("Modificar nombre ha fallado.\n");
                                    }
                                    break;

                                case 2:
                                    printf("Horas trabajadas a modificar: %d\n", empleado->horasTrabajadas);
                                    if (getInt(&horas, 1, 10000, INTENTOS,"Ingrese el nuevo sueldo: ", "Error. \n"))
                                    {
                                        empleado->horasTrabajadas = horas;
                                        printf("Sueldo modificado con exito!\n");
                                        todoOk = 1;
                                    }
                                    else
                                    {
                                        printf("Modificar sueldo ha fallado.\n");
                                    }
                                    break;

                                case 3:
                                    printf("Sueldo a modificar: %d\n",empleado->sueldo);
                                    if (getInt(&sueldo, 1, 1000000, INTENTOS, "Ingrese el nuevo sueldo: ", "Error. \n"))
                                    {
                                        empleado->sueldo= sueldo;
                                        printf("Sueldo modificado con exito!\n");
                                        todoOk = 1;
                                    }
                                    else
                                    {
                                        printf("Modificar sueldo ha fallado.\n");
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            printf("\nNo puede modificar un empleado sin haber dado de alta al menos un empleado.\n\n");
        }
    }


    return todoOk;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int len;
    int todoOk =0;
    int id;
    int auxId;
    char respuesta;
    char nombre[128];
    int horas;
    int sueldo;
    Employee* empleado = NULL;

    if(pArrayListEmployee!= NULL)
    {
        len = ll_len(pArrayListEmployee);
        if(len >0)
        {
            //controller_ListEmployee(pArrayListEmployee);
            if(getInt(&id, 1, 10000, INTENTOS, "Ingrese ID del empleado que desea eliminar: ", "Error. "))
            {
                for(int i=0; i<len; i++)
                {
                    empleado = (Employee*)ll_get(pArrayListEmployee, i);
                    if(employee_getId(empleado, &auxId))
                    {
                        if(auxId == id)
                        {
                            if( employee_getNombre(empleado, nombre) &&
                                    employee_getHorasTrabajadas(empleado, &horas) &&
                                    employee_getSueldo(empleado, &sueldo))
                            {
                                printf("\n  ID     NOMBRE        HORAS      SUELDO\n");
                                printf(" %04d    %-15s%-3d      %d\n\n", id, nombre, horas, sueldo);
                                if (!getLetra(&respuesta, INTENTOS, "Esta seguro que quiere eliminar este empleado? ", "Error. "))
                                {
                                    printf("Ha excedido el limite de intentos.\n");
                                }
                                else
                                {


                                    if(respuesta == 's')
                                    {
                                        ll_remove(pArrayListEmployee, i);
                                        todoOk =1;

                                    }

                                }

                            }
                        }
                    }
                }
            }
        }
        else
        {
            printf("\nNo puede modificar un empleado sin haber dado de alta al menos un empleado.\n\n");
        }
    }
    return todoOk;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int id;
    char nombre[128];
    int horas;
    int sueldo;
    int cantEmployee=0;
    int todoOk =0;

    if(pArrayListEmployee != NULL)
    {
        printf("--------- LISTADO DE EMPLEADOS ---------\n");
        printf("  ID     NOMBRE        HORAS      SUELDO\n");

        int len = ll_len(pArrayListEmployee);

        for(int i=0; i<len; i++)
        {
            empleado = (Employee*)ll_get(pArrayListEmployee, i);
            if(employee_getId(empleado, &id) &&
                    employee_getNombre(empleado, nombre) &&
                    employee_getHorasTrabajadas(empleado, &horas) &&
                    employee_getSueldo(empleado, &sueldo))
            {
                printf(" %04d    %-15s%-3d      %d\n", id, nombre, horas, sueldo);
                cantEmployee++;
            }
        }
        if(cantEmployee == len)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk =0;
    int len = ll_len(pArrayListEmployee);
    Employee* empleado1 = NULL;
    Employee* empleado2 = NULL;
    //Employee auxEmpleado;
    char nombre1[128];
    char nombre2[128];

    if(pArrayListEmployee!= NULL)
    {
        todoOk =1;
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                empleado1 = ll_get(pArrayListEmployee, i);
                empleado2 = ll_get(pArrayListEmployee, j);

                if(empleado1 != NULL && empleado2 != NULL)
                {
                    if(employee_getNombre(empleado1, nombre1) &&
                            employee_getNombre(empleado2, nombre2))
                    {
                        if (strcmp(nombre1, nombre2) > 0)
                        {
                            //auxEmpleado = *empleado1;
                            //*empleado1 = *empleado2; // cambia estrcuturas
                            //*empleado2 =auxEmpleado;
                            ll_set(pArrayListEmployee,i,empleado2); // cambia las eiorecciones de memoria en la linkedlist
                            ll_set(pArrayListEmployee,j,empleado1);
                        }
                    }
                    else
                    {
                        todoOk =0;
                    }
                }
                else
                {
                    todoOk =0;
                }
            }
        }
    }
    return todoOk;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char respuesta = 's';
    int id;
    char nombre[128];
    int horas;
    int sueldo;
    Employee* auxEmp;
    FILE* f = NULL;
    int cantCargados =0;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path, "r");
        if(f != NULL)
        {
            if(!getLetra(&respuesta, INTENTOS, "Este archivo ya existe. Desea sobreescribirlo? ", "Error. "))
            {
                printf("Ha exedido el limite de intentos.\n");
                respuesta ='n';
            }
            fclose(f);
        }

        if(respuesta != 'n')
        {
            f = fopen(path, "w");
            if(f == NULL)
            {
                printf("No se pudo abrir el archivo.\n");
            }
            else
            {
                fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
                for(int i=0; i< ll_len(pArrayListEmployee); i++)
                {
                    auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
                    if(auxEmp != NULL)
                    {
                        if(employee_getId(auxEmp, &id) &&
                                employee_getNombre(auxEmp, nombre) &&
                                employee_getHorasTrabajadas(auxEmp, &horas) &&
                                employee_getSueldo(auxEmp, &sueldo))
                        {
                            fprintf(f, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
                            cantCargados++;
                        }
                    }
                }
                if(cantCargados == ll_len(pArrayListEmployee))
                {
                    todoOk = 1;
                }

            }
        }
        fclose(f);
    }
    return todoOk;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char respuesta = 'n';
    Employee* auxEmp;
    FILE* f = NULL;
    int cantCargados =0;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path, "rb");
        if(f != NULL)
        {
            if(!getLetra(&respuesta, INTENTOS, "Este archivo ya existe. Desea sobreescribirlo? ", "Error. "))
            {
                printf("Ha exedido el limite de intentos.\n");
                respuesta ='s';
            }
            fclose(f);
        }

        if(respuesta != 's')
        {
            f = fopen(path, "wb");
            if(f == NULL)
            {
                printf("No se pudo abrir el archivo.\n");
            }
            else
            {
                for(int i=0; i< ll_len(pArrayListEmployee); i++)
                {
                    auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
                    if(auxEmp != NULL)
                    {
                        if(fwrite(auxEmp, sizeof(Employee),1, f) == 1)
                        {
                            cantCargados++;
                        }

                    }
                }
                if(cantCargados == ll_len(pArrayListEmployee))
                {
                    todoOk = 1;
                }

            }
        }
        fclose(f);
    }
    return todoOk;
}

