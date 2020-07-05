#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include<sys/wait.h> 
int dup(int fd);
int dup2(int fd1, int fd2);


#define MAX_BUFFER 4096
#define message "./redir -i fich_entrada -o fich_saida comando arg1 arg2 ...\n"

int main(int argc, char* argv[]){
    int i_fd,o_fd;

    if(argc >= 6){

        if(!strcmp(argv[1],"-i")){
            if((i_fd = open(argv[2],O_RDONLY)) > 0){
                dup2(i_fd,0);
                close(i_fd);
            }
            else {
                printf("Error: Invalid Input File\n");
                _exit(-1);
            }
        }

        if(!strcmp(argv[3],"-o")){
            if((o_fd = open(argv[4],O_CREAT | O_TRUNC | O_WRONLY, 0666)) > 0){
                dup2(o_fd,1);
                close(o_fd);
            }
            else {
                printf("Error: Invalid Output File\n");
                _exit(-1);
            }
        }

        execvp(argv[5],argv+5);

    }

    else{
        printf("Error while validating input\n");
        printf("Try this : %s",message);
    }

    return 0;
} 