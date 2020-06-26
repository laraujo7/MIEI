#ifndef PROJ_JOGADASMANUAL_H
#define PROJ_JOGADASMANUAL_H
#include "Structs.h"
#include "MatrizAjuda.h"
#include "Stack.h"
#include "NJogadasValidas.h"

//Funcoes para a construçao da jogada
void EfetuaJogada (ESTADO *e,char *linha);

int ConvertePecas (VALOR Matriz[][8],VALOR Jogador, int Li, int Co); //esta é a funcao que troca as pecas em uma jogada

void TrocaPeca (ESTADO *e);



#endif //PROJ_JOGADASMANUAL_H
