#include "menu.h"

static char *menu[14] = {
    "Files Info",
    "Products Started by Letter",
    "Profit And Sales By a Product In a Month",
    "Products Never Bought",
    "Clients That Bought In All Branches",
    "Count Of Clients And Products That Never Bought",
    "Products Bought By Client",
    "Sales And Profit",
    "Product Buyers",
    "Favorite Products Of a Client",
    "Top Selled Products", 
    "Top Profit Products Of a Client", 
    "Data From Files Info",
    "Exit",
};


static char *infoLoad[10] = {
    "                                            Clients File Loaded ➤ ",
    "                                            Nº Of Lines Read From Clients File ➤ ",
    "                                            Clients Validated ➤ ",
    "                                            Products File Loaded ➤ ",
    "                                            Nº Of Lines Read From Products File ➤ ",
    "                                            Products Validated ➤ ",
    "                                            Sales File Loaded ➤ ",
    "                                            Nº Of Lines Read From Sales File ➤ ",
    "                                            Sales Validated ➤ ",
    "                                            RunTime ➤ ",
};

void getEnter() {
    while (getchar() != '\n');
}

void enterToContinue(){
    puts(COR_B_VERMELHO PISCAR"\n\n\n\n                                                     Click Enter to Continue\n" COR_RESET RESET);
    getEnter();
}

int showMenuOption(){
    int res = 0;
    int invalido = 0;

    while(res != 1 && res != 2) {
    system("clear");
    if(!invalido)puts("\n\n\n\n\n");

    if(invalido) {
        puts("\n\n\n");
        puts(COR_B_VERMELHO"                                                         Invalid Option\n"COR_RESET);
        invalido = 0;
    }

    parteDeCimaMenu();
    letrasSGV();
    puts("\n");
  printf(COR_B_VERMELHO"                                 【1】➤  "COR_RESET);
  printf("Normal");
  printf(COR_B_VERMELHO"                               【2】➤  "COR_RESET);
    puts("Iterative");

    puts(COR_B_VERMELHO"                       █████████████████████████████████████         █████████████████████████████████████"COR_RESET);
    puts(COR_B_VERMELHO"                       ██╔═══════════════════════════════╗██         ██╔═══════════════════════════════╗██"COR_RESET);
    puts(COR_B_VERMELHO"                      ██╔╝                               ╚╗██       ██╔╝                               ╚╗██"COR_RESET);
  printf(COR_B_VERMELHO"                      ██║"COR_RESET);
  printf(COR_B_VERDE"            【MENU】             "COR_RESET);
  printf(COR_B_VERMELHO"║██       ██║"COR_RESET);
  printf(COR_B_VERDE PISCAR"            【MENU】             "RESET COR_RESET );
  puts(COR_B_VERMELHO"║██"COR_RESET);
    puts(COR_B_VERMELHO"                      ██╚╗                               ╔╝██       ██╚╗                               ╔╝██"COR_RESET);
    puts(COR_B_VERMELHO"                       ██╚═══════════════════════════════╝██         ██╚═══════════════════════════════╝██"COR_RESET);
    puts(COR_B_VERMELHO"                       █████████████████████████████████████         █████████████████████████████████████"COR_RESET);

    puts("");
    parteDeBaixoMenu();
    printf(COR_B_VERDE"\n                                                          Opção : "COR_RESET);
    scanf(" %d",&res);
    getEnter();
    if(res!= 1 && res!=2) invalido = 1;

    }

    return res;
}

void parteDeCimaMenu(){
    puts(COR_B_VERMELHO"           ███████████████████████████████████████████████████████████████████████████████████████████████████████████" COR_RESET);
    puts(COR_B_VERMELHO"           ██╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗██" COR_RESET);
    puts(COR_B_VERMELHO"           ██║                                                                                                     ║██" COR_RESET);
    puts(COR_B_VERMELHO"           ╚═╝                                                                                                     ╚═╝" COR_RESET);
}

void letrasSGV(){
    puts(COR_B_AMARELO"                                                    ███████╗ ██████╗ ██╗   ██╗"COR_RESET);
    puts(COR_B_AMARELO"                                                    ██╔════╝██╔════╝ ██║   ██║"COR_RESET);
    puts(COR_B_AMARELO"                                                    ███████╗██║  ███╗██║   ██║"COR_RESET);
    puts(COR_B_AMARELO"                                                    ╚════██║██║   ██║╚██╗ ██╔╝"COR_RESET);
    puts(COR_B_AMARELO"                                                    ███████║╚██████╔╝ ╚████╔╝ "COR_RESET);
    puts(COR_B_AMARELO"                                                    ╚══════╝ ╚═════╝   ╚═══╝  "COR_RESET);
}

void dataPalavra(){
    puts(COR_B_AMARELO"                                                 ██████╗  █████╗ ████████╗ █████╗ "COR_RESET);
    puts(COR_B_AMARELO"                                                 ██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗"COR_RESET);
    puts(COR_B_AMARELO"                                                 ██║  ██║███████║   ██║   ███████║"COR_RESET);
    puts(COR_B_AMARELO"                                                 ██║  ██║██╔══██║   ██║   ██╔══██║"COR_RESET);
    puts(COR_B_AMARELO"                                                 ██████╔╝██║  ██║   ██║   ██║  ██║"COR_RESET);
    puts(COR_B_AMARELO"                                                 ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝"COR_RESET);
}


void menuPalavra(){
    puts(COR_B_AMARELO"                                               ███╗   ███╗███████╗███╗   ██╗██╗   ██╗" COR_RESET);
    puts(COR_B_AMARELO"                                               ████╗ ████║██╔════╝████╗  ██║██║   ██║" COR_RESET);
    puts(COR_B_AMARELO"                                               ██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║" COR_RESET);
    puts(COR_B_AMARELO"                                               ██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║" COR_RESET);
    puts(COR_B_AMARELO"                                               ██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝" COR_RESET);
    puts(COR_B_AMARELO"                                               ╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝ " COR_RESET);
}

void parteDeBaixoMenu(){
    puts(COR_B_VERMELHO"           ╔═╗                                                                                                     ╔═╗" COR_RESET);
    puts(COR_B_VERMELHO"           ██║                                                                                                     ║██" COR_RESET);
    puts(COR_B_VERMELHO"           ██╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝██" COR_RESET);
    puts(COR_B_VERMELHO"           ███████████████████████████████████████████████████████████████████████████████████████████████████████████" COR_RESET);
}

void loading(){
    printf(ESCONDE_CURSOR);
    system("clear");
    puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    puts(COR_B_VERMELHO PISCAR"                                                   ███████████████████████████" COR_RESET RESET);
    puts(COR_B_VERMELHO PISCAR"                                                   ██╔═════════════════════╗██" COR_RESET RESET);
    puts(COR_B_VERMELHO PISCAR"                                                   ██║      LOADING....    ║██" COR_RESET RESET);
    puts(COR_B_VERMELHO PISCAR"                                                   ██╚═════════════════════╝██" COR_RESET RESET);
    puts(COR_B_VERMELHO PISCAR"                                                   ███████████████████████████" COR_RESET RESET);
    puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf(MOSTRA_CURSOR);
}


void parteDeCimaTempos() {
    puts("");
    puts(COR_B_VERMELHO"                                █████████████████████████████████████████████████████████████████" COR_RESET);
    puts(COR_B_VERMELHO"                                ██╔═══════════════════════════════════════════════════════════╗██" COR_RESET);
    puts(COR_B_VERMELHO"                                ╚═╝                                                           ╚═╝" COR_RESET);
}


void parteDeBaixoTempos() {
    puts(COR_B_VERMELHO"                                ╔═╗                                                           ╔═╗" COR_RESET);
    puts(COR_B_VERMELHO"                                ██╚═══════════════════════════════════════════════════════════╝██" COR_RESET);
    puts(COR_B_VERMELHO"                                █████████████████████████████████████████████████████████████████" COR_RESET);
}


int showMenu1(int valid) {
    int i,op;
    system("clear");

    if(valid == -1) printf(COR_B_VERMELHO"\n                                                        Files Yet To Be Read\n\n"COR_RESET);
        else if(!valid) printf(COR_B_VERMELHO"\n                                                        Invalid Option\n\n"COR_RESET);
            else puts("\n\n");

    parteDeCimaMenu();
    menuPalavra();
    puts("");

    for (i = 0; i < 14; i++) {
        
        if (i < 10)
            printf(COR_B_VERDE"                                【%d】➤  " COR_RESET, i);

        else
            printf(COR_B_VERDE"                               【%d】➤  " COR_RESET, i);

        printf("%s\n", menu[i]);
    }

    parteDeBaixoMenu();
    
    printf(COR_B_VERDE" Option : "COR_RESET);
    scanf(" %d",&op);
    getEnter();

    printf(MOSTRA_CURSOR);
    return op;
}



