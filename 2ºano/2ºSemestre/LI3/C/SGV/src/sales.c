#include "sales.h"

struct sales {
    GHashTable* productsClients;
    GHashTable* clientsProducts;
};

struct prodCl {
    double totalProduct[2][2][12];
    GHashTable* client;
    int totalYear;
};

struct clProd {
    int totalClient[12];
    GHashTable* arrayProd[12];
};

struct clSearcher {
    char** clients[2];
    int units[2];
};

struct prSearcher {
    char* prod;
    double qt;
};



SALES initSales(){
    SALES sales = malloc(sizeof(struct sales));

    sales->productsClients = g_hash_table_new_full(g_str_hash,g_str_equal,free,destroyProductsClients);
    sales->clientsProducts = g_hash_table_new_full(g_str_hash,g_str_equal,free,destroyClientsProducts);

    return sales;
}

void destroySales(SALES sales){

    g_hash_table_destroy(sales->productsClients);
    g_hash_table_destroy(sales->clientsProducts);

    free(sales);
}


void destroyProductsClients (void* prCl){
    PRODCL pcl = (PRODCL) prCl;
    
    g_hash_table_destroy(pcl->client);

    free(pcl);
}


void destroyClientsProducts(void* clPr){
    int i;
    CLPROD clp = (CLPROD) clPr;

    for (i=0 ; i<12 ; i++) g_hash_table_destroy(clp->arrayProd[i]);

    free(clp);
}

void addBranch(SALES sales,char* product,char* client,char type,float price,int units,int month){
    PRODCL pc = g_hash_table_lookup(sales->productsClients,product);
    CLPROD cp = g_hash_table_lookup(sales->clientsProducts,client);
 
    if (pc) {
        changeTotalProducts(pc->totalProduct,type,price,month);
        pc->totalYear += units;
        changeProductsClients(pc,client,type);
    }

    else {
        pc = initProductsClients();
        changeTotalProducts(pc->totalProduct,type,price,month);
        pc->totalYear += units;
        changeProductsClients(pc,client,type);
        char* keyP = strdup(product);
        g_hash_table_insert(sales->productsClients,keyP,pc);
    }

    if (cp) {
        cp->totalClient[month] += units;
        changeClientsProducts(cp,product,month,units,price);
    }

    else {
        cp = initClientProducts();
        cp->totalClient[month] += units;
        changeClientsProducts(cp,product,month,units,price);
        char* keyC = strdup(client);
        g_hash_table_insert(sales->clientsProducts,keyC,cp);
    }
}


CLPROD initClientProducts(){
    int i;
    CLPROD cp = malloc(sizeof(struct clProd));

    for (i=0 ; i<12 ; i++) {
        cp->arrayProd[i] = g_hash_table_new_full(g_str_hash, g_str_equal, free, free);
        cp->totalClient[i] = 0;
    }

    return cp;
}


void changeClientsProducts(CLPROD cp, char* product, int month, int units, float price){
    double exist = g_hash_table_contains(cp->arrayProd[month],product);
    double *uni = calloc(2,sizeof(double));
    double *pointer = g_hash_table_lookup(cp->arrayProd[month],product);
    
    if (exist) {
        uni[0] = (units * price) + pointer[0];
        uni[1] = units + pointer[0];
    }

    else {
        uni[0] = units * price;
        uni[1] = units;
    }

    char* key = strdup(product);
    g_hash_table_insert(cp->arrayProd[month],key,uni); 
}


PRODCL initProductsClients(){
    int i,j,k;
    PRODCL pc = malloc(sizeof(struct prodCl));

    pc->client = g_hash_table_new_full(g_str_hash,g_str_equal,free,NULL);
    pc->totalYear = 0;

    for(i=0 ; i<2 ; i++) {
        for(j=0; j<2 ; j++) {
            for(k=0 ; k<12 ; k++) 
                pc->totalProduct[i][j][k] = 0;
        }
    }

    return pc;
}


void changeTotalProducts(double total[][2][12], char type, float price, int month){

    if(type == 'N') {
        total[0][0][month] += price;          /*total[0 1]   [0       1]      [0..11]*/
        total[0][1][month]++;                 /*      N P   preço   vendas      mes */
    }

    else if (type == 'P') {
        total[1][0][month] += price;
        total[1][1][month]++;
    }
}


