#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>     /*chamadas ao sistema: defs e decls essenciais*/

//int pipe(pd[2]);

#define MAX_BUFFER 4096
#define message "Luke I'm Your Father\n"

//fields[0] descritor de leitura
//fields[1] descritor de escrita

int main(int argc, char* argv[]){
    int fields[2];
    int n_bytes;

    char* buffer[4096];

    if(pipe(fields) == -1) return -1;

    if(fork() == 0){
        close(fields[1]);

        while((n_bytes = read(fields[0],buffer,MAX_BUFFER)) > 0){
                write(1,buffer,n_bytes);
        }

        close(fields[0]);
        _exit(0);
    }

    else{
        close(fields[0]);
        char m[] = message;

        write(fields[1],m,sizeof(m));

        close(fields[1]);
        wait(NULL);
    }

    return 0;
} 