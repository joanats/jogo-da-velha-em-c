#include <stdio.h>
#include "jogadorIA.h"
#include <unistd.h>

void JogadorIA_joga(JogadorIA *j, Tabuleiro *t)
{
    printf("IA Pensando...\n");
    sleep(2);

    int oponente = 4;

    // regra 1

    for(int i = 0; i < 3; i++) 
    {
        if(t->M[i][0] == j->tipo && t->M[i][1] == j->tipo && t->M[i][2] == 0) { Tabuleiro_marcaJogada(t, i, 2, j->tipo); return; }
        if(t->M[i][0] == j->tipo && t->M[i][2] == j->tipo && t->M[i][1] == 0) { Tabuleiro_marcaJogada(t, i, 1, j->tipo); return; }
        if(t->M[i][1] == j->tipo && t->M[i][2] == j->tipo && t->M[i][0] == 0) { Tabuleiro_marcaJogada(t, i, 0, j->tipo); return; }

        if(t->M[i][0] == oponente && t->M[i][1] == oponente && t->M[i][2] == 0) { Tabuleiro_marcaJogada(t, i, 2, j->tipo); return; }
        if(t->M[i][0] == oponente && t->M[i][2] == oponente && t->M[i][1] == 0) { Tabuleiro_marcaJogada(t, i, 1, j->tipo); return; }
        if(t->M[i][1] == oponente && t->M[i][2] == oponente && t->M[i][0] == 0) { Tabuleiro_marcaJogada(t, i, 0, j->tipo); return; }
    }

    for(int i = 0; i < 3; i++) 
    {
        if(t->M[0][i] == j->tipo && t->M[1][i] == j->tipo && t->M[2][i] == 0) { Tabuleiro_marcaJogada(t, 2, i, j->tipo); return; }
        if(t->M[0][i] == j->tipo && t->M[2][i] == j->tipo && t->M[1][i] == 0) { Tabuleiro_marcaJogada(t, 1, i, j->tipo); return; }
        if(t->M[1][i] == j->tipo && t->M[2][i] == j->tipo && t->M[0][i] == 0) { Tabuleiro_marcaJogada(t, 0, i, j->tipo); return; }

        if(t->M[0][i] == oponente && t->M[1][i] == oponente && t->M[2][i] == 0) { Tabuleiro_marcaJogada(t, 2, i, j->tipo); return; }
        if(t->M[0][i] == oponente && t->M[2][i] == oponente && t->M[1][i] == 0) { Tabuleiro_marcaJogada(t, 1, i, j->tipo); return; }
        if(t->M[1][i] == oponente && t->M[2][i] == oponente && t->M[0][i] == 0) { Tabuleiro_marcaJogada(t, 0, i, j->tipo); return; }
    }

    if(t->M[0][0] == j->tipo && t->M[1][1] == j->tipo && t->M[2][2] == 0) { Tabuleiro_marcaJogada(t, 2, 2, j->tipo); return; }
    if(t->M[0][0] == j->tipo && t->M[2][2] == j->tipo && t->M[1][1] == 0) { Tabuleiro_marcaJogada(t, 1, 1, j->tipo); return; }
    if(t->M[1][1] == j->tipo && t->M[2][2] == j->tipo && t->M[0][0] == 0) { Tabuleiro_marcaJogada(t, 0, 0, j->tipo); return; }

    if(t->M[0][0] == oponente && t->M[1][1] == oponente && t->M[2][2] == 0) { Tabuleiro_marcaJogada(t, 2, 2, j->tipo); return; }
    if(t->M[0][0] == oponente && t->M[2][2] == oponente && t->M[1][1] == 0) { Tabuleiro_marcaJogada(t, 1, 1, j->tipo); return; }
    if(t->M[1][1] == oponente && t->M[2][2] == oponente && t->M[0][0] == 0) { Tabuleiro_marcaJogada(t, 0, 0, j->tipo); return; }

    if(t->M[0][2] == j->tipo && t->M[1][1] == j->tipo && t->M[2][0] == 0) { Tabuleiro_marcaJogada(t, 2, 0, j->tipo); return; }
    if(t->M[0][2] == j->tipo && t->M[2][0] == j->tipo && t->M[1][1] == 0) { Tabuleiro_marcaJogada(t, 1, 1, j->tipo); return; }
    if(t->M[1][1] == j->tipo && t->M[2][0] == j->tipo && t->M[0][2] == 0) { Tabuleiro_marcaJogada(t, 0, 2, j->tipo); return; }
    
    if(t->M[0][2] == oponente && t->M[1][1] == oponente && t->M[2][0] == 0) { Tabuleiro_marcaJogada(t, 2, 0, j->tipo); return; }
    if(t->M[0][2] == oponente && t->M[2][0] == oponente && t->M[1][1] == 0) { Tabuleiro_marcaJogada(t, 1, 1, j->tipo); return; }
    if(t->M[1][1] == oponente && t->M[2][0] == oponente && t->M[0][2] == 0) { Tabuleiro_marcaJogada(t, 0, 2, j->tipo); return; }

// regra 2

    for(int l = 0; l < 3; l++) 
    {
        for(int c = 0; c < 3; c++) 
        {
            if(t->M[l][c] == 0) 
            {
                int sequencias = 0;
                t->M[l][c] = j->tipo;
                
                for(int i = 0; i < 3; i++) 
                {
                    if((t->M[i][0] == j->tipo && t->M[i][1] == j->tipo && t->M[i][2] == 0) || 
                    (t->M[i][0] == j->tipo && t->M[i][2] == j->tipo && t->M[i][1] == 0) || 
                    (t->M[i][1] == j->tipo && t->M[i][2] == j->tipo && t->M[i][0] == 0)) sequencias++;
                }
                
                for(int i = 0; i < 3; i++) 
                {
                    if((t->M[0][i] == j->tipo && t->M[1][i] == j->tipo && t->M[2][i] == 0) || 
                    (t->M[0][i] == j->tipo && t->M[2][i] == j->tipo && t->M[1][i] == 0) || 
                    (t->M[1][i] == j->tipo && t->M[2][i] == j->tipo && t->M[0][i] == 0)) sequencias++;
                }
                
                if((t->M[0][0] == j->tipo && t->M[1][1] == j->tipo && t->M[2][2] == 0) || 
                (t->M[0][0] == j->tipo && t->M[2][2] == j->tipo && t->M[1][1] == 0) || 
                (t->M[1][1] == j->tipo && t->M[2][2] == j->tipo && t->M[0][0] == 0)) sequencias++;

                if((t->M[0][2] == j->tipo && t->M[1][1] == j->tipo && t->M[2][0] == 0) || 
                (t->M[0][2] == j->tipo && t->M[2][0] == j->tipo && t->M[1][1] == 0) || 
                (t->M[1][1] == j->tipo && t->M[2][0] == j->tipo && t->M[0][2] == 0)) sequencias++;

                t->M[l][c] = 0;
                
                if(sequencias >= 2) { Tabuleiro_marcaJogada(t, l, c, j->tipo); return; }
            }
        }
    }

// regra 3

    if(t->M[1][1] == 0) { Tabuleiro_marcaJogada(t, 1, 1, j->tipo); return; }

// regra 4

    if(t->M[0][0] == oponente && t->M[2][2] == 0) { Tabuleiro_marcaJogada(t, 2, 2, j->tipo); return; }
    if(t->M[2][2] == oponente && t->M[0][0] == 0) { Tabuleiro_marcaJogada(t, 0, 0, j->tipo); return; }
    if(t->M[0][2] == oponente && t->M[2][0] == 0) { Tabuleiro_marcaJogada(t, 2, 0, j->tipo); return; }
    if(t->M[2][0] == oponente && t->M[0][2] == 0) { Tabuleiro_marcaJogada(t, 0, 2, j->tipo); return; }

// regra 5

    if(t->M[0][0] == 0) { Tabuleiro_marcaJogada(t, 0, 0, j->tipo); return; }
    if(t->M[0][2] == 0) { Tabuleiro_marcaJogada(t, 0, 2, j->tipo); return; }
    if(t->M[2][0] == 0) { Tabuleiro_marcaJogada(t, 2, 0, j->tipo); return; }
    if(t->M[2][2] == 0) { Tabuleiro_marcaJogada(t, 2, 2, j->tipo); return; }

// regra 6

    for(int i = 0; i < 3; i++) 
    {
        for(int j2 = 0; j2 < 3; j2++) 
        {
            if(t->M[i][j2] == 0) { Tabuleiro_marcaJogada(t, i, j2, j->tipo); return; }
        }
    }
}