void changeProductsClients(PRODCL pc, char* client, char type){
    int uni = GPOINTER_TO_INT(g_hash_table_lookup(pc->client,client));
    int u = 0;
    
    if (uni) {if ((uni == 1 && type == 'P') || (uni == 2 && type == 'N')) uni = 3;}
    
    else {
        if (type == 'N') u = 1;
        else if (type == 'P') u = 2;
    }

    char *key = strdup(client); 
    g_hash_table_insert(pc->client,key,GINT_TO_POINTER(u));
}

/*----------------------------------------------------------------------------*/
/* -> Query 3 <- */
void findProductSalesAndProfit(SALES* sales,char* productID,int month,double res[][4]){
    int i;

    for(i=0 ; i<3 ; i++) {
        PRODCL pc = g_hash_table_lookup(sales[i]->productsClients,productID);

        if(pc) {
        res[i][0] = pc->totalProduct[0][0][month];  /*[Normal][Preco][Mes]  */
        res[i][1] = pc->totalProduct[0][1][month];  /*[Normal][Vendas][Mes] */
        res[i][2] = pc->totalProduct[1][0][month];  /*[Promocao][Preco][Mes] */
        res[i][3] = pc->totalProduct[1][1][month];  /*[Promocao][Vendas][Mes] */
        
        }
    }
}


/*----------------------------------------------------------------------------*/
/* -> Query 7 <- */
void findProductSellesByClient(SALES sales,char* client,int* res){
    int i;
    CLPROD cp = g_hash_table_lookup(sales->clientsProducts,client);
    if(cp) for(i=0 ; i<12 ; i++) res[i] = cp->totalClient[i];
}

/*----------------------------------------------------------------------------*/
/* -> Query 9 <- */
CLSEARCHER getCLSearcher(SALES sales,char* productID) {
    PRODCL pc = g_hash_table_lookup(sales->productsClients,productID);
    CLSEARCHER cls = malloc(sizeof(struct clSearcher));
    int totalSalesN,totalSalesP;
    
    totalSalesN = pc ? numberOfSales(pc,0) : 0;
    totalSalesP = pc ? numberOfSales(pc,1) : 0;

    cls->clients[0] = malloc(totalSalesN * sizeof(char*));
    cls->clients[1] = malloc(totalSalesP * sizeof(char*));
    cls->units[0] = cls->units[1] = 0;

    if(pc) g_hash_table_foreach(pc->client,findCLS,cls);

    return cls;
}


int numberOfSales(PRODCL pc, int flag){
    int i,res = 0;

    for (i=0 ; i<12 ;i++) res += (int) pc->totalProduct[flag][1][i];

    return res;
}


void findCLS(gpointer key, gpointer value, gpointer data){
    char* client = (char*) key;
    int v = GPOINTER_TO_INT(value);
    CLSEARCHER cls = (CLSEARCHER) data;
    
    if(v != 2) {
        cls->clients[0][cls->units[0]] = malloc(6 * sizeof(char));
        strcpy(cls->clients[0][cls->units[0]++],client);
    }

    if(v != 1) {
        cls->clients[1][cls->units[1]] = malloc(6 * sizeof(char));
        strcpy(cls->clients[1][cls->units[1]++],client);
    }
}


int getClientsAndUnitsCLS(CLSEARCHER cls,char*** clientes,int flag){
    if(cls) (*clientes) = cls->clients[flag];
    return cls->units[flag];
}


void destroyCLS(CLSEARCHER cls){
    int i,j;
    for(i=0 ; i<2 ; i++) {
        for(j=0 ; j < cls->units[i] ; j++) free(cls->clients[i][j]);

        free(cls->clients[i]);
    }
    free(cls);
}


/*----------------------------------------------------------------------------*/
/* -> Query 10 <- */
PRSEARCHER findClientFavotiteProducts(SALES* sales,char* client,int month,int* size){
    int i,j = 0;
    gpointer key;
    double* value;
    GHashTableIter r;

    for(i=0 ; i<3 ; i++) (*size) += sizeOfProducts(sales[i],client,month);

    PRSEARCHER prs = malloc((*size) * sizeof(struct prSearcher));

    for(i=0 ; i<3 ; i++) {

    CLPROD cp = g_hash_table_lookup(sales[i]->clientsProducts,client);

    if(cp) { 
        g_hash_table_iter_init(&r,cp->arrayProd[month]);
        
        while(g_hash_table_iter_next(&r,(void*) &key, (void*) &value)) {
            prs[j].prod = (char*) key;
            prs[j++].qt = (double) value[1];
            }
        }
    }

    qsort(prs,(*size),sizeof(struct prSearcher),sort);
    return prs;
}

