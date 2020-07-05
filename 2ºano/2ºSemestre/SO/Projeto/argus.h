#ifndef ARGUS_H
#define ARGUS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFSIZE 256
#define MAX_BUFFER 4096
#define SERVER "server_fifo"
#define CLIENT "client_fifo"
#define LOG "log"
#define LOG_IDX "log.idx"
#define SIGNAL_FILE "signal_file"

typedef enum {running, concluded, max_inactivity, max_execution, terminated} STATUS;
typedef enum {false, true} bool;

typedef struct logidx {
    int offset;
    int size;
} LOGIDX;

typedef struct task {
    int ncmd;
    pid_t pid[64];
    STATUS status;
    char *task;
} TASK;

typedef struct tasklist {
    int used;
    TASK list[4096];
} TASKLIST;

typedef struct readln_buffer {
    int fd;
    ssize_t mem_size;
    char *line;
} ReadlnBuffer;

typedef struct parsed_line {
    char opt;
    char arg[4096];
} ParsedLine;


void time_inactivity(int sec);
void time_execution(int sec);
int output(int task);
int list_tasks(char type);
int terminate(int task);
int help();


void sigchld_handler(int signum);
void sigint_handler(int signum);
void sigalrm_handler(int signum);


int idx_add();
int idx_set(int index, int offset, int size);
void task_add(char *buff, int ncmd);
int parse(char *buff, char *args[256][256]);
int execute(char *argv[256][256], int n);


ssize_t validate(char *token, ParsedLine *pl);
void initRB(int fd, ReadlnBuffer *rb, size_t init_size);
void resizeRB(ReadlnBuffer *rb);
ssize_t readln(ReadlnBuffer *rb);
ssize_t readlnToPL(ReadlnBuffer *rb, ParsedLine *pl);


int process(ParsedLine request);
int process_time_inactivity(char *sec_inact);
int process_time_execution(char *sec_exec);
int process_execute(char *task);
int process_output(char *task_idx);
int process_terminate(char *task_idx);



#endif //ARGUS_H