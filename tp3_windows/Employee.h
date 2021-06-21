
#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crea un nuevo empleado en la memoria dinamica, y lo inicializa en 0 o ""
 *
 * \return Employee* devuelve la direccion del empleado
 *
 */
Employee* employee_new();

/** \brief Crea un nuevo empleado en la memoria dinamica, y lo inicializa con los parametros pasados
 *
 * \param idStr char* id como cadena de texto
 * \param nombreStr char* nombre
 * \param horasTrabajadasStr char* horas trabajadas como cadena de texto
 * \param sueldoStr char* sueldo como cadena de texto
 * \return Employee* devuelve la direccion del empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief elimina al empleado, hace el free()
 *
 * \param this Employee* direccion del empleado a eliminar
 * \return void
 *
 */
void employee_delete(Employee* this);

/** \brief setea en un empleado el id
 *
 * \param this Employee* direccion del empleado que se le quiere setear
 * \param id int id a setearle
 * \return int retorna 1 si esta todo bien o 0 si hubo un problema
 *
 */
int employee_setId(Employee* this,int id);

/** \brief obtiene de un empleado el id
 *
 * \param this Employee* direccion del empleado que se le quiere setear
 * \param id int* direccion de memoria donde se devuelve el id
 * \return int retorna 1 si esta todo bien o 0 si hubo un problema
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief setea en un empleado el nombre
 *
 * \param this Employee* direccion del empleado que se le quiere setear
 * \param nombre char* nombre a setear
 * \return int retorna 1 si esta todo bien o 0 si hubo un problemat
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief obtiene de un empleado el nombre
 *
 * \param this Employee* direccion del empleado que se le quiere setear
 * \param nombre char* variable donde nos va a devolver el nombre
 * \return int retorna 1 si esta todo bien o 0 si hubo un problema
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief setea en un empleado las horas trabajadas
 *
 * \param this Employee* direccion del empleado que se le quiere setear
 * \param horasTrabajadas int horas a setear
 * \return int retorna 1 si esta todo bien o 0 si hubo un problema
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief obtiene de un empleado las horas trabajadas
 *
 * \param this Employee* direccion del empleado que se le quiere setear
 * \param horasTrabajadas int* direccion de memoria donde se devuelve las horas
 * \return int retorna 1 si esta todo bien o 0 si hubo un problema
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief setea en un empleado el sueldo
 *
 * \param this Employee* direccion del empleado que se le quiere setear
 * \param sueldo int sueldo a setear
 * \return int retorna 1 si esta todo bien o 0 si hubo un problema
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief obtiene de un empleado el sueldo
 *
 * \param this Employee* direccion del empleado que se le quiere setear
 * \param sueldo int* direccion de memoria donde se devuelve  el sueldo
 * \return int retorna 1 si esta todo bien o 0 si hubo un problema
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief busca el mayor id de la lista de empleados y lo devuelve
 *
 * \param lista LinkedList* puntero a la lista de empleados
 * \param id int* direccion de memoria donde nos devuelve el id
 * \return int retorna 1 si esta todo bien o 0 si hubo un problema
 *
 */
int employee_buscarMayorId(LinkedList* lista, int* id);
#endif // employee_H_INCLUDED
