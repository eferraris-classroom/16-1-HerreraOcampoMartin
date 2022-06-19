#include <stdio.h>
#include "Numeros.h"

int main() {

    ListaNumeros *lista = crearListaNumeros();

    agregarNumero(lista, crearNumero(12000));
    agregarNumero(lista, crearNumero(432));
    agregarNumero(lista, crearNumero(6456));
    agregarNumero(lista, crearNumero(234));
    agregarNumero(lista, crearNumero(-3));
    agregarNumero(lista, crearNumero(34));
    agregarNumero(lista, crearNumero(534));
    agregarNumero(lista, crearNumero(-756));

    imprimirNumeros(lista);

    Numero *busqueda = buscarNumero(lista, -33);
    if(busqueda == NULL){
        printf("No se encontró el valor.\n");
    }else {
        printf("Se encontró el número %d en la lista.\n", busqueda->valor);
    }

    liberarNumeros(lista);

    return 0;
}
