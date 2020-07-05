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
    pid_t pid;

    if((pid = fork()) == 0){
        printf("\t\t\t\tIm the son and my pid is : %d\n",getpid());
        printf("\t\t\t\tMy process father is : %d\n\n",getppid());
    }
    else {
        printf("\t\t\t\tIm the dad and my pid is : %d\n",getpid());
    }

    return 0;
}