/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

typedef struct
{
    int id;
    char descripcion[20];
    char marca[20];
    float precio;
} eCelular;

void mostrarCelular(eCelular* celu);

void mostrarCelulares(LinkedList* list);

int ordernarPrecio(void* c1, void* c2);

int main(void)
{
    eCelular* celular = NULL;
    LinkedList* celulares = NULL;
    LinkedList* celularesClone = NULL;
    LinkedList* celularesSubList = NULL;
    int indice;

    /* Creo una linkedlist con la funcion ll_newLinkedList()*/
    printf("--- Creo una linkedlist con la funcion ll_newLinkedList() ---\n");
    celulares = ll_newLinkedList();
    if(celulares != NULL)
    {
        printf("Linked list de celulares creada.\n\n");
    }
    else
    {
        exit(1);
    }

    /* Pido espacio en memoria para una estructura eCelular*/
    celular = (eCelular*)malloc(sizeof(eCelular));
    if(celular != NULL) // si me pudo asignar una direccion de memoria, hardcodeo un celular
    {
        celular->id = 1000;
        strcpy(celular->descripcion, "MI 9T");
        strcpy(celular->marca, "Xiaomi");
        celular->precio = 21999;
    }

    /* Añado un celular al linked list, con la funcion ll_add()*/
    printf("--- Aniado un celular al linked list, con la funcion ll_add() ---\n");
    if(ll_add(celulares, celular) == 0)
    {
        printf("Celular aniadido.\n");
    }

    /* creo otro celular y lo añado a la linked list*/
    celular = (eCelular*)malloc(sizeof(eCelular));
    if(celular != NULL)
    {
        celular->id = 1001;
        strcpy(celular->descripcion, "Galaxy S8");
        strcpy(celular->marca, "Samsung");
        celular->precio = 32000;
    }
    if(ll_add(celulares, celular) == 0)
    {
        printf("Celular aniadido.\n\n");
    }

    /* muestro todos los elementos de la linked list*/
    mostrarCelulares(celulares);
    printf("\n");

    /* muestro el tamanio del linkedlist con ll_len()*/
    printf("--- Muestro el tamanio del linkedlist con ll_len() ---\n");
    printf("Tamanio del Linked list: %d\n\n",ll_len(celulares));

    /* Creo un celular y lo añado al linked list en el indice 1 (entre el xiaomi y el samsung), con la funcion ll_push()*/
    printf("--- Creo un celular y lo aniado al linkedList en el indice 1 (entre el xiaomi y el samsung),con la funcion ll_push() ---");
    celular = (eCelular*)malloc(sizeof(eCelular));
    if(celular != NULL)
    {
        celular->id = 1002;
        strcpy(celular->descripcion, "Moto G8");
        strcpy(celular->marca, "Motorola");
        celular->precio = 24000;
    }
    if(ll_push(celulares, 1, celular) ==0)
    {
        printf("Se aniadio correctamente en el indice 1.\n");
    }
    mostrarCelulares(celulares);
    printf("\n");

    /* reemplazo/modifico el celular que esta en el indice 0 con la funcion ll_set()*/
    printf("--- Reemplazo/modifico el celular que esta en el indice 0 con la funcion ll_set() ---\n");
    celular = (eCelular*)malloc(sizeof(eCelular));
    if(celular != NULL)
    {
        celular->id = 1003;
        strcpy(celular->descripcion, "Redmi 8");
        strcpy(celular->marca, "Xiaomi");
        celular->precio = 25000;
    }
    if(ll_set(celulares, 0, celular) ==0)
    {
        printf("Se reemplazo correctamente en el indice 0.\n");
    }
    mostrarCelulares(celulares);
    printf("\n");

    /* Hago una copia de la lista de celulares con ll_clone() */
    printf("--- Hago una copia de la lista de celulares con ll_clone() y la muestro---\n");
    celularesClone = ll_clone(celulares);
    if(celularesClone != NULL)
    {
        printf("Se creo la copia de celulares correctamente\n");
        mostrarCelulares(celularesClone);
        printf("\n");
    }

    /* Ordeno los elementos de la lista por su precio en forma descendente, con la funcion ll_sort()*/
    printf("--- Ordeno los elementos de la lista por su precio en forma descendente ---\n");
    if(ll_sort(celulares,ordernarPrecio,1) != -1)
    {
        printf("Ordenados con exito.\n");
        mostrarCelulares(celulares);
        printf("\n");
    }

    /* Verifico que todos los elementos de la lista de celulares esten en la lista copiada ll_containsAll()*/
    printf("-- Verifico que todos los elementos de la lista de celulares esten en la lista copiada ll_containsAll() ---\n");
    if(ll_containsAll(celularesClone, celulares))
    {
        printf("Todos los elementos de la lista de celulares estan en la lista de celulares copiada.\n\n");
    }

    /* Elimino el celular que esta en el indice 0 de la lista de celulares con la funcion ll_remove(). */
    printf("--- Elimino el celular que esta en el indice 0 de la lista de celulares con la funcion ll_remove(). ---\n");
    if(ll_remove(celulares, 0) == 0)
    {
        printf("Se elimino el celular del indice 0 correctamente.\n");
    }
    mostrarCelulares(celulares);
    printf("\n");

    /* busco el indice en el que se encuentra el Redmi 8 con la funcion ll_indexOf() */
    printf("--- Busco el indice en el que se encuentra el Redmi 8 con la funcion ll_indexOf() ---\n");
    indice = ll_indexOf(celulares, celular);
    if(indice != -1)
    {
       printf("Indice del celular buscado: %d\n\n", indice );
    }
    else
    {
        printf("No se encontro el celular.\n\n");
    }

    /* Creo una sublista con los elementos del 1 al 2 inclusive de la lista copiada con la funcion ll_subList*/
    printf("--- Creo una sublista con los elementos del 1 al 2 inclusive de la lista copiada ---\n");
    celularesSubList= ll_subList(celularesClone,1,3);
    if(celularesSubList != NULL)
    {
        printf("Se creo una sublista con los elementos del 1 al 2 inclusive.\n");
        mostrarCelulares(celularesSubList);
        printf("\n");
    }

    /* copio la direccion de memoria del elemento en e indice 2 de la lista clon (galaxy S8) y lo elimino, con la funcion ll_pop()*/
    printf("--- Copio la direccion de memoria del elemento en el indice 2 de la lista clon y lo elimino ---\n");
    celular = ll_pop(celularesClone, 2);
    if(celular != NULL)
    {
        printf("Se elimino y copio correctamente el elemento en el indice 2.\n\n");
    }

    /* Me fijo si el celular eliminado sigue estando en la lista, con la funcion ll_contains()*/
    printf("--- Me fijo si el celular eliminado sigue estando en la lista ---\n");
    if(ll_contains(celularesClone, celular) == 0)
    {
        printf("Este celular no se encuentra en la lista.\n\n");
    }
    mostrarCelulares(celularesClone);
    printf("\n");

    /* Elimino todos los elementos de la lista clon, con la funcion ll_clear()*/
    printf("--- Elimino todos los elementos de la lista clon, y muestro la lista vacia ---\n");
    if(ll_clear(celularesClone) !=-1)
    {
        printf("Lista limpiada con exito.\n");
        mostrarCelulares(celularesClone);
        printf("\n");
    }

    /* Elimino la linked list de celulares con la funcion ll_deleteLinkedList()*/
    printf("--- Elimino la linked list de celulares con la funcion ll_deleteLinkedList() ---\n");
    if(ll_deleteLinkedList(celulares) != -1)
    {
        celulares = NULL;
        printf("Lista de celulares eliminada con exito.\n\n");
    }
    // startTesting(1);  // ll_newLinkedList
    //startTesting(2);  // ll_len
    //startTesting(3);  // getNode - test_getNode
    // startTesting(4);  // addNode - test_addNode
    //startTesting(5);  // ll_add
    //  startTesting(6);  // ll_get
    // startTesting(7);  // ll_set
    //startTesting(8);  // ll_remove
    //startTesting(9);  // ll_clear
    //  startTesting(10); // ll_deleteLinkedList
    //startTesting(11); // ll_indexOf
    //startTesting(12); // ll_isEmpty
    // startTesting(13); // ll_push
    //startTesting(14); // ll_pop
    // startTesting(15); // ll_contains
    //startTesting(16); // ll_containsAll
    //startTesting(17); // ll_subList
    //startTesting(18); // ll_clone
    //startTesting(19); // ll_sort */

    return 0;
}


void mostrarCelular(eCelular* celu)
{
    if(celu!= NULL)
    {
        printf("%d  %-10s  %-8s %.2f\n", celu->id, celu->descripcion, celu->marca, celu->precio);
    }
}

void mostrarCelulares(LinkedList* list)
{
    int tam;
    if(list != NULL)
    {
        tam = ll_len(list);
        printf(" ID  DESCRIPCION  MARCA    PRECIO\n");
        for(int i=0; i<tam; i++)
        {
            mostrarCelular((eCelular*)ll_get(list, i)); // tomo con ll_get(), el celular de la lista, que este en el indice i y se lo paso a mostrar celular()
        }
    }
}

int ordernarPrecio(void* c1, void* c2)
{
    int retorno = -1;
    if(c1 != NULL && c2 != NULL)
    {
        if(((eCelular*)c1)->precio < ((eCelular*)c2)->precio)
        {
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}





