int sizeOfProducts(SALES sales,char* client,int month){
    int size = 0;

    CLPROD cp = g_hash_table_lookup(sales->clientsProducts,client);
    if(cp) size = g_hash_table_size(cp->arrayProd[month]);

    return size;
}

int sort(const void* one, const void* two) {
    PRSEARCHER a = (PRSEARCHER) one;
    PRSEARCHER b = (PRSEARCHER) two;
    
    return b->qt > a->qt ? 1 : b->qt < a->qt ? -1 : 0;
}

char** getProductsAndUnitsPRS(PRSEARCHER prs,int size,int qt[]){
    int i;
    char** prods = malloc(size * sizeof(char*));
    if(prs) {
        for(i=0 ; i<size ; i++) {
            prods[i] = malloc(7 * sizeof(char));
            memcpy(prods[i] , prs[i].prod,7 * sizeof(char));
            qt[i] = prs[i].qt;
        } 
    }
    return prods;
}


/*----------------------------------------------------------------------------*/
/* -> Query 11 <- */
GHashTable* mergeBranches(SALES* sales){
    int i,value = 0;
    GHashTable* merge = g_hash_table_new_full(g_str_hash,g_str_equal,NULL,NULL);
    GHashTableIter r;
    gpointer key;
    PRODCL pc;

    for(i=0 ; i<3 ;i++) {

        g_hash_table_iter_init(&r,sales[i]->productsClients);

        while(g_hash_table_iter_next(&r,(void*) &key,(void*) &pc)) {
            value = GPOINTER_TO_INT(g_hash_table_lookup(merge,key));
            value += pc->totalYear;
            g_hash_table_insert(merge,key,GINT_TO_POINTER(value));
        }
    }
    return merge;
}


char** findSalesMerge(GHashTable* merge,double qt[],int size, int limit,int flag) {
    int i;
    gpointer key,value;
    GHashTableIter r;
    char** prods = malloc(limit * sizeof(char*));
    PRSEARCHER arrayMerge = malloc(size * sizeof(struct prSearcher));

    g_hash_table_iter_init(&r,merge);
    i=0;

    while(g_hash_table_iter_next(&r,(void*) &key,(void*) &value)) {

        arrayMerge[i].prod = (char*) key;

        if(flag == 11) arrayMerge[i++].qt = GPOINTER_TO_INT(value);
        else arrayMerge[i++].qt = *(double*) value;
    }

    qsort(arrayMerge,size,sizeof(struct prSearcher),sort);    
    
    for(i=0 ; i<limit ; i++) {
        prods[i] = malloc(7 * sizeof(char));
        strcpy(prods[i],arrayMerge[i].prod);
        qt[i] = arrayMerge[i].qt;
    }

    free(arrayMerge);
    g_hash_table_destroy(merge);

    return prods;
}

void findData(SALES* sales,int data[][3][2],char** prods,int limit,int branch){
    int i;
    for(i=0 ; i<limit ; i++) {
        PRODCL pc = g_hash_table_lookup(sales[branch]->productsClients,prods[i]);
        
        if(pc) {
            data[i][branch][0] = pc->totalYear;
            data[i][branch][1] = g_hash_table_size(pc->client); 
        }
    }
}

/*----------------------------------------------------------------------------*/
/* -> Query 12 <- */
GHashTable* mergeBranchesAndMonths(SALES* sales,char* client) {
    int i,j;
    GHashTable* merge = g_hash_table_new_full(g_str_hash,g_str_equal,NULL,free);
    GHashTableIter r;
    gpointer key;
    double* value;
    double* total;

    for(i=0 ; i<3 ; i++){
        CLPROD cp = g_hash_table_lookup(sales[i]->clientsProducts,client);
    
        if(cp) {

            for(j=0 ; j<12 ; j++) {
                
                g_hash_table_iter_init(&r,cp->arrayProd[j]);

                while(g_hash_table_iter_next(&r,(void*) &key,(void*) &value)) {
                    total = g_hash_table_lookup(merge,key);
                    if(!total) total = calloc(1,sizeof(double));
                    *total += *value;
                    g_hash_table_insert(merge,key,total);
                }
            }
        }
    }
    return merge;
}
