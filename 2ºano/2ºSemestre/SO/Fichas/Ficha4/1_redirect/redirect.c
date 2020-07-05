#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include<sys/wait.h> 
int dup(int fd);
int dup2(int fd1, int fd2);


#define MAX_BUFFER 4096

int main(int argc, char* argv[]){

    int i_fd = open("input.txt", O_RDONLY);
    int o_fd = open("out/output.txt", O_CREAT | O_TRUNC | O_WRONLY, 0666);
    int e_fd = open("out/error.txt", O_CREAT | O_TRUNC | O_WRONLY, 0666);

    dup2(i_fd,0);
    close(i_fd);

    dup2(o_fd,1);
    close(o_fd);

    dup2(e_fd,2);
    close(e_fd);


    char buffer[MAX_BUFFER];
    int n_bytes = read(0,buffer,MAX_BUFFER);
    write(1,buffer,n_bytes);

    return 0;
} 