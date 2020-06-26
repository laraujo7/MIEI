#include "sgv.h"

struct sgv {
    int linesValidatedAndRead[6];

    CLIENTS clients;
    PRODUCTS products[26];
    SALES sales[3];
    double totalSalesMonth[2][12];
};


SGV initialize_SGV() {
    int i,j;
    SGV sgv = malloc(sizeof(struct sgv));

    sgv->clients = initClients();

    for(i=0 ; i<26 ; i++) sgv->products[i] = initProducts();

    for(i=0 ; i<3 ; i++) sgv->sales[i] = initSales();

    for(i=0 ; i<2 ; i++) {
        for(j=0 ; j<12 ; j++) sgv->totalSalesMonth[i][j] = 0;
    }

    return sgv;
}


void destroctionSGV(SGV sgv){
    int i;

    destroyClients(sgv->clients);

    for (i=0 ; i<26 ; i++) destroyProducts(sgv->products[i]);
    
    for(i=0 ; i<3 ; i++) destroySales(sgv->sales[i]);
}


SGV loadSGV(SGV sgv, char* clientsFilePath, char* productsFilePath, char* salesFilePath){
    
    readClients(sgv,clientsFilePath);
    readProducts(sgv,productsFilePath);
    readSales(sgv,salesFilePath);
    return sgv;
}


void readClients(SGV sgv, char* clientsFilePath){
    FILE *fp = fopen(clientsFilePath,"r");
    char* client = NULL;
    char buffer[256];

    sgv->linesValidatedAndRead[1] = 0;
    for(sgv->linesValidatedAndRead[0] = 0 ; fgets(buffer,256,fp) ; sgv->linesValidatedAndRead[0]++) {

        client = strtok(buffer,"\r\n");

        if(validateClient(client)) {
            sgv->linesValidatedAndRead[1]++;
            addClient(sgv->clients,client);
        }

    }

    fclose(fp);
}


void readProducts(SGV sgv,char* productsFilePath){
    FILE *fp = fopen(productsFilePath,"r");
    char buffer[256];
    char* prod;

    sgv->linesValidatedAndRead[3] = 0;
    for(sgv->linesValidatedAndRead[2] = 0 ; fgets(buffer,256,fp) ; sgv->linesValidatedAndRead[2]++) {
        
        prod = strtok(buffer,"\r\n");

        if(validateProduct(prod)) {
            sgv->linesValidatedAndRead[3]++;
            addProduct(sgv->products[prod[0]-'A'],prod);
        }

    }

    fclose(fp);
}


void readSales(SGV sgv,char* salesFilePath){
    FILE *fp = fopen(salesFilePath,"r");
    char buffer[256];
    char *token[7];
    float price;
    int i,units,month,branch;
    char type;
    
    sgv->linesValidatedAndRead[5] = 0;
    for(sgv->linesValidatedAndRead[4] = 0 ; fgets(buffer, 256, fp) ; sgv->linesValidatedAndRead[4]++) {
    
    if (buffer[strlen(buffer) - 1 ] == '\n') buffer[strlen(buffer) - 1 ] = '\0';
    
    token[0] = strtok(buffer," ");
    for(i=1 ; i < 7 ; i++) {
        token[i] = strtok(NULL," "); /*0-produto , 1-preço , 2-unidades, 3-tipo , 4-cliente, 5-mes, 6-filial */
    }
    
    if (validadeSale(sgv,token)) {
        price = atof(token[1]);
        units = atoi(token[2]);
        type = token[3][0];
        month = atoi(token[5]) - 1;
        branch = atoi(token[6]) - 1;
        
        sgv->linesValidatedAndRead[5]++;
        
        addBranch(sgv->sales[branch],token[0],token[4],type,price,units,month);
        changeBranchClients(sgv->clients,token[4],branch);
        changeTotalMonth(sgv,price,units,month);
        changeBranchProducts(sgv->products[token[0][0]-'A'],token[0],branch);
        }
    }

    fclose(fp);
}

void changeTotalMonth(SGV sgv, float price, int units, int month) {

    sgv->totalSalesMonth[0][month] += (price * units);
    sgv->totalSalesMonth[1][month]++;

}


int validadeSale(SGV sgv,char** token){
    int res=1;

    if (!validateProduct(token[0]) 
        || !validatePrice(token[1])
        || !validateUnits(token[2])
        || !validateType(token[3])
        || !validateClient(token[4])
        || !validateMonth(token[5])
        || !validateBranch(token[6])
        || !listOfClients(sgv->clients,token[4])
        || !listOfProducts(sgv->products[token[0][0]-'A'],token[0])) res=0;

    return res;
}


int validateProduct(char* buffer){
    int i,res = 1;

    for(i=0; i<6 && res ; i++) {
        if(i==0 || i==1) {if (buffer[i] < 'A' || buffer[i] > 'Z') res = 0;}

        else res = isdigit(buffer[i]);

    }
    return res;
}


int validatePrice(char *price)  {
    double pre = atof(price);
    return (pre >= 0.0 && pre <= 999.99);
}


int validateUnits(char *units){
    int uni = atoi(units);
    return (uni >= 1 && uni <= 200);
}


int validateType(char *type){
    return (type[0] == 'N' || type[0] == 'P');
}


int validateClient(char* buffer){
    int res = 1;
    int i = 1;

    if (buffer[0] >= 'A' && buffer[0] <= 'Z' && strlen(buffer) == 5) {
        for (; i < 4 && res == 0; i++) {
            if (buffer[i] < '0' || buffer[i] > '9') res = 0;
        }
    }

    else res = 0;

    return res;
}


int validateMonth(char *month){
    int m = atoi(month);
    return(m >= 1 && m <= 12);
}


int validateBranch(char *branch){
    int f = atoi(branch);
    return (f >= 1 && f <= 3);
}

PRODUCTS getArrayProductsByLetter(SGV sgv,char letter){
    return (sgv->products[letter-'A']);
}

PRODUCTS* getArrayProducts(SGV sgv){
    return (sgv->products);
}

SALES* getArraySales(SGV sgv){
    return (sgv->sales);
}

SALES getSales(SGV sgv, int branch){
    return (sgv->sales[branch]);
}

CLIENTS getClients(SGV sgv) {
    return (sgv->clients);
}

int* getLinesValidatedAndRead(SGV sgv){
    return (sgv->linesValidatedAndRead);
}


/*----------------------------------------------------------------------------*/
/* -> Query 8 <-  */
void findSalesAndProfit(SGV sgv,int minMonth,int maxMonth,double res[]){
    int month,i;

    for(i=0 ; i<2 ; i++) {
        for(month=minMonth ; month <= maxMonth ; month++)
            res[i] += sgv->totalSalesMonth[i][month];
    }
}
