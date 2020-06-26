#include "ContadorIcons.h"

///conta o numero de peças do VALOR_X (X) no tabuleiro atual
int NumeroJ1 (ESTADO *e) {
    int i,j,res=0;

    for (i=0 ; i<8 ; i++) {
        for (j=0 ; j<8 ; j++) {
            if (e->grelha[i][j] == VALOR_X) res++;
        }
    }

    return res;
}

///conta o numero de peças do VALOR_O (O) no tabuleiro atual
int NumeroJ2 (ESTADO *e) {
    int i,j,res=0;

    for (i=0 ; i<8 ; i++) {
        for (j=0 ; j<8 ; j++) {
            if (e->grelha[i][j] == VALOR_O) res++;
        }
    }

    return res;
}
