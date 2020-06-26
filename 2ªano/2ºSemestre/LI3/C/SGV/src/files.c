#include "files.h"


void getFiles(char* clientsFilePath,char*  productsFilePath,char* salesFilePath){
    char files[256];
    int i = 0;
    int valido = 0;

    while (i < 3) {
        
        if (i == 0) printf(COR_B_VERDE "Clients File Path : " COR_RESET);
        if (i == 1) printf(COR_B_VERDE "Products File Path : " COR_RESET);
        if (i == 2) printf(COR_B_VERDE "Sales File Path : " COR_RESET);
        
        fgets(files, 256, stdin);

        if(i==0) valido = verifyFiles(files,clientsFilePath);
        if(i==1) valido = verifyFiles(files,productsFilePath);
        if(i==2) valido = verifyFiles(files,salesFilePath);

        if(valido) i++;
    }
}

int verifyFiles(char* files, char* filePath){
    int res = 0;
    FILE *fp;
    char* token;

    if (files[0] != '\n') {
        token = strtok(files,"\r\n");

        fp = fopen(token, "r");

        if (fp == NULL) puts("Ficheiro invalido");

        else {
            strcpy(filePath, token);
            fclose(fp);
            res = 1;
        }
    }

    else res = 1;

    return res;
}
