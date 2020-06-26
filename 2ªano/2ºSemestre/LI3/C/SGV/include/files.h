/**
@file files.h
\brief Modulo de tratamento dos ficheiros
*/
#ifndef FILES_H
#define FILES_H

#include <stdio.h>
#include <string.h>

#include "defines.h"

/**
@brief Busca os ficheiros a serem lidos
@param Ficheiro dos Clientes
@param Ficheiro dos Produtos
@param Ficheiro das Vendas
*/
void getFiles(char* clientsFilePath, char* productsFilePath, char* salesFilePath);
/**
@brief Verifica se o ficheiro é valido
@param Ficheiro a ser testado
@param String que guarda o file caso seja valido
*/
int verifyFiles(char* files, char* filePath);

#endif