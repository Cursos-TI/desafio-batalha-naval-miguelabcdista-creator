#include <stdio.h>

#define TAM 10
#define HABILIDADE 5
#define TAM_HAB 5

int main() {

    // Tabuleiro 10x10
    int tabuleiro[TAM][TAM];

    // Vetores que representam os navios
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};
    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};

    // Matrizes das habilidades
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas dos navios
    int linhaH = 2;
    int colunaH = 1;

    int linhaV = 5;
    int colunaV = 7;

    int linhaD1 = 0;
    int colunaD1 = 6;

    int linhaD2 = 7;
    int colunaD2 = 2;

    // Posiciona o navio horizontal
    if (colunaH + 2 < TAM) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaH][colunaH + i] == 0) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        }
    }

    // Posiciona o navio vertical
    if (linhaV + 2 < TAM) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaV + i][colunaV] == 0) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        }
    }

    // Posiciona o navio diagonal principal
    if (linhaD1 + 2 < TAM && colunaD1 + 2 < TAM) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] == 0) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = navioDiagonal1[i];
            }
        }
    }

    // Posiciona o navio diagonal secundária
    if (linhaD2 - 2 >= 0 && colunaD2 + 2 < TAM) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaD2 - i][colunaD2 + i] == 0) {
                tabuleiro[linhaD2 - i][colunaD2 + i] = navioDiagonal2[i];
            }
        }
    }

    // ==========================
    // CONSTRUÇÃO DAS HABILIDADES
    // ==========================

    // Inicializa todas as matrizes com 0
    for(i = 0; i < TAM_HAB; i++){
        for(j = 0; j < TAM_HAB; j++){
            cone[i][j] = 0;
            cruz[i][j] = 0;
            octaedro[i][j] = 0;
        }
    }

    // Cone
    for(i = 0; i < TAM_HAB; i++){
        for(j = 0; j < TAM_HAB; j++){
            if(j >= 2 - i && j <= 2 + i)
                cone[i][j] = 1;
        }
    }

    // Cruz
    for(i = 0; i < TAM_HAB; i++){
        for(j = 0; j < TAM_HAB; j++){
            if(i == 2 || j == 2)
                cruz[i][j] = 1;
        }
    }

    // Octaedro (Losango)
    for(i = 0; i < TAM_HAB; i++){
        for(j = 0; j < TAM_HAB; j++){
            if((i-2 >= 0 ? i-2 : 2-i) + (j-2 >= 0 ? j-2 : 2-j) <= 2)
                octaedro[i][j] = 1;
        }
    }

    // ==========================
    // POSIÇÃO DAS HABILIDADES
    // ==========================

    int origemConeLinha = 1;
    int origemConeColuna = 1;

    int origemCruzLinha = 5;
    int origemCruzColuna = 4;

    int origemOctLinha = 7;
    int origemOctColuna = 8;

    // Sobreposição do Cone
    for(i = 0; i < TAM_HAB; i++){
        for(j = 0; j < TAM_HAB; j++){

            int linha = origemConeLinha + (i - 2);
            int coluna = origemConeColuna + (j - 2);

            if(linha >= 0 && linha < TAM &&
               coluna >= 0 && coluna < TAM){

                if(cone[i][j] == 1 && tabuleiro[linha][coluna] == 0)
                    tabuleiro[linha][coluna] = HABILIDADE;
            }
        }
    }

    // Sobreposição da Cruz
    for(i = 0; i < TAM_HAB; i++){
        for(j = 0; j < TAM_HAB; j++){

            int linha = origemCruzLinha + (i - 2);
            int coluna = origemCruzColuna + (j - 2);

            if(linha >= 0 && linha < TAM &&
               coluna >= 0 && coluna < TAM){

                if(cruz[i][j] == 1 && tabuleiro[linha][coluna] == 0)
                    tabuleiro[linha][coluna] = HABILIDADE;
            }
        }
    }

    // Sobreposição do Octaedro
    for(i = 0; i < TAM_HAB; i++){
        for(j = 0; j < TAM_HAB; j++){

            int linha = origemOctLinha + (i - 2);
            int coluna = origemOctColuna + (j - 2);

            if(linha >= 0 && linha < TAM &&
               coluna >= 0 && coluna < TAM){

                if(octaedro[i][j] == 1 && tabuleiro[linha][coluna] == 0)
                    tabuleiro[linha][coluna] = HABILIDADE;
            }
        }
    }

    // ==========================
    // EXIBE O TABULEIRO
    // ==========================

    printf("TABULEIRO BATALHA NAVAL\n\n");

    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){

            if(tabuleiro[i][j] == 0)
                printf("~ ");
            else if(tabuleiro[i][j] == 3)
                printf("N ");
            else if(tabuleiro[i][j] == 5)
                printf("* ");

        }
        printf("\n");
    }

    return 0;
}