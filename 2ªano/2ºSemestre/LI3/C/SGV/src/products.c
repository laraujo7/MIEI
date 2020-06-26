#include "products.h"

struct products {
    GTree* prod;
};

struct productSearch {
    char** products;
    int qt;
};


PRODUCTS initProducts() {
    PRODUCTS products = malloc(sizeof(struct products));

    products->prod = g_tree_new_full((GCompareDataFunc) (void (*)(void))strcasecmp,NULL,free,free);

    return products;
}


void destroyProducts(PRODUCTS products) {

    g_tree_destroy(products->prod);
    
    free(products);
}

void addProduct(PRODUCTS products,char* product) {
    char* key = strdup(product);
        int *branch = calloc(3,sizeof(int));

    g_tree_insert(products->prod,key,branch);
}


void changeBranchProducts(PRODUCTS products,char* product,int branch) {
    int* b = g_tree_lookup(products->prod,product);
    b[branch] = 1;
}


int listOfProducts(PRODUCTS products,char* product) {
    return g_tree_lookup(products->prod,product) ? 1 : 0;
}

/*----------------------------------------------------------------------------*/
/* -> Query2 <- */
PRODUCTSEARCH findProductsByLetter(PRODUCTS products){
    PRODUCTSEARCH ps;
    int size = g_tree_nnodes(products->prod);

    ps = initProductSearch(size);

    g_tree_foreach(products->prod, (GTraverseFunc)iter_all, ps);

    return ps;
}

int iter_all(gpointer key, gpointer value, gpointer data) {
    PRODUCTSEARCH ps = (PRODUCTSEARCH) data;
    (void) value;

    memcpy(ps->products[ps->qt++] , (char*) key , 7*sizeof(char));
    
    return 0;
}


PRODUCTSEARCH initProductSearch(int size) {
    int i;
    PRODUCTSEARCH ps = malloc(sizeof(PRODUCTSEARCH));;
    
    ps->products = malloc(size * sizeof(char*));

    for(i=0 ; i<size ; i++) ps->products[i] = malloc(7*sizeof(char));

    ps->qt = 0;

    return ps;
}


char** getProductsOfPS(PRODUCTSEARCH ps) {
    if(ps) return ps->products;
        else return NULL;
}


int getTotalOfPS(PRODUCTSEARCH ps) {
    if(ps) return ps->qt;
        else return 0;
}

void destroyPS(PRODUCTSEARCH ps) {
    int i;

    for(i=0 ; i < ps->qt ; i++) free(ps->products[i]);

    free(ps->products);
    free(ps);
}

/*----------------------------------------------------------------------------*/
/* -> Query 4 <- */
PRODUCTSEARCH findProductsNeverBought(PRODUCTS* products,int branch){
    PRODUCTSEARCH ps;
    int size[3] = {0};
    int s = 0;
    int i;
    
    if(branch != 3) {
        for(i=0 ; i<26 ; i++) g_tree_foreach(products[i]->prod,sizeOfProductsNeverBoughtAllBranches,size);

        ps = initProductSearch(size[branch]);

        if(branch == 0)for(i=0 ; i<26 ;i++) g_tree_foreach(products[i]->prod,productsNeverBought0,ps);
        if(branch == 1)for(i=0 ; i<26 ;i++) g_tree_foreach(products[i]->prod,productsNeverBought1,ps);
        if(branch == 2)for(i=0 ; i<26 ;i++) g_tree_foreach(products[i]->prod,productsNeverBought2,ps);

    }

    else {
        for(i=0 ; i<26 ;i++) g_tree_foreach(products[i]->prod,sizeOfProductsNeverBoughtEveryBranch,&s);

        ps = initProductSearch(s);

        for(i=0 ; i<26 ;i++) g_tree_foreach(products[i]->prod,productsNeverBought,ps);

    }

    return ps;
}

int productsNeverBought0(gpointer key, gpointer value, gpointer data){
    PRODUCTSEARCH ps = (PRODUCTSEARCH) data;
    int* branch  = (int*) value;

    if(!branch[0]) memcpy(ps->products[ps->qt++], (char*) key , 7*sizeof(char));

    return 0;
}

int productsNeverBought1(gpointer key, gpointer value, gpointer data){
    PRODUCTSEARCH ps = (PRODUCTSEARCH) data;
    int* branch  = (int*) value;

    if(!branch[1]) memcpy(ps->products[ps->qt++], (char*) key , 7*sizeof(char));

    return 0;
}

int productsNeverBought2(gpointer key, gpointer value, gpointer data){
    PRODUCTSEARCH ps = (PRODUCTSEARCH) data;
    int* branch  = (int*) value;

    if(!branch[2]) memcpy(ps->products[ps->qt++], (char*) key , 7*sizeof(char));

    return 0;
}


int sizeOfProductsNeverBoughtAllBranches(gpointer key, gpointer value, gpointer data){
    int i;
    int* size = (int*) data;
    int* branch = (int*) value;
    (void) key;

    for(i=0 ; i<3 ; i++) {
        if(!branch[i]) size[i]++;
    }

    return 0;
}

int productsNeverBought(gpointer key, gpointer value, gpointer data){
    PRODUCTSEARCH ps = (PRODUCTSEARCH) data;
    int* branch  = (int*) value;

    if(!branch[0] && !branch[1] && !branch[2]) memcpy(ps->products[ps->qt++], (char*) key , 7*sizeof(char));

    return 0;
}

int sizeOfProductsNeverBoughtEveryBranch(gpointer key, gpointer value, gpointer data){
    int i;
    int* size = (int*) data;
    int* branch = (int*) value;
    (void) key;

    for(i=0 ; i<3 ; i++) {
        if(!branch[0] && !branch[1] && !branch[2]) (*size)++;
    }

    return 0;
}


/*----------------------------------------------------------------------------*/
/* -> Query 6 <- */
int findProductsNeverBoughtCount(PRODUCTS* products){
    int i,size = 0;

    for(i=0 ; i<26 ; i++) g_tree_foreach(products[i]->prod,numberOfProductsNeverBought,&size);

    return size;
}

int numberOfProductsNeverBought(gpointer key, gpointer value, gpointer data){
    int* size = (int*) data;
    int* branch = (int*) value;
    (void) key;

    if(!branch[0] && !branch[1] && !branch[2]) (*size)++;

    return 0;
}
