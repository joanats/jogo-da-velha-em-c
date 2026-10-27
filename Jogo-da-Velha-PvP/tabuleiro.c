#include <stdio.h>
#include "tabuleiro.h"


void Tabuleiro_inicializa(Tabuleiro *t)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            t->M[i][j] = 0;
        }
    }
}


void Tabuleiro_desenha(Tabuleiro *t)
{
    printf("\n=== JOGO DA VELHA ===\n\n");
    printf("    0   1   2\n");

    for (int i = 0; i < 3; i++)
    {
        printf("%d ", i);

        for (int j = 0; j < 3; j++)
        {
            char simbolo = ' ';

            if (t->M[i][j] == 1)
            {
                simbolo = 'O';
            }

            else if (t->M[i][j] == 4)
            {
                simbolo = 'X';
            }

            printf(" %c ", simbolo);

            if (j < 2)
            {
                printf("|");
            }
        }

        printf("\n");

        if (i < 2)
        {
            printf("  ---|---|---\n");
        }
    }

    printf("\n");
}


int Tabuleiro_temVencedor(Tabuleiro *t)
{
    int soma;

    for (int i = 0; i < 3; i++)
    {
        soma = t->M[i][0] + t->M[i][1] + t->M[i][2];

        if (soma == 3)
        {
            return 1; 
        }

        if (soma == 12)
        {
            return 4; 
        }
    }


    for (int j = 0; j < 3; j++)
    {
        soma = t->M[0][j] + t->M[1][j] + t->M[2][j];

        if (soma == 3)
        {
            return 1; 
        }

        if (soma == 12)
        {
            return 4; 
        }
    }


    soma = t->M[0][0] + t->M[1][1] + t->M[2][2];

    if (soma == 3)
    {
        return 1;
    }

    if (soma == 12)
    {
        return 4;
    }


    soma = t->M[0][2] + t->M[1][1] + t->M[2][0];

    if (soma == 3)
    {
        return 1;
    }

    if (soma == 12)
    {
        return 4;
    }


    return 0;
}


void Tabuleiro_marcaJogada(Tabuleiro *t, int x, int y, int tipo)
{
    t->M[x][y] = tipo;
}