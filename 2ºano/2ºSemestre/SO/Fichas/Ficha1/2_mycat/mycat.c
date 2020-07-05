#include <sys/types.h>
#include <unistd.h>   /*chamadas ao sistema: defs e decls essenciais*/
#include <fcntl.h>    /*O_RDONLY, O_WRONLY, O_CREAT, O_* */

#define MAX_BUFFER 256


    /**
     * int     open(const char*path, int oflag [, mode]);
     * ssize_t read(int fildes, void*buf, size_t nbyte);
     * ssize_t write(int fildes, const void*buf, size_t nbyte);
     * off_t   lseek(int fd, off_t offset, int whence);
     * int     close(int fildes);
     */


    /**
     * Nota :
     * STDIN = 0
     * STDOUT = 1
     */


int main(int argc, char* argv[]){
    char buffer[MAX_BUFFER];
	int n_bytes = read(0,buffer,MAX_BUFFER);

	write(1,buffer,n_bytes);
    
    return 0;
}