int showAndGetOptionMenu2(int valid) {
    int op = 0;
    char c = 0;


    printf(ESCONDE_CURSOR);

    while(c != ENTER) {
        system("clear");

        if(valid == -1) printf(COR_B_VERMELHO"\n                                                        Files Yet To Be Read\n\n"COR_RESET);
            else puts("\n\n");

        showMenu2(op);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(op < 13 && c == BAIXO) (op)++;
        else if(op > 0 && c == CIMA) (op)--;
        else if(op == 0 && c == CIMA) op = 13;
        else if(op == 13 && c == BAIXO) op = 0;
    }

    return op;
}

void showMenu2(int op){
    int tam,j,i;
    
    parteDeCimaMenu();
    menuPalavra();
    puts("");

    for (i = 0; i < 14; i++) {
        tam = (132 - strlen(menu[i])) / 2;
        for(j=0 ; j<tam ; j++) printf(" ");
        if(op == i) printf(COR_B_VERDE PISCAR);
        printf("%s\n", menu[i]);
        printf(RESET);
    }

    parteDeBaixoMenu();
}


void parteDeCimaTabela() {
    puts(COR_B_VERMELHO"                                 █████████████████████████████████████████████████████████████████"COR_RESET);
    puts(COR_B_VERMELHO"                                 ██╔═══════════════════════════════════════════════════════════╗██"COR_RESET);
}

void parteDeBaixoTabela() {
    puts(COR_B_VERMELHO"                                 ██╚═══════════════════════════════════════════════════════════╝██"COR_RESET);
    puts(COR_B_VERMELHO"                                 █████████████████████████████████████████████████████████████████"COR_RESET);
}

void infoPalavra() {
    int i;
    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_AMARELO"               ██╗███╗   ██╗███████╗ ██████╗"COR_RESET);
    puts(COR_B_VERMELHO"               ║██"COR_RESET);
    
    for(i = 0; i<5 ; i++) {
    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    if(i==0) printf(COR_B_AMARELO"               ██║████╗  ██║██╔════╝██╔═══██╗"COR_RESET);
    if(i==1) printf(COR_B_AMARELO"               ██║██╔██╗ ██║█████╗  ██║   ██║"COR_RESET);
    if(i==2) printf(COR_B_AMARELO"               ██║██║╚██╗██║██╔══╝  ██║   ██║"COR_RESET);
    if(i==3) printf(COR_B_AMARELO"               ██║██║ ╚████║██║     ╚██████╔╝"COR_RESET);
    if(i==4) printf(COR_B_AMARELO"               ╚═╝╚═╝  ╚═══╝╚═╝      ╚═════╝ "COR_RESET);
    puts(COR_B_VERMELHO"              ║██"COR_RESET);
    }
    
    puts(COR_B_VERMELHO"                                 ██║                                                           ║██"COR_RESET);
}

void mostraLetra(char letter){

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"   Left Arrow ➤ "COR_RESET);
    printf("Previous");
    printf(COR_B_VERDE"  Letter ➤ "COR_RESET);
    printf("%c",letter);
    printf(COR_B_VERDE"  Right Arrow ➤ "COR_RESET);
    printf("Next   ");

    puts(COR_B_VERMELHO"║██"COR_RESET);

}


void mostraProdutosQuery2(char** prods, int size, int nPags, int pag){
    int i,j,k,valid=1;
    char str1[256];
    char str2[256];
    int tam = 0;

    puts(COR_B_VERMELHO"                                 ██╠══════════════╦════════╦════════╦════════╦════════╦════════╣██"COR_RESET);

    for(i=0 ; i<8 ; i++) {
        int n1 = (pag*40)+(i*5)+1;
        int n2 = (pag*40)+(i*5)+5;
        if(valid && n2 > size) {
            n2 = size;
            valid = 0;
        }

        if( n1 > n2) {
            n1 = n2;
        }
        sprintf(str1,"%d",n1);
        sprintf(str2,"%d",n2);

        tam = (14 - (strlen(str1) + strlen(str2) + 4) ) / 2;
        printf(COR_B_VERMELHO"                                 ██║"COR_RESET);

        if(valid || n2 == size) {
            for(k=0 ; k<tam ;k++) printf(" ");

            printf(COR_B_VERDE"[%d..%d]"COR_RESET,n1,n2);
        
            tam += (strlen(str1) + strlen(str2) + 4);

            for(; tam < 14 ; tam++) printf(" ");
        }
        else printf("              ");

        printf(COR_B_VERMELHO"║"COR_RESET);

        int n3 = (pag*40)+(i*5);

        for(j=n3 ; j<n3+5 ; j++) {
            if(j < size)
                printf(" %s ",prods[j]);
                else 
                    printf("        ");

            printf(COR_B_VERMELHO"║"COR_RESET);
        }

        puts(COR_B_VERMELHO"██"COR_RESET);



        if(i!=7) puts(COR_B_VERMELHO"                                 ██╠══════════════╬════════╬════════╬════════╬════════╬════════╣██"COR_RESET);

    }

    puts(COR_B_VERMELHO"                                 ██╚══════════════╩════════╩════════╩════════╩════════╩════════╝██"COR_RESET);
    puts(COR_B_VERMELHO"                                 █████████████████████████████████████████████████████████████████"COR_RESET);
}

void miniMenuQuery2(float time,int nPags,int pag,int size){
    int i;
    char strTime[256];
    char strnPags[256];
    char strPag[256];
    char strSize[256];

    sprintf(strTime,"%f",time);
    sprintf(strnPags,"%d",nPags);
    sprintf(strPag,"%d",pag+1);
    sprintf(strSize,"%d",size);
                         
    int tam = (59 - (strlen(strTime) + strlen(strnPags) + strlen(strPag) + strlen(strSize) + 36));

    puts("");
    parteDeCimaTabela();

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);

    for(i=0 ; i< tam/2 ; i++) printf(" ");

    printf(COR_B_VERDE"RunTime ➤ "COR_RESET);
    printf("%f",time);

    printf(COR_B_VERDE" Pags"COR_RESET);
    printf("[%d/%d]",pag+1,nPags);

    if(pag+1 < 10000) printf(COR_B_VERDE" Nº of Products ➤ "COR_RESET);
        else printf(COR_B_VERDE"Nº of Products ➤ "COR_RESET);

    printf("%d",size);

    for(i=tam/2 ; i <tam ; i++) printf(" ");

    puts(COR_B_VERMELHO"║██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██║                      Enter to go Back                     ║██"COR_RESET);
    

    parteDeBaixoTabela();
}

void produtoMesPalavras(char *product,int month) {

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"             PRODUCT ➤ "COR_RESET);
    printf("%s",product);
    printf(COR_B_VERDE"       MONTH ➤ "COR_RESET);
    printf("%d",month+1);
    if(month >= 10) puts(COR_B_VERMELHO"             ║██"COR_RESET);
    else puts(COR_B_VERMELHO"              ║██"COR_RESET);

    
}

void filiaisPalavras() {
    int i;

    puts(COR_B_VERMELHO"                                 ██╠═════╦═════════════════╦═════════════════╦═════════════════╣██"COR_RESET);
    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERMELHO"     ║"COR_RESET);

    for(i=1 ; i<4 ; i++) {

    printf(COR_B_VERDE"    BRANCH %d     "COR_RESET,i);
    if(i!=3)printf(COR_B_VERMELHO BARRA COR_RESET);

    }

    printf(COR_B_VERMELHO"║██\n"COR_RESET);
}

void fatUniPalavras() {
    int i;

    puts(COR_B_VERMELHO"                                 ██║     ╠════════╦════════╬════════╦════════╬════════╦════════╣██"COR_RESET);
    printf(COR_B_VERMELHO"                                 ██║     "COR_RESET);

    for(i= 0 ; i<3 ; i++) {
        printf(COR_B_VERMELHO BARRA COR_RESET);
        printf(COR_B_VERDE" Profit "COR_RESET);
        printf(COR_B_VERMELHO BARRA COR_RESET);
        printf(COR_B_VERDE" Units  "COR_RESET);
        
    }

    puts(COR_B_VERMELHO"║██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██╠═════╬════════╬════════╬════════╬════════╬════════╬════════╣██"COR_RESET);

}

