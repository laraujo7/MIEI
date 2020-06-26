#ifndef PROJ_FUNCOESAXULIARES_H
#define PROJ_FUNCOESAXULIARES_H
#include "Stack.h"
#include "Structs.h"
#include "ContadorIcons.h"

//Funcoes para o modo competetivo
void NovoJogoCompetetivo (ESTADO *e,char *linha);

void LoadRanking (ESTADO *e);

void snoc(ESTADO *e, char *line);

int ProcuraJogador (ESTADO *e,float Jscore);

float CalculaScore (ESTADO *e);

void AcrescentaScore (ESTADO *e,float Jscore);

void AtualizaRankingTXT (ESTADO *e);

void showListRanking (LRanking l);


//Funcao para printar o ranking
void PrintRanking (ESTADO *e);



#endif //PROJ_FUNCOESAXULIARES_H
