#include "FuncoesAxuliares.h"
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


//   FUNCOES PARA O MODO COMPETETIVO


/**Altera o estado do jogo para preparar o mesmo para o modo competitivo.
 * Esta funçao limpa tambem a stack; guarda o nickname do jogador no estado;
 * armazenar o primeiro jogador a jogar; meter a dificuldade em 4(que é a dificuldade do modo competitivo)
 * e finalmente meter o jogo no seu estado inicial
*/

void NovoJogoCompetetivo (ESTADO *e,char *linha) {
    int n,i,j;
    char cmd[256];
    char peca[256];
    char nickname[256];

    n = sscanf(linha,"%s %s %s",cmd,peca,nickname);

    if (n == 3) {

        if ((toupper(peca[0]) == e->icon[0]) || (toupper(peca[0]) == e->icon[1])) {

            if (strlen(nickname) <= 8) {

                LimpaStack(e);

                if (toupper(peca[0]) == e->icon[0]) e->peca = VALOR_X;
                else e->peca = VALOR_O;

                strcpy(e->nomeTemporario, nickname);

                e->jogadas = 0;
                e->dificuldade = 3;
                e->modo = 'A';

                for (i = 0; i < 8; i++) {
                    for (j = 0; j < 8; j++) {
                        if (i == 3 && j == 3) e->grelha[3][3] = VALOR_O;
                        else if (i == 4 && j == 4) e->grelha[4][4] = VALOR_O;
                        else if (i == 3 && j == 4) e->grelha[3][4] = VALOR_X;
                        else if (i == 4 && j == 3) e->grelha[4][3] = VALOR_X;
                        else e->grelha[i][j] = VAZIA;
                    }
                }

            }

            else printf("So são permitidos Niclname's com menos de 9 caracteres\n\n");
        }

        else if (toupper(peca[0]) != e->icon[0] && toupper(peca[0]) != e->icon[1]) printf("Peca invalida\n\n");

        else printf("Nivel invalido\n\n");

    }

    else printf("erro: é preciso um parâmetro\n\n");

}


/**Altera o estado do jogo para preparar o mesmo para o modo competitivo.
 * Esta funçao limpa tambem a stack; guarda o nickname do jogador no estado;
 * armazenar o primeiro jogador a jogar; meter a dificuldade em 4(que é a dificuldade do modo competitivo)
 * e finalmente meter o jogo no seu estado inicial
*/
void LoadRanking (ESTADO *e) {
    char line[256];
    int primeriaLinha = 0;

    FILE *f = fopen("Ranking.txt","r");

    while (fgets(line, 256 , f)) {

        if (primeriaLinha == 0) primeriaLinha++;

        else snoc(e,line);
    }

    fclose(f);

}


///Funçao aulixiar da funçao LoadRanking
void snoc(ESTADO *e, char *line) {
    int i,j,n;
    char score[5];

    LRanking a;
    LRanking aux = e->tabela;


    a = malloc (sizeof (Ranking));
    a->prox = 0;
    a->jogador.score = 0;


    n = strlen(line);

    i=0;

    while (line[i] != ' ' ) {
        i++;
    }

    while (line[i] == ' ') {
        i++;
    }

    j=0;

    while (line[i] != ' ' ) {
        a->jogador.nome[j] = line[i];
        j++;
        i++;
    }

    while (line[i] == ' ') {
        i++;
    }

    j=0;

    while ( i < n-1 && line[i] != '.') {
        score[j] = line[i];
        j++;
        i++;
    }

    score[j] = '\0';

    n = strlen(score);
    n--;
    i = n;

    while (i!=-1) {
        a->jogador.score += ((score[i] - '0') * pow(10,(n)-i));
        i--;
    }


    if (!aux) e->tabela = a;
    else {

        while (aux->prox) {
            aux = aux->prox;
        }

        aux->prox = a;
    }

}



