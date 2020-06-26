#ifndef PROJ_JOGADASBOTCOMP_H
#define PROJ_JOGADASBOTCOMP_H
#include "Structs.h"
#include "MatrizAjuda.h"
#include "JogadasManual.h"
#include "JogadasBotComp.h"
#include "JogadasBotMedio.h"


void EfetuaJogadaBot4 (ESTADO *e,char *linha);


void JogaBot4 (ESTADO *e);

int CalculaMobilidade(ESTADO *e,VALOR MatrizJogadas[][8],int i, int j);


#endif //PROJ_JOGADASBOTCOMP_H
