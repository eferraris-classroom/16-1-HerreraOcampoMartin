#include "Numeros.h"
#include <stdlib.h>
#include <stdio.h>

ListaNumeros *crearListaNumeros(){
    ListaNumeros *lista = (ListaNumeros*) malloc(sizeof (ListaNumeros));

    if(lista == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    lista->tam = 0;
    lista->primero = NULL;

    return lista;
}

Numero *crearNumero(int valor){

    Numero *num = (Numero*) malloc(sizeof (Numero));

    if(num == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    num->siguiente = NULL;
    num->valor = valor;

    return num;
}

void agregarNumero(ListaNumeros *lista, Numero *nuevo){
    nuevo->siguiente = lista->primero;
    lista->primero = nuevo;
    lista->tam++;
}

Numero *mirarSiguienteNumero(Numero *aux, int valor){
    if(aux == NULL){
        return NULL;
    }

    if(aux->valor == valor){
        return aux;
    }
    return mirarSiguienteNumero(aux->siguiente, valor);
}

Numero *buscarNumero(ListaNumeros *lista, int valor){
    Numero *aux = lista->primero;

    if(aux == NULL){
        printf("La lista está vacía, no se encuentra el valor.\n");
        return NULL;
    }

    Numero *res = mirarSiguienteNumero(aux, valor);
    return res;
}

void imprimirNumeros(ListaNumeros *lista){
    Numero *aux = lista->primero;

    if(aux == NULL){
        printf("La lista está vacía.\n");
        return;
    }

    for (; aux != NULL; aux = aux->siguiente){
        printf("%d ", aux->valor);
    }

    printf("\n");
}

void liberarNumeros(ListaNumeros *lista){
    Numero *aux = lista->primero;

    if(aux != NULL){
        while(aux->siguiente != NULL){
            Numero *ant = aux;
            aux = aux->siguiente;
            free(ant);
        }

        free(aux);
    }

    free(lista);
}

