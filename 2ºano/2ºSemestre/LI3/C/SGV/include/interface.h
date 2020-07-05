/**
@file interface.h
\brief Modulo que faz o tratamento das queries
*/
#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sgv.h"
#include "defines.h"
#include "menu.h"
#include "files.h"
#include "gets.h"
#include "sales.h"
#include "products.h"

/**
@brief Inicialização da Base de Dados
@return Base de Dados
*/
SGV initSGV();

/**
@brief Destrução da Base de Dados
@param Base de Dados a ser destruida
*/
void destroySGV(SGV sgv);

/**
@brief Carregar Base de Dados (SGV) a partir de ficheiros
@param Ficheiro dos Clientes
@param Ficheiro dos Produtos
@param Ficheiro das Vendas
@return Base de Dados (SGV) carregada
*/
SGV loadSGVFromFiles(SGV sgv, 
    char* clientsFilePath, 
    char* productsFilePath, 
    char* salesFilePath
    );

void getCurrentFilesInfo(SGV sgv);

/**
@brief Função que vai buscar todos produtos que começam por um letra (QUERY2)
@param Estrutura de Dados (SGV)
@param Letra inicial do produto
*/
void getProductsStartedByLetter(SGV sgv, char letter);

/**
@brief Função que vai buscar todas as vendas e faturaçao ocurridas num certo mes por um produto(QUERY3)
@param Estrutura de Dados (SGV)
@param Produto a ser examinado
@param Mes em questao
*/
void getProductSalesAndProfit(SGV sgv, char* productID, int month);

/**
@brief Função que vai buscar todos os produtos que nao foram vendidos (por filiais ou geral) (QUERY4)
@param Estrutura de Dados (SGV)
@param Filial a procurar produtos
*/
void getProductsNeverBought(SGV sgv, int branchID);

/**
@brief Função que vai buscar todos os clientes que efetuaram compras em todas as filias (QUERY5)
@param Estrutura de Dados (SGV)
*/
void getClientsOfAllBranches(SGV sgv);

/**
@brief Função que vai calcular o numero de produtos e clientes que nao efetuaram compras (QUERY6)
@param Estrutura de Dados (SGV)
*/
void getClientsAndProductsNeverBoughtCount(SGV sgv);

/**
@brief Função que vai buscar o numero de compras de um determinado cliente (QUERY7)
@param Estrutura de Dados (SGV)
@param Cliente a ser examinado
*/
void getProductsBoughtByClient(SGV sgv, char* clientID);

/**
@brief Função que vai buscar o numero de compras e a faturação num intervalo de meses (QUERY8)
@param Estrutura de Dados (SGV)
@param Mes minimo
@param Mes maximo
*/
void getSalesAndProfit(SGV sgv, int minMonth, int maxMonth);

/**
@brief Função que vai buscar os clientes que compraram um produto num certo filial (QUERY9)
@param Estrutura de Dados (SGV)
@param Produto a ser procurado
@param Filial a ser procurada
*/
void getProductsBuyers(SGV sgv, char* productID, int branch);

/**
@brief Função que vai buscar os produtos comprados por um cliente num certo mes, ordenando-os (QUERY10)
@param Estrutura de Dados (SGV)
@param Cliente a ser procurado
@param Mes a ser procurada
*/
void getClientFavoriteProducts(SGV sgv, char* clientID, int month);

/**
@brief Função que vai buscar os produtos mais vendidos (QUERY11)
@param Estrutura de Dados (SGV)
@param Numero de produtos a pesquisar
*/
void getTopSelledProducts(SGV sgv, int limit);

/**
@brief Função que encontra os 'n' produtos mais comprados pelo cliente (QUERY12)
@param Estrutura de Dados (SGV)
@param Cliente em questao
@param Numero de produtos a pesquisar
*/
void getClientTopProfitProducts(SGV sgv, char* clientID, int limit);

/**
@brief Função que mostra a informaçao sobre a leitura dos files da primeira query (QUERY13)
@param Estrutura de Dados (SGV)
@param Ficheiro dos clientes
@param Ficheiro dos produtos
@param Ficheiro das vendas
@param Tempo de construção da base de dados
*/
void showFilesInfo(SGV sgv,char* clientsFilePath,char* productsFilePath,char* salesFilePath,float time);




#endif
