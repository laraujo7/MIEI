#include "NJogadasValidas.h"


///ve o numero de ' . ' na matriz ( jogadas validas)
int NumeroP (char MatrizAjuda[][8]) {
    int i,j,res=0;


    for (i=0 ; i<8 ; i++) {
        for (j=0 ; j<8 ; j++) {
            if (MatrizAjuda[i][j] == '.') res++;
        }
    }

    return res;
}
