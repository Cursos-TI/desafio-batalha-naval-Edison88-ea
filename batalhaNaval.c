#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];
    int i, j;

    // Inicializa com zeros
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // posicionando primeiro navio horizontal
    int linhaNavio = 6;
    int colunaInicio = 6;
    int tamanhoNavio = 3;

    for( j = colunaInicio; j < colunaInicio + tamanhoNavio; j++ ){
        tabuleiro[linhaNavio][j] = 3; // adiciona o navio na horizontal ocupando três índices
    }

    // posicionando segundo navio vertical
    int colunaNavio1 = 2;
    int linhaInicio1 = 2;
    int tamanhoNavio1 = 4;

    for( i = linhaInicio1; i < linhaInicio1 + tamanhoNavio1; i++ ){
        tabuleiro[i][colunaNavio1] = 3; //adiciona o navio na vertical ocupando quatro índices
    }

    // Imprime o tabuleiro
    printf("~~~~~~~~~ BATALHA NAVAL ~~~~~~~~~\n");
    printf("\n");
    printf("   ");
    for (j = 0; j < 10; j++){
        printf(" %c ", linha[j]); // imprime a coluna das letras
    }
    printf("\n");
    
    for (i = 0; i < 10; i++) {
        printf("%2d ", i + 1); //Imprime número das linhas
        for (j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]); // imprime o tabuleiro
        }
        printf("\n");
    }

    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
