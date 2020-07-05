#include "argus.h"

extern int cfifo_fd;
extern int time_inact;
extern int time_exec;
extern TASKLIST tasks;

int execute(char *argv[256][256], int n)
{
    int log_fd, pids_fd;
    int beforePipe = 0;
    int afterPipe[2];

    signal(SIGCHLD, sigchld_handler);
    
    switch (fork()) {
    case -1:
        perror("fork");
        return -1;
    case 0:
        signal(SIGCHLD, SIG_IGN);

        int pids[256];

        char pids_file[16];
        sprintf(pids_file, "tmp%d", tasks.used);

        if ((log_fd = open(LOG, O_CREAT | O_APPEND | O_WRONLY, 0666)) == -1) {
            perror("open");
            return -1;
        }

        //if(time_exec > 0) {
        //    signal(SIGALRM,sigalrm_handler);
        //    alarm(time_exec);
        //}
    
        for (int i = 0; i < n; i++) {

            int offsetA;

            if(i == n - 1){
                offsetA = lseek(log_fd, 0, SEEK_END);
            }

            if (i < n - 1)
                pipe(afterPipe);

            switch (pids[i] = fork()) {
            case -1:
                perror("fork");
                return -1;
            case 0:
                if (i > 0) {
                    dup2(beforePipe, 0);
                    close(beforePipe);
                }
                if (i < n - 1) {
                    dup2(afterPipe[1], 1);
                    close(afterPipe[0]);
                    close(afterPipe[1]);
                }
                if (i == n - 1) {
                    dup2(log_fd, STDOUT_FILENO);
                    close(log_fd);
                }
                if (execvp(argv[i][0], argv[i])) {
                    perror("execvp");
                    return -1;
                }
                break;
            default:

                if (i < n - 1)
                    close(afterPipe[1]);
                if (i > 0)
                    close(beforePipe);
                beforePipe = afterPipe[0];

                pids_fd = open(pids_file, O_CREAT | O_WRONLY, 0640);
                write(pids_fd, pids, sizeof(pids));
                close(pids_fd);

                if (i == n - 1) {
                    waitpid(pids[i],NULL,0);
                    int offsetB = lseek(log_fd, 0, SEEK_END);
                    idx_set(tasks.used - 1, offsetA, offsetB - offsetA);
                }
            }
        }
        
        int signal_pipe_fd = open(SIGNAL_FILE, O_CREAT | O_TRUNC | O_WRONLY, 0640);

        write(signal_pipe_fd, &tasks.used, sizeof(int));
        close(signal_pipe_fd);

        close(log_fd);

        unlink(pids_file);

        exit(0);
    }

    return 0;
}

int idx_add()
{
    int idx_fd;
    LOGIDX idx;

    idx_fd = open(LOG_IDX, O_CREAT | O_APPEND | O_WRONLY, 0640);
    write(idx_fd, &idx, sizeof(LOGIDX));
    close(idx_fd);

    return 0;
}

int idx_set(int index, int offset, int size)
{
    int idx_fd;

    idx_fd = open(LOG_IDX, O_RDWR);
    lseek(idx_fd, index * sizeof(LOGIDX), SEEK_SET);

    LOGIDX idx = {
        .offset = offset,
        .size = size,
    };

    write(idx_fd, &idx, sizeof(idx));

    close(idx_fd);

    return 0;
}

void task_add(char *task, int ncmd)
{
    tasks.list[tasks.used].task = strdup(task);
    tasks.list[tasks.used].status = running;
    tasks.list[tasks.used].ncmd = ncmd;
    tasks.used++;
}

int parse(char *buf, char *args[256][256])
{
    char *token;
    char *pipe_ptr, *space_ptr;
    int i, j;

    token = strtok_r(buf, "|", &pipe_ptr);

    for (i = 0; token; i++) {
        token = strtok_r(token, " ", &space_ptr);

        for (j = 0; token; j++) {
            args[i][j] = token;
            token = strtok_r(NULL, " ", &space_ptr);
        }

        args[i][j] = NULL;

        token = strtok_r(NULL, "|", &pipe_ptr);
    }

    return i;
}