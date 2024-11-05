#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frutas.h"
#include "lista.h"

void cadastrarFruta() {
    Fruta nova;
    printf("Digite o codigo da fruta: ");
    scanf("%d", &nova.codigo);

    if (buscarNodo(nova.codigo) != NULL) {
        printf("Codigo ja cadastrado. Tente novamente.\n");
        return;
    }

    printf("Digite o nome da fruta: ");
    scanf("%s", nova.nome);
    printf("Digite a quantidade da fruta: ");
    scanf("%d", &nova.quantidade);
    printf("Digite o preco da fruta: ");
    scanf("%f", &nova.preco);

    Nodo* novoNodo = criarNodo(nova);
    adicionarNodo(novoNodo);

    printf("Fruta cadastrada com sucesso!\n");
}

void listarFrutas() {
    Nodo* atual = cabeca;
    if (atual == NULL) {
        printf("Nenhuma fruta cadastrada.\n");
        return;
    }

    while (atual != NULL) {
        printf("Codigo: %d, Nome: %s, Quantidade: %d, Preco: %.2f\n",
               atual->fruta.codigo, atual->fruta.nome, atual->fruta.quantidade, atual->fruta.preco);
        atual = atual->prox;
    }
}

void buscarFruta() {
    int codigo;
    printf("Digite o codigo da fruta para buscar: ");
    scanf("%d", &codigo);

    Nodo* nodo = buscarNodo(codigo);
    if (nodo != NULL) {
        printf("Fruta encontrada!\n");
        printf("Codigo: %d, Nome: %s, Quantidade: %d, Preco: %.2f\n",
               nodo->fruta.codigo, nodo->fruta.nome, nodo->fruta.quantidade, nodo->fruta.preco);
    } else {
        printf("Fruta com codigo %d nao encontrada.\n", codigo);
    }
}

void alterarFruta() {
    int codigo;
    printf("Digite o codigo da fruta para alterar: ");
    scanf("%d", &codigo);

    Nodo* nodo = buscarNodo(codigo);
    if (nodo != NULL) {
        printf("Digite o novo nome da fruta: ");
        scanf("%s", nodo->fruta.nome);
        printf("Digite a nova quantidade: ");
        scanf("%d", &nodo->fruta.quantidade);
        printf("Digite o novo preco: ");
        scanf("%f", &nodo->fruta.preco);
        printf("Fruta alterada com sucesso!\n");
    } else {
        printf("Fruta com codigo %d nao encontrada.\n", codigo);
    }
}

void excluirFruta() {
    int codigo;
    printf("Digite o codigo da fruta para excluir: ");
    scanf("%d", &codigo);

    Nodo* nodo = buscarNodo(codigo);
    if (nodo != NULL) {
        if (nodo->fruta.quantidade > 0) {
            printf("Nao e possivel excluir. Quantidade em estoque ainda disponivel.\n");
            return;
        }

        removerNodo(codigo);
        printf("Fruta excluida com sucesso!\n");
    } else {
        printf("Fruta com codigo %d nao encontrada.\n", codigo);
    }
}
