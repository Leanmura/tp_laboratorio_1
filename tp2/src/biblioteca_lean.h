/*
 * biblioteca_lean.h
 *
 *  Created on: May 15, 2021
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef BIBLIOTECA_LEAN_H_
#define BIBLIOTECA_LEAN_H_


#endif /* BIBLIOTECA_LEAN_H_ */


/** \brief formatea un sustantivo propio ("Leandro")
 *
 * \param sustP[] char sustantivo a formatear
 * \return int devuelve 1 si esta todo ok, 0 si algo salio mal
 *
 */
int formatSustP(char sustP[]);


/** \brief formatea un comun ("vaso")
 *
 * \param sustC[] char sustantivo a fomatear
 * \return int devuelve 1 si esta todo ok, 0 si algo salio mal
 *
 */
int formatSustC(char sustC[]);
