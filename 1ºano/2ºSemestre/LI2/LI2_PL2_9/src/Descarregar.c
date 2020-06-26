#include "Descarregar.h"
#include <stdio.h>

/**Carrega um jogo anterior em desenvolvimento começando por limpar a stack
 * e descarregar para a mesma do jogo que foi selecionada e no fim colocando
 * o tabuleiro atual de jogo
*/
void LoadEstado (ESTADO *e,char *linha) {
    int n,i,j,flag = 0;
    char modo[256];
    char jogador[256];
    char nivel[256],c;
    char guardaLinha[256];
    char cmd[256];
    char ficheiro[256];
    FILE *f;


    n = sscanf(linha,"%s %s",cmd,ficheiro);

    if (n == 2) {


        if (f = fopen(ficheiro, "r")) {

            if (!ProcuraFicheiro(ficheiro)) {
                AcrescentaFicheiro(ficheiro);
            }

            LimpaStack(e);


            while (fgets(guardaLinha,256,f)) {

                sscanf(guardaLinha,"%s %s",modo,jogador);

                if ((modo[0] == 'M' || modo[0] == 'A') && flag == 0) {
                    e->modo = modo[0];

                    if (modo[0] == 'M') e->dificuldade = 0;
                }


                if (e->modo == 'M' && flag < 2) {
                    e->icon[flag] = jogador[0];
                    flag++;
                }

                else if (e->modo == 'A' && flag == 0) {
                    e->icon[flag] = jogador[0];
                    flag++;
                }


                if (e->modo == 'A') {

                    sscanf(guardaLinha,"%s %s %s",modo,jogador,nivel);

                    if (flag == 1) e->dificuldade = nivel[0] - '0';
                }

                if (jogador[0] == e->icon[0]) e->peca = VALOR_X;
                else e->peca = VALOR_O;

                for (i=0 ; i<8 ; i++) {
                    for (j=0 ; j<8 ; j++) {

                        fscanf(f,"%c ",&c);

                        if (e->icon[0] == c) {
                            e->grelha[i][j] = VALOR_X;
                        }

                        else if (e->icon[2] == c) {
                            e->grelha[i][j] = VAZIA;
                        }

                        else {
                            e->grelha[i][j] = VALOR_O;

                            if (flag == 1) {
                                e->icon[1] = c;
                            }
                        }

                    }
                }

                push(e);


            }

            fclose(f);


            e->jogadas = CalculaNumeroJogadas(e);



        }

        else printf("O Ficheiro nao existe\n\n");




    }

    else printf("erro: é preciso um parâmentro\n\n");

}


///calcula o numero de jogodas realizadas num jogo
int CalculaNumeroJogadas (ESTADO *e) {
    int numeroJ1,numeroJ2,res;

    numeroJ1 = NumeroJ1(e);
    numeroJ2 = NumeroJ2(e);

    res = (numeroJ1 + numeroJ2) - 4;


    return res;
}