#include "JogadasBotFacil.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


///efetua a jogada de forma aleatoria do bot
void EfetuaJogadaBot1 (ESTADO *e,char *linha) {
    int n,Li,Co;
    char cmd[256];
    char Linha[256];
    char Coluna[256];
    VALOR JogadorAdversario;

    if (e->peca == VALOR_X) JogadorAdversario = VALOR_O;
    else JogadorAdversario = VALOR_X;

    n = sscanf(linha,"%s %s %s",cmd,Linha,Coluna);

    if (n == 3) {

        Li = Linha[0] - '0'-1;
        Co = Coluna[0] - '0'-1;

        if (Li >= 0 && Li <= 9 && Co >= 0 && Co <= 9) {

            MatrizAjuda(e,1);

            if (e->MatrizAjuda[Li][Co] == '.') {

                e->grelha[Li][Co] = e->peca;

                ConvertePecas(e->grelha,e->peca,Li,Co);

                TrocaPeca(e);

                e->jogadas++;

                while (e->peca == JogadorAdversario && e->jogadas <= 60) {

                    JogaBot1(e);
                    TrocaPeca(e);
                    e->jogadas++;
                }


                push(e);
            }

            else printf("  Posiçao invalida\n\n");

        }

        else printf("  Jogada invalida\n\n");

    }

    else printf("erro: é preciso um parâmentro\n\n");

}


///Gera um numero aleatorio entre 1 e o numero maximo de pontos escolhendo 1 desse intervalo
void JogaBot1 (ESTADO *e) {
    int i,j,encontrado = 0;
    int numerodeP;
    int numeroRandom;

    numerodeP = NumeroP(e->MatrizAjuda);

    srand(time(0));

    numeroRandom = (rand() % numerodeP) +1;

    for (i=0 ; i<8 && encontrado == 0; i++) {
        for (j=0 ; j<8 && encontrado == 0; j++) {

            if (numeroRandom == 1 && e->MatrizAjuda[i][j] == '.') {

                e->grelha[i][j] = e->peca;
                ConvertePecas(e->grelha,e->peca,i,j);
                encontrado = 1;
            }

            else if (e->MatrizAjuda[i][j] == '.') numeroRandom--;
        }
    }

}