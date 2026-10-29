#ifndef JOGADOR_H
#define JOGADOR_H

#include "tabuleiro.h"

typedef struct
{
    int tipo;
} JogadorTeclado;

void JogadorTeclado_joga(JogadorTeclado *j, Tabuleiro *t);

#endif