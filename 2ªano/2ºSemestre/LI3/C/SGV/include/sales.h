/**
@file sales.h
\brief Modulo que faz o tratamento das vendas
*/
#ifndef SALES_H
#define SALES_H

#include <stdio.h>
#include <gmodule.h>

/**
@brief Estrutura das vendas
*/
typedef struct sales* SALES;

/**
@brief Estrutura que relaciona produtos com clientes
*/
typedef struct prodCl* PRODCL;

/**
@brief Estrutura que relaciona clientes com produtos
*/
typedef struct clProd* CLPROD;

/**
@brief Estrutura que guarda clientes numa procura
*/
typedef struct clSearcher* CLSEARCHER;

/**
@brief Estrutura que guarda produtos numa procura
*/
typedef struct prSearcher* PRSEARCHER;


/**
@brief Inicializador da Estrutura das Vendas
@return Estrutura das Vendas
*/
SALES initSales();

/**
@brief Destruiçao da Estrutura das Vendas
@param Estrutura a ser destruida
*/
void destroySales(SALES sales);

/**
@brief Destruiçao da Estrutura que relaciona produtos com clientes
@param Estrutura a ser destruida
*/
void destroyProductsClients (void* prCl);

/**
@brief Destruiçao da Estrutura que relaciona clientes com produtos
@param Estrutura a ser destruida
*/
void destroyClientsProducts(void* clPr);

/**
@brief Carrega uma venda a Estrutura de Vendas
@param Estrutura de Vendas
@param Cliente a adicionar
@param Produto a adicionar
@param Tipo da venda
@param Custo unitario do produto
@param Unidades vendidas
@param Mes da venda
*/
void addBranch(SALES sales,char* product,char* client,char type,float price,int units,int month);

/**
@brief Inicialização da Estrutura que relaciona Clientes com Produtos
@return Estrutura que relaciona Clientes com Produtos inicializada
*/
CLPROD initClientProducts();

/**
@brief Altera a Estrutura que relaciona clientes com produtos, alterando a faturaçao do produto
@param Estrutra a ser alterada
@param Produto que sera alterado
@param Mes da venda
@param Unidades da vena
@param Preço unitario da venda
*/
void changeClientsProducts(CLPROD cp, char* product, int month, int units, float price);

/**
@brief Inicialização da Estrutura que relaciona Produtos com Clientes
@return Estrutura que relaciona Produtos com Clientes inicializada
*/
PRODCL initProductsClients();

/**
@brief Altera a Estrutura que relaciona produtos com clientes, aumentando o preço e o numero de vendas sofridas por um produto
@param Estrutra a ser alterada
@param Tipo da venda
@param Preço unitario da venda
@param Mes da venda
*/
void changeTotalProducts(double total[][2][12], char type, float price, int month);

/**
@brief Altera a Estrutura que relaciona produtos com clientes, alterando o tipo de venda que o cliente fez
@param Estrutra a ser alterada
@param Cliente que sera alterado
@param Tipo de venda
*/
void changeProductsClients(PRODCL cl, char* client, char type);

/**
@brief Função que encontra as vendas e a faturaçao de um produto num certo mes
@param Estrutura de filiais
@param Produto a procura
@param Mes em questao
@param Array o qual sera guardado as respostas das vendas e faturaçao dividido em filiais 
*/
void findProductSalesAndProfit(SALES* sales,char* productID,int month,double res[][4]);

/**
@brief Função que encontra as vendas feitas por um cliente
@param Estrutura das vendas
@param Cliente a procurar
@param Array onde sera guardado as respostas
*/
void findProductSellesByClient(SALES sales,char* client,int* res);

/**
@brief Função que encontra as clientes que compraram um produto
@param Estrutura das vendas
@param Produto a procurar
@return Estrutura que guarda os clientes divindindo-os em compras N e P
*/
CLSEARCHER getCLSearcher(SALES sale,char* productID);

/**
@brief Função que encontra o numero de vendas feitas
@param Estrutura que relaciona produtos com clientes
@param Flag para procurar clientes que fizeram compras de tipo N ou P
@return Numero de vendas
*/
int numberOfSales(PRODCL pc, int flag);

/**
@brief Função auxiliar que encontra clientes
@param Estrutura que relaciona produtos com clientes
@param Flag para procurar clientes que fizeram compras de tipo N ou P
@return Numero de vendas
*/
void findCLS(gpointer key, gpointer value, gpointer data);

/**
@brief Função que retira os clientes e as unidades da Estrutura de procura "CLSEARCHER"
@param Estrutura de procura "CLSEARCHER"
@param Lista de strings onde sera guardado os clientes
@param Flag para determinar o tipo N ou P
@return Numero de unidades
*/
int getClientsAndUnitsCLS(CLSEARCHER cls,char*** clientes,int flag);

/**
@brief Função que elimina a estrutura de procura "CLSEARCHER"
@param Estrutura a ser destruida
*/
void destroyCLS(CLSEARCHER cls);

/**
@brief Função que constroi a estrutura de procura "PRSEARCHER"
@param Array de Estrutura das vendas
@param Cliente a ser procurado
@param Mes a ser procurado
@param Numero de produtos comprados por um cliente
@return Estrutura de procura "PRSEARCHER"
*/
PRSEARCHER findClientFavotiteProducts(SALES* sales,char* client,int month,int* size);

/**
@brief Função que calcula o numero de produtos comprados por um cliente
@param Estrutura das vendas
@param Cliente a ser procurado
@param Mes a ser procurado
@return numero de produtos comprados
*/
int sizeOfProducts(SALES sales,char* client,int month);

/**
@brief Função auxilar que retorna se o segundo parametro é maior do que o primeiro
@param String 1
@param String 2
@return Resposta da comparaçao de duas strings
*/
int sort(const void* one, const void* two);

/**
@brief Função encontra os produtos da estrutura "PRSEARCHER" e coloca-os numa lista de strings
@param Estrutura de procura "PRSEARCHER"
@param Tamanho da lista
@return Lista de produtos
*/
char** getProductsAndUnitsPRS(PRSEARCHER prs,int size,int qt[]);

/**
@brief Função que junta as filiais numa unica hash table
@param Array de Estruturas das vendas
@return Hash table retornada
*/
GHashTable* mergeBranches(SALES* sales);

/**
@brief Função encontra os 'n' produtos que mais faturou em todo ano (este executa a query 11 e query a partir de uma flag)
@param Hash table de todas as filiais juntas
@param Tamanho da hash table
@param Numero de produtos a ir buscar
@param Flag para saber se estamos a executar a query 11 ou 12
@return Lista de produtos
*/
char** findSalesMerge(GHashTable* merge,double qt[], int size, int limit,int flag);

/**
@brief 
@param Array de estrutura das vendas
@param Matriz que ir guardar os resultados dividido em filiais, vendas, e numero de clientes comprados
@param Numero de produtos
@param Filial a procurar
*/
void findData(SALES* sales,int data[][3][2],char** prods,int limit,int branch);

/**
@brief Função que junta as filiais devididas em meses numa unica hash table
@param Array de Estruturas das vendas
@return Hash table retornada
*/
GHashTable* mergeBranchesAndMonths(SALES* sales,char* client);



#endif
