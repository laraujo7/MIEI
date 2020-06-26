#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


/** variavel global */ 
int vector1[5];

int main(){
    int i,j;

    /** variavel automatica */
    int vector2[5];

    /** memoria alocada dinamicamente */
    int *vector3 = malloc(5 * sizeof(int));

    /**
     * Exercicio 2
     */
    puts("   ->  Exercicio 2 <-\n");

    puts("     Funcoes fill");

    fill(vector1,5,10);
    fill(vector2,5,10);
    fill(vector3,5,10);

    for(i=0 ; i<3 ; i++){
        printf("vector%d ->",i+1);

        for(j=0 ; j<5 ; j++) {
            if(i==0) printf(" %d",vector1[j]);
            if(i==1) printf(" %d",vector2[j]);
            if(i==2) printf(" %d",vector3[j]);
        }
        puts("");
    }

    printf("\n     Funcoes find \n       ");
    printf("%d  ",find(vector1,5,9));
    printf("%d  ",find(vector2,5,11));
    printf("%d",find(vector3,5,10));
    puts("\n");


    /**
     * Exercicio 3
     * Diga mos que estamos a procura do indice com valor 123
     */

    


    int value = 123;
    for(i=1000 ; i < 2000 && vector1[i] != value ; i++);
    for(i=1000 ; i < 2000 && vector2[i] != value ; i++);
    for(i=1000 ; i < 2000 && vector3[i] != value ; i++);

    //respostas i;

    /**
     * Exercicio 4
     * Esta escrita e leitura é possivel porem perigosa. Visto que estamos a escrever
     * num local onde a memoria nao foi alocada para guardar inteiros, ou seja, estamos
     * a escrever em cima de memoria a qual nao sabemos para que é que esta a ser
     * utilizada.
     */ 

    puts("   ->  Exercicio 4 <-\n");

    vector1[10] = 10;
    vector2[10] = 10;
    vector3[10] = 10;

    printf("vector1 -> %d\n",vector1[9]);
    printf("vector2 -> %d\n",vector2[9]);
    printf("vector3 -> %d\n",vector3[10]);

    return 0;
}