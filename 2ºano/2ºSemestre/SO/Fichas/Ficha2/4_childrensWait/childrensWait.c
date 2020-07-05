#include <unistd.h>     /*chamadas ao sistema: defs e decls essenciais*/
#include <sys/wait.h>   /*chamadas wait*() e macros relacionadas*/
#include <stdio.h>
pid_t getpid(void);
pid_t getppid(void);
pid_t fork(void);
void _exit(int status);
pid_t wait(int*status);
pid_t waitPID(pid_t pid, int*status, int options);
//int WIFEXITED(int status); /*macro*/
//int WEXITSTATUS(int status); /*macro*/


int main(int argc, char* agrv[]){
    int i,status,aux;
    pid_t pid,children;

    for(i=0 ; i<10 ; i++){

        if((pid = fork()) == 0){
            printf("Sons pid : %d\n",getpid());
            _exit(i+1);
        }

    }

    for(i=0 ; i<10 ; i++){
        children = wait(&status);
        if(WIFEXITED(status)) aux = WEXITSTATUS(status);
        printf("Im the father\n");
        printf("(Sons pid,Exit code) : (%d,%d)\n",children,aux);
    }

    return 0;
} 