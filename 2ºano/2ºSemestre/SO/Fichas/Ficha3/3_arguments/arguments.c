#include <unistd.h>     /*chamadas ao sistema: defs e decls essenciais*/
#include <stdio.h>
//int execl(const char*path, const char*arg0, ..., NULL);
//int execlp(const char*file, const char*arg0, ..., NULL);
//int execv(const char*path, char*const argv[]);
//int execvp(const char*file, char*const argv[]);


int main(int argc, char* argv[]){

    for(int i=1 ; i<argc ; i++) printf("%s\n",argv[i]);

    return 0;
} 