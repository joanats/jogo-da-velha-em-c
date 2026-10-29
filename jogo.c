#include <stdio.h>
#include "jogo.h"

void Partida_configuraJogadores(Partida *p) {
    Tabuleiro_inicializa(&p->tabuleiro);

    printf("~~~~ JOGO DA VELHA ~~~~\n");
    printf("\t1 - Jogador x Jogador\n");
    printf("\t2 - Jogador x IA\n");
    printf("Escolha: ");
    scanf("%d",&p->modoJogo);

    p->jogadores[0].tipo = 4; 
    p->jogadores[1].tipo = 1;
    p->jogadorIA.tipo = 1;
}


void Partida_inicia(Partida *p) {
    
    Partida_configuraJogadores(p);

    char nomes[2][20];
    int jogadas = 0;
    int vencedor = 0;
    int turno = 0;

    if (p->modoJogo == 1) {

        printf("\t~~~~ JOGO DA VELHA ~~~~\n");

        printf("Digite o nome do jogador X: ");
        scanf("%19s", nomes[0]);

        printf("Digite o nome do jogador O: ");
        scanf("%19s", nomes[1]);

    }


    while(jogadas < 9 && vencedor == 0) {
        Tabuleiro_desenha(&p->tabuleiro);

        if(turno == 0)
        {
            JogadorTeclado_joga(&p->jogadores[0],&p->tabuleiro);
        }
        else
        {
            if(p->modoJogo == 1) {
                JogadorTeclado_joga(&p->jogadores[1],&p->tabuleiro);

            } else {
                JogadorIA_joga(&p->jogadorIA,&p->tabuleiro);

            }
        }

        vencedor = Tabuleiro_temVencedor(&p->tabuleiro);

        turno = 1 - turno;

        jogadas++;
    }

    Tabuleiro_desenha(&p->tabuleiro);

    if (p->modoJogo == 2) {

        if(vencedor == 4) {
            printf("\tParabens! Voce venceu!\n");

        }
        else if(vencedor == 1) {
            printf("\tPoxaa! A IA venceu!\n");

        } else {
            printf("\tDeu velha!\n");

        }

    } else {

        if(vencedor == 4) {
            printf("\tParabens, %s! Voce venceu!\n", nomes[0]);

        } else if(vencedor == 1) {
            printf("\tParabens, %19s! Você venceu!\n", nomes[1]);

        } else {
            printf("\tDeu velha! %19s e %19s empataram :(\n", nomes[0], nomes[1]);

        }
    }
}