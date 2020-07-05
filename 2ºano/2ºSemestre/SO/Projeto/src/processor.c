#include "argus.h"

extern TASKLIST tasks;
extern int cfifo_fd;
extern int time_exec;

int process(ParsedLine request)
{
    switch (request.opt) { // e i l m o t r
        case 'i': // tempo inatividade
            return process_time_inactivity(request.arg);
        case 'm': // tempo execucao
            return process_time_execution(request.arg);
        case 'e': // executar tarefa
            return process_execute(request.arg);
        case 'o': // output
            return process_output(request.arg);
        case 'l': case 'r': // listar tarefas em execucao
            return list_tasks(request.opt);
        case 't': // terminar tarefa
            return process_terminate(request.arg);
        case 'h':
            return help();
    }

    return -1;
}

int process_time_inactivity(char *sec_inact)
{
    char *endptr;
    int sec;

    sec = (int)strtol(sec_inact, &endptr, 10);

    if (sec < 1 || *endptr != '\0') {
        char *invalid = "Invalid inactivity time. Type \"ajuda\" (w/o quotes) for help\n";
        write(cfifo_fd, invalid, strlen(invalid));
        return -1;
    }

    time_inactivity(sec);

    return 0;
}

int process_time_execution(char *sec_exec)
{
    char *endptr;
    int sec;

    sec = (int)strtol(sec_exec, &endptr, 10);
    
    if (sec < 1 || *endptr != '\0') {
        char *invalid = "Invalid execution time. Type \"ajuda\" (w/o quotes) for help\n";
        write(cfifo_fd, invalid, strlen(invalid));
        return -1;
    }

    char* valid = "Execution time updated\n";
    write(cfifo_fd,valid,strlen(valid));

    time_exec = sec;

    return 0;
}

int process_execute(char *task)
{
    int n;
    char *argv[256][256];
    char *buffer;

    char *executing = "Task received\n";
    write(cfifo_fd, executing, strlen(executing));

    task = strtok(task, "'");
    buffer = strdup(task);
    idx_add();
    n = parse(buffer, argv);
    task_add(task, n);
    execute(argv, n);

    free(buffer);
    return 0;
}

int process_output(char *task_idx)
{
    char *endptr;
    int index;

    index = (int)strtol(task_idx, &endptr, 10) - 1;

    if (index < 0 || *endptr != '\0') {
        char *invalid = "Invalid task index. Type \"ajuda\" (w/o quotes) for help\n";
        write(cfifo_fd, invalid, strlen(invalid));
        return -1;
    }

    if (tasks.list[index].status == running) {
        char notyet[35];
        sprintf(notyet, "Task %d is still running\n", index + 1);
        write(cfifo_fd, notyet, strlen(notyet));
        return -1;
    }

    return output(index);
}

int process_terminate(char *task_idx)
{
    char *endptr;
    int index;

    index = (int)strtol(task_idx, &endptr, 10);

    if (index < 0 || *endptr != '\0') {
        char *invalid = "Invalid task index. Type \"ajuda\" (w/o quotes) for help\n";
        write(cfifo_fd, invalid, strlen(invalid));
        return -1;
    }

    if (index > tasks.used) {
        char invalid[34];
        sprintf(invalid, "There's only %d task(s)\n", tasks.used);
        write(cfifo_fd, invalid, strlen(invalid));
        return -1;
    }

    if (tasks.list[index - 1].status != running) {
        char notyet[33];
        sprintf(notyet, "Task %d wasn't running\n", index);
        write(cfifo_fd, notyet, strlen(notyet));
        return -1;
    }
    
    terminate(index);

    char response[29];
    sprintf(response, "Task %d terminated\n", index);
    write(cfifo_fd, response, strlen(response));

    return 0;
}