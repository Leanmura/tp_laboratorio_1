/*
 * ArrayEmployees.h
 *
 *  Created on: May 15, 2021
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_lean.h"
#include "inputs_lean.h"
#include "menus.h"

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

#endif /* ARRAYEMPLOYEES_H_ */


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee *list, int len);

/** \brief busca si hay un lugar vacio en el array de empleados
 *
 * \param list Employee* array de empleados
 * \param len int tamanio del array de empleados
 * \return int  Devuelve -1 si hay error (No hay lugar, tamanio invalido o un puntero NULL) o sino devuelve el indice del primer lugar vacio
 *
 */
int findEmpty(Employee *list, int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list Employee* array de empleados
 * \param len int tamanio del array de empleados
 * \param id int id assigned to then employee
 * \param name[] char name of the employee
 * \param lastName[] char lastname of the employee
 * \param salary float salary of the employee
 * \param sector int sector of the employeee
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addEmployee(Employee *list, int len, int id, char name[], char lastName[], float salary, int sector);

/** \brief Pide al usuario el nombre, apellido, salario y sector del empleado.
 *
 * \param name[] char array donde se guarda el nombre
 * \param lastName[] char array donde se guarda el apellido
 * \param salary float* puntero a la variable donde se guarda el salario
 * \param sector int* puntero a la variable donde se guarda el sector
 * \param nextId int proximo id libre
 * \return int Retorna 0 si hay algun error (tamanio invalido o un puntero NULL) o 1 si esta todo ok
 *
 */
int getEmployee(char name[], char lastName[], float *salary, int *sector, int nextId);

/** \brief print the content of employees array
 *
 * \param list Employee* Pointer to array of employees
 * \param length int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printEmployees(Employee *list, int length);

/** \brief muestra los datos de un empleado
 *
 * \param emp Employee datos de un empleado
 * \return void
 *
 */
void printEmployee(Employee emp);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee* Pointer to array of employees
 * \param length int Array length
 * \param id int id the user is searching for
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee *list, int len, int id);

/** \brief modifica el nombre, apellido, salario o sector de un empleado
 *
 * \param lista[] Employee array de empleados
 * \param tam int tamanio del array de empleados
 * \return int devuelve 1 si esta todo ok, 0 si hay algun error(tamanio invalido o un puntero NULL)
 *
 */
int modificarEmpleado(Employee lista[], int tam);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee* Pointer to array of employees
 * \param length int Array length
 * \param id int id the user want to remove
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee *list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee *list, int len, int order);
