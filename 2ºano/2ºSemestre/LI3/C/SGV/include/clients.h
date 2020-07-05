/**
@file clients.h
\brief Modulo que faz o tratamento dos clientes
*/
#ifndef CLIENTS_H
#define CLIENTS_H

#include <stdio.h>
#include <string.h>
#include <gmodule.h>

/**
@brief Estrutura dos Clientes
*/
typedef struct clients* CLIENTS;

/**
@brief Inicializador da Estrutura dos Clientes
@return Estrutura dos Clientes
*/
CLIENTS initClients();

/**
@brief Destruiçao da Estrutura dos Clientes
@param Estrutura a ser destruida
*/
void destroyClients(CLIENTS clients);

/**
@brief Adiciona um cliente a estrutura dos Clientes
@param Estrutura a dos clientes
@param Cliente a ser introduzido
*/
void addClient(CLIENTS clients,char* client);

/**
@brief Altera valor do array branch, na estrutura Cliente, para que este esteja marcado como comprou um produto num filial
@param Estrutura a dos clientes
@param Cliente a ser alterado
@param Branch a ser alterada
*/
void changeBranchClients(CLIENTS clients, char* client,int branch);

/**
@brief Verifica se um cliente esta na Estrutura de Clientes
@param Estrutura a dos clientes
@param Cliente a ser verificado
*/
int listOfClients(CLIENTS clients,char* client);


/**
@brief Função que vai buscar todos os clientes que efetuaram compras em todas as filias e ordena-os
@param Estrutura dos clientes
@param Apontador do tamanho do numero de clientes
*/
char** findClientesOfAllBranches(CLIENTS clients,int* size);

/**
@brief Função auxiliar que ordena clientes
@param Cliente 1
@param Cliente 2
@return Retorna (0) caso sejam igual, (1) se cliente 2 > cliente 1 e (-1) de cliente 2 < cliente 1
*/
int sortByLetter(const void* a, const void* b);

/**
@brief Função que inicializa um lista de strings
@param Tamanho da lista
@return Lista de strings inicializada
*/
char** initCLS(int size);

/**
@brief Função auxiliar que conta o numero de clientes que efetuaram compras em todas as filias
@param Key correspondente ao cliente
@param Value correspondente ao cliente
@param Data intrudozida (neste caso o tamanho que ir tomar a lista de strings)
*/
void numberOfClientsOfAllBranches(gpointer key, gpointer value, gpointer data);

/**
@brief Função que conta o numero de clientes que nunca compraram
@param Estrutura dos Clientes
@return Numero de clientes que nunca compraram
*/
int findClientsNeverBoughtCount(CLIENTS clients);

/**
@brief Função auxiliar que conta o numero de clientes que nunca compraram
@param Key correspondente ao cliente
@param Value correspondente ao cliente
@param Data intrudozida (neste caso o numero de clientes que nunca compraram)
*/
void numberOfClientsNeverBought(gpointer key, gpointer value, gpointer data);

#endif
