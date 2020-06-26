#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>


///guarda na stack o estado atual do jogo
void push (ESTADO *e) {
    int i,j;
    Undo avanca = e->undoEstado;
    Undo auxiliar;

    auxiliar = malloc(sizeof(struct Node));

    auxiliar->UndoJogador = e->peca;

    for (i=0 ; i<8 ; i++) {
        for (j=0 ; j<8 ; j++) {
            auxiliar->UndoGrelha[i][j] = e->grelha[i][j];
        }
    }

    auxiliar->prox = 0;


    if (!e->undoEstado) e->undoEstado = auxiliar;

    else {

        for (; avanca->prox ; avanca = avanca->prox)
            ;

        avanca->prox = auxiliar;

    }



}


///retira o primeiro elemenento da stack
void EfetuaUndo (ESTADO *e) {

    pop(e);

    if (e->jogadas > 0) e->jogadas--;


}



///retira o primeiro elemento da stack
void pop (ESTADO *e) {
    int i,j;
    Undo anterior ;
    Undo auxiliar = e->undoEstado;

    if (e->undoEstado) {

        anterior = auxiliar;
        auxiliar = auxiliar->prox;

        if (auxiliar) {

            for (; auxiliar->prox ; anterior = auxiliar , auxiliar = auxiliar->prox )
                ;

            free(auxiliar);
            anterior->prox = 0;

            e->peca = anterior->UndoJogador;

            for (i=0 ; i<8 ; i++) {
                for (j=0 ; j<8 ; j++) {

                    e->grelha[i][j] = anterior->UndoGrelha[i][j];

                }
            }

        }

        else printf ("Nao é possivel voltar mais atras\n\n");

    }

    else printf("Nenhum jogo inicializado\n\n");
}


///limpa a stack ate um estado inicial(Vazio)
void LimpaStack (ESTADO *e) {

    if (e->undoEstado) {

        while (e->undoEstado->prox) {
            pop(e);
        }
    }
}
