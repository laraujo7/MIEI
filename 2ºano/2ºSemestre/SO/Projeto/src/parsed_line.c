#include "argus.h"

// Valerá a pena dividir esta função em duas, comando e opção, para simplificar estes if statements e aproveitar o facto de as opçoes serem apenas um char? (utilizar switch)
// A cena de alinhar os || foi só para facilitar a leitura. Se não for divido em duas funções põe-se isso direito outra vez.
ssize_t validate(char *token, ParsedLine *pl)
{
    if (!strcmp(token, "tempo-inactividade")  || !strcmp(token, "-i"))
        pl->opt = 'i';
    else if (!strcmp(token, "tempo-execucao") || !strcmp(token, "-m"))
        pl->opt = 'm';
    else if (!strcmp(token, "executar")       || !strcmp(token, "-e"))
        pl->opt = 'e';
    else if (!strcmp(token, "listar")         || !strcmp(token, "-l"))
        pl->opt = 'l';
    else if (!strcmp(token, "terminar")       || !strcmp(token, "-t"))
        pl->opt = 't';
    else if (!strcmp(token, "historico")      || !strcmp(token, "-r"))
        pl->opt = 'r';
    else if (!strcmp(token, "ajuda")          || !strcmp(token, "-h"))
        pl->opt = 'h';
    else if (!strcmp(token, "output")         || !strcmp(token, "-o"))
        pl->opt = 'o';
    else {
        perror("error");
        return -1;
    }

    return 0;
}

int validateArg(char *arg)
{
    int i;

    if (arg[0] == '\'') {
        for (i = 1; arg[i] && arg[i] != '\''; i++);
        return (arg[i] == '\'' && arg[i + 1] == '\0');
    } else {
        for(i = 0; arg[i] && arg[i] != ' ' ; i++);
        return arg[i] == '\0';
    }
}


void initRB(int fd, ReadlnBuffer *pl, size_t init_size)
{
    pl->fd = fd;
    pl->mem_size = init_size;
    pl->line = malloc(sizeof(char) * init_size);
}

void resizeRB(ReadlnBuffer *rb)
{
    rb->mem_size += 2 * rb->mem_size;
    rb->line = realloc(rb->line, rb->mem_size);
}


ssize_t readlnToPL(ReadlnBuffer *rb, ParsedLine *pl)
{
    int flag = true;
    ssize_t bytes_read;
    char *token, *aux;

    if ((bytes_read = readln(rb)) > 0) {
        if ((token = strtok(rb->line, " ")) == NULL)
            flag = false;

        if (flag && (aux = strtok(NULL, "")) != NULL) {
            if ((flag = validateArg(aux)))
                //pl->arg = strdup(aux); HHEEEEEYYOUUUUU
                strcpy(pl->arg, aux);
            else
                return -1;
        }

        if (flag) {
            if (validate(token, pl) == -1)
                return -1;
        }
    }

    return bytes_read;
}



ssize_t readln(ReadlnBuffer *rb)
{
    int read_bytes = 0, found = false, size = 0;
    char buffer[BUFFSIZE];

    while(!found && (read_bytes = read(rb->fd, buffer, BUFFSIZE)) > 0) {
        if (size > rb->mem_size)
            resizeRB(rb);

        for (int i = 0; i < read_bytes && !found; size++, i++) {
            if (buffer[i] == '\n') {
                buffer[i] = '\0';
                found = true;
            }

            rb->line[size] = buffer[i];
        }
    }

    return size;
}