void dadosComprasF(double res[][4]) {
    int i,j,k;
    int tam;

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"  N  "COR_RESET);
    printf(COR_B_VERMELHO BARRA COR_RESET);

    for (i = 0 ; i<3 ; i++) {

        for (j=0 ; j<2 ; j++) {
            char insert[9] = "        ";
            char str[256];

            sprintf(str, "%f", res[i][j]);

            if(strlen(str) >= 8) tam = 0;
                else tam = (8 - strlen(str)) / 2;

            for(k=0 ;str[k] && k < 8;k++) {insert[tam++] = str[k];}

            printf("%s",insert);

            if (i!=2 || j!=1) printf(COR_B_VERMELHO BARRA COR_RESET);
        }

    }

    puts(COR_B_VERMELHO"║██"COR_RESET);
    puts(COR_B_VERMELHO"                                 ██╠═════╬════════╬════════╬════════╬════════╬════════╬════════╣██"COR_RESET);

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"  P  "COR_RESET);
    printf(COR_B_VERMELHO BARRA COR_RESET);

    for (i = 0 ; i<3 ; i++) {

        for (j=2 ; j<4 ; j++) {

            char insert2[9] = "        ";
            char str2[256];

            sprintf(str2, "%f", res[i][j]);

            if(strlen(str2) >= 8) tam = 0;
                else tam = (8 - strlen(str2)) / 2;

            for(k=0; str2[k] && k < 8 ;k++) {insert2[tam++] = str2[k];}

            printf("%s",insert2);

            if (i!=2 || j!=3) printf(COR_B_VERMELHO BARRA COR_RESET);
        }

    }

    puts(COR_B_VERMELHO"║██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██╚═════╩════════╩════════╩════════╩════════╩════════╩════════╝██"COR_RESET);
    puts(COR_B_VERMELHO"                                 █████████████████████████████████████████████████████████████████"COR_RESET);
}

void visaoGlobalPalvra() {

    puts(COR_B_VERMELHO"                                 ██╠═════╦═════════════════════════════════════════════════════╣██"COR_RESET);
    printf(COR_B_VERMELHO"                                 ██║     ║"COR_RESET);
    printf(COR_B_VERDE"                       OVERVIEW                      "COR_RESET);
    puts(COR_B_VERMELHO"║██"COR_RESET);
    puts(COR_B_VERMELHO"                                 ██║     ╠══════════════════════════╦══════════════════════════╣██"COR_RESET);
}


void FatUniPalavrasG() {

    printf(COR_B_VERMELHO"                                 ██║     "COR_RESET);
    printf(COR_B_VERMELHO BARRA COR_RESET);
    printf(COR_B_VERDE"          Profit          "COR_RESET);
    printf(COR_B_VERMELHO BARRA COR_RESET);
    printf(COR_B_VERDE"          Units           "COR_RESET);
    puts(COR_B_VERMELHO"║██"COR_RESET);
    puts(COR_B_VERMELHO"                                 ██╠═════╬══════════════════════════╬══════════════════════════╣██"COR_RESET);

}

void dadosComprasG(double res[][4]){
    int i,tam,k;
    double faturado[2]; /* Normal = 0  && Promocao = 1 */
    double unidades[2];

    faturado[0] = res[0][0] + res[1][0] + res[2][0];
    unidades[0] = res[0][1] + res[1][1] + res[2][1];
    faturado[1] = res[0][2] + res[1][2] + res[2][2];
    unidades[1] = res[0][3] + res[1][3] + res[2][3];

    for (i=0 ; i<2 ; i++) {

        printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
        if(i==0) printf(COR_B_VERDE"  N  "COR_RESET);
        if(i==1) printf(COR_B_VERDE"  P  "COR_RESET);
        printf(COR_B_VERMELHO"║"COR_RESET);

        char insert1[27] = "                          ";
        char str1[256];

        sprintf(str1, "%f", faturado[i]);
        tam = (26 - strlen(str1)) / 2;

        for(k=0;str1[k];k++) {insert1[tam++] = str1[k];}

        printf("%s",insert1);

        printf(COR_B_VERMELHO"║"COR_RESET);

        char insert2[27] = "                          ";
        char str2[256];

        sprintf(str2, "%f", unidades[i]);
        tam = (26 - strlen(str2)) / 2;

        for(k=0;str2[k];k++) {insert2[tam++] = str2[k];}

        printf("%s",insert2);



    puts(COR_B_VERMELHO"║██"COR_RESET);
    if(i==0) puts(COR_B_VERMELHO"                                 ██╠═════╬══════════════════════════╬══════════════════════════╣██"COR_RESET);

    }


    puts(COR_B_VERMELHO"                                 ██╚═════╩══════════════════════════╩══════════════════════════╝██"COR_RESET);
    puts(COR_B_VERMELHO"                                 █████████████████████████████████████████████████████████████████"COR_RESET);
}

void miniMenuQuery3(float time, int op){

    parteDeCimaTabela();

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE" RunTime ➤ "COR_RESET);
    printf("%f",time);

    if(op == 0) printf(PISCAR);
    printf(COR_B_VERDE"        Branches     "COR_RESET RESET);
    if(op == 1) printf(PISCAR);
    printf(COR_B_VERDE"     Global        "COR_RESET RESET);
    puts(COR_B_VERMELHO"║██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██║                      Enter to go Back                     ║██"COR_RESET);

    parteDeBaixoTabela();
}

void mostraFilial(int filial) {

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    if(filial != 3) {
        printf(COR_B_VERDE"  Left Arrow ➤ "COR_RESET);
        printf("Previous");
        printf(COR_B_VERDE"   Branch ➤ "COR_RESET);
        printf("%d",filial+1);
        printf(COR_B_VERDE"  Right Arrow ➤ "COR_RESET);
        printf("Next   ");
        
    }
    else {
        printf(COR_B_VERDE"  Left Arrow ➤ "COR_RESET);
        printf("Previous");
        printf(COR_B_VERDE"     Global    "COR_RESET);
        printf(COR_B_VERDE"Right Arrow ➤ "COR_RESET);
        printf("Next   ");
    }

    puts(COR_B_VERMELHO"║██"COR_RESET);
}


void mostraClientesQuery5(char** clients, int size, int nPags, int pag){
    int tam,i,j,k,valid=1;
    char str1[256];
    char str2[256];

    puts(COR_B_VERMELHO"                                 ██╠═══════════════════╦═══════╦═══════╦═══════╦═══════╦═══════╣██"COR_RESET);
    
        for(i=0 ; i<8 ; i++) {
        int n1 = (pag*40)+(i*5)+1;
        int n2 = (pag*40)+(i*5)+5;
        if(valid && n2 > size) {
            n2 = size;
            valid = 0;
        }

        if( n1 > n2) {
            n1 = n2;
        }
        sprintf(str1,"%d",n1);
        sprintf(str2,"%d",n2);

        tam = (19 - (strlen(str1) + strlen(str2) + 4) ) / 2;
        printf(COR_B_VERMELHO"                                 ██║"COR_RESET);

        if(valid || n2 == size) {
            for(k=0 ; k<tam ;k++) printf(" ");

            printf(COR_B_VERDE"[%d..%d]"COR_RESET,n1,n2);
        
            tam += (strlen(str1) + strlen(str2) + 4);

            for(; tam < 19 ; tam++) printf(" ");
        }
        else printf("                   ");

        printf(COR_B_VERMELHO"║"COR_RESET);

        int n3 = (pag*40)+(i*5);

        for(j=n3 ; j<n3+5 ; j++) {
            if(j < size)
                printf(" %s ",clients[j]);
                else 
                    printf("       ");

            printf(COR_B_VERMELHO"║"COR_RESET);
        }

        puts(COR_B_VERMELHO"██"COR_RESET);



        if(i!=7) puts(COR_B_VERMELHO"                                 ██╠═══════════════════╬═══════╬═══════╬═══════╬═══════╬═══════╣██"COR_RESET);
    }

    puts(COR_B_VERMELHO"                                 ██╚═══════════════════╩═══════╩═══════╩═══════╩═══════╩═══════╝██"COR_RESET);
    puts(COR_B_VERMELHO"                                 █████████████████████████████████████████████████████████████████"COR_RESET);

}

void setasPalavras(){

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"     Left Arrow ➤ "COR_RESET);
    printf("Previous");
    printf(COR_B_VERDE"         Right Arrow ➤ "COR_RESET);
    printf("Next      ");
    puts(COR_B_VERMELHO"║██"COR_RESET);
}


void miniMenuQuery5(float time,int size,int nPags,int pag){
    int i;
    char strTime[256];
    char strnPags[256];
    char strPag[256];
    char strSize[256];

    sprintf(strTime,"%f",time);
    sprintf(strnPags,"%d",nPags);
    sprintf(strPag,"%d",pag+1);
    sprintf(strSize,"%d",size);

    int tam = (59 - (strlen(strTime) + strlen(strnPags) + strlen(strPag) + strlen(strSize) + 36));

    puts("");
    parteDeCimaTabela();

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);

    for(i=0 ; i< tam/2 ; i++) printf(" ");

    printf(COR_B_VERDE"RunTime ➤ "COR_RESET);
    printf("%f",time);

    printf(COR_B_VERDE" Pags"COR_RESET);
    printf("[%d/%d]",pag+1,nPags);
    printf(COR_B_VERDE" Nº of Clients ➤ "COR_RESET);
    printf("%d",size);

    for(i=tam/2 ; i <tam ; i++) printf(" ");

    puts(COR_B_VERMELHO" ║██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██║                      Enter to go Back                     ║██"COR_RESET);
    
    parteDeBaixoTabela();
}


