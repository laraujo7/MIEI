#include "gets.h"


char getLetter() {
    char letter = 0;
    int valido = 0;

    while(!valido) {
        system("clear");

        if(!valido && letter) puts(" Invalid Letter");
        printf(COR_B_VERDE"Choose a letter : "COR_RESET);

        scanf(" %c",&letter);
        getEnter();
        valido = isalpha(letter);
    }

    return (toupper(letter));
}

void getProduct(SGV sgv,char product[]) {
    int i,j = 0,valid = 0;
    char buffer[256];

    while(!valid) {
        system("clear");

        if(!valid && j) puts(" Invalid Product");
        printf(COR_B_VERDE" Introduce a Product : "COR_RESET);
        
        fgets(buffer, 256, stdin); 

        if(buffer[0] != '\n') {for(i=0 ; i<6 ; i++) product[i] = buffer[i]; product[6] = '\0';}

        if(validateProduct(product) && listOfProducts(getArrayProductsByLetter(sgv,product[0]),product)) valid = 1;
        
        j++;
    }
}

int getMonth() {
    int j = 0,m = 0;
    char* month = NULL;
    char buffer[256];

    while (!m) {
        system("clear");

        if(!m && j) puts(" Invalid Month");
        printf(COR_B_VERDE" Introduce a Month : "COR_RESET);

        fgets(buffer,256,stdin);

        if(buffer[0] != '\n') month = strtok(buffer,"\r\n");

        if(month != NULL && validateMonth(month)) m = atoi(month);
        j++;
    }

    return --m;
}

int getBranch() {
    int j = 0,b = 0;
    char* branch = NULL;
    char buffer[256];

    while (!b) {
        system("clear");

        if(!b && j) puts(" Invalid Option");
        puts(COR_B_VERDE" 1 -> Branch 1"COR_RESET);
        puts(COR_B_VERDE" 2 -> Branch 2"COR_RESET);
        puts(COR_B_VERDE" 3 -> Branch 3"COR_RESET);
        puts(COR_B_VERDE" 4 -> All in one"COR_RESET);
        printf(COR_B_VERDE" Introduce Your Option : "COR_RESET);

        fgets(buffer,256,stdin);

        if(buffer[0] != '\n') branch = strtok(buffer,"\r\n");

        if(branch!=NULL && (validateBranch(branch) || atoi(branch) == 4)) b = atoi(branch);
        j++;
    }

    return --b;
}

void getClient(SGV sgv,char client[]) {
    int i,j = 0,valid = 0;
    char buffer[256] = {0};

    while(!valid) {
        system("clear");

        if(!valid && j) puts(" Invalid Client");
        printf(COR_B_VERDE" Introduce a Client : "COR_RESET);
        
        fgets(buffer, 256, stdin); 

        if(buffer[0] != '\n') {for(i=0 ; i<5 ; i++) client[i] = buffer[i]; client[5] = '\0';}

        if(validateClient(client) && listOfClients(getClients(sgv),client)) valid = 1;
        
        j++;
    }
}


int getMaxMonth(int minMonth){
    int j = 0,m = 0;
    char* month = NULL;
    char buffer[256];

    while (!m) {

        if(!m && j) puts(" Invalid Month");
        printf(COR_B_VERDE" Introduce a Month : "COR_RESET);

        fgets(buffer,256,stdin);

        if(buffer[0] != '\n') month = strtok(buffer,"\r\n");

        if(month != NULL && validateMonth(month) && atoi(month) >= minMonth+1) m = atoi(month);
        j++;

    }

    return --m;
}


int getOneBranch() {
    int j = 0,b = 0;
    char* branch = NULL;
    char buffer[256];

    while (!b) {
        system("clear");

        if(!b && j) puts(" Invalid Option");
        printf(COR_B_VERDE" Introduce a Branch: "COR_RESET);

        fgets(buffer,256,stdin);

        if(buffer[0] != '\n') branch = strtok(buffer,"\r\n");

        if(branch!=NULL && validateBranch(branch)) b = atoi(branch);
        j++;
    }

    return --b;
}


int getNumber(){
    char buffer[256];
    char* number = NULL;
    int i,j = 0,valid = 0;

    while(!valid) {
        system("clear");
        if(!valid && j) puts(" Invalid Option");
        printf(COR_B_VERDE" Introduce a Number : "COR_RESET);

        fgets(buffer, 256 , stdin);

        if(buffer[0] != '\n') {
            number = strtok(buffer,"\r\n");
            valid = 1;
        }

        for(i=0 ; valid && number[i]; i++) if(!isdigit(number[i])) valid = 0;

        j++;
    }

    return atoi(number);
}
