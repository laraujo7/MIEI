#include "Salvar.h"
#include "ControloDeFicheiros.h"
#include <stdio.h>
#include <string.h>


///acrescenta a um ficheiro um nome de um ficheiro
void AcrescentaFicheiro(char *ficheiro) {

    FILE *f = fopen ("Ficheiros.txt","a+");

    fprintf (f,"%s\n",ficheiro);

    fclose(f);
}


///Guarda no ficheiro o estado do jogo ( comando E do interpretador)
void SaveEstado (ESTADO *e,char *linha) {
    Undo auxiliar = e->undoEstado;
    int n,i,j;
    char cmd[256];
    char ficheiro[256];

    n = sscanf(linha,"%s %s",cmd,ficheiro);

    if (n == 2) {

        if (!ProcuraFicheiro(ficheiro)) {
            AcrescentaFicheiro(ficheiro);
        }

        FILE *f = fopen (ficheiro,"w");

        while (auxiliar) {

            if (e->modo == 'M') {

                if (auxiliar->UndoJogador == VALOR_X) fprintf(f,"%c %c\n",e->modo,e->icon[0]);

                else fprintf(f,"%c %c\n",e->modo,e->icon[1]);
            }

            else {

                if (auxiliar->UndoJogador == VALOR_X) fprintf(f,"%c %c %d\n",e->modo,e->icon[0],e->dificuldade);

                else fprintf(f,"%c %c %d\n",e->modo,e->icon[1],e->dificuldade);
            }

            for (i=0 ; i<8 ; i++) {
                for (j=0 ; j<8 ; j++) {

                    switch (auxiliar->UndoGrelha[i][j]) {

                        case VALOR_X:
                            fprintf(f,"%c ",e->icon[0]);
                            break;

                        case VALOR_O:
                            fprintf(f,"%c ",e->icon[1]);
                            break;

                        default:
                            fprintf(f,"%c ",e->icon[2]);
                            break;
                    }

                }

                fprintf(f,"\n");

            }

            fprintf(f,"\n");

            auxiliar = auxiliar ->prox;
        }

        fclose(f);

        printf("Jogada salvada\n\n");


    }


    else printf("erro: é preciso um parâmentro\n\n");


}