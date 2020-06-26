#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>     /*chamadas ao sistema: defs e decls essenciais*/

//int pipe(pd[2]);

#define MAX_BUFFER 4096

//fields[0] descritor de leitura
//fields[1] descritor de escrita

int main(int argc, char* argv[]){
    pid_t pid;
    int fields[2];
    int n_bytes,status;

    char* buffer[MAX_BUFFER];

    if(pipe(fields) == -1) return -1;

    if(fork() == 0){
        close(fields[1]);
        dup2(fields[0],0);
        close(fields[0]);
        execlp("wc","wc",NULL);
        _exit(-1); // esta funcao so sera executada se o execlp falhar
    }

    else{
        close(fields[0]);
    
        while((n_bytes = read(0,buffer,MAX_BUFFER)) > 0){
            write(fields[1],buffer,n_bytes);
        }

        close(fields[1]);

        if(WIFEXITED(status))
            printf("Child process (%d) ended with sucess!\n",pid);
        else 
            printf("Error in child process (%d)!\n",pid);
    }

    return 0;
}