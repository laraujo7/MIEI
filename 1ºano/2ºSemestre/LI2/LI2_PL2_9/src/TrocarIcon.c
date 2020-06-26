#include "TrocarIcon.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>


///Troca os icons jogaveis(X e O)
void TrocaIcon (ESTADO *e, char *linha) {
    int n;
    char cmd[256];
    char peca1[256];
    char peca2[256];

    n = sscanf (linha,"%s %s %s",cmd,peca1,peca2);

    if (n == 3) {

        if (strlen(peca1) == 1 && strlen(peca2) == 1 && strcmp(peca1,peca2)) {
            e->icon[0] = toupper (peca1[0]);
            e->icon[1] = toupper (peca2[0]);
        }

        else {
            if (strlen(peca1) > 1) printf("erro: Peca 1 nao é um caracter\n\n");
            else if (strlen(peca2) > 1) printf("erro: Peca 2 nao é um caracter\n\n");
            else printf("Nao é possivel que 2 jogadores tenham a mesmo character\n\n");
        }


    }

    else printf("erro: é preciso um parâmetro\n\n");
}

