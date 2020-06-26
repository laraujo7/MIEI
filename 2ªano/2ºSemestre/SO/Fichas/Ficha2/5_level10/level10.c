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

int main(int argc, char* argv[]){
    int status;
    pid_t pid,children;


    for(int i=1 ; i<11 ; i++){
        
        if((pid = fork()) == 0){
            //printf("forking\n");
            _exit(i);
        }
        else{
            children = wait(&status);
            printf("Fathers pid : %d\n",getpid());
            printf("Sons pid : %d\n",children);
            
        }

    }

    return 0;
}