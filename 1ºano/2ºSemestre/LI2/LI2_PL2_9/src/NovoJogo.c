#include "NovoJogo.h"
#include <stdio.h>
#include <ctype.h>



///inicializa uma matriz para um jogo manual (1 contra 1)
void NovoJogoManual (ESTADO *e,char *linha) {
    int n,i,j;
    char peca[256];
    char cmd[256];

    n = sscanf(linha,"%s %s",cmd,peca);

    if (n == 2) {

        if ((toupper(peca[0]) == e->icon[0]) || (toupper(peca[0]) == e->icon[1])) {

            LimpaStack(e);

            if (toupper(peca[0]) == e->icon[0]) e->peca = VALOR_X;
            else e->peca = VALOR_O;


            e->modo = 'M';
            e->jogadas = 0;
            e->dificuldade = 0;


            for (i = 0; i < 8; i++) {
                for (j = 0; j < 8; j++) {
                    if (i == 3 && j == 3) e->grelha[3][3] = VALOR_O;
                    else if (i == 4 && j == 4) e->grelha[4][4] = VALOR_O;
                    else if (i == 3 && j == 4) e->grelha[3][4] = VALOR_X;
                    else if (i == 4 && j == 3) e->grelha[4][3] = VALOR_X;
                    else e->grelha[i][j] = VAZIA;
                }
            }


            push(e);

        }

        else printf("Peça Invalida\n\n");



    }

    else printf("erro: é preciso um parâmentro\n\n");

}





///inicializa uma matriz de um jogo automatico e respetiva dificuldade(jogo contra bot)
void NovoJogoBot (ESTADO *e,char *linha) {
    int i,j,n;
    char cmd[256];
    char peca[256];
    char nivel[256];


    n = sscanf(linha,"%s %s %s",cmd,peca,nivel);


    if (n == 3) {


        if ((toupper(peca[0]) == e->icon[0] || toupper(peca[0]) == e->icon[1]) && nivel[0] >= '0' && nivel[0] <= '3') {

            LimpaStack(e);

            e->modo = 'A';
            e->jogadas = 0;

            if (nivel[0] == '1') e->dificuldade = 1;

            else if (nivel[0] == '2') e->dificuldade = 2;

            else e->dificuldade = 3;


            if (toupper(peca[0]) == e->icon[0]) e->peca = VALOR_X;
            else e->peca = VALOR_O;


            for (i = 0; i < 8; i++) {
                for (j = 0; j < 8; j++) {
                    if (i == 3 && j == 3) e->grelha[3][3] = VALOR_O;
                    else if (i == 4 && j == 4) e->grelha[4][4] = VALOR_O;
                    else if (i == 3 && j == 4) e->grelha[3][4] = VALOR_X;
                    else if (i == 4 && j == 3) e->grelha[4][3] = VALOR_X;
                    else e->grelha[i][j] = VAZIA;
                }
            }

            push(e);


        }

        else if (toupper(peca[0]) != e->icon[0] && toupper(peca[0]) != e->icon[1]) printf("Peca invalida\n\n");

        else printf("Nivel invalido\n\n");

    }

    else printf("erro: é preciso um parâmentro\n\n");

}