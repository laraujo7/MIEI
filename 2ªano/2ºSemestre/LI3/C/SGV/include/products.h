/**
@file products.h
\brief Modulo que faz o tratamento dos produtos
*/
#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <stdio.h>
#include <gmodule.h>


/**
@brief Estrutura dos Produtos
*/
typedef struct products* PRODUCTS;

/**
@brief Estrutura que guarda os produtos durante uma procura
*/
typedef struct productSearch* PRODUCTSEARCH;

/**
@brief Inicializador da Estrutura dos Produtos
@return Estrutura dos Produtos
*/
PRODUCTS initProducts();

/**
@brief Destruiçao da Estrutura dos Produtos
@param Estrutura a ser destruida
*/
void destroyProducts(PRODUCTS products);

/**
@brief Adiciona um produto a estrutura dos Produtos
@param Estrutura a dos produtos
@param Produto a ser introduzido
*/
void addProduct(PRODUCTS products,char* product);

/**
@brief Altera value do produto, indicando em qual filial o produto foi vendido 
@param Estrutura a dos produtos
@param Produto a ser aleterado
@param Filial em que a venda foi efetuada
*/
void changeBranchProducts(PRODUCTS products,char* product,int branch);

/**
@brief Verifica se um produto esta na Estrutura de Produtos
@param Estrutura a dos produtos
@param Produto a ser verificado
*/
int listOfProducts(PRODUCTS products,char* product);

/**
@brief Função que encontra os produtos começados por uma determinada letra
@param Estrutura a dos produtos
@return Estrutura a qual guarda os produtos procurados
*/
PRODUCTSEARCH findProductsByLetter(PRODUCTS products);

/**
@brief Função auxiliar que atravesa todos os nodos de uma arvore
@param Key correspondente ao nodo
@param Value correspondente ao nodo
@param Paramentro passado pela funçao "g_hash_table_foreach" (neste caso a estrutura PRODUCTSEARCH)
@return Inteiro caso queria parar a funçao
*/
int iter_all(gpointer key, gpointer value, gpointer data);

/**
@brief Inicializa uma estrutura de procura para os produtos
@param Tamanho da lista a strings
@return Estrutura inicializada
*/
PRODUCTSEARCH initProductSearch(int size);

/**
@brief Função que passa os produtos encontrados pela estrutura PRODUCTSEARCH para um lista de strings
@param Estrutura PRODUCTSEARCH
@return Lista de Strings
*/
char** getProductsOfPS(PRODUCTSEARCH ps);

/**
@brief Função que retorna o numero de produtos encontrados pela estrutura PRODUCTSEARCH
@param Estrutura PRODUCTSEARCH
@return Numero de produtos lidos
*/
int getTotalOfPS(PRODUCTSEARCH ps);

/**
@brief Função que destroi a estrutura PRODUCTSEARCH
@param Estrutura PRODUCTSEARCH a ser eleminada
*/
void destroyPS(PRODUCTSEARCH ps);

/**
@brief Função que encontra todos os produtos nao vendidos de uma ou todas filial
@param Array de Estrutura de Produtos
@param Filial a procurar
@return Array de Estruturas PRODUCTSEARCH
*/
PRODUCTSEARCH findProductsNeverBought(PRODUCTS* products,int branch);

/**
@brief Função auxiliar que atravesa todos os nodos de uma arvore e encontra os produtos nao vendidos na filial 1
@param Key correspondente ao nodo
@param Value correspondente ao nodo
@param Paramentro passado pela funçao "g_hash_table_foreach" (neste caso um array de inteiros)
@return Inteiro caso queria parar a funçao
*/
int productsNeverBought0(gpointer key, gpointer value, gpointer data);

/**
@brief Função auxiliar que atravesa todos os nodos de uma arvore e encontra os produtos nao vendidos na filial 2
@param Key correspondente ao nodo
@param Value correspondente ao nodo
@param Paramentro passado pela funçao "g_hash_table_foreach" (neste caso um array de inteiros)
@return Inteiro caso queria parar a funçao
*/
int productsNeverBought1(gpointer key, gpointer value, gpointer data);

/**
@brief Função auxiliar que atravesa todos os nodos de uma arvore e encontra os produtos nao vendidos ma filial 3
@param Key correspondente ao nodo
@param Value correspondente ao nodo
@param Paramentro passado pela funçao "g_hash_table_foreach" (neste caso um array de inteiros)
@return Inteiro caso queria parar a funçao
*/
int productsNeverBought2(gpointer key, gpointer value, gpointer data);

/**
@brief Função auxiliar que atravesa todos os nodos de uma arvore e calcula o numero de produtos nao vendidos em todas a filiais
@param Key correspondente ao nodo
@param Value correspondente ao nodo
@param Paramentro passado pela funçao "g_hash_table_foreach" (neste caso um array de inteiros)
@return Inteiro caso queria parar a funçao
*/
int sizeOfProductsNeverBoughtEveryBranch(gpointer key, gpointer value, gpointer data);

/**
@brief Função auxiliar que atravesa todos os nodos de uma arvore e calcula o numero de produtos nao vendidos
@param Key correspondente ao nodo
@param Value correspondente ao nodo
@param Paramentro passado pela funçao "g_hash_table_foreach" (neste caso um array de inteiros)
@return Inteiro caso queria parar a funçao
*/
int sizeOfProductsNeverBoughtAllBranches(gpointer key, gpointer value, gpointer data);

/**
@brief Função auxiliar que atravesa todos os nodos de uma arvore e encontra os produtos nao vendidos em todas as filiais
@param Key correspondente ao nodo
@param Value correspondente ao nodo
@param Paramentro passado pela funçao "g_hash_table_foreach" (neste caso um array de inteiros)
@return Inteiro caso queria parar a funçao
*/
int productsNeverBought(gpointer key, gpointer value, gpointer data);

/**
@brief Função que conta o numero de produtos que nunca foram comprados
@param Array de Estrutura dos Produtos
@return Numero de produtos que nunca foram comprados
*/
int findProductsNeverBoughtCount(PRODUCTS* products);

/**
@brief Função auxiliar que conta o numero de produtos que nunca foram comprados
@param Key correspondente ao produto
@param Value correspondente ao produto
@param Data intrudozida (neste caso o numero de produtos que nunca foram comprados)
@return Inteiro caso queria parar a funçao
*/
int numberOfProductsNeverBought(gpointer key, gpointer value, gpointer data);

#endif
