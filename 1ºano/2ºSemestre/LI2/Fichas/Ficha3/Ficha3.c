#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*
int verificaRep (int a,int *controlo,int p ) {

    int i;

    for (i=0 ; i<p ; i++) {

        if (a == controlo[i] || a+32 == controlo[i] || a-32 == controlo[i]) return 1;

    }

    return 0;
}



void repetidos (char *frase,int *letras) {
    int repetidos,z,l,i,v,p=0,controlo [256];
    float tamanho;

    tamanho = strlen (frase);

    for (l=0 ; l < tamanho ; l++) {

        repetidos = 0;

        for (i = l; i < tamanho; i++) {

            if (frase[l] == frase[i] || frase[l] == frase[i]+32 || frase[l] == frase[i]-32)
                repetidos++;


        }

        if (verificaRep(frase[l], controlo, p) == 0) {

            controlo[p] = frase[l];
            p++;

            if (frase[l] - 65 >= 0 && frase[l] - 65 <= 26) {

                for (v = 0; v != (frase[l] - 65); v++) {

                }
                letras[v] = repetidos;


            }

            else if (frase[l] - 97 >= 0 && frase[l] - 97 <= 26) {

                for (z = 0; z != (frase[l] - 97); z++) {
                }
                letras[z] = repetidos;
            }

        }

    }
}

*/


void repetidos (char s[],int letras []) {
    int i ;

    for (i = 0; s[i] ; i++) {

        if (s[i] >= 'a' && s[i] <= 'z') {

            letras[s[i] - 'a']++;

        } else if (s[i] >= 'A' && s[i] <= 'Z') {

            letras[s[i] - 'A']++;
        }

    }
}


int numeroMaximoArray (int *letras) {
    int maior=letras[0],i;

    for (i=1 ; i<26 ; i++) {
        if (letras[i] > maior) maior = letras[i];
    }
        return maior;
}


void desenhaGrafico (int *letras) {
    int i,j,maior;

    maior = numeroMaximoArray (letras);

    for (i=maior ; i>0 ; i--) {

        if (maior >= i) {

            for (j = 0; j < 26; j++) {

                if (letras[j] == i) {

                    printf("x ");
                    letras[j] -= 1;

                }

                else printf("  ");
            }
            printf ("\n");
        }
        else printf ("\n");
    }

    for (i=0 ; i<26 ; i++) {
        printf("%c ", ('A' + i));
    }
    printf("\n");

}


int main () {
    char frase [256];
    int letras [26] = {0};

    printf ("Insert your sentence : ");
    fgets (frase,256,stdin);
    printf("\n");

    repetidos (frase,letras);
    desenhaGrafico (letras);


    return 0;
}