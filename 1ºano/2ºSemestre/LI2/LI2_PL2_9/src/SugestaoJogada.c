#include "SugestaoJogada.h"
#include <stdio.h>

///Insere o '?' na matriz MatrizAjuda dependendo dos valores presentes na matriz matrizValores
void SugestaoJogada (ESTADO *e) {
    int i,j,maior,flag = 0;
    int x,y;

    for (i=0 ;i<8 ; i++) {
        for (j=0 ; j<8 ; j++) {

            if (e->MatrizAjuda[i][j] == '.') {

                if (flag == 0) {

                    maior = e->matrizValores[i][j];
                    x = i;
                    y = j;
                    flag++;

                }

                else {

                    if (maior < e->matrizValores[i][j]) {

                        maior = e->matrizValores[i][j];
                        x = i;
                        y = j;

                    }


                }


            }

        }
    }


    if (flag > 0) e->MatrizAjuda[x][y] = '?';


}
