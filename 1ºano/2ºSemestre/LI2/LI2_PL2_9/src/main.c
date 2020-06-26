#include "TrocarIcon.h"
#include "Structs.h"
#include "FuncoesAxuliares.h"
#include "ControloDeFicheiros.h"
#include "Interpretador.h"
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")


///main
int main () {

    int i,j;

    int temporario[8][8] =  {
                            {120, -20, 20, 5, 5, 20, -20, 120},
                            {-20, -40, -5, -5, -5, -5, -40, -20},
                            {20, -5, 15, 3, 3, 15, -5, 20},
                            {5, -5, 3, 3, 3, 3, -5, 5},
                            {5, -5, 3, 3, 3, 3, -5, 5},
                            {20, -5, 15, 3, 3, 15, -5, 20},
                            {-20, -40, -5, -5, -5, -5, -40, -20},
                            {120, -20, 20, 5, 5, 20, -20, 120}
                            };



    ESTADO e = {0};

    e.jogadas = -1;

    e.icon[0]='X';
    e.icon[1]='O';
    e.icon[2]='-';
    e.icon[3]='.';
    e.icon[4]='?';

    e.undoEstado = 0;


    for (i=0 ; i < 8 ; i++) {
        for (j=0 ; j < 8 ; j++) {
            e.matrizValores[i][j] = temporario[i][j];
        }
    }


    CriaFiles();
    LoadRanking(&e);


    clrscr();

    Intepretador(&e);



    return 0;
}