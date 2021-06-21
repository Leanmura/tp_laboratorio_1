#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
Employee* employee_new()
{
    Employee* newEmployee =(Employee*)malloc(sizeof(Employee));
    if(newEmployee!=NULL)
    {
        newEmployee->id = 0;
        strcpy(newEmployee->nombre, "");
        newEmployee->horasTrabajadas = 0;
        newEmployee->sueldo = 0;
    }
    return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* newEmployee = employee_new();

    if(newEmployee!=NULL)
    {
        if(!(employee_setId(newEmployee, atoi(idStr)) &&
           employee_setNombre(newEmployee, nombreStr) &&
           employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr)) &&
           employee_setSueldo(newEmployee, atoi(sueldoStr))))
        {
            employee_delete(newEmployee);
            newEmployee = NULL;
        }
    }
    return newEmployee;
}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)
{
    int todoOk =0;
    if(this!=NULL && id > 0)
    {
        this->id = id;
        todoOk=1;
    }
    return todoOk;
}
int employee_getId(Employee* this,int* id)
{
    int todoOk =0;
    if(this != NULL)
    {
        *id = this->id;
        todoOk =1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk =0;
    if(this != NULL && nombre != NULL && strlen(nombre)<128 && strlen(nombre)>1)
    {
        strcpy(this->nombre, nombre);
        todoOk=1;
    }
    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk =0;
    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk =1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;
    if(this!= NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk =0;
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk =1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk =0;
    if(this!= NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk=1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk =0;
    if(this!= NULL)
    {
        *sueldo = this->sueldo;
        todoOk=1;
    }
    return todoOk;
}

int employee_buscarMayorId(LinkedList* lista, int* id)
{
    int todoOk =0;
    Employee* auxEmp = NULL;
    int mayor=0;
    if(lista!= NULL)
    {
        for(int i=0; i< ll_len(lista); i++)
        {
            auxEmp = (Employee*) ll_get(lista, i);
            if(auxEmp != NULL && (i == 0 || auxEmp->id > mayor))
            {
                mayor = auxEmp->id;
            }
        }
        *id = mayor + 1;
        todoOk = 1;
    }
    return todoOk;
}



