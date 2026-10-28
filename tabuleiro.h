#ifndef TABULEIRO_H
#define TABULEIRO_H

typedef struct
{
    int M[3][3];
} Tabuleiro;

void Tabuleiro_inicializa(Tabuleiro *t);
void Tabuleiro_desenha(Tabuleiro *t);
int Tabuleiro_temVencedor(Tabuleiro *t);
void Tabuleiro_marcaJogada(Tabuleiro *t, int x, int y, int tipo);

#endif