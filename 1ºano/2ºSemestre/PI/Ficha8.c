#include <stdio.h>
#include <string.h>

int main (int argc,char *argv[]) {
    FILE *input;
    Dicionario d1;
    int r=0, count = 0;
    char word[100];

    initDic(&d1);

    if (argc == 1) input = stdin;
    else input = fopen(argv[1],"r");

    if (input == NULL) r=1;

    else {
        while (fscanf(input,"%s",word)==1) {
            acrescenta(&d1,word);
        }

        fclose(input);
        printf ("%s - %d ",maisFreq(d1,&count),count);
    }
    return r;
}
 
/*

           ------
          | argc - 1
$ p.exe  =|
          | argv - {"p.exe"}
          |
           -----

                     ------
                    | argc - 2
                    |
$ p.exe teste.txt = |
                    |
                    | argv - {"p.exe","teste.txt"}
                     -----

*/

typedef Palavras Dicionario;

typedef struct entrada {
    char *palavra;
    int ocorr;
    struct entrada *prox;
} *Palavras;

//1
void initDic (Dicionario *d) {
    *d = NULL;
}

int acrescenta (Dicionario *d, char *p) {
    Dicionario t = *d;
    Dicionario pr,ant; 
    

    while (t) {

        if (strcmp(t->palavra,p) == 0) {
        t->ocorr++;
        return t->ocorr;
        }

        else if (strcmp (t->palavra,p) == 1) {
        pr = malloc (sizeof(struct entrada));  //strdup (palavra) <---------------- IMPORTANTE (faz malloc e copia string);
        pr->palavra = p;                       // char *nova = (char *) malloc (sizeof (strlen(palavra)+1));
        pr->ocorr = 1;                         // strcpy(nova,palavra);
        pr->prox = t->prox;                    //
        t = pr;
        return 1;
        }


        else {
            t = t->prox;
            ant = t;
    }

    if (t == NULL) {
        pr = malloc (sizeof(struct entrada));  
        pr->palavra = p;                       
        pr->ocorr = 1;                         
        pr->prox = NULL;                      
        ant = pr;
        return 1;
    }
    

}

char *maisFreq (Dicionario d,int *c) {
    int count = 0;
    char *palavra = NULL;

    d = d.prox;

    while (d) {
        if (d->ocorr > count) {
            count = d->ocorr;
            palavra = d->palavra;
        }
        d = d->prox;
    }
    *c = maior;

    return palavra;

}



#define HSIZE 1000
typedef Palavras Dicionario[HSIZE];

int hash (char *pal, int s){            // [0,(HSIZE-1)]
    int r;
    for (r=0; *pal != ’\0’; pal++)
    r += *pal;
return (r%s);
}


int acrescentaH(Dicionario d1,char *p) {
    return acrescenta(&d1[hash(pal,HSIZE)],pal);
}