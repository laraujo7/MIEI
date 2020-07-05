/**
@file gets.h
\brief  Modulo de tratamento de interaçao com o utilizador
*/
#ifndef GETS_H
#define GETS_H


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "sgv.h"
#include "defines.h"
#include "menu.h"

/**
@brief Função que pede uma letra ao utilizador
@return Letra a ser devolvida
*/
char getLetter();

/**
@brief Função que pede uma produto ao utilizador
@param Estrutura de Dados para vereficar a existencia do produto
@param Produto a ser devolvido
*/
void getProduct(SGV sgv,char product[]);

/**
@brief Função que pede um mes ao utilizador
@return Mes introduzido
*/
int getMonth();

/**
@brief Função que pede uma filial ao utilizador
@return Filial introduzido
*/
int getBranch();

/**
@brief Função que pede uma cliente ao utilizador
@param Estrutura de Dados para vereficar a existencia do cliente
@param Cliente a ser devolvido
*/
void getClient(SGV sgv,char client[]);

/**
@brief Funcao que pede um mes ao utilizador para fazer um intervalo
@return Mes maximo
*/
int getMaxMonth();

/**
@brief Função que pede uma filial ao utilizador
@return Filial introduzido
*/
int getOneBranch();

/**
@brief Função que pede um numero ao utilizador
@return Numero introduzido
*/
int getNumber();

#endif