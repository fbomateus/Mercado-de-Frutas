#include <stdio.h>
#include "frutas.h"
#include "lista.h"
#include "vendas.h"

int main() {
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar fruta\n");
        printf("2. Listar frutas\n");
        printf("3. Buscar fruta\n");
        printf("4. Alterar fruta\n");
        printf("5. Excluir fruta\n");
        printf("6. Vender fruta\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarFruta(); break;
            case 2: listarFrutas(); break;
            case 3: buscarFruta(); break;
            case 4: alterarFruta(); break;
            case 5: excluirFruta(); break;
            case 6: venderFruta(); break;
            case 7: printf("Saindo...\n"); break;
            default: printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}
