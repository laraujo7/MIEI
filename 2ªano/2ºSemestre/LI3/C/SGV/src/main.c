#include "interface.h"

typedef struct information{
    char product[7];
    char client[6];
    char letter;
    int month;
    int branches;
    int branch;
    int minMonth;
    int maxMonth;
    int limit;
}*INFORMATION;


int main() {
    SGV sgv = NULL;
    clock_t start,end;
    int menuOption,option,valid = 1,menu = 1;
    float time = 0;

    char clientsFilePath[256] = "Info/Clientes.txt";
    char productsFilePath[256] = "Info/Produtos.txt";
    char salesFilePath[256] = "Info/Vendas_1M.txt";

    menuOption = showMenuOption();

    while (menu) {
        INFORMATION info = calloc(1,sizeof(struct information));
                
        if(menuOption == 1) option = showMenu1(valid);
            else option = showAndGetOptionMenu2(valid);
        
        valid = 1;

        switch (option) {

            case 0:
            if(sgv) destroySGV(sgv);
                getFiles(clientsFilePath,productsFilePath,salesFilePath);
                loading();
                start = clock();
                sgv = initSGV();
                sgv = loadSGVFromFiles(sgv,clientsFilePath,productsFilePath,salesFilePath);
                end = clock();
                time = ((float)(end - start) / CLOCKS_PER_SEC);
                break;

            case 1:
                if(sgv) {
                    if(menuOption == 1) info->letter = getLetter();
                        else info->letter = getLetter2();
                    getProductsStartedByLetter(sgv,info->letter);
                } 
                else valid = -1;

                break;
            case 2:
                if(sgv) {
                    if(menuOption == 1) {
                        getProduct(sgv,info->product);
                        info->month = getMonth();
                    }
                        else getProductAndMonth2(sgv,info->product,&(info->month));

                    getProductSalesAndProfit(sgv,info->product,info->month);
                }
                else valid = -1;
                break;

            case 3:
                if(sgv) {
                    if(menuOption == 1) info->branches = getBranch();
                        else info->branches = getBranches2();

                    getProductsNeverBought(sgv,info->branches);
                }
                else valid = -1;
                break;

            case 4:
                if(sgv) getClientsOfAllBranches(sgv);
                else valid = -1;
                break;

            case 5:
                if(sgv) getClientsAndProductsNeverBoughtCount(sgv);
                else valid = -1;
                break;

            case 6:
                if(sgv) {
                    if(menuOption == 1) getClient(sgv,info->client);
                    else getClient2(sgv,info->client);

                    getProductsBoughtByClient(sgv,info->client);
                }
                else valid = -1;
                break;

            case 7:
                if(sgv){
                    if(menuOption == 1) { 
                        info->minMonth = getMonth();
                        info->maxMonth = getMaxMonth(info->minMonth);
                    }
                    else getMinAndMaxMonth2(&(info->minMonth),&(info->maxMonth));

                    getSalesAndProfit(sgv,info->minMonth,info->maxMonth);
                }
                else valid = -1;
                break;

            case 8:
                if(sgv){
                    if(menuOption == 1) {
                        getProduct(sgv,info->product);
                        info->branch = getOneBranch();
                    }
                    else getProductAndBranch2(sgv,info->product,&(info->branch));

                    getProductsBuyers(sgv,info->product,info->branch);
                }
                else valid = -1;
                break;
        
            case 9:
                if(sgv){
                    if(menuOption == 1){
                        getClient(sgv,info->client);
                        info->month = getMonth();
                    }
                    else getClientAndMonth2(sgv,info->client,&(info->month));

                    getClientFavoriteProducts(sgv,info->client,info->month);
                }
                else valid = -1;
                break;

            case 10:
                if(sgv) {
                    if(menuOption == 1) info->limit = getNumber();
                        else info->limit = getNumber2();

                    getTopSelledProducts(sgv,info->limit);
                }
                else valid = -1;
                break;

            case 11:
                if(sgv){
                    if(menuOption == 1){
                        getClient(sgv,info->client);
                        info->limit = getNumber();
                    }
                    else info->limit = getClientAndNumber(sgv,info->client);

                    getClientTopProfitProducts(sgv,info->client,info->limit);
                }
                else valid = -1;
                break;

            case 12:
                if(sgv){
                    showFilesInfo(sgv,clientsFilePath,productsFilePath,salesFilePath,time);
                }
                else valid = -1;
                break;
            
            case 13:
                if(sgv) destroySGV(sgv);
                menu = 0;
                break;

            default:
                valid = 0;
                break;
        }
        free(info);
    }
    
    return 0;
}
