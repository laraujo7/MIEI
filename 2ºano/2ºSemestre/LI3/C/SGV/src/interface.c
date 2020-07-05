#include "interface.h"

SGV initSGV() {
    return initialize_SGV();
}


void destroySGV(SGV sgv) {
    clock_t start,end;
    
    loading();

    start = clock();

    destroctionSGV(sgv);
    free(sgv);

    end = clock();
    showDestructionTime((float)(end - start) / CLOCKS_PER_SEC);
}


SGV loadSGVFromFiles(SGV sgv, char* clientsFilePath, char* productsFilePath, char* salesFilePath) {
    return loadSGV(sgv,clientsFilePath,productsFilePath,salesFilePath);
}


/* -> Query 2 <- */
void getProductsStartedByLetter(SGV sgv, char letter){
    PRODUCTSEARCH ps;

    clock_t start,end;
    start = clock();

    ps = findProductsByLetter(getArrayProductsByLetter(sgv,letter));

    char** prods = getProductsOfPS(ps);
    int total = getTotalOfPS(ps);

    end = clock();

    showProductsStartbyLetter(prods,letter,total,((float)(end - start) / CLOCKS_PER_SEC));

    destroyPS(ps);   
}


/* -> Query3 <- */
void getProductSalesAndProfit(SGV sgv, char* productID, int month){
    double res[3][4];

    clock_t start,end;
    start = clock();
    
    findProductSalesAndProfit(getArraySales(sgv),productID,month,res);

    end = clock();
    
    showProductSalesAndProfit(productID,month,res,((float)(end - start) / CLOCKS_PER_SEC));
}


/* -> Query4 <- */
void getProductsNeverBought(SGV sgv, int branchID) {
    PRODUCTSEARCH ps;
    char** prods;
    int size;

    clock_t start,end;
    start = clock();

    ps = findProductsNeverBought(getArrayProducts(sgv),branchID);

    prods = getProductsOfPS(ps);
    size = getTotalOfPS(ps);
    
    qsort(prods,size,sizeof(char*),sortByLetter);

    end = clock();

    showProductsNeverBought(prods,size,branchID,((float)(end - start) / CLOCKS_PER_SEC));

    destroyPS(ps);
}


/* -> Query 5 <- */
void getClientsOfAllBranches(SGV sgv){
    char** prods;
    int i,size = 0;

    clock_t start,end;
    start = clock();

    prods = findClientesOfAllBranches(getClients(sgv),&size);

    end = clock();
    
    showClientsOfAllBranches(prods,size,((float)(end - start) / CLOCKS_PER_SEC));
    
    for(i=0 ; i<size ; i++) free(prods[i]);

    free(prods);
}


/* -> Query 6 <- */
void getClientsAndProductsNeverBoughtCount(SGV sgv){
    int res[2];

    clock_t start,end;
    start = clock();

    res[0] = findClientsNeverBoughtCount(getClients(sgv));
    res[1] = findProductsNeverBoughtCount(getArrayProducts(sgv));

    end = clock();

    showClientsAndProductsNeverBoughtCount(res,((float)(end - start) / CLOCKS_PER_SEC));
}


/* -> Query 7 <- */
void getProductsBoughtByClient(SGV sgv, char* clientID){
    int i;
    int res[3][12] = {0};

    clock_t start,end;
    start = clock();

    for(i=0 ; i<3 ; i++)
        findProductSellesByClient(getSales(sgv,i),clientID,res[i]);

    end = clock();

    showProductsBoughtByClient(clientID,res,((float)(end - start) / CLOCKS_PER_SEC));

}


/* -> Query 8 <- */
void getSalesAndProfit(SGV sgv, int minMonth, int maxMonth){
    double res[2] = {0};

    clock_t start,end;
    start = clock();

    findSalesAndProfit(sgv,minMonth,maxMonth,res);

    end = clock();
    
    showSalesAndProfit(minMonth,maxMonth,res,((float)(end - start) / CLOCKS_PER_SEC)); 
}


/* -> Query 9 <- */
void getProductsBuyers(SGV sgv, char* productID, int branch){
    CLSEARCHER cls = NULL;
    char** clientsN = NULL;
    char** clientsP = NULL;
    int unitsN,unitsP;

    clock_t start,end;
    start = clock();

    cls = getCLSearcher(getSales(sgv,branch),productID);

    unitsN = getClientsAndUnitsCLS(cls,&clientsN,0);
    unitsP = getClientsAndUnitsCLS(cls,&clientsP,1);

    end = clock();
    
    showProductsBuyers(productID,branch,clientsN,clientsP,unitsN,unitsP,((float)(end - start) / CLOCKS_PER_SEC));

    destroyCLS(cls);
}


/* -> Query 10 <- */
void getClientFavoriteProducts(SGV sgv, char* client, int month){
    char** prods = NULL;
    PRSEARCHER prs;
    int i,size = 0;

    clock_t start,end;
    start = clock();

    prs = findClientFavotiteProducts(getArraySales(sgv),client,month,&size);
    int qt[size];
    prods = getProductsAndUnitsPRS(prs,size,qt);

    end = clock();

    showClientFavoriteProducts(prods,qt,client,month,size,((float)(end - start) / CLOCKS_PER_SEC));

    for(i=0 ; i<size ; i++) free(prods[i]);
    free(prods);
    free(prs);
}

/* -> Query 11 <- */
void getTopSelledProducts(SGV sgv, int limit){
    char** prods;
    int i,j,k,size = 0;
    GHashTable* merge;

    clock_t start,end;
    start = clock();


    merge = mergeBranches(getArraySales(sgv));
    size = g_hash_table_size(merge);
    if(limit > size) limit = size;

    int data[limit][3][2];
    double qt[limit];
    for(i=0 ; i<limit ; i++)
        for(j=0 ; j<3 ; j++)
            for(k=0 ; k<2 ; k++) data[i][j][k] = 0;

    prods = findSalesMerge(merge,qt,size,limit,11);
    
    for(i=0 ; i<3 ; i++) findData(getArraySales(sgv),data,prods,limit,i);

    end = clock();

    showTopSoldProducts(prods,data,limit,((float)(end - start) / CLOCKS_PER_SEC)); 

    for(i=0 ; i<limit ; i++) free(prods[i]);
    free(prods);
}

/* -> Query 12 <- */
void getClientTopProfitProducts(SGV sgv,char* client,int limit){
    char** prods;
    GHashTable* merge;
    int i,size = 0;
    
    clock_t start,end;
    start = clock();

    merge = mergeBranchesAndMonths(getArraySales(sgv),client);
    size = g_hash_table_size(merge);
    if(limit > size) limit = size;

    double qt[limit];
        for(i=0 ; i<limit ; i++) qt[i] = 0;

    prods = findSalesMerge(merge,qt,size,limit,12);

    end = clock();

    showClientTopProfitProducts(prods,qt,client,limit,((float)(end - start) / CLOCKS_PER_SEC));


    for(i=0 ; i<limit ; i++) free(prods[i]);
    free(prods);
}

/* -> Query 13 <- */
void showFilesInfo(SGV sgv,char* clientsFilePath,char* productsFilePath,char* salesFilePath,float time){

    filesInfo(getLinesValidatedAndRead(sgv),clientsFilePath,productsFilePath,salesFilePath,time);
}
