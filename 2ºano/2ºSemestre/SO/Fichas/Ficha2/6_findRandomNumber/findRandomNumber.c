#include <unistd.h>     /*chamadas ao sistema: defs e decls essenciais*/
#include <sys/wait.h>   /*chamadas wait*() e macros relacionadas*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

pid_t getpid(void);
pid_t getppid(void);
pid_t fork(void);
void _exit(int status);
pid_t wait(int*status);
pid_t waitPID(pid_t pid, int*status, int options);
//int WIFEXITED(int status); /*macro*/
//int WEXITSTATUS(int status); /*macro*/


int main(int agrc, char* argv[]){
    pid_t pid;
    int aux,status,exists = 0, res = 0;
    int matrix[20][1000] = {0};
    matrix[2][402] = 1;
    matrix[4][821] = 1;
    matrix[18][12] = 1;
    matrix[14][442] = 1;

    for(int i=0 ; i<20 ; i++){

        if((pid = fork()) == 0){

            for(int j=0 ; j<1000 ; j++){
                if(matrix[i][j] == 1) res = 1;
            }

        _exit(res);

        }

    }

    for(int i=0 ; i<20 ; i++){
        wait(&status);
        if(WIFEXITED(status)) {
            if((aux = WEXITSTATUS(status)) == 1 && !exists){
                printf("Does the number 1 exists on the matrix ? %d\n",aux);
                exists = 1;
            }
        }
    }

    return 0;
} 