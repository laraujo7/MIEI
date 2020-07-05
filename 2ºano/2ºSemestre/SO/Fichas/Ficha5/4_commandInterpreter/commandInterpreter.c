#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>     /*chamadas ao sistema: defs e decls essenciais*/

//int pipe(pd[2]);
#define MAX_BUFFER 4096

int main(){
    pid_t pid;
    int fd[2];

    if(pipe(fd) == -1){
        perror("Error");
        return -1;
    }
    
    if(fork() == 0){
        close(fd[1]);
        dup2(fd[0],0);
        close(fd[0]);
        
        execlp("wc","wc","-l",NULL);
        _exit(-1);
    }
    else{
        close(fd[0]);
        dup2(fd[1],1);
        close(fd[1]);

        execlp("ls","ls","/etc",NULL);
    }
    return 0;
}