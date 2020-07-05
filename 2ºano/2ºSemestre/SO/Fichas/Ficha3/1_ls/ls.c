#include <unistd.h>     /*chamadas ao sistema: defs e decls essenciais*/
//int execl(const char*path, const char*arg0, ..., NULL);
//int execlp(const char*file, const char*arg0, ..., NULL);
//int execv(const char*path, char*const argv[]);
//int execvp(const char*file, char*const argv[]);



int main(int argc, char* argv[]){
    execl("/bin/ls","ls","-l",NULL);
    //execlp("ls","ls","-l",NULL); procura o executável no $PATH  
    //char* execargs []= {"ls","-l",NULL};
    //execv("/bin/ls",execargs);
}