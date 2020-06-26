#include "MatrizAjuda.h"
#include <stdio.h>

///Copia a matriz atual do jogo para a matrizajuda e printa com a ajuda da FuncaoAuxiliarPrintaMatrizAjuda.
void MatrizAjuda (ESTADO *e,int flag) {
    int i,j;


    for (i=0 ; i<8 ; i++) {
        for (j=0 ; j<8 ; j++) {

            switch (e->grelha[i][j]){

                case VALOR_X :
                    e->MatrizAjuda[i][j] = e->icon[0];
                    break;

                case VALOR_O :
                    e->MatrizAjuda[i][j] = e->icon[1];
                    break;

                default :
                    e->MatrizAjuda[i][j] = e->icon[2];
                    break;
            }

        }
    }

    JogadasValidas(e->grelha,e->peca,e->MatrizAjuda);

    if (flag == 0) FuncaoAuxiliarPrintaMatrizAjuda(e);

}


///Printa a MatrizAjuda no ecra para o jogador ver onde sao as jogadas possiveis.
void FuncaoAuxiliarPrintaMatrizAjuda (ESTADO *e) {
    int i,j,numeroJ1,numeroJ2;

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


    for (i=0 ; i<8 ; i++) {
        for (j=0 ; j<8 ; j++) {
            printf("%c ",e->MatrizAjuda[i][j]);
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



///Procura na MatrizAjuda as jogadas validas e quando encontradas as mesmas coloca um ' . ' na posiçao de jogada
void JogadasValidas (VALOR Matriz[][8],VALOR Jogador, char MatrizAjuda[][8]) {
    int l,c,i,flag,encontrado,ok;
    char JogadorAdversario;


    if (Jogador == VALOR_X) JogadorAdversario = VALOR_O;
    else JogadorAdversario = VALOR_X;

    for (l=0 ; l < 8 ; l++) {
        for (c=0 ; c < 8 ; c++) {

            if (Matriz[l][c] == Jogador) {

                flag = 0;
                encontrado = 0;
                ok = 0;
                for (i = 1; l + i <= 7 && encontrado == 0 && ok == 0; i++) {

                    if (Matriz[l + i][c] == JogadorAdversario) flag = 1;
                    else if (Matriz[l + i][c] == VAZIA) encontrado = 1;
                    else if (Matriz[l + i][c] == Jogador) ok = 1;

                }

                i--;

                if (flag == 1 && encontrado == 1 && ok == 0) MatrizAjuda[l + i][c] = '.';

// ->

                flag = 0;
                encontrado = 0;
                ok = 0;
                for (i = 1; l - i >= 0 && encontrado == 0 && ok == 0; i++) {

                    if (Matriz[l - i][c] == JogadorAdversario) flag = 1;
                    else if (Matriz[l - i][c] == VAZIA) encontrado = 1;
                    else if (Matriz[l - i][c] == Jogador) ok = 1;

                }

                i--;

                if (flag == 1 && encontrado == 1 && ok == 0) MatrizAjuda[l - i][c] = '.';

// ->

                flag = 0;
                encontrado = 0;
                ok = 0;
                for (i = 1; c + i <= 7 && encontrado == 0 && ok == 0; i++) {

                    if (Matriz[l][c + i] == JogadorAdversario) flag = 1;
                    else if (Matriz[l][c + i] == VAZIA) encontrado = 1;
                    else if (Matriz[l][c + i] == Jogador) ok = 1;

                }

                i--;

                if (flag == 1 && encontrado == 1 && ok == 0) MatrizAjuda[l][c + i] = '.';

// ->

                flag = 0;
                encontrado = 0;
                ok = 0;
                for (i = 1; c - i >= 0 && encontrado == 0 && ok == 0; i++) {

                    if (Matriz[l][c - i] == JogadorAdversario) flag = 1;
                    else if (Matriz[l][c - i] == VAZIA) encontrado = 1;
                    else if (Matriz[l][c - i] == Jogador) ok = 1;

                }

                i--;

                if (flag == 1 && encontrado == 1 && ok == 0) MatrizAjuda[l][c - i] = '.';

// ->

                flag = 0;
                encontrado = 0;
                ok = 0;
                for (i = 1; l + i <= 7 && c + i <= 7 && encontrado == 0 && ok == 0; i++) {

                    if (Matriz[l + i][c + i] == JogadorAdversario) flag = 1;
                    else if (Matriz[l + i][c + i] == VAZIA) encontrado = 1;
                    else if (Matriz[l + i][c + i] == Jogador) ok = 1;

                }

                i--;

                if (flag == 1 && encontrado == 1 && ok == 0) MatrizAjuda[l + i][c + i] = '.';

// ->

                flag = 0;
                encontrado = 0;
                ok = 0;
                for (i = 1; l - i >= 0 && c + i <= 7 && encontrado == 0 && ok == 0; i++) {

                    if (Matriz[l - i][c + i] == JogadorAdversario) flag = 1;
                    else if (Matriz[l - i][c + i] == VAZIA) encontrado = 1;
                    else if (Matriz[l - i][c + i] == Jogador) ok = 1;

                }

                i--;

                if (flag == 1 && encontrado == 1 && ok == 0) MatrizAjuda[l - i][c + i] = '.';

// ->

                flag = 0;
                encontrado = 0;
                ok = 0;
                for (i = 1; l + i <= 7 && c - i >= 0 && encontrado == 0 && ok == 0; i++) {

                    if (Matriz[l + i][c - i] == JogadorAdversario) flag = 1;
                    else if (Matriz[l + i][c - i] == VAZIA) encontrado = 1;
                    else if (Matriz[l + i][c - i] == Jogador) ok = 1;

                }

                i--;

                if (flag == 1 && encontrado == 1 && ok == 0) MatrizAjuda[l + i][c - i] = '.';

// ->

                flag = 0;
                encontrado = 0;
                ok = 0;
                for (i = 1; l - i >= 0 && c - i >= 0 && encontrado == 0 && ok == 0; i++) {

                    if (Matriz[l - i][c - i] == JogadorAdversario) flag = 1;
                    else if (Matriz[l - i][c - i] == VAZIA) encontrado = 1;
                    else if (Matriz[l - i][c - i] == Jogador) ok = 1;

                }

                i--;

                if (flag == 1 && encontrado == 1 && ok == 0) MatrizAjuda[l - i][c - i] = '.';

            }
        }
    }


}

