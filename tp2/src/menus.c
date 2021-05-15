/*
 * menu.c
 *
 *  Created on: May 15, 2021
 *      Author: Leandro
 */

#include "menus.h"

void menu(void)
{
    //system("cls");
    printf("------- MENU -------\n");
    printf("1. ALTAS\n");
    printf("2. MODIFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. SALIR\n\n");
}

void menuInformes(void)
{
    //system("cls");
    printf("-------- MENU INFORMES --------\n");
    printf("1. Listar los empleados ordenados alfabeticamente por Apellido y Sector\n");
    printf("2. Mostrar total y promedio de los salarios, y cuantos empleados superan el salario promedio\n");
    printf("3. Salir\n\n");
}

void menuModificar()
{
    //system("cls");
    printf("------- Menu Modificar -------\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Sueldo\n");
    printf("4. Sector\n\n");
}

void menuSectors()
{
    printf("\n***** Listado de sectores *****\n");
    printf(" ID   Descripcion\n");
    printf("500   Sistemas\n");
    printf("501   Legales\n");
    printf("502   RRHH\n");
    printf("503   Comunicacion\n");
    printf("504   Ventas\n\n");
}

