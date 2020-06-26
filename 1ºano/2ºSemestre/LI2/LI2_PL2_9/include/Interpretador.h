#ifndef PROJ_INTERPRETADOR_H
#define PROJ_INTERPRETADOR_H
#include "Structs.h"
#include "SugestaoJogada.h"
#include "NovoJogo.h"
#include "AtualizarJogo.h"
#include "FuncoesAxuliares.h"
#include "Salvar.h"
#include "Descarregar.h"
#include "ControloDeFicheiros.h"
#include "ControloJogadas.h"
#include "TrocarIcon.h"
#include "MatrizAjuda.h"
#include "Stack.h"
#include "JogadasBotDificil.h"

void Intepretador (ESTADO *e);

void PrintInterpretador (ESTADO *e);

void Interpreta (ESTADO *e, char *linha);



#endif //PROJ_INTERPRETADOR_H
