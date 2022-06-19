#ifndef INC_16_1_HERRERAOCAMPOMARTIN_NUMEROS_H
#define INC_16_1_HERRERAOCAMPOMARTIN_NUMEROS_H

typedef struct numero {
    int valor;
    struct numero *siguiente;
} Numero;

typedef struct listaNumeros{
    int tam;
    Numero *primero;
} ListaNumeros;

ListaNumeros *crearListaNumeros();
Numero *crearNumero(int valor);
Numero *buscarNumero(ListaNumeros *lista, int valor);
void agregarNumero(ListaNumeros *lista, Numero *nuevo);
void imprimirNumeros(ListaNumeros *lista);
void liberarNumeros(ListaNumeros *lista);

#endif
