#include <stdio.h>
#include "vendas.h"
#include "lista.h"

void venderFruta() {
    int codigo, quantidade;
    printf("Digite o codigo da fruta: ");
    scanf("%d", &codigo);
    printf("Digite a quantidade a vender: ");
    scanf("%d", &quantidade);

    Nodo* nodo = buscarNodo(codigo);
    if (nodo != NULL) {
        if (nodo->fruta.quantidade < quantidade) {
            printf("Quantidade insuficiente em estoque.\n");
            return;
        }

        nodo->fruta.quantidade -= quantidade;
        registrarVenda(codigo, quantidade);
        printf("Venda realizada com sucesso!\n");
    } else {
        printf("Fruta com codigo %d nao encontrada.\n", codigo);
    }
}

void registrarVenda(int codigo, int quantidade) {
    FILE* arquivo = fopen("data/vendas.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de vendas.\n");
        return;
    }

    Nodo* nodo = buscarNodo(codigo);
    if (nodo != NULL) {
        fprintf(arquivo, "Codigo: %d, Nome: %s, Quantidade Vendida: %d\n",
                nodo->fruta.codigo, nodo->fruta.nome, quantidade);
    }

    fclose(arquivo);
}
