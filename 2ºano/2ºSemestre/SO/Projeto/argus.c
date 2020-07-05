#include "argus.h"

int sfifo_fd;
int cfifo_fd;


void sigint_handler(int signum)
{
    if (unlink(CLIENT) == -1) {
        perror("unlink");
        exit(-1);
    }

    exit(0);
}

int main(int argc, char *argv[])
{
    char response[4096];
    ssize_t bytes_output;

    signal(SIGINT, sigint_handler);

    if (mkfifo(CLIENT, 0666) == -1) {
        perror("mkfifo");
        return -1;
    }
    
    if ((sfifo_fd = open(SERVER, O_WRONLY)) == -1) {
        perror("open");
        return -1;
    }

    if ((cfifo_fd = open(CLIENT, O_RDONLY)) == -1) {
        perror("open");
        return -1;
    }

    ReadlnBuffer *rb = (ReadlnBuffer *)calloc(1, sizeof(ReadlnBuffer));
    initRB(0, rb, MAX_BUFFER);

    ParsedLine pl;

    if (argc == 1) {
        ssize_t bytes_read = 1;
        while (bytes_read) {
            char *prompt = "argus$ ";
            if (write(STDIN_FILENO, prompt, strlen(prompt)) == -1) {
                perror("write");
                return -1;
            }
            if ((bytes_read = readlnToPL(rb, &pl)) > 1) {
                if (write(sfifo_fd, &pl, sizeof(ParsedLine)) == -1) {
                    perror("write");
                    return -1;
                }

                do {
                    if ((bytes_output = read(cfifo_fd, &response, 4096)) == -1) {
                        perror("read");
                        return -1;
                    }
                    if (write(STDOUT_FILENO, response, bytes_output) == -1) {
                        perror("write");
                        return -1;
                    }
                } while (bytes_output == 4096);

                if (bytes_output == -1) {
                    perror("read");
                    return -1;
                }
            }
        }
    } else {
        pl.opt = argv[1][1];
        strcpy(pl.arg, argv[2]);
        
        if (validate(argv[1], &pl) == -1) {
            char *invalid = "Invalid comand use \"ajuda\" (option -h) for help\n";
            write(1, invalid, strlen(invalid));
        } else {
            write(sfifo_fd, &pl, sizeof(ParsedLine));
            char response[4096];
            ssize_t bytes_output;

            do {
                if ((bytes_output = read(cfifo_fd, &response, 4096)) == -1) {
                    perror("read");
                    return -1;
                }
                if (write(STDOUT_FILENO, response, bytes_output) == -1) {
                    perror("write");
                    return -1;
                }
            } while (bytes_output == 4096);

            if (bytes_output == -1) {
                perror("read");
                return -1;
            }
        }

        if ((bytes_output = read(cfifo_fd, &response, 4096)) == -1) {
            perror("read");
            return -1;
        }
        if (write(STDOUT_FILENO, response, bytes_output) == -1) {
            perror("write");
            return -1;
        }
    }

    if (close(cfifo_fd) == -1) {
        perror("close");
        return -1;
    }

    if (close(sfifo_fd) == -1) {
        perror("close");
        return -1;
    }

    if (unlink(CLIENT) == -1) {
        perror("unlink");
        return -1;
    }

    return 0;
}