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
    pid_t t;
    t=getpid();
    printf("%d\n",t);
    t=getppid();
    printf("%d\n",t);

    return 0;
} 