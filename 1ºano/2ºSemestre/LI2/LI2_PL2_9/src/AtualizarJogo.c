#include "AtualizarJogo.h"
#include <stdio.h>


/**
 * Mostra o interpretador no direito do ecra e as suas opçoes em seguida precorre a matriz de jogo e
 *quando encontra o VALOR_X substitui por 'X' o VALOR_O substitui por 'O' caso contrario substitui por '-'
*/
void PrintMatriz (ESTADO *e) {
    int i,j,numeroJ1,numeroJ2;
    char c;

    numeroJ1 = NumeroJ1(e);
    numeroJ2 = NumeroJ2(e);



    printf("                           ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("                                         Interpretador \n");


    if (numeroJ1 < 10 && numeroJ2 < 10) printf("\n   %c ➤ %d    %c ➤ %d           N <Peca> ➤ Novo Jogo\n",e->icon[0],numeroJ1,e->icon[1],numeroJ2);

    else if ((numeroJ1 >= 10 && numeroJ2 < 10) || (numeroJ1 < 10 && numeroJ2 >= 10)) printf("\n   %c ➤ %d    %c ➤ %d          N <Peca> ➤ Novo Jogo\n",e->icon[0],numeroJ1,e->icon[1],numeroJ2);

    else printf("\n   %c ➤ %d    %c ➤ %d         N <Peca> ➤ Novo Jogo\n",e->icon[0],numeroJ1,e->icon[1],numeroJ2);


    printf("                            A <Peca> <Nivel> ➤ Novo Jogo Contra Bot");


    printf("\n   1 2 3 4 5 6 7 8          E <Ficheiro> ➤ Salvar esta jogada");


    printf("\n1  ");


    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {

            switch (e->grelha[i][j]) {

                case VALOR_X:
                    c = e->icon[0];
                    break;

                case VALOR_O:
                    c = e->icon[1];
                    break;

                default :
                    c = e->icon[2];
                    break;



            }

            printf("%c ",c);
        }


        if (i==0) printf ("         G <Peca> <NickName> ➤ Modo Competitivo");
        if (i==1) printf ("         L <Ficheiro> ➤ Descarregar Ficheiro");
        if (i==2) printf ("         R <Ficheiro> ➤ Remover Ficheiros");
        if (i==3) printf ("         J <L,C> ➤ Jogar na Linha L e Coluna C");
        if (i==4) printf ("         C <Char,Char> ➤ Trocar de peças");
        if (i==5) printf ("         S ➤ Jogadas Validas");
        if (i==6) printf ("         H ➤ Sugestao de Jogada");
        if (i==7) printf ("         U ➤ Undo");

        if (i!=7) printf("\n%d  ",i+2);
        else printf("\n");
    }

    printf ("                            T ➤ Ficheiros guardados\n");
    printf ("                            W ➤ Ranking\n");
    printf ("                            Q ➤ Sair\n\n");
    printf ("                           ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

}

