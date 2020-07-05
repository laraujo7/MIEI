#include <unistd.h>     /*chamadas ao sistema: defs e decls essenciais*/
#include <stdio.h>
//int execl(const char*path, const char*arg0, ..., NULL);
//int execlp(const char*file, const char*arg0, ..., NULL);
//int execv(const char*path, char*const argv[]);
//int execvp(const char*file, char*const argv[]);

int main(int argc, char* agrv[]){

    if(fork() == 0){
        execl("/bin/ls","ls","-l",NULL); //o processo filho ira ser terminado atraves do execl
    }

    printf("Did it pass ?\n");
    return 0;
} 