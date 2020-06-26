#include "JogadasManual.h"
#include "MatrizAjuda.h"
#include <stdio.h>

///efetua a jogada do modo manual( 1 contra 1 )
void EfetuaJogada (ESTADO *e,char *linha) {
    int n,Li,Co;
    char cmd[256];
    char Linha[256];
    char Coluna[256];

    n = sscanf(linha,"%s %s %s",cmd,Linha,Coluna);

    if (n == 3) {

        Li = Linha[0] - '0'-1;
        Co = Coluna[0] - '0'-1;

        if (Li >= 0 && Li <= 7 && Co >= 0 && Co <= 7) {

            MatrizAjuda(e,1);

            if (e->MatrizAjuda[Li][Co] == '.') {

                e->grelha[Li][Co] = e->peca;

                ConvertePecas(e->grelha,e->peca,Li,Co);

                TrocaPeca(e);

                e->jogadas++;

                push(e);


            }

            else printf("  Posiçao invalida\n\n");

        }

        else printf("  Jogada invalida\n\n");

    }

    else printf("erro: é preciso um parâmentro\n\n");

}


///Troca as peças que tem de ser viradas apos uma jogada
int ConvertePecas (VALOR Matriz[][8],VALOR Jogador, int Li, int Co) {
    int res = 0;
    int i,flag,encontrado;
    VALOR JogadorAdversario;

    if (Jogador == VALOR_X) JogadorAdversario = VALOR_O;
    else JogadorAdversario = VALOR_X;

    flag = 0;
    encontrado = 0;
    for (i=1 ; Matriz[Li+i][Co] != VAZIA && Li+i <= 7 && encontrado == 0; i++) {
        if (Matriz[Li+i][Co] == JogadorAdversario) flag = 1;
        else encontrado = 1;
    }

    for (i=1 ; encontrado == 1 && flag == 1 && Matriz[Li+i][Co] != Jogador ; i++) {
        Matriz[Li+i][Co] = Jogador;
        res++;
    }

//->

    flag = 0;
    encontrado = 0;
    for (i=1 ; Matriz[Li-i][Co] != VAZIA && Li-i >= 0 && encontrado == 0; i++) {
        if (Matriz[Li-i][Co] == JogadorAdversario) flag = 1;
        else encontrado = 1;
    }

    for (i=1 ; encontrado == 1 && flag == 1 && Matriz[Li-i][Co] != Jogador ; i++) {
        Matriz[Li-i][Co] = Jogador;
        res++;
    }

//->

    flag = 0;
    encontrado = 0;
    for (i=1 ; Matriz[Li][Co+i] != VAZIA && Co+i <= 7 && encontrado == 0; i++) {
        if (Matriz[Li][Co+i] == JogadorAdversario) flag = 1;
        else encontrado = 1;
    }

    for (i=1 ; encontrado == 1 && flag == 1 && Matriz[Li][Co+i] != Jogador ; i++) {
        Matriz[Li][Co+i] = Jogador;
        res++;
    }

//->

    flag = 0;
    encontrado = 0;
    for (i=1 ; Matriz[Li][Co-i] != VAZIA && Co-i >= 0 && encontrado == 0; i++) {
        if (Matriz[Li][Co-i] == JogadorAdversario) flag = 1;
        else encontrado = 1;
    }

    for (i=1 ; encontrado == 1 && flag == 1 && Matriz[Li][Co-i] != Jogador ; i++) {
        Matriz[Li][Co-i] = Jogador;
        res++;
    }

//->

    flag = 0;
    encontrado = 0;
    for (i=1 ; Matriz[Li+i][Co+i] != VAZIA && Li+i <= 7 && Co+i <= 7 && encontrado == 0; i++) {
        if (Matriz[Li+i][Co+i] == JogadorAdversario) flag = 1;
        else encontrado = 1;
    }

    for (i=1 ; encontrado == 1 && flag == 1 && Matriz[Li+i][Co+i] != Jogador ; i++) {
        Matriz[Li+i][Co+i] = Jogador;
        res++;
    }

//->

    flag = 0;
    encontrado = 0;
    for (i=1 ; Matriz[Li+i][Co-i] != VAZIA && Li+i <= 7 && Co-i >= 0 && encontrado == 0; i++) {
        if (Matriz[Li+i][Co-i] == JogadorAdversario) flag = 1;
        else encontrado = 1;
    }

    for (i=1 ; encontrado == 1 && flag == 1 && Matriz[Li+i][Co-i] != Jogador ; i++) {
        Matriz[Li+i][Co-i] = Jogador;
        res++;
    }

//->


    flag = 0;
    encontrado = 0;
    for (i=1 ; Matriz[Li-i][Co+i] != VAZIA && Li-i >= 0 && Co+i <= 7 && encontrado == 0; i++) {
        if (Matriz[Li-i][Co+i] == JogadorAdversario) flag = 1;
        else encontrado = 1;
    }

    for (i=1 ; encontrado == 1 && flag == 1 && Matriz[Li-i][Co+i] != Jogador ; i++) {
        Matriz[Li-i][Co+i] = Jogador;
        res++;
    }

//->


    flag = 0;
    encontrado = 0;
    for (i=1 ; Matriz[Li-i][Co-i] != VAZIA && Li-i >= 0 && Co-i >= 0 && encontrado == 0; i++) {
        if (Matriz[Li-i][Co-i] == JogadorAdversario) flag = 1;
        else encontrado = 1;
    }

    for (i=1 ; encontrado == 1 && flag == 1 && Matriz[Li-i][Co-i] != Jogador ; i++) {
        Matriz[Li-i][Co-i] = Jogador;
        res++;
    }

    return res+1;
}



///Troca a vez do jogador a jogar (passa a vez)
void TrocaPeca (ESTADO *e) {

    if (e->peca == VALOR_X) e->peca = VALOR_O;
    else e->peca = VALOR_X;

    MatrizAjuda(e,1);


    if (!NumeroP(e->MatrizAjuda)) {
        if (e->peca == VALOR_X) e->peca = VALOR_O;
        else e->peca = VALOR_X;

        MatrizAjuda(e,1);

        if (!NumeroP(e->MatrizAjuda)) {
            e->jogadas = 61;
            printf("Nenhum dos Jogadores tem uma Jogada Possivel\n\n");
        }

        else printf("Passou a jogada\n\n");

    }

}


