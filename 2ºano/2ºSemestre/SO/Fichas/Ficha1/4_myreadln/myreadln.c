#include <stdlib.h>
#include <stdio.h>
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


ssize_t myreadln_4(int fd, char* line, size_t size){
    int i,n_bytes = 0,read_bytes = 0,found = 0;
    char* buffer = malloc(BUFFER_SIZE * sizeof(char));
    char* aux = line;

    while(n_bytes < size && !found && (read_bytes = read(fd,buffer,BUFFER_SIZE)) > 0){

        for(i=0 ; i < read_bytes && n_bytes + i < size && !found; i++,aux++){
            if (buffer[i] == '\n') found = 1;
            *aux = buffer[i];
        }

        n_bytes += i;
    }

    line[n_bytes] = '\0';

    return n_bytes == size ? -1 : n_bytes;
}

int main(int argc, char* agrv[]){

    if(argc == 2){
        int fd_origem;

        if((fd_origem = open(agrv[1],O_RDONLY)) == -1){
            perror("error");
            return -1;
        }

        char* linha = malloc(MAX_BUFFER * sizeof(char));

        int n_bytes = myreadln_4(fd_origem,linha,MAX_BUFFER);

        if(n_bytes == -1) puts("MAX_BUFFER insuficiente");
            else printf("%s -> %d bytes/caracteres\n",linha,n_bytes);

        close(fd_origem);
        free(linha);    
    }

    else puts("Numero de argumentos invalidos");

    return 0;
} 