#include "ControloJogadas.h"
#include <stdio.h>


///Contrala as jogadas cosoante o modo de jogo selicionado ela joga de acordo com o pedido
void ControloDeJogadas (ESTADO *e, char *linha) {
    int numeroJ1,numeroJ2;
    float Jscore;


    if (e->jogadas >= 0 && e->modo == 'M') {

        EfetuaJogada(e,linha);

    }

    else if (e->jogadas >= 0 && e->modo == 'A') {

        if (e->dificuldade == 1) {

            EfetuaJogadaBot1(e,linha);

        }

        else if (e->dificuldade == 2) {

            EfetuaJogadaBot2(e,linha);

        }

        //else if (e->dificuldade == 3) {

        //    EfetuaJogadaBot4(e,linha);

        //}

        else if (e->dificuldade == 3) {

            EfetuaJogadaBot3(e,linha);

            numeroJ1 = NumeroJ1(e);
            numeroJ2 = NumeroJ2(e);

            if (e->jogadas >= 60 || numeroJ1 <= 0 || numeroJ2 <= 0) {

                Jscore = CalculaScore(e);
                AcrescentaScore(e,Jscore);
                AtualizaRankingTXT(e);


            }
        }


    }


        numeroJ1 = NumeroJ1(e);
        numeroJ2 = NumeroJ2(e);


    if (e->jogadas <= 60 && numeroJ1 > 0 && numeroJ2 > 0) PrintMatriz(e);

    else {

        if (numeroJ1 > numeroJ2) {

            printf("                      Jogo Terminado\n\n                Score :   %c ➤ %d       %c ➤ %d\n\n                   Jogador %c ganhou o jogo\n\n",
                   e->icon[0], numeroJ1, e->icon[1], numeroJ2, e->icon[0]);

        } else if (numeroJ1 < numeroJ2){

            printf("                      Jogo Terminado\n\n                Score :   %c ➤ %d       %c ➤ %d\n\n                   Jogador %c ganhou o jogo\n\n",
                   e->icon[0], numeroJ1, e->icon[1], numeroJ2, e->icon[1]);

        }

        else {

            printf("                      Jogo Terminado\n\n                Score :   %c ➤ %d       %c ➤ %d\n\n                   Jogador Empatado\n\n",
                   e->icon[0], numeroJ1, e->icon[1], numeroJ2);

        }


        e->jogadas = -1;
        e->peca = 0;
        e->Code = 0;
        e->icon[0] = 'X';
        e->icon[1] = 'O';

    }


}
