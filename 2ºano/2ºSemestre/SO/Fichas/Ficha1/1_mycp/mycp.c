#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>   /*chamadas ao sistema: defs e decls essenciais*/
#include <fcntl.h>    /*O_RDONLY, O_WRONLY, O_CREAT, O_* */

#define MAX_BUFFER 4096

    /**
     * int     open(const char*path, int oflag [, mode]);
     * ssize_t read(int fildes, void*buf, size_t nbyte);
     * ssize_t write(int fildes, const void*buf, size_t nbyte);
     * off_t   lseek(int fd, off_t offset, int whence);
     * int     close(int fildes);
     */


int main(int argc, char *argv[]){

    if(argc == 3){
        int fd_origem,fd_destino;

        if((fd_origem = open(argv[1],O_RDONLY)) == -1){
            perror("error");
            return -1;
        }

        if((fd_destino = open(argv[2],O_WRONLY|O_CREAT,0600)) == -1){
            perror("error");
            return -1;
        }

        int n_bytes;
        char* buffer = malloc(MAX_BUFFER * sizeof(char));

        clock_t start = clock();

        while((n_bytes = read(fd_origem,buffer, MAX_BUFFER))>0){
            write(fd_destino,buffer,n_bytes);
        }

        close(fd_origem);
        close(fd_destino);
        free(buffer);

        printf("Tempo de copia -> %f\n", (float) (clock() - start) / CLOCKS_PER_SEC);
    }

    else puts("Numero de argumentos invalidos");

    return 0;

} 