void mostraContador(int res[]){
    int i,j,tam;
    

    puts(COR_B_VERMELHO"                                 ██╠═════════════════════════════╦═════════════════════════════╣██"COR_RESET);
    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"  Clients Never Bought Count"COR_RESET);
    printf(COR_B_VERMELHO " " BARRA " " COR_RESET);
    printf(COR_B_VERDE" Products Never Bought Cout "COR_RESET);
    puts(COR_B_VERMELHO"║██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██╠═════════════════════════════╬═════════════════════════════╣██"COR_RESET);

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    for(i=0 ; i<2 ; i++) {
        char insert[30] = "                             ";
        char str[256];
        sprintf(str,"%d",res[i]);

        tam = (29 - strlen(str))/ 2;

        for(j=0 ; str[j] ; j++) {insert[tam++] = str[j];}

        printf("%s",insert);

        printf(COR_B_VERMELHO BARRA COR_RESET);
    }
    puts(COR_B_VERMELHO"██"COR_RESET);
    
    puts(COR_B_VERMELHO"                                 ██╚═════════════════════════════╩═════════════════════════════╝██"COR_RESET);
    puts(COR_B_VERMELHO"                                 █████████████████████████████████████████████████████████████████"COR_RESET);

}

void miniMenuQuery6(float time){

    puts("");
    parteDeCimaTabela();

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"                     RunTime ➤ "COR_RESET);
    printf("%f",time);
    puts(COR_B_VERMELHO"                    ║██"COR_RESET);
    puts(COR_B_VERMELHO"                                 ██║                      Enter to go Back                     ║██"COR_RESET);

    parteDeBaixoTabela();
}

void clientePalavra(char* client){

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"                       Client ➤ "COR_RESET);
    printf("%s             ",client);
    puts(COR_B_VERMELHO"         ║██"COR_RESET);
    
}

void dadosClientesMes(int res[][12]){
    int k,i,j,tam;
    int filial[3] = {0};

    puts(COR_B_VERMELHO"                                 ██╠═════╦═════════════════╦═════════════════╦═════════════════╣██"COR_RESET);
    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"Month"COR_RESET);
    printf(COR_B_VERMELHO"║"COR_RESET);

    for(i=1 ; i<4 ; i++) {

    printf(COR_B_VERDE"    BRANCH %d     "COR_RESET,i);
    if(i!=3)printf(COR_B_VERMELHO BARRA COR_RESET);

    }

    printf(COR_B_VERMELHO"║██\n"COR_RESET);
    

    puts(COR_B_VERMELHO"                                 ██╠═════╬═════════════════╬═════════════════╬═════════════════╣██"COR_RESET);

    for(i=0 ; i<12 ; i++) {

        printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
        
        if (i+1 < 10) printf(COR_B_VERDE"  %d  "COR_RESET,i+1);
            else printf(COR_B_VERDE" %d  "COR_RESET,i+1);

        printf(COR_B_VERMELHO BARRA COR_RESET);

        for(j=0 ; j<3 ; j++) {
            filial[j] += res[j][i];

            char insert[18] = "                 ";
            char str[256];
            sprintf(str,"%d", res[j][i]);
            tam = (17 - strlen(str)) / 2;

            for(k=0 ; str[k] ; k++) {insert[tam++] = str[k];}

            printf("%s",insert);

            printf(COR_B_VERMELHO BARRA COR_RESET);
        }

        puts(COR_B_VERMELHO"██"COR_RESET);
        
    }

    puts(COR_B_VERMELHO"                                 ██╠═════╬═════════════════╬═════════════════╬═════════════════╣██"COR_RESET);

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"Total"COR_RESET);
    printf(COR_B_VERMELHO BARRA COR_RESET);
    
    for(i=0 ; i<3 ; i++) {
            
            char insert2[18] = "                 ";
            char str2[256];
            sprintf(str2,"%d", (int) filial[i]);
            tam = (17 - strlen(str2)) / 2;

            for(k=0 ; str2[k] ; k++) {insert2[tam++] = str2[k];}

            printf("%s",insert2);

        printf(COR_B_VERMELHO BARRA COR_RESET);
    }
        puts(COR_B_VERMELHO"██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██╚═════╩═════════════════╩═════════════════╩═════════════════╝██"COR_RESET);
    puts(COR_B_VERMELHO"                                 █████████████████████████████████████████████████████████████████"COR_RESET);
}



void dadosTotalVendas(int* intervalo, double* res) {
    int i,tam;
    intervalo[0]++;
    intervalo[1]++;

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);

    char str1[256];
    char str2[256];
    sprintf(str1,"%d",intervalo[0]);
    sprintf(str2,"%d",intervalo[1]);
    tam = 59 - (strlen(str1) + strlen(str2) + 14);

    for(i=0 ; i<tam/2 ; i++) printf(" ");

    printf(COR_B_VERDE"Months ➤ "COR_RESET);
    printf("[%d...%d]",intervalo[0],intervalo[1]);

    for(i=tam/2; i<tam ; i++) printf(" ");

    puts(COR_B_VERMELHO"║██"COR_RESET);


    puts(COR_B_VERMELHO"                                 ██╠═════════════════╦═════════════════════════════════════════╣██"COR_RESET);

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"     Profit      "COR_RESET);
    printf(COR_B_VERMELHO BARRA COR_RESET);
    printaDadosTotalVendas(res[0],0);
    puts(COR_B_VERMELHO"║██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██╠═════════════════╬═════════════════════════════════════════╣██"COR_RESET);

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"   Units Sold    "COR_RESET);
    printf(COR_B_VERMELHO BARRA COR_RESET);
    printaDadosTotalVendas(res[1],1);
    puts(COR_B_VERMELHO"║██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██╚═════════════════╩═════════════════════════════════════════╝██"COR_RESET);
    puts(COR_B_VERMELHO"                                 █████████████████████████████████████████████████████████████████"COR_RESET);

}

void printaDadosTotalVendas(double res,int q) {
    int tam,i=0;
    char tudo[42] = "                                         ";
    char flt[256];
    if(q==0)sprintf(flt, "%f", res);
    if(q==1){
        tam = (int) res;
        sprintf(flt, "%d", tam);
    }

    tam = (41 - strlen(flt)) / 2;
    
    while(flt[i]) {tudo[tam++] = flt[i++];}

    printf("%s",tudo);
}



void produtoFilialPalavras(char* produto, int filial) {

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"               Product ➤ "COR_RESET);
    printf("%s",produto);
    printf(COR_B_VERDE"    Branch ➤ "COR_RESET);
    printf("%d",filial);
    puts(COR_B_VERMELHO"              ║██"COR_RESET);


}


void miniMenuQuery9(int total,float time) {
    char i,str1[256],str2[256];
    sprintf(str1,"%d",total);
    sprintf(str2,"%f",time);
    int tam = 59 - (strlen(str1) + (strlen(str2)) + 30);

    puts("\n");    
    parteDeCimaTabela();
    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);


    for(i=0 ; i<tam/2 ; i++) printf(" ");

    printf(COR_B_VERDE"RunTime ➤ "COR_RESET);
    printf("%f",time);
    printf(COR_B_VERDE"       Nº Clients ➤ "COR_RESET);
    printf("%d",total);

    for(i=tam/2; i<tam ; i++) printf(" ");

    puts(COR_B_VERMELHO"║██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██║                      Enter to go Back                     ║██"COR_RESET);
    puts(COR_B_VERMELHO"                                 ██╚═══════════════════════════════════════════════════════════╝██"COR_RESET);
    puts(COR_B_VERMELHO"                                 █████████████████████████████████████████████████████████████████"COR_RESET);

}


void clientesQuery9(char** clientesN,int unidN,char** clientesP,int unidP, int maior) {
    int i,j,tam;

    puts(COR_B_VERMELHO"                                 ██╠═════╦══════════════════════════╦══════════════════════════╣██"COR_RESET);

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERMELHO"     ║"COR_RESET);
    printf(COR_B_VERDE"             N            "COR_RESET);
    printf(COR_B_VERMELHO BARRA COR_RESET);
    printf(COR_B_VERDE"             P            "COR_RESET);
    puts(COR_B_VERMELHO"║██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██╠═════╬══════════════════════════╬══════════════════════════╣██"COR_RESET);



    for(i=0 ; i < maior ; i++) {
        char insert1[6] = "     ";
        char str1[256];
        sprintf(str1,"%d",i);
        tam = (5 - strlen(str1)) / 2;

        for(j=0 ; str1[j] ; j++) insert1[tam++] = str1[j];

        printf(COR_B_VERMELHO"                                 ██║"COR_RESET);

        printf("%s",insert1);

        printf(COR_B_VERMELHO BARRA COR_RESET);

        if(i<unidN) printf("           %s          ",clientesN[i]);
            else printf("                          ");

        printf(COR_B_VERMELHO BARRA COR_RESET);

        if(i<unidP) printf("           %s          ",clientesP[i]);
            else printf("                          ");

        puts(COR_B_VERMELHO"║██"COR_RESET);

    }

    puts(COR_B_VERMELHO"                                 ██╠═════╬══════════════════════════╬══════════════════════════╣██"COR_RESET);
    

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"Total"COR_RESET);
    printf(COR_B_VERMELHO BARRA COR_RESET);

    char insert2[27] = "                          ";
    char insert3[27] = "                          ";
    char str2[256];
    char str3[256];
    sprintf(str2,"%d",unidN);
    sprintf(str3,"%d",unidP);

    tam = (26 - strlen(str2)) / 2;
    for(j=0 ; str2[j] ; j++) insert2[tam++] = str2[j];

    tam = (26 - strlen(str3)) / 2;
    for(j=0 ; str3[j] ; j++) insert3[tam++] = str3[j];

    printf("%s",insert2);
    printf(COR_B_VERMELHO BARRA COR_RESET);
    printf("%s",insert3);


    puts(COR_B_VERMELHO"║██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██╚═════╩══════════════════════════╩══════════════════════════╝██"COR_RESET);
    puts(COR_B_VERMELHO"                                 █████████████████████████████████████████████████████████████████"COR_RESET);

}


