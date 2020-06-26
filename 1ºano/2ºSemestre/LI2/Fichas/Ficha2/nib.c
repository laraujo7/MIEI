#include "nib.h"

char* indicaBanco (char *a) {
    char Bancos[11][17] = {"Novo Banco","BPI","Santander Totta","BBVA","Millenium BCP","Caixa Geral Dep.","Montepio Geral","Credito Agricola","Banco CTT","Bankinter","Banco Popular"};
    char indicaBancos[11][5] = {"0007","0010","0018","0019","0033","0035","0036","0045","0193","0269","0046"};
    char nibBanco [4];
    int l,k=0;
    strncpy (nibBanco,a,4);
    for (l=0;l<12;l++) {
        if (strcmp (nibBanco,indicaBancos[l])==0) {printf ("%s\n",Bancos[l]);k=1; break;}

    }
    if (k==0) printf ("Banco Invalido");
}


void numeroConta (char a[21]) {
    int j;
    char k = '0';
    for (j = 8; j < 19; j++)
        if (a[j] == '0' && k == '0') ;
        else if (a[j] != '0' && k == '0') {
            k = '1' ;
            printf("%c", a[j]);
        }
        else {printf("%c", a[j]);}

    printf ("\n");
}

void numeroControlo (char a[21]) {
    int h;
    for (h=19 ; h<21 ; h++) {printf("%c",a[h]);}
    printf("\n");
}

void nibCompleto (char a[21]){
    int c;
    for (c=0 ; c<4 ; c++)
    {printf("%c",a[c]);}
    printf("     ");
    for (c=4 ; c<8 ; c++)
    {printf("%c",a[c]);}
    printf("     ");
    for (c=8 ; c<19 ; c++)
    {printf("%c",a[c]);}
    printf("     ");
    for (c=19 ; c<21 ; c++)
    {printf("%c",a[c]);}
    printf("\n");
}


void leNIB (char a[22],int *b) {
    int x=0;
    char z[22];
    char var;
    char controlo;


    printf ("Introduza o seu NIB : ");
    scanf ("%c",&controlo);


    while (x<21) {

        var = getchar ();

        if (var >= '0' && var <='9' && var!='\n') {
            z[x] = var;
            x++;
        }
        else {
            x+=21;
            controlo='k';
        }

    }

    if (controlo=='k') printf ("NIB mal introduzido\n");
    else {
        scanf("%c", &controlo);
        if (controlo != '\n') printf("NIB mal introduzido\n");
        else {
            *b=1;
            for (x=0 ; x<21 ; x++) {
                a[x]=z[x];
            }
            a[21]='\0';
        }

    }

}

void verificacaoNib (char *a) {
    int soma=0,i,x,temp [2],var1,var2;
    int verif[19] = {73,17,89,38,62,45,53,15,50,5,49,34,81,76,27,90,9,30,3};

    temp[0] = a[19] - '0';
    temp[1] = a[20] - '0';

    for (i=0 ; i<19 ; i++) {

        soma += (a[i] - '0') * verif[i];

    }

    x = soma / 97;

    x *=97;

    soma -= x;

    soma = 98 - soma;




    if (soma < 10) {

        if (soma == temp [1]) printf("Valido !\n");

        else printf("NIB Valido !\n");
    }

    else {
        var1 = soma/10;
        var2 = soma - var1*10;

        if (var1 == temp [0] && var2 == temp [1]) {

            printf("Valido !\n");
        }
        else printf("Invalido !\n");
    }

}








void menuPrincipal1 (char a[22],int b) {
    int z;
    char option;
    printf ("------------------------------------ Menu Principal ------------------------------------\n");

    if (a[21]=='\0') {
        printf("O seu NIB : ");

        for (z = 0; z < 21; z++)
            printf("%c", a[z]);
    }

    printf ("\n----------------------------------------------------------------------------------------\n");
    printf ("[1] - Lê NIB\n");
    printf ("[2] - Banco\n");
    printf ("[3] - Número da conta (sem zeros a esquerda)\n");
    printf ("[4] - Número de controlo\n");
    printf ("[5] - NIB (com espaços)\n");
    printf ("[6] - Verificar o NIB\n");
    printf ("[7] - Sair\n");


    scanf(" %c", &option);

    if (b == 1) {

        switch (option) {
            case '1' :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                leNIB(a,&b);
                menuPrincipal1(a, b);
                break;
            case '2' :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("Banco : ");
                indicaBanco(a);
                printf("\n");
                menuPrincipal1(a, b);
                break;
            case '3' :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("Número da conta : ");
                numeroConta(a);
                printf("\n");
                menuPrincipal1(a, b);
                break;
            case '4' :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("Número de controlo : ");
                numeroControlo(a);
                printf("\n");
                menuPrincipal1(a, b);
                break;
            case '5' :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("Banco   Agencia     NºConta     NºControlo\n");
                nibCompleto(a);
                printf("\n");
                menuPrincipal1(a, b);
                break;
            case '6' :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf ("O seu NIB é ");
                verificacaoNib (a);
                printf("\n");
                menuPrincipal1(a,b);
                break;
            case '7' :
                break;
            default :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("                                ------------------------\n");
                printf("                               | Número mal introduzido |\n");
                printf("                                ------------------------\n");
                printf("\n");
                menuPrincipal1(a, b);
                break;

        }
    }
    else {
        switch (option) {
            case '1' :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                leNIB(a,&b);
                menuPrincipal1(a, b);
                break;
            case '2' :
            case '3' :
            case '4' :
            case '5' :
            case '6' :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf ("NIB nao introduzido\n");
                menuPrincipal1(a, b);
                break;
            case '7' :
                break;
            default :
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("                                ------------------------\n");
                printf("                               | Número mal introduzido |\n");
                printf("                                ------------------------\n");
                printf("\n");
                menuPrincipal1(a, b);
                break;
        }
    }

}
