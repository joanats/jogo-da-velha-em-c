#ifndef JOGO_H
#define JOGO_H

#include "tabuleiro.h"
#include "jogador.h"
#include "jogadorIA.h"

typedef struct{
    Tabuleiro tabuleiro;
    JogadorTeclado jogadores[2];
    JogadorIA jogadorIA;
    int modoJogo;

} Partida;

void Partida_configuraJogadores(Partida *p);
void Partida_inicia(Partida *p);

#endif
