#include <stdio.h>
#include "jogo.h"

void Partida_configuraJogadores(Partida *p)
{
    Tabuleiro_inicializa(&p->tabuleiro);

    p->jogadores[0].tipo = 4; 
    p->jogadores[1].tipo = 1;
}


void Partida_inicia(Partida *p)
{
    char resposta;
    char nomes[2][50];

    printf("===== JOGO DA VELHA =====\n");

    printf("Digite o nome do jogador X: ");
    scanf("%49s", nomes[0]);

    printf("Digite o nome do jogador O: ");
    scanf("%49s", nomes[1]);

    do
    {
        Partida_configuraJogadores(p);

        int jogadas = 0;
        int vencedor = 0;
        int turno = 0;

        while (jogadas < 9 && vencedor == 0)
        {
            Tabuleiro_desenha(&p->tabuleiro);

            JogadorTeclado_joga(&p->jogadores[turno], &p->tabuleiro);

            vencedor = Tabuleiro_temVencedor(&p->tabuleiro);

            if (turno == 0)
            {
                turno = 1;
            }
            else
            {
                turno = 0;
            }

            jogadas++;
        }

        
        Tabuleiro_desenha(&p->tabuleiro);

        if (vencedor == 4)
        {
            printf("Parabens, %s! Voce venceu como X!\n", nomes[0]);
        }
        else if (vencedor == 1)
        {
            printf("Parabens, %s! Voce venceu como O!\n", nomes[1]);
        }
        else
        {
            printf("Deu velha! O jogo empatou.\n");
        }

    
        printf("Deseja jogar novamente? (S/N): ");
        scanf(" %c", &resposta);

    } while (resposta == 'S' || resposta == 's');

    printf("Obrigado por jogar!\n");
}