void clienteMesPalavras(char* client,int month){

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"            Client ➤ "COR_RESET);
    printf("%s",client);

    if(month < 10) printf(COR_B_VERDE"            Month ➤ "COR_RESET);
        else printf(COR_B_VERDE"           Month ➤ "COR_RESET);

    printf("%d",month+1);

    puts(COR_B_VERMELHO"            ║██"COR_RESET);
}



void dadosQuery10(char** prods,int qt[],int size){
    int k,i,j,tam,total=0;

    puts(COR_B_VERMELHO"                                 ██╠═════╦══════════════════════════╦══════════════════════════╣██"COR_RESET);

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERMELHO"     ║"COR_RESET);
    printf(COR_B_VERDE"         Products         "COR_RESET);
    printf(COR_B_VERMELHO BARRA COR_RESET);
    printf(COR_B_VERDE"         Quantity         "COR_RESET);
    puts(COR_B_VERMELHO"║██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██╠═════╬══════════════════════════╬══════════════════════════╣██"COR_RESET);

    for(i=0 ; i < size ; i++) {
        total += qt[i];
        char insert1[6] = "     ";
        char str1[256];
        sprintf(str1,"%d",i+1);
        tam = (5 - strlen(str1)) / 2;

        for(j=0 ; str1[j] ; j++) insert1[tam++] = str1[j];

        printf(COR_B_VERMELHO"                                 ██║"COR_RESET);

        printf(COR_B_VERDE"%s"COR_RESET,insert1);

        printf(COR_B_VERMELHO BARRA COR_RESET);

        printf("          %s          ",prods[i]);

        printf(COR_B_VERMELHO BARRA COR_RESET);

        char insert2[27] = "                          ";
        char str2[256];
        sprintf(str2,"%d",qt[i]);
        tam = (26 - strlen(str2)) / 2;

        for(j=0 ; str2[j] ; j++) insert2[tam++] = str2[j];

        printf("%s",insert2);

        puts(COR_B_VERMELHO"║██"COR_RESET);

    }

    puts(COR_B_VERMELHO"                                 ██╠═════╬══════════════════════════╬══════════════════════════╣██"COR_RESET);
    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"Total"COR_RESET);
    printf(COR_B_VERMELHO BARRA COR_RESET);

    for(k=0 ; k<2 ; k++) {
        char insert3[27] = "                          ";
        char str3[256];
        if(k==0) sprintf(str3,"%d",i);
            else sprintf(str3,"%d",total);

        tam = (26 - strlen(str3)) / 2;

        for(j=0 ; str3[j] ; j++) insert3[tam++] = str3[j];

        printf("%s",insert3);
        printf(COR_B_VERMELHO BARRA COR_RESET);
    }

    puts(COR_B_VERMELHO"██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██╚═════╩══════════════════════════╩══════════════════════════╝██"COR_RESET);
    puts(COR_B_VERMELHO"                                 █████████████████████████████████████████████████████████████████"COR_RESET);

}

void mostraLimit(int limit){
    int i,tam;
    char str[256];

    sprintf(str,"%d",limit);

    tam = 59 - ( strlen(str) + 51);

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);

    for(i=0 ; i<tam/2 ; i++) printf(" ");

    printf(COR_B_VERDE"Left Arrow ➤ "COR_RESET);
    printf("Previous");
    printf(COR_B_VERDE"  Limit ➤ "COR_RESET);
    printf("%d",limit);
    printf(COR_B_VERDE"  Right Arrow ➤ "COR_RESET);
    printf("Next");

    for(i=tam/2; i<tam ; i++) printf(" ");

    puts(COR_B_VERMELHO"║██"COR_RESET);
}


void query11Palavras() {
    int i;

    puts(COR_B_VERMELHO"                                 ██╠════════╦════════════════╦════════════════╦════════════════╣██"COR_RESET);
    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERMELHO"        ║"COR_RESET);

    for(i=1 ; i<4 ; i++) {

        printf(COR_B_VERDE"    BRANCH %d    "COR_RESET,i);
        if(i!=3)printf(COR_B_VERMELHO BARRA COR_RESET);

    }
    puts(COR_B_VERMELHO"║██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██╠════════╬════════╦═══════╬════════╦═══════╬════════╦═══════╣██"COR_RESET);

    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"Products"COR_RESET);

    for(i=0 ; i<3 ; i++) {
        printf(COR_B_VERMELHO BARRA COR_RESET);
        printf(COR_B_VERDE" Nº Cls "COR_RESET);
        printf(COR_B_VERMELHO BARRA COR_RESET);
        printf(COR_B_VERDE" Units "COR_RESET);
    }
    puts(COR_B_VERMELHO"║██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██╠════════╬════════╬═══════╬════════╬═══════╬════════╬═══════╣██"COR_RESET);

}


void dadosQuery11(char** prods,int data[][3][2],int size,int nPags,int pag){
    int i,j,k;
    char str1[256];
    char str2[256];
    int tam = 0;


    for(i=0 ; i<7 ; i++) {
        int n1 = (pag*7)+i;

        if(n1 < size) {

            printf(COR_B_VERMELHO"                                 ██║"COR_RESET);

            printf(COR_B_VERDE" %s "COR_RESET,prods[n1]);
            

            printf(COR_B_VERMELHO"║"COR_RESET);

            for(j=0 ; j<3 ; j++) {
                char insert1[9] = "        ";
                char insert2[8] = "       ";
                sprintf(str1,"%d",data[n1][j][0]);
                sprintf(str2,"%d",data[n1][j][1]);

                tam = (8 - strlen(str1)) / 2 ;
                for(k=0 ; str1[k] ; k++) insert1[tam++] = str1[k];

                printf("%s",insert1);

                printf(COR_B_VERMELHO"║"COR_RESET);

                tam = (8 - strlen(str2)) / 2 ;
                for(k=0 ; str2[k] ; k++) insert2[tam++] = str2[k];

                printf("%s",insert2);
                printf(COR_B_VERMELHO"║"COR_RESET);

            }

            puts(COR_B_VERMELHO"██"COR_RESET);            
        }

        else puts(COR_B_VERMELHO"                                 ██║        ║        ║       ║        ║       ║        ║       ║██"COR_RESET);

        if(i!=6) puts(COR_B_VERMELHO"                                 ██╠════════╬════════╬═══════╬════════╬═══════╬════════╬═══════╣██"COR_RESET);
    }

    puts(COR_B_VERMELHO"                                 ██╚════════╩════════╩═══════╩════════╩═══════╩════════╩═══════╝██"COR_RESET);
    puts(COR_B_VERMELHO"                                 █████████████████████████████████████████████████████████████████"COR_RESET);
}



void mostraClientesPalavras(char* client){

    
    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"  Left Arrow ➤ "COR_RESET);
    printf("Previous");
    printf(COR_B_VERDE" Client ➤ "COR_RESET);
    printf("%s",client);
    printf(COR_B_VERDE" Right Arrow ➤ "COR_RESET);
    printf("Next  ");

    puts(COR_B_VERMELHO"║██"COR_RESET);

}

void dadosQuery12(char** prods,double qt[],int limit,int pag){
    int i,j,tam;

    puts(COR_B_VERMELHO"                                 ██╠═════════════════════════════╦═════════════════════════════╣██"COR_RESET);
    printf(COR_B_VERMELHO"                                 ██║"COR_RESET);
    printf(COR_B_VERDE"          Products          "COR_RESET);
    printf(COR_B_VERMELHO " " BARRA " " COR_RESET);
    printf(COR_B_VERDE"           Profit           "COR_RESET);
    puts(COR_B_VERMELHO"║██"COR_RESET);

    puts(COR_B_VERMELHO"                                 ██╠═════════════════════════════╬═════════════════════════════╣██"COR_RESET);

    for(i=0 ; i<7 ; i++) {
        int n1 = (pag*7)+i;

        if(n1<limit) {

        printf(COR_B_VERMELHO"                                 ██║"COR_RESET);

        printf("           %s            ",prods[n1]);
        printf(COR_B_VERMELHO BARRA COR_RESET);
        
        char insert[30] = "                             ";
        char str[256];

        sprintf(str,"%f",qt[n1]);
        tam = (29 - strlen(str)) / 2;

        for(j=0 ; str[j] ; j++) {insert[tam++] = str[j];}

        printf("%s",insert);

        puts(COR_B_VERMELHO"║██"COR_RESET);
        }

        else puts(COR_B_VERMELHO"                                 ██║                             ║                             ║██"COR_RESET);

        if(i!=6) puts(COR_B_VERMELHO"                                 ██╠═════════════════════════════╬═════════════════════════════╣██"COR_RESET);

    }

    puts(COR_B_VERMELHO"                                 ██╚═════════════════════════════╩═════════════════════════════╝██"COR_RESET);
    puts(COR_B_VERMELHO"                                 █████████████████████████████████████████████████████████████████"COR_RESET);

}




