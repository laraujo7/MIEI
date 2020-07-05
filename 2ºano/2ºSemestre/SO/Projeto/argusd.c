#include "argus.h"

int sfifo_fd;
int cfifo_fd;
int time_exec;
TASKLIST tasks;


void sigalrm_handler(int signum){
    int index;

    int signal_pipe_fd = open(SIGNAL_FILE, O_RDONLY);
    read(signal_pipe_fd, &index, sizeof(int));

    terminate(index);
    tasks.list[index - 1].status = max_execution;
}


void sigchld_handler(int signum)
{
    wait(NULL);

    int index;

    int signal_pipe_fd = open(SIGNAL_FILE, O_RDONLY);
    read(signal_pipe_fd, &index, sizeof(int));

    if(tasks.list[index - 1].status == running){
        tasks.list[index - 1].status = concluded;
    }
}

void sigint_handler(int signum)
{
    if (unlink(SERVER) == -1) {
        exit(-1);
    }

    if (unlink(SIGNAL_FILE) == -1) {
        exit(-1);
    }

    int fd;

    if ((fd = open(LOG, O_TRUNC)) == -1) {
        exit(-1);
    }
    close(fd);

    if ((fd = open(LOG_IDX, O_TRUNC)) == -1) {
        exit(-1);
    }
    close(fd);
    

    exit(0);
}

int main(int argc, char *argv[])
{
    signal(SIGINT, sigint_handler);

    tasks.used = 0; //substituir por init xomxing
    time_exec = 0;
    
    if (mkfifo(SERVER, 0666) == -1) {
        return -1;
    }
    
    while (1) {
        if ((sfifo_fd = open(SERVER, O_RDONLY)) == -1) {
            return -1;
        }
        
        if ((cfifo_fd = open(CLIENT, O_WRONLY)) == -1) {
            return -1;
        }
    
        ParsedLine request;

        while (read(sfifo_fd, &request, sizeof(ParsedLine)) > 0) {
            process(request);
        }

        if (close(cfifo_fd) == -1) {
            return -1;
        }

        if (close(sfifo_fd) == -1) {
            return -1;
        }
    }

    if (unlink(SERVER) == -1) {
        return -1;
    }

    return -1;
}