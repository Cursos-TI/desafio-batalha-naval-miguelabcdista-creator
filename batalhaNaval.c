#include <stdio.h>

int main() {

    // Tabuleiro 10x10
    int tabuleiro[10][10];

    // Vetores que representam os navios
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};
    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};

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

    // Coordenadas do navio diagonal principal (\)
    int linhaD1 = 0;
    int colunaD1 = 6;

    // Coordenadas do navio diagonal secundária (/)
    int linhaD2 = 7;
    int colunaD2 = 2;

    // Posiciona o navio horizontal
    if (colunaH + 2 < 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaH][colunaH + i] == 0) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        }
    }

    // Posiciona o navio vertical
    if (linhaV + 2 < 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaV + i][colunaV] == 0) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        }
    }

    // Posiciona o navio diagonal principal (\)
    if (linhaD1 + 2 < 10 && colunaD1 + 2 < 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] == 0) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = navioDiagonal1[i];
            }
        }
    }

    // Posiciona o navio diagonal secundária (/)
    if (linhaD2 - 2 >= 0 && colunaD2 + 2 < 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaD2 - i][colunaD2 + i] == 0) {
                tabuleiro[linhaD2 - i][colunaD2 + i] = navioDiagonal2[i];
            }
        }
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