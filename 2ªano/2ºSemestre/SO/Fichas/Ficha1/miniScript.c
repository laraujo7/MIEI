#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

char nomes[15][19] = {
    "Drake",
    "Travis Scott",
    "Eminem",
    "Zara G",
    "Freddie Mercury",
    "Post Malone",
    "Logic",
    "Chester Bennington",
    "Elvis Presley",
    "Lil Uzi Vert",
    "J.Cole",
    "The Weeknd",
    "Profjam",
    "Juice Wrld",
    "John Lennon"
};

int idade[15] = {33,28,47,22,74,24,30,44,85,25,35,30,28,22,80};


int main(){
    int i;
    char id[12];
    
    srand(time(NULL));

    clock_t start = clock();

    for(i=0 ; i < 1000000 ; i++){
        sprintf(id,"%d",idade[rand() % 15]);
    
        char* args[] = {"pessoas","-i",nomes[rand() % 15],id,NULL};
    
        if(fork()==0) {
            execvp("/Users/luisaraujo/MIEI/2ªano/SO/Ficha1/6_pessoas/pessoas",args);
            perror("/Users/luisaraujo/MIEI/2ªano/SO/Ficha1/6_pessoas/pessoas");
            _exit(0);
        }

    }

    printf("Tempo de execuçao -> %f\n",(float) (clock() - start) / CLOCKS_PER_SEC);

    return 0;
}