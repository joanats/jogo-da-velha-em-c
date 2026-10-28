#ifndef JOGADORIA_H
#define JOGADORIA_H

#include "tabuleiro.h"

typedef struct
{
    int tipo;
} JogadorIA;

void JogadorIA_joga(JogadorIA *j, Tabuleiro *t);

#endif