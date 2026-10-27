#ifndef JOGO_H
#define JOGO_H

#include "tabuleiro.h"
#include "jogador.h"

typedef struct
{
    Tabuleiro tabuleiro;
    JogadorTeclado jogadores[2];
} Partida;

void Partida_configuraJogadores(Partida *p);
void Partida_inicia(Partida *p);

#endif
