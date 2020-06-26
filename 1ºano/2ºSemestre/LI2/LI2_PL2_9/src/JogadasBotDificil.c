#include "JogadasBotDificil.h"
#include <stdio.h>


///efetua a jogada do bot dificil usando a estrategia da mobilidade, de posiçoes e de maior numero de peças
void EfetuaJogadaBot4 (ESTADO *e, char *linha) {
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

                    JogaBot4(e);

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


///Funçao que faz com que o bot jogue nos cantos mal tenha possibilidade de e aplique as estrategias em todas as outras situaçoes
void JogaBot4 (ESTADO *e) {
    int i,j,menor,challenger,flag = 0;
    int maiorPecas,challengerPecas;
    Posicao coordenadas;



    if (e->MatrizAjuda[0][0] == '.') {
        coordenadas.x = 0;
        coordenadas.y = 0;
        flag++;
    }

    else if (e->MatrizAjuda[7][0] == '.') {
        coordenadas.x = 7;
        coordenadas.y = 0;
        flag++;
    }

    else if (e->MatrizAjuda[0][7] == '.') {
        coordenadas.x = 0;
        coordenadas.y = 7;
        flag++;
    }

    else if (e->MatrizAjuda[7][7] == '.') {
        coordenadas.x = 7;
        coordenadas.y = 7;
        flag++;
    }


    else {

        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {

                if (e->MatrizAjuda[i][j] == '.' && flag == 0) {

                    menor = CalculaMobilidade(e, e->grelha, i, j);
                    coordenadas.x = i;
                    coordenadas.y = j;
                    flag++;

                }


                else if (e->MatrizAjuda[i][j] == '.') {

                    challenger = CalculaMobilidade(e, e->grelha, i, j);

                    if (menor >= challenger) {

                        if (menor > challenger) {

                            menor = challenger;
                            coordenadas.x = i;
                            coordenadas.y = j;

                        } else if (menor == challenger) {

                            maiorPecas = ConvertePecas(e->MatrizAjudaBot, e->peca, coordenadas.x, coordenadas.y);
                            CopiaMatrizBot(e->MatrizAjudaBot, e->grelha);

                            challengerPecas = ConvertePecas(e->MatrizAjudaBot, e->peca, i, j);
                            CopiaMatrizBot(e->MatrizAjudaBot, e->grelha);

                            if (maiorPecas >= challengerPecas) {


                                if (maiorPecas > challengerPecas) {

                                    menor = challenger;
                                    coordenadas.x = i;
                                    coordenadas.y = j;

                                } else if (maiorPecas == challengerPecas) {

                                    if (e->matrizValores[coordenadas.x][coordenadas.y] < e->matrizValores[i][j]) {

                                        menor = challenger;
                                        coordenadas.x = i;
                                        coordenadas.y = j;


                                    }

                                }

                            }


                        }


                    }


                }

            }
        }
    }

    if (flag > 0) {

        e->grelha[coordenadas.x][coordenadas.y] = e->peca;
        ConvertePecas(e->grelha, e->peca, coordenadas.x, coordenadas.y);

    }

}


///calcula a estrategia da mobilidade aplicada pelo bot
int CalculaMobilidade(ESTADO *e,VALOR MatrizJogadas[][8],int i,int j) {
    char MatrizP[8][8];
    VALOR Matriz[8][8];
    VALOR JogadorAdversario;

    if (e->peca == VALOR_O) JogadorAdversario = VALOR_X;
    else JogadorAdversario = VALOR_O;

    CopiaMatrizBot(Matriz, MatrizJogadas);


    Matriz[i][j] = e->peca;
    ConvertePecas(Matriz, e->peca, i, j);


    ConverteMatriz(e,Matriz,MatrizP);
    JogadasValidas(Matriz,JogadorAdversario , MatrizP);



    return NumeroP(MatrizP);


}