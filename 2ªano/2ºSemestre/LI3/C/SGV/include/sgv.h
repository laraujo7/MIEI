/**
@file sgv.h
\brief Modulo de tratamento da Base de Dados
*/
#ifndef SGV_H
#define SGV_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
@brief Base de Dados
*/
typedef struct sgv* SGV;

#include "clients.h"
#include "products.h"
#include "sales.h"


/**
@brief Inicializador da Base de Dados
@return Estrutura SGV
*/
SGV initialize_SGV();

/**
@brief Destruiçao da Base de Dados
@param Estrutura a ser destruida
*/
void destroctionSGV(SGV sgv);

/**
@brief Carrega Bases de Dados (SGV) com os ficheiros
@param Ficheiro dos clientes
@param Ficheiro dos produtos
@param Ficheiro das vendas
@return Bases de Dados (SGV) carregado
*/
SGV loadSGV(SGV sgv, char* clientsFilePath, char* productsFilePath, char* salesFilePath);

/**
@brief Carrega Estrutura dos clientes a partir do ficheiro dos clientes
@param Base de Dados (SGV)
@param Ficheiro dos clientes
*/
void readClients(SGV sgv, char* clientsFilePath);

/**
@brief Carrega Estrutura dos produtos a partir do ficheiro dos produtos
@param Base de Dados (SGV)
@param Ficheiro dos produtos
*/
void readProducts(SGV sgv,char* productsFilePath);

/**
@brief Carrega Estrutura das vendas a partir do ficheiro das vendas
@param Base de Dados (SGV)
@param Ficheiro das vendas
*/
void readSales(SGV sgv,char* salesFilePath);

/**
@brief Altera o numero de vendas faturação total por meses
@param Base de Dados (SGV)
@param Preço unitario da vendas
@param Unidades da venda
@param Mes da venda
*/
void changeTotalMonth(SGV sgv, float price, int units, int month);

/**
@brief Verifica se uma venda é valida
@param Base de Dados (SGV)
@param Apontador de strings a serem validadas
*/
int validadeSale(SGV sgv,char** token);

/**
@brief Verifica se um produto é bem contruido
@param String a ser validada
*/
int validateProduct(char* buffer);

/**
@brief Verifica se um preço é bem contruido
@param String a ser validada
*/
int validatePrice(char *price);

/**
@brief Verifica se as unidades sao bem contruidas
@param String a ser validada
*/
int validateUnits(char *units);

/**
@brief Verifica se o tipo de venda é bem contruida
@param String a ser validada
*/
int validateType(char *type);

/**
@brief Verifica se um cliente é bem contruido
@param String a ser validada
*/
int validateClient(char* buffer);

/**
@brief Verifica se o mes da venda é bem contruida
@param String a ser validada
*/
int validateMonth(char *month);

/**
@brief Verifica se a filial da venda é bem contruida
@param String a ser validada
*/
int validateBranch(char *branch);

/**
@brief Função que encontra o array de produtos correspondente a uma letra
@param Estrutura de Dados (SGV)
@param Letra a qual ir corresponde o array
@return Estrutura dos produtos
*/
PRODUCTS getArrayProductsByLetter(SGV sgv,char letter);

/**
@brief Função que encontra o array de produtos
@return Array da Estrutura dos produtos
*/
PRODUCTS* getArrayProducts(SGV sgv);

/**
@brief Função que retorna o array de filias
@param Estrutura de Dados (SGV)
@return Estrutura de filias
*/
SALES* getArraySales(SGV sgv);

/**
@brief Função que retorna um Estrutura de Filias
@param Estrutura de Dados (SGV)
@param Filia a ser procurada
@return Estrutura de filias
*/
SALES getSales(SGV sgv, int branch);

/**
@brief Função que retorna a Estrutura dos Clientes
@param Estrutura de Dados (SGV)
@return Estrutura dos Clientes
*/
CLIENTS getClients(SGV sgv);

/**
@brief Função que retorna as linhas lidas e as validas da leitura dos files
@param Estrutura de Dados (SGV)
@return Array com o numero das linhas lidas e as validas da leitura dos files
*/
int* getLinesValidatedAndRead(SGV sgv);

/**
@brief Função que retorna a Estrutura dos Clientes
@param Estrutura de Dados (SGV)
@param Mes minimo
@param Mes maximo
@param Array que ira guardar a resposta
*/
void findSalesAndProfit(SGV sgv,int minMonth,int maxMonth,double res[]);

#endif
