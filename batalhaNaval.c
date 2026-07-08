#include <stdio.h>

int main() {

    // Tabuleiro 10x10
    int tabuleiro[10][10];

    // Vetores que representam os navios
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas do navio horizontal
    int linhaH = 2;
    int colunaH = 1;

    // Coordenadas do navio vertical
    int linhaV = 5;
    int colunaV = 7;

    // Posiciona o navio horizontal
    for (i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // Posiciona o navio vertical
    for (i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // Exibe o tabuleiro
    printf("TABULEIRO BATALHA NAVAL\n\n");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}