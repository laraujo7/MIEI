#include "Interpretador.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define clrscr() printf("\e[1;1H\e[2J")



///Le o carater e consoante a leitura ira realizar o comando do mesmo como um interpretador normal
void Interpreta (ESTADO *e, char *linha) {
    char cmd[256];
    int i,j;


    sscanf(linha,"%s",cmd);


    switch ( toupper(cmd[0]) ) {

        case 'N' :

            clrscr();
            NovoJogoManual(e,linha);

            if (e->jogadas >= 0) PrintMatriz(e);

            break;

        case 'A' :

            clrscr();
            NovoJogoBot(e,linha);

            if (e->jogadas >= 0) PrintMatriz(e);

            break;

        case 'G' :

            clrscr();
            NovoJogoCompetetivo(e,linha);

            if (e->jogadas >= 0) PrintMatriz(e);

            break;


        case 'E' :

            clrscr();

            if (e->jogadas >= 0 && e->dificuldade != 4) SaveEstado(e,linha);

            else if (e->jogadas < 0) printf("Nenhum Jogo inicializado\n\n");

            else printf("Nao é possivel salvar um jogo no modo competetivo\n\n");

            if (e->jogadas >= 0) PrintMatriz(e);


            break;

        case 'L' :

            clrscr();
            if (e->dificuldade != 4 || e->Code == 1) {

                LoadEstado(e, linha);


            }

            else {
                printf ("Nao pode dar load a um ficheiro em modo competetivo\n\n");
                PrintMatriz(e);

            }

            if (e->jogadas >= 0) PrintMatriz(e);

            break;

        case 'R' :

            clrscr();
            RemoveFicheiro(linha);

            if (e->jogadas >= 0) PrintMatriz(e);

            break;

        case 'J' :

            clrscr();

            if (e->jogadas >= 0) ControloDeJogadas(e,linha);

            else printf("Nenhum jogo inicializado\n\n");

            break;

        case 'C' :

            clrscr();

            if (e->jogadas < 0) {

                TrocaIcon(e,linha);

            }

            else {
                printf("Nao é possivel trocar os jogadores neste momento\n\n");
                PrintMatriz(e);
            }

            break;

        case 'S' :

            clrscr();

            if (e->dificuldade != 4 || e->Code == 1) {

                if (e->jogadas >= 0) {

                    MatrizAjuda(e, 0);

                }

                else printf("Nenhum jogo inicializado\n\n");

            }

            else {

                printf ("Este comando nao é permitido em modo competetivo\n\n");
                PrintMatriz(e);

                }

            break;

        case 'H' :

            clrscr();

            if (e->dificuldade != 4) {

                if (e->jogadas >= 0) {

                    MatrizAjuda(e, 1);
                    SugestaoJogada(e);
                    FuncaoAuxiliarPrintaMatrizAjuda(e);

                } else printf("Nenhum jogo inicializado\n\n");

            }

            else {

                printf ("Este comando nao é permitido em modo competetivo\n\n");
                PrintMatriz(e);

            }


            break;

        case 'U' :

            clrscr();
            if (e->jogadas >= 0 && e->dificuldade != 4) {
                EfetuaUndo(e);
            }

            else if (e->dificuldade == 4) printf("Nao é permitido fazer undo's no modo competitivo\n\n");

            else printf("Nenhum jogo inicializado\n\n");

            if (e->jogadas >= 0) PrintMatriz(e);

            break;

        case 'T' :

            clrscr();
            Leficheiro();

            if (e->jogadas >= 0) PrintMatriz(e);

            break;

        case 'W' :

            clrscr();
            PrintRanking(e);

            if (e->jogadas >= 0) PrintMatriz(e);

            break;


        case '-' :
            if (!strcmp(linha,"-cmd -l -g\n")) {
                e->Code = 1;

            }

            break;

        case 'Q':

            exit(0);

        default:
            clrscr();
            printf("Comando invalido (rtfm)!\n\n");

            if (e->jogadas >= 0) PrintMatriz(e);

            break;

    }


}



///Mostra o interpretador ao utilizador
void PrintInterpretador (ESTADO *e) {

    if (e->jogadas == -1) {
        printf("       ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("                      Interpretador\n\n");
        printf("         N <Peca> ➤ Novo Jogo                                Jogador 1 ➤ %c\n",e->icon[0]);
        printf("         A <Peca> <Nivel> ➤ Novo Jogo Contra Bot             Jogador 2 ➤ %c\n",e->icon[1]);
        printf("         G <Peca> <NickName> ➤ Modo Competitivo\n");
        printf("         E <Ficheiro> ➤ Salvar esta jogada\n");
        printf("         L <Ficheiro> ➤ Descarregar Ficheiro\n");
        printf("         R <Ficheiro> ➤ Remover Ficheiros\n");
        printf("         J <L,C> ➤ Jogar na Linha L e Coluna C\n");
        printf("         C <Char,Char> ➤ Trocar de peças\n");
        printf("         S ➤ Jogadas Validas\n");
        printf("         H ➤ Sugestao de Jogada\n");
        printf("         U ➤ Undo\n");
        printf("         T ➤ Ficheiros guardados\n");
        printf("         W ➤ Ranking\n");
        printf("         Q ➤ Sair\n\n");
        printf("       ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    }

    switch (e->peca){

        case VALOR_X:
            printf("reversi %c ➤ ",e->icon[0]);
            break;
        case VALOR_O:
            printf("reversi %c ➤ ",e->icon[1]);
            break;
        default:
            printf("reversi ? ➤ ");
            break;
    }
}



///interpreta o carater dado ao interpretador
void Intepretador (ESTADO *e) {
    char linha[256];

    PrintInterpretador(e);

    while ( fgets(linha,256,stdin) ) {

        Interpreta(e,linha);
        PrintInterpretador(e);

    }

}