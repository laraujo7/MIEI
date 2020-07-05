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
    pid_t pid,children;
    int status,s;

    for(int i=1 ; i<11; i++){

        if((pid = fork()) == 0){
            //filho
            printf("Im the son and my pid is : %d\n",getpid());
            printf("My dads pid is : %d\n",getppid());
            _exit(i);
        }

        else if(pid == -1){
            perror("error");
            _exit(-1);
        }

        else{
            //pai
            children = wait(&status);
            if (WIFEXITED(status)) s = WEXITSTATUS(status); //wifeexisted- devolve algo !0 se o status tiver vindo de um child process
            printf("(Sons pid,Exit code) : (%d,%d)\n\n",children,s);
        }   
    }

    return 0;
} 