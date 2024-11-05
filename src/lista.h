#ifndef LISTA_H
#define LISTA_H

#include "frutas.h"

typedef struct Nodo {
    Fruta fruta;
    struct Nodo* prox;
} Nodo;

extern Nodo* cabeca;  // Ponteiro global para o início da lista

// Declarações das funções relacionadas à lista ligada
Nodo* criarNodo(Fruta fruta);
void adicionarNodo(Nodo* novoNodo);
Nodo* buscarNodo(int codigo);
void removerNodo(int codigo);

#endif // LISTA_H