/* -> Query 2 <- */
void showProductsStartbyLetter(char** prods,char letter, int size, float time){
    char c = 0;
    int i = 0,nPags = (size / 40) + (size % 40 ? 1 : 0);


    while(c != ENTER) {

    system("clear");
    puts("");
    parteDeCimaTabela();
    infoPalavra();
    mostraLetra(letter);
    mostraProdutosQuery2(prods,size,nPags,i);
    miniMenuQuery2(time,nPags,i,size);
    
    system ("/bin/stty raw");
    c = getchar();
    system ("/bin/stty cooked");

    if(i < nPags-1 && c == DIREITA) i++;
    if(i > 0 && c == ESQUERDA) i--;

    }

}

/* -> Query 3 <- */
void showProductSalesAndProfit(char* product, int month, double res[][4],float time){
    char c = 0;
    int op = 0;

    while (c != ENTER){

        system("clear");
        puts("\n\n\n\n");
        parteDeCimaTabela();
        infoPalavra();
        produtoMesPalavras(product,month);

        if(op == 0) {
            filiaisPalavras();
            fatUniPalavras();
            dadosComprasF(res);
        }

        else {
            visaoGlobalPalvra();
            FatUniPalavrasG();
            dadosComprasG(res);
        }

        puts("");
        miniMenuQuery3(time,op);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(op < 1 && c == DIREITA) op++;
        if(op > 0 && c == ESQUERDA) op--;

    }

}

/* -> Query 4 <- */
void showProductsNeverBought(char** prods,int size,int branchID, float time){
    char c = 0;
    int i = 0,nPags = (size / 40) + (size % 40 ? 1 : 0);

    while (c != ENTER) {
        system("clear");
        puts("");
        parteDeCimaTabela();
        infoPalavra();
        mostraFilial(branchID);
        mostraProdutosQuery2(prods,size,nPags,i);
        miniMenuQuery2(time,nPags,i,size);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(i < nPags-1 && c == DIREITA) i++;
        if(i > 0 && c == ESQUERDA) i--;
    }

}

/* -> Query 5 <- */
void showClientsOfAllBranches(char** clients,int size, float time) {
    char c = 0;
    int i = 0,nPags = (size / 40) + (size % 40 ? 1 : 0);

    while (c != ENTER) {
        system("clear");
        puts("");
        parteDeCimaTabela();
        infoPalavra();
        setasPalavras();
        mostraClientesQuery5(clients,size,nPags,i);
        miniMenuQuery5(time,size,nPags,i);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(i < nPags-1 && c == DIREITA) i++;
        if(i > 0 && c == ESQUERDA) i--;
    }

}

/* -> Query 6 <- */
void showClientsAndProductsNeverBoughtCount(int res[], float time){

    system("clear");
    puts("\n\n\n\n\n\n");
    parteDeCimaTabela();
    infoPalavra();
    mostraContador(res);
    miniMenuQuery6(time);

    printf(ESCONDE_CURSOR);
    getEnter();
    printf(MOSTRA_CURSOR);
}

/* -> Query 7 <- */
void showProductsBoughtByClient(char* client, int res[][12], float time){

    system("clear");

    puts("\n");
    parteDeCimaTabela();
    infoPalavra();
    clientePalavra(client);
    dadosClientesMes(res);
    miniMenuQuery6(time);

    printf(ESCONDE_CURSOR);
    getEnter();
    printf(MOSTRA_CURSOR);
}

/* -> Query 8 <- */
void showSalesAndProfit(int minMonth,int maxMonth,double res[],float time){
    int window[2] = {minMonth,maxMonth};
    
    system("clear");
    puts("\n\n\n\n\n");
    parteDeCimaTabela();
    infoPalavra();
    dadosTotalVendas(window,res);
    miniMenuQuery6(time);
    
    printf(ESCONDE_CURSOR);
    getEnter();
    printf(MOSTRA_CURSOR);
}

/* -> Query 9 <- */
void showProductsBuyers(char* productID,int branch,char** clientsN,char** clientsP,int unitsN,int unitsP,float time){
    int i,enters;
    int maior = (unitsN > unitsP) ? unitsN : unitsP;

    if(maior < 7) enters = 3 - (maior / 2);
        else enters = 0;
        
    system("clear");

    for(i=0 ; i<enters ; i++) puts("");

    parteDeCimaTabela();
    infoPalavra();
    produtoFilialPalavras(productID, branch+1);
    clientesQuery9(clientsN,unitsN,clientsP,unitsP,maior);
    miniMenuQuery9(unitsP+unitsN,time);

    printf(ESCONDE_CURSOR);
    getEnter();
    printf(MOSTRA_CURSOR);
}

/* -> Query 10 <- */
void showClientFavoriteProducts(char** prods,int qt[],char* client,int month,int size,float time){
    int i,enters;

    if(size < 7) enters = 7 - (size / 2);
        else enters = 0;
        
    system("clear");

    for(i=0 ; i<enters ; i++) puts("");

    parteDeCimaTabela();
    infoPalavra();
    clienteMesPalavras(client,month);
    dadosQuery10(prods,qt,size);
    miniMenuQuery6(time);

    printf(ESCONDE_CURSOR);
    getEnter();
    printf(MOSTRA_CURSOR);
}

/* -> Query 11 <- */
void showTopSoldProducts(char** prods,int data[][3][2],int limit,float time){
    char c = 0;
    int i = 0,nPags = (limit / 7) + (limit % 7 ? 1 : 0);

    while(c != ENTER) {
        system("clear");
        parteDeCimaTabela();
        infoPalavra();
        setasPalavras();
        query11Palavras();
        dadosQuery11(prods,data,limit,nPags,i);
        miniMenuQuery2(time,nPags,i,limit);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");
        
        if(i < nPags-1 && c == DIREITA) i++;
        if(i > 0 && c == ESQUERDA) i--;

    }

}

void showClientTopProfitProducts(char** prods,double qt[],char* client,int limit,float time){
    char c = 0;
    int i = 0,nPags = (limit / 7) + (limit % 7 ? 1 : 0);

    while(c != ENTER) {
        system("clear");
        parteDeCimaTabela();
        infoPalavra();
        mostraClientesPalavras(client);
        dadosQuery12(prods,qt,limit,i);
        miniMenuQuery2(time,nPags,i,limit);


        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");
        
        if(i < nPags-1 && c == DIREITA) i++;
        if(i > 0 && c == ESQUERDA) i--;

    }

}

void filesInfo(int l[],char* clients, char* prods, char* sales, float time){
    int i;

    system("clear");
    puts("\n\n");
    parteDeCimaTempos();
    dataPalavra();
    puts("");

    for (i=0; i < 10; i++) {
        printf(COR_B_VERDE "%s" COR_RESET, infoLoad[i]);
        if (i == 0) printf("%s\n", clients);
        if (i == 1) printf("%d\n", l[0]);
        if (i == 2) {
            printf("%d\n", l[1]);
            puts("");
        }
        if (i == 3) printf("%s\n", prods);
        if (i == 4) printf("%d\n",l[2]);
        if (i == 5) {
            printf("%d\n",l[3]);
            puts("");
        }
        if (i == 6) printf("%s\n", sales);
        if (i == 7) printf("%d\n",l[4]);
        if (i == 8) {
            printf("%d\n",l[5]);
            puts("");
        }
        
        if (i == 9) printf("%f\n", time);
    }

    parteDeBaixoTempos();
    puts(COR_B_VERMELHO PISCAR"\n\n\n\n                                                     Click Enter to Continue\n" COR_RESET RESET);

    printf(ESCONDE_CURSOR);
    getEnter();
    printf(MOSTRA_CURSOR);
}

void showDestructionTime(float time){

    system("clear");
    puts("\n\n\n\n\n");
    parteDeCimaTempos();
    dataPalavra();
    puts("\n");

    printf(COR_B_VERDE"                                                    Destruction Time ➤ "COR_RESET);
    printf("%f\n",time);

    parteDeBaixoTempos();
    puts(COR_B_VERMELHO PISCAR"\n\n\n\n                                                     Click Enter to Continue\n" COR_RESET RESET);

    printf(ESCONDE_CURSOR);
    getEnter();
    printf(MOSTRA_CURSOR);

}