///Dado um nome de um jogador procura o mesmo no ranking
int ProcuraJogador (ESTADO *e,float Jscore) {
    int encontrado = 0;
    LRanking ant = 0;
    LRanking aux = e->tabela;


    while (aux && encontrado == 0) {

        if (!strcmp(aux->jogador.nome,e->nomeTemporario)) {

            encontrado = 2;

            if (Jscore > aux->jogador.score) {

                encontrado = 1;

                ant->prox = aux->prox;

                free(aux);


            }


        }

        else {
            ant = aux;
            aux = aux->prox;
        }

    }

    return encontrado;

}


///Calcula a pontuçao de um jogador no fim do modo competitivo tendo em conta as suas peças e jogadas
float CalculaScore (ESTADO *e) {
    float Jscore = 0;
    int n,j;

    if (e->peca == VALOR_X) n = NumeroJ1(e);
    else n = NumeroJ2(e);

    j = e->jogadas-30;

    if (n <= 20) Jscore = n;
    else if (n <= 40) Jscore = 2 * n;
    else if (n <= 55) Jscore = 3 * n;
    else Jscore = 4 * n;

    if (j <= 20)  Jscore += (j * 25);
    else if (j <= 23) Jscore += (j * 15);
    else if (j <= 27) Jscore += (j * 10);
    else if (j < 30) Jscore += (j * 5);
    else Jscore += (j * 2);

    return Jscore;

}


/**acrescenta um jogador ao score caso este nao exista se o mesmo existir
 * vai adicionar ordenadamente um novo nodo
 * com o novo nickname e o score obtido pelo jogador a lista ligada existente
*/
void AcrescentaScore (ESTADO *e,float Jscore) {
    LRanking acres;
    LRanking ant = 0;
    LRanking aux = e->tabela;


    if ( ProcuraJogador(e,Jscore) == 0) {

        acres = malloc(sizeof(struct Ranking));
        acres->jogador.score = Jscore;
        strcpy(acres->jogador.nome, e->nomeTemporario);


        while (aux && aux->jogador.score > Jscore) {
            ant = aux;
            aux = aux->prox;
        }

        acres->prox = aux;

        if (ant) ant->prox = acres;
        else e->tabela = acres;

    }

}


///Atualiza o Ranking no ficheiro "Ranking.txt" com a lista ligada alterada
void AtualizaRankingTXT (ESTADO *e) {
    int i;
    int tamanhoNome;
    LRanking aux = e->tabela;


    FILE *f = fopen("Ranking.txt","w");

    fprintf (f,"Position              Nickname              Score\n");

    for (i=1 ; aux ; aux = aux->prox , i++) {

        tamanhoNome = strlen(aux->jogador.nome);

        fprintf(f,"%d",i);

        if (i < 10) fprintf(f,"                     %s",aux->jogador.nome);
        else fprintf(f,"                    %s",aux->jogador.nome);

        if (tamanhoNome == 1) fprintf(f,"                     ");
        else if (tamanhoNome == 2) fprintf(f,"                    ");
        else if (tamanhoNome == 3) fprintf(f,"                   ");
        else if (tamanhoNome == 4) fprintf(f,"                  ");
        else if (tamanhoNome == 5) fprintf(f,"                 ");
        else if (tamanhoNome == 6) fprintf(f,"                ");
        else if (tamanhoNome == 7) fprintf(f,"               ");
        else if (tamanhoNome == 8) fprintf(f,"              ");

        fprintf(f,"%.2f\n",aux->jogador.score);

    }

    fclose(f);


}


///Mostra o ranking ao utilizador
void PrintRanking (ESTADO *e) {
    char linha[256];


    FILE *f = fopen("Ranking.txt","r");

    printf("   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("                  Ranking do Modo Competetivo\n\n");

    while (fgets(linha,256,f)) {
        printf("     %s",linha);
    }

    fclose(f);
    printf ("\n   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n");

}



