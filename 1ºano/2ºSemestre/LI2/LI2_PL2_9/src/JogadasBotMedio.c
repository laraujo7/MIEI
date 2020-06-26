#include "JogadasBotMedio.h"
#include "MatrizAjuda.h"
#include "NJogadasValidas.h"
#include "Stack.h"
#include "JogadasManual.h"
#include "MatrizAjuda.h"
#include <stdio.h>


///efetua a jogada do bot utilizando a estrategia do bot
void EfetuaJogadaBot2 (ESTADO *e,char *linha) {
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

                    JogaBot2(e);
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


///calcula a jogada do bot utilizando a estrategia do maior numero de peças viradas
void JogaBot2 (ESTADO *e) {
    int i,flag=0,j,maior,competidor;
    Posicao coordenadas;


        CopiaMatrizBot(e->MatrizAjudaBot,e->grelha);

        for (i=0 ; i<8 ; i++) {
            for (j=0 ; j<8 ; j++) {

                if (flag==0 && e->MatrizAjuda[i][j] == '.') {

                    maior = ConvertePecas(e->MatrizAjudaBot,e->peca,i,j);
                    coordenadas.x = i;
                    coordenadas.y = j;


                    CopiaMatrizBot(e->MatrizAjudaBot,e->grelha);
                    flag++;

            }
                else if (e->MatrizAjuda[i][j] == '.') {

                    competidor = ConvertePecas(e->MatrizAjudaBot,e->peca,i,j);

                    if (maior < competidor) {

                        maior = competidor;
                        coordenadas.x = i;
                        coordenadas.y = j;


                        CopiaMatrizBot(e->MatrizAjudaBot,e->grelha);

                    }

                }

            }

        }

        e->grelha[coordenadas.x][coordenadas.y] = e->peca;
        ConvertePecas(e->grelha,e->peca,coordenadas.x,coordenadas.y);

}



///copia a matriz ajuda para verificar qual a jogada que vira mais peças
void CopiaMatrizBot (VALOR MatrizAjudaBot[][8], VALOR grelha[][8]) {
    int i,j;

    for (i=0 ; i<8 ; i++) {
        for (j=0 ; j<8 ; j++) {
            MatrizAjudaBot[i][j] = grelha[i][j];
        }
    }


}