/*---------------------------------------------------------------------------------------------------------------------------*/
/* -> Query 2 <- */
char getLetter2(){
    int valid = 0;
    char c = ' ';
    char letter = ' ';

    while(!valid){
        system("clear");

        if(!c) printf(COR_B_VERMELHO"\n\n\n\n\n\n\n\n\n\n\n\n\n                                                           Invalid Letter\n"COR_RESET);
            else puts("\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printf(COR_B_VERMELHO CIMAMENU COR_RESET);
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);

        char insert[11] = "          ";
        insert[0] = letter;

        printf(COR_B_VERDE"      Letter ➤ "COR_RESET);
        printf("%s",insert);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);
        printf(COR_B_VERMELHO BAIXOMENU COR_RESET);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(c != ENTER){

            if(c != BACKSPACE){

                if(!isalpha(c)) c = 0;  
                    else letter = c;

            }
            else letter = ' ';
        }
        else if(isalpha(letter)){
            valid = 1;
        }
    }
    return toupper(letter);
}


/*---------------------------------------------------------------------------------------------------------------------------*/
/* -> Query 3 <- */
void getProductAndMonth2(SGV sgv,char product[],int* month){
    int i,j = 0,valid = 0;
    char c = ' ';
    
    while(!valid){
        system("clear");

        if(!c) printf(COR_B_VERMELHO"\n\n\n\n\n\n\n\n\n\n\n\n\n                                                           Invalid Product\n"COR_RESET);
            else puts("\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printf(COR_B_VERMELHO CIMAMENU COR_RESET);
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);

        char insert1[11] = "          ";
        for(i=0 ; product[i] ; i++) insert1[i] = product[i];

        printf(COR_B_VERDE"     Product ➤ "COR_RESET);
        printf("%s",insert1);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);
        printf(COR_B_VERMELHO BAIXOMENU COR_RESET);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(c != ENTER){

            if(c != BACKSPACE){

                if(j<6 && (isalpha(c) || isdigit(c))) {

                    product[j] = c;
                    product[++j] = '\0';

                }

            }
            else if(j>0) {
                product[--j] = '\0';
            }

        }
        else if(j < 6 || !validateProduct(product) || !listOfProducts(getArrayProductsByLetter(sgv,product[0]),product)){
            j=0;
            c=0;
            product[0] = '\0';
        }

        else valid = 1;
    }

    valid = j = 0;
    c = ' ';
    char buffer[3];

    while(!valid){

        system("clear");
        if(!c) printf(COR_B_VERMELHO"\n\n\n\n\n\n\n\n\n\n\n\n\n                                                           Invalid Month\n"COR_RESET);
            else puts("\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printf(COR_B_VERMELHO CIMAMENU COR_RESET);
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);
        printf(COR_B_VERDE"     Product ➤ "COR_RESET);
        printf("%s    ",product);
        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);

        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);

        char insert2[11] = "          ";
        for(i=0 ; buffer[i] ; i++) insert2[i] = buffer[i];

        printf(COR_B_VERDE"       Month ➤ "COR_RESET);
        printf("%s",insert2);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);
        printf(COR_B_VERMELHO BAIXOMENU COR_RESET);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(c != ENTER){

            if(c != BACKSPACE){

                if(isdigit(c) && j<2) {
                    buffer[j] = c;
                    buffer[++j] = '\0';

                }
            }
            else if(j>0) {
                buffer[--j] = '\0';
            }

        }
        else if(atoi(buffer) > 12 || atoi(buffer) <= 0) {
            j=0;
            c=0;
            buffer[0] = '\0';
        }
        else valid = 1;

    }

    (*month) = atoi(buffer) - 1;
}

/*---------------------------------------------------------------------------------------------------------------------------*/
/* -> Query 4 <- */
int getBranches2(){
    int option = 0;
    char c = 0;

    while(c != ENTER){

        system("clear");
        puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printf(COR_B_VERMELHO CIMAMENU COR_RESET);
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);

        if(option == 0) printf(PISCAR);
        printf(COR_B_VERDE"   Branch 1  "COR_RESET RESET);
        if(option == 1) printf(PISCAR);
        printf(COR_B_VERDE"  Branch 2  "COR_RESET RESET);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);
        
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);

        if(option == 2) printf(PISCAR);
        printf(COR_B_VERDE"   Branch 3  "COR_RESET RESET);
        if(option == 3) printf(PISCAR);
        printf(COR_B_VERDE"   Global   "COR_RESET RESET);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);
        printf(COR_B_VERMELHO BAIXOMENU COR_RESET);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(c == BAIXO && option == 0) option = 2;
        if(c == BAIXO && option == 1) option = 3;
        if(c == DIREITA && option == 0) option = 1;
        if(c == DIREITA && option == 2) option = 3;
        if(c == ESQUERDA && option == 1) option = 0;
        if(c == ESQUERDA && option == 3) option = 2;
        if(c == CIMA && option == 2) option = 0;
        if(c == CIMA && option == 3) option = 1;
        
    }

    return option;
}

/*---------------------------------------------------------------------------------------------------------------------------*/
/* -> Query 7 <- */
void getClient2(SGV sgv,char client[]){
    int i,j = 0,valid = 0;
    char c = ' ';
    
    while(!valid){
        system("clear");

        if(!c) printf(COR_B_VERMELHO"\n\n\n\n\n\n\n\n\n\n\n\n\n                                                           Invalid Client\n"COR_RESET);
            else puts("\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printf(COR_B_VERMELHO CIMAMENU COR_RESET);
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);

        char insert1[11] = "          ";
        for(i=0 ; client[i] ; i++) insert1[i] = client[i];

        printf(COR_B_VERDE"      Client ➤ "COR_RESET);
        printf("%s",insert1);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);
        printf(COR_B_VERMELHO BAIXOMENU COR_RESET);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(c != ENTER){

            if(c != BACKSPACE){

                if(j<5 && (isalpha(c) || isdigit(c))) {
                    client[j] = c;
                    client[++j] = '\0';

                }
            }
            else if(j>0) {
                client[--j] = '\0';
            }
        }
        else if(j < 5 || !validateClient(client) || !listOfClients(getClients(sgv),client)){
            j=0;
            c=0;
            client[0] = '\0';
        }

        else valid = 1;
    }
}

/*---------------------------------------------------------------------------------------------------------------------------*/
/* -> Query 8 <- */
void getMinAndMaxMonth2(int* minMonth,int* maxMonth){
    int i,j = 0,valid = 0;
    char c = ' ';
    char buffer[3];
    
    while(!valid){
        system("clear");

        if(!c) printf(COR_B_VERMELHO"\n\n\n\n\n\n\n\n\n\n\n\n\n                                                             Invalid Month\n"COR_RESET);
            else puts("\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printf(COR_B_VERMELHO CIMAMENU COR_RESET);
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);

        char insert1[10] = "         ";
        for(i=0 ; buffer[i] ; i++) insert1[i] = buffer[i];

        printf(COR_B_VERDE"    Min Month ➤ "COR_RESET);
        printf("%s",insert1);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);
        printf(COR_B_VERMELHO BAIXOMENU COR_RESET);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(c != ENTER){

            if(c != BACKSPACE){

                if(isdigit(c) && j<2) {
                    buffer[j] = c;
                    buffer[++j] = '\0';

                }
            }
            else if(j>0) {
                buffer[--j] = '\0';
            }

        }
        else if(atoi(buffer) > 12 || atoi(buffer) <= 0) {
            j=0;
            c=0;
            buffer[0] = '\0';
        }
        else {
            valid = 1;
        }
    }

    *minMonth = atoi(buffer);
    valid = j = 0;
    c = ' ';
    buffer[0] = '\0';

    while(!valid){
        system("clear");

        if(!c) printf(COR_B_VERMELHO"\n\n\n\n\n\n\n\n\n\n\n\n\n                                                             Invalid Month\n"COR_RESET);
            else puts("\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printf(COR_B_VERMELHO CIMAMENU COR_RESET);
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);
        printf(COR_B_VERDE"    Min Month ➤ "COR_RESET);
        if(*minMonth < 10) printf("%d        ",*minMonth);
            else printf("%d       ",*minMonth);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);

        char insert2[10] = "         ";
        for(i=0 ; buffer[i] ; i++) insert2[i] = buffer[i];

        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);
        printf(COR_B_VERDE"    Max Month ➤ "COR_RESET);
        printf("%s",insert2);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);
        printf(COR_B_VERMELHO BAIXOMENU COR_RESET);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(c != ENTER){

            if(c != BACKSPACE){

                if(isdigit(c) && j<2) {
                    buffer[j] = c;
                    buffer[++j] = '\0';

                }
            }
            else if(j>0) {
                buffer[--j] = '\0';
            }

        }
        else if(atoi(buffer) > 12 || atoi(buffer) <= 0 || atoi(buffer) < *minMonth) {
            j=0;
            c=0;
            buffer[0] = '\0';
        }
        else {
            valid = 1;
        }
    }

    (*maxMonth) = atoi(buffer);

    (*minMonth)--;
    (*maxMonth)--;
}

