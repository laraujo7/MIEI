/**
@file menu.h
\brief Modulo de tratamento do menu
*/
#ifndef MENU_H
#define MENU_H

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "defines.h"
#include "sgv.h"
#include "products.h"
#include "clients.h"


int showMenuOption();

int showMenu1(int valid);

int showAndGetOptionMenu2(int valid);
void showMenu2(int op);

void parteDeCimaMenu();
void parteDeBaixoMenu();
void letrasSGV();
void menuPalavra();
void loading();
void parteDeCimaTabela();
void parteDeBaixoTabela();
void infoPalavra();
void dataPalavra();
void parteDeCimaTempos();
void parteDeBaixoTempos();
void getEnter();
void enterToContinue();




/* funcoes auxiliares de cada query*/
void mostraLetra(char letter);
void mostraProdutosQuery2(char** prods, int size, int nPags, int pag);
void miniMenuQuery2(float time,int nPags,int pag,int size);


void produtoMesPalavras(char* product,int month);
void filiaisPalavras();
void fatUniPalavras();
void dadosCompras(double res[][4]);
void visaoGlobalPalvra();
void FatUniPalavrasG();
void dadosComprasG(double res[][4]);
void miniMenuQuery3(float time, int op);


void mostraFilial(int filial);


void mostraClientesQuery5(char** clients, int size, int nPags, int pag);
void setasPalavras();
void miniMenuQuery5(float time,int size,int nPags,int pag);


void mostraContador(int res[]);
void miniMenuQuery6(float time);


void clientePalavra(char* client);
void dadosClientesMes(int res[][12]);

void dadosTotalVendas(int* intervalo, double* res);
void printaDadosTotalVendas(double res,int q);
void produtoFilialPalavras(char* produto, int filial);
void clientesQuery9(char** clientesN,int unidN,char** clientesP,int unidP, int maior);
void miniMenuQuery9(int total,float time);


void clienteMesPalavras(char* client,int month);
void dadosQuery10(char** prods,int qt[],int size);


void query11Palavras();
void dadosQuery11(char** prods,int data[][3][2],int size,int nPags,int pag);


void mostraClientesPalavras(char* client);
void dadosQuery12(char** prods,double qt[],int limit,int pag);


/* Resposta de cada query */
void showProductsStartbyLetter(char** prods,char letter,int size, float time);
void showProductSalesAndProfit(char* product, int month, double res[][4],float time);
void showProductsNeverBought(char** prods,int size,int branchID, float time);
void showClientsOfAllBranches(char** clients,int size, float time);
void showClientsAndProductsNeverBoughtCount(int res[], float time);
void showProductsBoughtByClient(char* client, int res[][12], float time);
void showSalesAndProfit(int minMonth,int maxMonth,double res[],float time);
void showProductsBuyers(char* productID,int branch,char** clientsN,char** clientsP,int unitsN,int unitsP,float time);
void showClientFavoriteProducts(char** prods,int qt[],char* client,int month,int size,float time);
void showTopSoldProducts(char** prods,int data[][3][2],int limit,float time);
void showClientTopProfitProducts(char** prods,double qt[],char* client,int limit,float time);
void filesInfo(int l[],char* clients, char* prods, char* sales, float time);

void showDestructionTime(float time);


/* gets do menu 2 */
/* query 2 */
char getLetter2();

/* query 3 */
void getProductAndMonth2(SGV sgv,char product[],int* month);

/* query 4 */
int getBranches2();

/* query 7 */
void getClient2(SGV sgv,char client[]);

/* query 8 */
void getMinAndMaxMonth2(int* minMonth,int* maxMonth);

/* query 9 */
void getProductAndBranch2(SGV sgv,char* product,int* branch);

/* query 10 */
void getClientAndMonth2(SGV sgv,char* client,int *month);

/* query 11 */
int getNumber2();

/* query 12 */
int getClientAndNumber(SGV sgv,char* client);

#endif
