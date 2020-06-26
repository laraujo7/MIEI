#ifndef PROJ_JOGADASBOTDIFICIL_H
#define PROJ_JOGADASBOTDIFICIL_H
#include "Structs.h"
#include "MatrizAjuda.h"
#include "JogadasManual.h"
#include "JogadasBotMedio.h"




void EfetuaJogadaBot3 (ESTADO *e, char *linha);



int MinMax (ESTADO *e,VALOR Matriz[][8],int Alcance,VALOR jogador,int alpha,int beta);


void ConverteMatriz (ESTADO *e,VALOR Matriz[][8],char MatrizAConverter[][8]);


#endif //PROJ_JOGADASBOTDIFICIL_H
