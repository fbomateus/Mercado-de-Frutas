#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Nodo* cabeca = NULL;

Nodo* criarNodo(Fruta fruta) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (novoNodo == NULL) {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    novoNodo->fruta = fruta;
    novoNodo->prox = NULL;
    return novoNodo;
}

void adicionarNodo(Nodo* novoNodo) {
    novoNodo->prox = cabeca;
    cabeca = novoNodo;
}

Nodo* buscarNodo(int codigo) {
    Nodo* atual = cabeca;
    while (atual != NULL) {
        if (atual->fruta.codigo == codigo) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void removerNodo(int codigo) {
    Nodo* atual = cabeca;
    Nodo* anterior = NULL;

    while (atual != NULL && atual->fruta.codigo != codigo) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        return;
    }

    if (anterior == NULL) {
        cabeca = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
}