/*---------------------------------------------------------------------------------------------------------------------------*/
/* -> Query 9 <- */
void getProductAndBranch2(SGV sgv,char* product,int* branch){
    int i,j = 0,valid = 0;
    char c = ' ';
    
    while(!valid){
        system("clear");

        if(!c) printf(COR_B_VERMELHO"\n\n\n\n\n\n\n\n\n\n\n\n\n                                                           Invalid Product\n"COR_RESET);
            else puts("\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printf(COR_B_VERMELHO CIMAMENU COR_RESET);
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);

        char insert1[11] = "          ";
        for(i=0 ; product[i] ; i++) insert1[i] = product[i];

        printf(COR_B_VERDE"     Product ➤ "COR_RESET);
        printf("%s",insert1);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);
        printf(COR_B_VERMELHO BAIXOMENU COR_RESET);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(c != ENTER){

            if(c != BACKSPACE){

                if(j<6 && (isalpha(c) || isdigit(c))) {

                    product[j] = c;
                    product[++j] = '\0';

                }

            }
            else if(j>0) {
                product[--j] = '\0';
            }

        }
        else if(j < 6 || !validateProduct(product) || !listOfProducts(getArrayProductsByLetter(sgv,product[0]),product)){
            j=0;
            c=0;
            product[0] = '\0';
        }

        else valid = 1;
    }

    valid = 0;
    c = ' ';
    char number = ' ';


    while(!valid){
        system("clear");

        if(!c) printf(COR_B_VERMELHO"\n\n\n\n\n\n\n\n\n\n\n\n\n                                                           Invalid Branch\n"COR_RESET);
            else puts("\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printf(COR_B_VERMELHO CIMAMENU COR_RESET);
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);
        printf(COR_B_VERDE"     Product ➤ "COR_RESET);
        printf("%s    ",product);
        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);

        char insert2[11] = "          ";
        insert2[0] = number;

        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);
        printf(COR_B_VERDE"      Branch ➤ "COR_RESET);
        printf("%s",insert2);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);
        printf(COR_B_VERMELHO BAIXOMENU COR_RESET);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(c != ENTER){

            if(c != BACKSPACE){

                if(!isdigit(c)) c = 0;  
                    else number= c;

            }
            else number = ' ';
        }
        else if(!isdigit(number) || number - '0' <= 0 || number - '0' >= 4){
            c = 0;
            number = ' ';
        }
        else valid = 1;
    }

    *branch = number - '0' - 1;

}

/*---------------------------------------------------------------------------------------------------------------------------*/
/* -> Query 10 <- */
void getClientAndMonth2(SGV sgv,char* client,int *month){
    int i,j = 0,valid = 0;
    char c = ' ';
    
    while(!valid){
        system("clear");

        if(!c) printf(COR_B_VERMELHO"\n\n\n\n\n\n\n\n\n\n\n\n\n                                                           Invalid Client\n"COR_RESET);
            else puts("\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printf(COR_B_VERMELHO CIMAMENU COR_RESET);
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);

        char insert1[11] = "          ";
        for(i=0 ; client[i] ; i++) insert1[i] = client[i];

        printf(COR_B_VERDE"      Client ➤ "COR_RESET);
        printf("%s",insert1);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);
        printf(COR_B_VERMELHO BAIXOMENU COR_RESET);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(c != ENTER){

            if(c != BACKSPACE){

                if(j<5 && (isalpha(c) || isdigit(c))) {
                    client[j] = c;
                    client[++j] = '\0';

                }
            }
            else if(j>0) {
                client[--j] = '\0';
            }
        }
        else if(j < 5 || !validateClient(client) || !listOfClients(getClients(sgv),client)){
            j=0;
            c=0;
            client[0] = '\0';
        }

        else valid = 1;
    }

    valid = j = 0;
    c = ' ';
    char buffer[3];

    while(!valid){

        system("clear");
        if(!c) printf(COR_B_VERMELHO"\n\n\n\n\n\n\n\n\n\n\n\n\n                                                           Invalid Month\n"COR_RESET);
            else puts("\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printf(COR_B_VERMELHO CIMAMENU COR_RESET);
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);
        printf(COR_B_VERDE"      Client ➤ "COR_RESET);
        printf("%s     ",client);
        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);

        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);

        char insert2[11] = "          ";
        for(i=0 ; buffer[i] ; i++) insert2[i] = buffer[i];

        printf(COR_B_VERDE"       Month ➤ "COR_RESET);
        printf("%s",insert2);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);
        printf(COR_B_VERMELHO BAIXOMENU COR_RESET);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(c != ENTER){

            if(c != BACKSPACE){

                if(isdigit(c) && j<2) {
                    buffer[j] = c;
                    buffer[++j] = '\0';

                }
            }
            else if(j>0) buffer[--j] = '\0';
        
        }
        else if(atoi(buffer) > 12 || atoi(buffer) <= 0) {
            j=0;
            c=0;
            buffer[0] = '\0';
        }
        else valid = 1;

    }

    (*month) = atoi(buffer) - 1;
}

/*---------------------------------------------------------------------------------------------------------------------------*/
/* -> Query 11 <- */
int getNumber2(){
    int i,valid = 0,j = 0;
    char c = ' ';
    char buffer[7];

    while(!valid){
        system("clear");

        if(!c) printf(COR_B_VERMELHO"\n\n\n\n\n\n\n\n\n\n\n\n\n                                                             Invalid Limit\n"COR_RESET);
            else puts("\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printf(COR_B_VERMELHO CIMAMENU COR_RESET);
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);

        char insert[11] = "          ";
        for(i=0 ; buffer[i] ; i++) insert[i] = buffer[i];
        
        printf(COR_B_VERDE"       Limit ➤ "COR_RESET);
        printf("%s",insert);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);
        printf(COR_B_VERMELHO BAIXOMENU COR_RESET);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(c != ENTER){

            if(c != BACKSPACE){

                if(j < 6 && isdigit(c)){
                    buffer[j] = c;
                    buffer[++j] = '\0';
                }
            }
            else if(j>0) buffer[--j] = '\0';
            
        }
        else if (j<=0) c = 0;
        else valid = 1;
    }

    return atoi(buffer);
}


/*---------------------------------------------------------------------------------------------------------------------------*/
/* -> Query 12 <- */
int getClientAndNumber(SGV sgv,char* client){
    int i,j = 0,valid = 0;
    char c = ' ';
    
    while(!valid){
        system("clear");

        if(!c) printf(COR_B_VERMELHO"\n\n\n\n\n\n\n\n\n\n\n\n\n                                                           Invalid Client\n"COR_RESET);
            else puts("\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printf(COR_B_VERMELHO CIMAMENU COR_RESET);
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);

        char insert1[11] = "          ";
        for(i=0 ; client[i] ; i++) insert1[i] = client[i];

        printf(COR_B_VERDE"      Client ➤ "COR_RESET);
        printf("%s",insert1);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);
        printf(COR_B_VERMELHO BAIXOMENU COR_RESET);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(c != ENTER){

            if(c != BACKSPACE){

                if(j<5 && (isalpha(c) || isdigit(c))) {
                    client[j] = c;
                    client[++j] = '\0';

                }
            }
            else if(j>0) {
                client[--j] = '\0';
            }
        }
        else if(j < 5 || !validateClient(client) || !listOfClients(getClients(sgv),client)){
            j=0;
            c=0;
            client[0] = '\0';
        }

        else valid = 1;
    }

    valid = j = 0;
    c = ' ';
    char buffer[7];

    while(!valid){
        system("clear");

        if(!c) printf(COR_B_VERMELHO"\n\n\n\n\n\n\n\n\n\n\n\n\n                                                             Invalid Limit\n"COR_RESET);
            else puts("\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printf(COR_B_VERMELHO CIMAMENU COR_RESET);
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);

        printf(COR_B_VERDE"      Client ➤ "COR_RESET);
        printf("%s     ",client);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);

        char insert2[11] = "          ";
        for(i=0 ; buffer[i] ; i++) insert2[i] = buffer[i];
        
        printf(COR_B_VERMELHO BARRAMENU1 COR_RESET);
        printf(COR_B_VERDE"       Limit ➤ "COR_RESET);
        printf("%s",insert2);

        puts(COR_B_VERMELHO BARRAMENU2 COR_RESET);
        printf(COR_B_VERMELHO BAIXOMENU COR_RESET);

        system ("/bin/stty raw");
        c = getchar();
        system ("/bin/stty cooked");

        if(c != ENTER){

            if(c != BACKSPACE){

                if(j < 6 && isdigit(c)){
                    buffer[j] = c;
                    buffer[++j] = '\0';
                }
            }
            else if(j>0) buffer[--j] = '\0';
            
        }
        else if (j<=0) c = 0;
        else valid = 1;
    }

    return atoi(buffer);

}
