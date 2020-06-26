#ifndef PROJ_MATRIZAJUDA_H
#define PROJ_MATRIZAJUDA_H
#include "Structs.h"
#include "ContadorIcons.h"

//Funcao para printar a matriz de jogadas validas
void MatrizAjuda (ESTADO *e,int flag);

void JogadasValidas (VALOR matriz[][8],VALOR jogador, char MatrizAjuda[][8]);

void FuncaoAuxiliarPrintaMatrizAjuda (ESTADO *e);




#endif //PROJ_MATRIZAJUDA_H
