#include <stdio.h>


int main() {
   
    //declaração de variaveis
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];
    int i, j;

    // Inicializa com zeros
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // NAVIOS
    // Adiciona 2 navios na vertical (tamanho 3)
     for (i = 2; i <= 4; i++) {
        tabuleiro[i][3] = 3; //  coluna D, linhas 3-5
        tabuleiro[i][7] = 3; // coluna H, linhas 3-5
    }

    // Adiciona 2 navios na horizontal (tamanho 3)
    for (j = 1; j <= 3; j++) {
        tabuleiro[5][j] = 3; //  linha 6, colunas B-D
        tabuleiro[8][j] = 3; //  linha 9, colunas B-D
    }   


    // HABILIDADES
    // Aplica habilidade CONE 
     for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            // Verifica se está na área do cone
            if (i >= 1 && i <= 5 && j >= 1 && j <= 5) {
                if ((i == 1 && j == 3) ||                   // Topo do cone
                    (i == 2 && j >= 2 && j <= 4) ||         // Segunda linha
                    (i == 3 && j >= 1 && j <= 5)) {        // Terceira linha (mais larga)
                    tabuleiro[i][j] = 5;  // Marca área afetada
                }
            }
        }
    }

    // Aplica habilidade CRUZ 
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
        // Verifica se está na área da cruz
            if ((i >= 4 && i <= 8 && j == 6) ||  
                (i == 6 && j >= 4 && j <= 8)) {  
                    tabuleiro[i][j] = 6;  
            }
        }
    }
    // Aplica habilidade OCTAEDRO 
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            int dist = (i > 8 ? i - 8 : 8 - i) + (j > 2 ? j - 2 : 2 - j);
            if (dist <= 2) {
                tabuleiro[i][j] = 7;
}
        }    
    }
            
    
     // Imprime o tabuleiro
     printf("~~~~~~~~~ BATALHA NAVAL ~~~~~~~~~\n");
     printf("\n");
     printf("   ");
     for (j = 0; j < 10; j++) {
         printf(" %c ", linha[j]); // imprime a coluna das letras
     }
     printf("\n");
     
     for (i = 0; i < 10; i++) {
         printf("%2d ", i + 1); //Imprime número das linhas
         for (j = 0; j < 10; j++) {
             if (tabuleiro[i][j] == 0) {
                 printf(" 0 "); // Água
             }else if (tabuleiro[i][j] == 3) {
                printf(" 3 "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                 printf(" 1 "); // Área afetada por habilidade cone
             } else if (tabuleiro[i][j] == 6) {
                printf(" 2 "); // Área afetada por habilidade cruz
            }  else if (tabuleiro[i][j] == 7) {
                printf(" 4 "); // Área afetada por habilidade octaedro
            } 
         }
         printf("\n");
     }    


    return 0;
}
