/*
 * leanmlib.h
 *
 *  Created on: 13 abr. 2021
 *      Author: Leandro
 */

#ifndef LEANMLIB_H_
#define LEANMLIB_H_

/** \brief muestra el menu
 *
 * \param x int primer numero ingresado
 * \param y int segundo numero ingresado
 * \param fNum1 int flag del primer numero
 * \param fNum2 int flag del segundo numero
 * \return void
 *
 */
void menu(int x, int y, int fNum1, int fNum2);


/** \brief Ingreso de un numero
 *
 * \param pResultado int* direccion donde se guarda el numero
 * \param min int numero minimo que se puede ingresar
 * \param max int numero maximo que se puede ingresar
 * \param textoIngreso[] char texto que pide el numero
 * \param textoError[] char texto por si hay un error
 * \param x int varibale auxiliar para utilizar en los textos
 * \return int devuelve 1 si se pudo hacer la funcion o 0 si no.
 *
 */
int ingresoNumero(int *pResultado, int min, int max, char textoIngreso[], char textoError[], int x);


/** \brief suma dos numeros enteros
 *
 * \param a int primer numero
 * \param b int segundo numero
 * \return int devuelve el resutado de la suma
 *
 */
int suma(int a, int b);


/** \brief resta dos numeros enteros
 *
 * \param a int primero numero
 * \param b int segundo numero
 * \return int devuelve el resultado de la resta
 *
 */
int resta(int a, int b);


/** \brief multiplica dos numeros enteros
 *
 * \param a int primer numero
 * \param b int segundo numero
 * \return int devuelve el resultado de la multiplicacion
 *
 */
int multiplicacion(int a, int b);


/** \brief divide dos numeros enteros
 *
 * \param dividendo int es el dividendo de la cuenta
 * \param divisor int es el divisor de la cuenta
 * \param pResultado float* direccion de memoria donde se guarda el resultado
 * \return int devuelve 1 si pudo hacer la division o 0 si no pudo
 *
 */
int division(int dividendo, int divisor, float *pResultado);


//int factorial(int a);
/** \brief realiza el factorial de un numero entero menor a 13
 *
 * \param n int numero que al cual se le quiere calcular el factorial
 * \return int devulve el resultado del factorial
 *
 */
int factorialRecursivo(int n);


/** \brief activa un flag
 *
 * \param x int* direccion de memoria del flag a activar
 * \return void
 *
 */
void activarFlag(int *x); // tarea


/** \brief resetea un flag
 *
 * \param x int* direccion de memoria del flag a resetear
 * \return void
 *
 */
void resetFlag(int *x);



#endif /* LEANMLIB_H_ */
