#include <stdio.h>


void LeFicheiro (char v[][4],char inicio[][4],int guarda) {
    int i = 0, j, L, C;
    FILE *f = fopen("tabuleiro.txt", "r");

    fscanf(f, "%d %d", &L, &C);

    if (guarda == 0) {

        for (i = 0; i < L; i++) {
            for (j = 0; j < C; j++) {
                fscanf(f, " %c", &v[i][j]);
            }

        }

        fclose(f);

        for (i = 0; i < L; i++) {
            for (j = 0; j < C; j++) {
                inicio[i][j]=v[i][j];
            }

        }

    }
        else {

        for (i = 0; i < L; i++) {
            for (j = 0; j < C; j++) {
                fscanf(f, " %c", &v[i][j]);
                }

            }
        }

        printf("               *---------*\n");
        printf("               | ");
        for (i = 0; i < L; i++) {
            for (j = 0; j < C; j++) {
                printf("%c ", v[i][j]);
            }
            if (i + 1 < L) printf("|\n               | ");


        }
        printf("|\n");
        printf("               *---------*\n");

}

void Jogada (char v[][4],char inicio[][4],int guarda) {
    int linha,coluna;
    char simbolo;

    printf ("Em que posiçao pretende fazer a jogada : \n");
    printf ("Linha : ");
    scanf (" %d",&linha);

    if (linha >=1 && linha <= 3) {

        printf("Coluna : ");
        scanf(" %d", &coluna);

        if (coluna >= 1 && coluna <= 4) {

            printf("Qual é o simbolo que deseja jogar (O ou X) : ");
            scanf(" %c", &simbolo);

            if (simbolo == 'X' || simbolo == 'O') {

                    if (v[linha-1][coluna-1] == '.') {
                        v[linha - 1][coluna - 1] = simbolo;
                        printf("\n\n");
                    }

                    else {
                        printf("\n\n\n\n\n\n------------ Jogada Impossivel ------------\n\n");
                        printf("              Volte a tentar\n\n");
                        LeFicheiro(v,inicio,guarda);
                        printf("\n\n");
                        Jogada(v,inicio,guarda);
                    }



            } else {
                printf("\n\n\n\n\n\n------------ Simbolo Invalida ------------\n\n");
                printf("              Volte a tentar\n\n");
                LeFicheiro(v,inicio,guarda);
                printf("\n\n");
                Jogada(v,inicio,guarda);
            }
        }
        else {
            printf("\n\n\n\n\n\n------------ Coluna Invalida ------------\n\n");
            printf("              Volte a tentar\n\n");
            LeFicheiro(v,inicio,guarda);
            printf("\n\n");
            Jogada(v,inicio,guarda);
        }
    }

    else {
        printf("\n\n\n\n\n\n------------- Linha Invalida -------------\n\n");
        printf("              Volte a tentar\n\n");
        LeFicheiro(v,inicio,guarda);
        printf("\n\n");
        Jogada(v,inicio,guarda);
    }
}

void PrintNoFicheiro (char v[][4]) {
    int i=0,j=0,Li,Co;

    FILE *f = fopen("tabuleiro.txt","r");

    fscanf (f,"%d %d",&Li,&Co);

    fclose(f);

    FILE *t = fopen ("tabuleiro.txt","w");

    fprintf(f,"%d %d\n",Li,Co);

    for (i=0 ; i<Li ; i++) {
        for (j=0; j < Co ; j++) {
            fprintf(f,"%c ", v[i][j]);
        }
       if (i+1<Li) fprintf(f,"\n");
    }

    fclose(t);


    printf("\n\n");

}

void VerificaJogo (char v[][4],char inicio[][4]) {
    int i,j,res=0;

    for (i=0 ; i<3 ; i++) {
        for (j = 0; j < 4; j++) {
            if (v[i][j] == '.') res = 1;
        }
    }

    if (res==0) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf ("        Jogo acabado e reiniciado");
        PrintNoFicheiro(inicio);

    }

}

void menu (char v[][4],int flag,char inicio[][4],int guarda) {
    char option;

    printf ("\n------------- Menu Principal -------------\n\n");

    if (flag==1) {
        LeFicheiro(v,inicio,guarda);
    }

    printf ("\n------------------------------------------\n");
    printf ("[1] - Abrir o Ficheiro\n");
    printf ("[2] - Faz Jogada\n");
    printf ("[3] - Reiniciar Jogo\n");
    printf ("[4] - Sair\n");



    scanf (" %c",&option);

    if (flag == 1) {

        switch (option) {

            case '1' :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                menu (v,flag,inicio,guarda);
                break;

            case '2' :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                LeFicheiro(v,inicio,guarda);
                guarda=1;
                printf ("\n\n");
                Jogada(v,inicio,guarda);
                PrintNoFicheiro(v);
                VerificaJogo(v,inicio);
                menu (v,flag,inicio,guarda);
                break;

            case '3' :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                PrintNoFicheiro(inicio);
                menu (v,flag,inicio,guarda);
                break;

            case '4' :
                PrintNoFicheiro(inicio);
                break;

            default :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("           Numero mal introduzido\n\n");
                menu (v,flag,inicio,guarda);
                break;
        }
    }

    else {

        switch (option) {

            case '1' :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                flag=1;
                menu (v,flag,inicio,guarda);
                break;

            case '2' :
            case '3' :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf ("        Tem de primeiro ler o Ficheiro \n");
                menu (v,flag,inicio,guarda);
                break;

            case '4' :
                break;

            default:
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("          Numero mal introduzido\n\n");
                menu (v,flag,inicio,guarda);
                break;
        }
    }
}

int main() {
    int flag=0,guarda=0;
    char v[3][4],inicio[3][4];
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    menu (v,flag,inicio,guarda);

    return 0;
}
