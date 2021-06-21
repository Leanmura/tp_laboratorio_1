#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).

 * \param path char* archivo de donde se obitiene los datos
 * \param pArrayListEmployee LinkedList* puntero a la lista de empleados
 * \return int devuelve 1 si esta todo bien o 0 si hubo algun problema
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* archivo de donde se obitiene los datos
 * \param pArrayListEmployee LinkedList* puntero a la lista de empleados
 * \return int devuelve 1 si esta todo bien o 0 si hubo algun problema
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif // PARSER_H_INCLUDED
