#ifndef FRUTAS_H
#define FRUTAS_H

typedef struct {
    int codigo;        // Código único para identificar a fruta
    char nome[50];     // Nome da fruta
    int quantidade;    // Quantidade disponível no estoque
    float preco;       // Preço unitário da fruta
} Fruta;

// Declarações das funções relacionadas às frutas
void cadastrarFruta();
void listarFrutas();
void buscarFruta();
void alterarFruta();
void excluirFruta();

#endif // FRUTAS_H
