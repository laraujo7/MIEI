#ifndef PROJ_DESCARREGAR_H
#define PROJ_DESCARREGAR_H
#include "Structs.h"
#include "Stack.h"
#include "Salvar.h"
#include "ContadorIcons.h"
#include "ControloDeFicheiros.h"


//Funcao para dar load a um estado de um ficheiro
void LoadEstado (ESTADO *e,char *linha);

int CalculaNumeroJogadas (ESTADO *e);




#endif //PROJ_DESCARREGAR_H
