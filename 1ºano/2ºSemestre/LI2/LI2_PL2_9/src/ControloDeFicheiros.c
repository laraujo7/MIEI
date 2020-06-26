#include "ControloDeFicheiros.h"
#include <stdio.h>
#include <string.h>

/** Com a ajuda da funçao "ProcuraFicheiro" vamos ao ficheiro com a lista dos ficheiros guardados, em seguida criamos um ficheiro temporario que ira receber tudo,
 * excepto o ficheiro selecionado para ser fechamos os ficheiros e abrimos um novo "ficheiros.txt" vazio e copiamos para la o temporario por fim removemos o
 * temporario e o ficheiro selecionado
*/
void RemoveFicheiro(char *linha) {
    int n;
    char cmd[256];
    char copy[256];
    char ficheiro[256];

    n = sscanf(linha,"%s %s",cmd,ficheiro);

    if (n==2) {

        if (ProcuraFicheiro(ficheiro)) {


            FILE *p = fopen("temporario.txt", "w");
            FILE *f = fopen("Ficheiros.txt", "r");

            while (fgets(copy, 256, f)) {

                copy[strlen(copy)-1] = '\0';

                if (strcmp(copy,ficheiro)) fprintf(p, "%s\n", copy);
            }

            fclose(f);
            fclose(p);

            FILE *z = fopen("temporario.txt", "r");
            FILE *d = fopen("Ficheiros.txt", "w");

            while (fgets(copy, 256, z)) {

                fprintf(d, "%s", copy);
            }

            fclose(z);
            fclose(d);


            remove("temporario.txt");
            remove(ficheiro);

            printf("Ficheiro Removido\n\n");

        }

        else printf("O ficheiro nao existe\n\n");
    }

    else printf("erro: é preciso um parâmentro\n\n");

}


///Abre a file com os ficheiros e procura um ficheiro com base no nome do mesmo quando encontrado devolve True caso contrario devolve False
void Leficheiro() {
    int i;
    char linha[256];

    printf("   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("                   Ficheiros Guardados\n\n");

    FILE *f = fopen ("Ficheiros.txt","r");

    for (i=0; fgets(linha,256,f) ; i++) {

        linha[strlen(linha)-1] = '\0';

        if (i==0) printf("     %s",linha);

        else if (i==3) {
            printf("       %s\n\n",linha);
            i=-1;
        }

        else printf("       %s",linha);
    }

    fclose(f);

    if (i % 4 == 0) printf ("\n   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n");
    else printf ("\n\n\n   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n");
}


///precorre a lista de ficheiros do ficheiro e da display dos mesmos
void CriaFiles () {

    FILE *file;
    if ((file = fopen("Ranking.txt", "r"))) fclose(file);
    else {
        file = fopen("Ranking.txt","w");
        fprintf (file,"Position              Nickname              Score\n");
    }

    fclose(file);

    FILE *f;
    if ((f = fopen("Ficheiros.txt", "r"))) fclose(f);
    else {
        f = fopen("Ficheiros.txt","w");
    }

    fclose(f);


}



///Cria um ficheiro dedicado ao ranking que mostra o mesmo com a sua posiçao nome e score caso este(ficheiro) ja exista apenas altera/modifica o mesmo
int ProcuraFicheiro (char *ficheiro) {
    int res = 0;
    char linha[256];

    FILE *f = fopen ("Ficheiros.txt","r");

    while (fgets(linha,256,f) && res == 0) {

        linha[strlen(linha)-1] = '\0';

        if (!strcmp(linha,ficheiro)) res = 1;
    }

    fclose(f);

    return res;
}
