#include "JogadasBotComp.h"
#include <stdio.h>


///efetua a jogada do bot no tabuleiro com uso do algoritmo MinMax(Alpha-Beta)
void EfetuaJogadaBot3 (ESTADO *e, char *linha) {
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

                    if (e->jogadas < 50) MinMax(e, e->grelha, 10, e->peca,-500,500);
                    else JogaBot2(e);

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



///Aplicaçao do Algoritmo MinMax(Alpha-Beta) para as jogadas do bot
int MinMax (ESTADO *e,VALOR Matriz[][8],int Alcance,VALOR Jogador,int alpha,int beta) {
    VALOR MatrizJogadas[8][8];
    char MatrizPontos[8][8];
    VALOR JogadorAdversario;
    int max = -500,min = 500;
    int challenger;
    int calcula = -500;
    int flag = 0;
    int i,j;
    Posicao coordenadas;


    CopiaMatrizBot(MatrizJogadas, Matriz);
    ConverteMatriz(e,MatrizJogadas,MatrizPontos);
    JogadasValidas(MatrizJogadas, Jogador, MatrizPontos);


    if (Jogador == VALOR_X) JogadorAdversario = VALOR_O;
    else JogadorAdversario = VALOR_X;


    for (i = 0; i < 8; i++) {

        for (j = 0; j < 8; j++) {

            if (MatrizPontos[i][j] == '.') {


                if (Alcance == 0) {

                    if (flag == 0) {
                        calcula = e->matrizValores[i][j];
                        flag++;
                    }

                    else if (calcula < e->matrizValores[i][j]) {

                        calcula = e->matrizValores[i][j];

                    }


                }

                else {

                    if (e->peca == Jogador) {

                        MatrizJogadas[i][j] = Jogador;
                        ConvertePecas(MatrizJogadas, Jogador, i, j);

                        challenger = MinMax(e, MatrizJogadas, Alcance - 1, JogadorAdversario,alpha,beta);

                        CopiaMatrizBot(MatrizJogadas, Matriz);

                        if (challenger > max) {

                            if (challenger > max) max = challenger;


                            if (Alcance == 10) {
                                coordenadas.x = i;
                                coordenadas.y = j;
                            }

                        }

                        if (max > alpha) {

                            alpha = max;

                        }

                        if (alpha >= beta) {

                            return max;

                        }





                    } else {

                        MatrizJogadas[i][j] = Jogador;
                        ConvertePecas(MatrizJogadas, Jogador, i, j);

                        challenger = MinMax(e, MatrizJogadas, Alcance - 1, JogadorAdversario,alpha,beta);

                        CopiaMatrizBot(MatrizJogadas, Matriz);

                        if (challenger < min) {

                            min = challenger;

                        }

                        if (min < beta) {

                            beta = min;

                        }

                        if (alpha >= beta) {

                            return min;

                        }


                    }

                }

            }

        }
    }


    if (Alcance == 0) return calcula;

    else {

        if (NumeroP(MatrizPontos)) {


            if (Alcance == 10) {

                e->grelha[coordenadas.x][coordenadas.y] = e->peca;
                ConvertePecas(e->grelha,e->peca,coordenadas.x,coordenadas.y);

            }


            if (e->peca == Jogador) return max;
            else return min;

        } else {

            if (Jogador != e->peca) Alcance--;

            return MinMax(e, MatrizJogadas, Alcance, JogadorAdversario,alpha,beta);
        }
    }

}



///Coverte a matriz de valores para catateres
void ConverteMatriz (ESTADO *e,VALOR Matriz[][8],char MatrizAConverter[][8]) {
    int i,j;

    for (i=0 ; i<8 ; i++) {
        for (j=0 ; j<8 ; j++) {

            switch (Matriz[i][j]) {

                case VALOR_X :
                    MatrizAConverter[i][j] = e->icon[0];
                    break;

                case VALOR_O :
                    MatrizAConverter[i][j] = e->icon[1];
                    break;

                default:
                    MatrizAConverter[i][j] = e->icon[2];
                    break;

            }
        }
    }
}

