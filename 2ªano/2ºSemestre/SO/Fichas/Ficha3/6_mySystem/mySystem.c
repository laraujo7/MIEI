#include <unistd.h>     /*chamadas ao sistema: defs e decls essenciais*/
#include <stdio.h>
#include <sys/wait.h>   /*chamadas wait*() e macros relacionadas*/
//int execl(const char*path, const char*arg0, ..., NULL);
//int execlp(const char*file, const char*arg0, ..., NULL);
//int execv(const char*path, char*const argv[]);
//int execvp(const char*file, char*const argv[]);

int main(int argc, char* argv[]){
    pid_t pid;

	if((pid = fork()) == 0){
		execvp(argv[1],&(argv[1]));
	}
	
	wait(NULL);
	
    return 0;
}