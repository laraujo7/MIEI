#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>   /*chamadas ao sistema: defs e decls essenciais*/
#include <fcntl.h>    /*O_RDONLY, O_WRONLY, O_CREAT, O_* */

#define BUFFER_SIZE 256
#define MAX_BUFFER 4096


    /**
     * int     open(const char*path, int oflag [, mode]);
     * ssize_t read(int fildes, void*buf, size_t nbyte);
     * ssize_t write(int fildes, const void*buf, size_t nbyte);
     * off_t   lseek(int fd, off_t offset, int whence);
     * int     close(int fildes);
     */


typedef struct pessoa {
    char nome[BUFFER_SIZE];
    int idade;
} Pessoa;



int add_pessoa(char* nome, char* idade){
    int fd;

    if((fd = open("out/ficheiro.bin", O_WRONLY | O_CREAT | O_APPEND, 0644)) == -1){  
        perror("error");
        return -1;
    }

    Pessoa p;
    strcpy(p.nome,nome);
    p.idade = atoi(idade);

    write(fd,&p,sizeof(Pessoa));
    
    close(fd);

    return 0;
}

int update_pessoa(char* nome, char* idade){
    int fd,found = -1;

    if((fd = open("out/ficheiro.bin",O_RDWR)) == -1){
        perror("eror");
        return -1;
    }
    
    Pessoa aux;

    while(found == -1 && read(fd,&aux,sizeof(Pessoa)) > 0){ 
    
        if(!strcmp(aux.nome,nome)){
            aux.idade = atoi(idade);
            lseek(fd,(-1)*sizeof(Pessoa),SEEK_CUR);
            write(fd,&aux,sizeof(Pessoa));
            found = 0;
        }

    }

    close(fd);

    return found;
}


void print(){
    int fd,i=0;

    if((fd = open("out/ficheiro.bin",O_RDONLY)) == -1){
        perror("error");
    }

    Pessoa aux;

    while(read(fd,&aux,sizeof(Pessoa)) > 0){
        printf("%d -> %s %d\n",i++,aux.nome,aux.idade);
    }

}



int main(int argc, char* argv[]){
    
    if(argc == 4 || !strcmp(argv[1],"-p")){

        if(!strcmp(argv[1],"-i")){
            if(add_pessoa(argv[2],argv[3]) == -1){
                printf("Nao foi possivel adicionar a pessoa\n");
            }
        }

        else if(!strcmp(argv[1],"-u")){
            if(update_pessoa(argv[2],argv[3]) == -1){
                printf("Nao foi possivel alterar idade da pessoa\n");
            }
        }

        else if(!strcmp(argv[1],"-p")){
            print();
        }
        
        else printf("Segundo argumento invalido\n");

    }

    else{
        puts("Numero de argumentos invalidos");
    } 

    return 0;
}