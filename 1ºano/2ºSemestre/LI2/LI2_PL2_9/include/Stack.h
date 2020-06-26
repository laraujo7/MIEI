#ifndef PROJ_STACK_H
#define PROJ_STACK_H
#include "Structs.h"

//Funcoes para controlo do undo
void EfetuaUndo (ESTADO *e);

void push (ESTADO *e);

void pop (ESTADO *e);




//Funcao para limpar Stack
void LimpaStack (ESTADO *e);



#endif //PROJ_STACK_H
