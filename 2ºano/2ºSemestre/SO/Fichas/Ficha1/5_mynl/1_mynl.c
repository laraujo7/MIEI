#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>   /*chamadas ao sistema: defs e decls essenciais*/
#include <fcntl.h>    /*O_RDONLY, O_WRONLY, O_CREAT, O_* */


#define MAX_BUFFER 4096
#define BUFFER_SIZE 256

    /**
     * int     open(const char*path, int oflag [, mode]);
     * ssize_t read(int fildes, void*buf, size_t nbyte);
     * ssize_t write(int fildes, const void*buf, size_t nbyte);
     * off_t   lseek(int fd, off_t offset, int whence);
     * int     close(int fildes);
     */


ssize_t myreadln_3(int fd, char* line, size_t size){
    int i,found=0;

    for(i=0 ; read(fd,line+i,1) && i < size && !found; i++){

        if(line[i] == '\n') found = 1;
    }

    line[i] = '\0';

    return i == size ? -1 : i;
}


void mynl_3(int fd, char* buffer){
    int i,n_bytes,total=0;

    for(i = 1 ; (n_bytes = myreadln_3(fd,buffer,MAX_BUFFER)) > 0 ; i++){
        total+=n_bytes;
        lseek(fd,total,SEEK_SET);
        char* num = malloc(12 * sizeof(char));
        sprintf(num,"\t%d ",i);
        write(1,strcat(num,buffer),strlen(num) + n_bytes);
        free(num);
    }

}



int main(int argc, char* agrv[]){

    if(argc == 2){
        int i = 0;
        int fd_origem;

        if((fd_origem = open(agrv[1],O_RDONLY)) == -1){
            perror("error");
            return -1;
        }

        char* buffer = malloc(MAX_BUFFER * sizeof(char));
        clock_t start = clock();

        mynl_3(fd_origem,buffer);

        printf("\n Tempo de execuçao (myreadln_3) -> %f\n",(float) (clock() - start) / CLOCKS_PER_SEC);

        close(fd_origem);
        free(buffer);
    }

    else puts("Numero de argumentos invalidos");

    return 0;
} 