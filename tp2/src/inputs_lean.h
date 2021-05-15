/*
 * inputs_lean.h
 *
 *  Created on: May 15, 2021
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef INPUTS_LEAN_H_
#define INPUTS_LEAN_H_



#endif /* INPUTS_LEAN_H_ */

/** \brief pide un numero entero al usuario y lo valida, dandole x cantidad de intetos
 *
 * \param pResultado int* puntero a la variable donde vamos a devolver el numero ingresado por el usuario
 * \param minimo int numero minimo que puede ingresar el usuario
 * \param maximo int numero maximo que puede ingresar el usuario
 * \param intentos int intentos totales que puede realizar el usuario para que el numero sea valido
 * \param mensaje[] char mensaje que pide el numero al usuario
 * \param mensajeError[] char mensaje que avisa al usuario si el numero no es valido.
 * \return int retorna 1 si salio todo bien, 0 si hubo un problema
 *
 */
int getInt(int *pResultado, int minimo, int maximo, int intentos, char mensaje[], char mensajeError[]);

/** \brief pide un numero flotante(con coma) al usuario y lo valida, dandole x cantidad de intetos
 *
 * \param pResultado float* puntero a la variable donde vamos a devolver el numero ingresado por el usuario
 * \param minimo float numero minimo que puede ingresar el usuario
 * \param maximo float numero maximo que puede ingresar el usuario
 * \param intentos int intentos totales que puede realizar el usuario para que el numero sea valido
 * \param mensaje[] char mensaje que pide el numero al usuario
 * \param mensajeError[] char mensaje que avisa al usuario si el numero no es valido.
 * \return int retorna 1 si salio todo bien, 0 si hubo un problema
 *
 */
int getFloat(float *pResultado, float minimo, float maximo, int intentos, char mensaje[], char mensajeError[]);

    /** \brief pide una o varias palabras, corroborando que no sea mayor al largo de la variable, dandole x cantidad de intetos
 *
 * \param cadena[] char variable donde vamos a devolver la cadena ingresada por el usuario
 * \param len int tamanio de la variable cadena[]
 * \param intentos int intentos totales que puede realizar el usuario para que el numero sea valido
 * \param mensaje[] char mensaje que pide el numero al usuario
 * \param mensajeError[] char mensaje que avisa al usuario si el numero no es valido.
 * \return int retorna 1 si salio todo bien, 0 si hubo un problema
 *
 */
int getString(char cadena[], int len, int intentos, char mensaje[], char mensajeError[]);
