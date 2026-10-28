#include <stdio.h>
#include "jogador.h"

void JogadorTeclado_joga(JogadorTeclado *j, Tabuleiro *t)
{
    int linha, coluna;
    char simbolo;

    if (j->tipo == 4) {
        simbolo = 'X';
    }
    else {
        simbolo = 'O';
    }

    while (1) {

        printf("Jogador %c, digite a linha e coluna: ", simbolo);
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            printf("Posicao invalida!\n");
        }

        else if (t->M[linha][coluna] != 0) {
            printf("Casa ocupada!\n");
        }

        else {
            Tabuleiro_marcaJogada(t, linha, coluna, j->tipo);
            break;
        }
    }
}