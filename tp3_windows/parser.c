#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk =0;
    int cant;
    char buffer[4][20];
    Employee* newEmployee;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%s", buffer[0], buffer[1], buffer[2], buffer[3]); // guardarlo en una matriz
            if(cant == 4)
            {
                newEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                if(newEmployee != NULL)
                {
                    ll_add(pArrayListEmployee, newEmployee);
                    todoOk=1;
                }
              else
                {
                    employee_delete(newEmployee);
                }
            }
        }
    }
    return todoOk;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk =0;

    Employee* newEmployee = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            newEmployee = employee_new();
            if(newEmployee != NULL)
            {
                if(fread(newEmployee, sizeof(Employee),1, pFile) == 1)
                {
                    ll_add(pArrayListEmployee, newEmployee);
                    todoOk=1;
                }
              else
                {
                    employee_delete(newEmployee);
                }
            }
        }
    }
    return todoOk;
}
