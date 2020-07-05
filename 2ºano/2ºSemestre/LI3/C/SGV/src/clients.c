#include "clients.h"

struct clients {
    GHashTable* cl;
};

CLIENTS initClients() {
    CLIENTS clients = malloc(sizeof(struct clients));

    clients->cl = g_hash_table_new_full(g_str_hash ,g_str_equal,free,free);

    return clients;
}

void destroyClients(CLIENTS clients) {
    g_hash_table_destroy(clients->cl);
    free(clients);
}

void addClient(CLIENTS clients,char* client) {
    char* key = strdup(client);
    int *branch = calloc(3,sizeof(int));

    g_hash_table_insert(clients->cl,key,branch);
}


void changeBranchClients(CLIENTS clients, char* client,int branch) {
    int* b = g_hash_table_lookup(clients->cl,client);

    b[branch] = 1;
}


int listOfClients(CLIENTS clients,char* client) {
    return (int) g_hash_table_contains(clients->cl,client);
}


/*----------------------------------------------------------------------------*/
/* -> Query 5 <- */
char** findClientesOfAllBranches(CLIENTS clients,int* size) {
    int i = 0;
    char** cls;
    int* branch;
    gpointer client;
    GHashTableIter r;

    g_hash_table_foreach(clients->cl,numberOfClientsOfAllBranches,size);

    cls = initCLS(*size);
    
    g_hash_table_iter_init(&r,clients->cl);

    while(g_hash_table_iter_next(&r,(void*) &client,(void*) &branch)){
        if(branch[0] && branch[1] && branch[2]) memcpy(cls[i++], (char*) client, 6 * sizeof(char));
    }

    qsort(cls,*size,sizeof(char*),sortByLetter);

    return cls;
}

int sortByLetter(const void* a, const void* b) {
    return strcmp(*(char**) a, *(char**) b);
}

char** initCLS(int size){
    int i;
    char** cls;

    cls = malloc(size * sizeof(char*));

    for(i=0 ; i<size ; i++) cls[i] = malloc(6 * sizeof(char));

    return cls;
}

void numberOfClientsOfAllBranches(gpointer key, gpointer value, gpointer data) {
    int* branch = (int*) value;
    int* size = (int*) data;
    (void) key;

    if(branch[0] && branch[1] && branch[2]) (*size)++;
    
}


/*----------------------------------------------------------------------------*/
/* -> Query 6 <- */
int findClientsNeverBoughtCount(CLIENTS clients){
    int size = 0;

    g_hash_table_foreach(clients->cl,numberOfClientsNeverBought,&size);

    return size;
}

void numberOfClientsNeverBought(gpointer key, gpointer value, gpointer data){
    int* branch = (int*) value;
    int* size = (int*) data;
    (void) key;

    if(!branch[0] && !branch[1] && !branch[2]) (*size)++;
}
