#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define TRUE 1
#define BUFFER 127
#define MAX_COMANNDS 5
#define MAX_COMMANDS_SIZE 5

void read_comand(char **);
int split (const char *, char , char ***);


int main(void) {
    char *comannds;
    char **cmd = NULL;
    int status;

    comannds = (char*) malloc(BUFFER * sizeof(char));
   
    read_comand(&comannds);
   
    int c = split(comannds, ' ', &cmd);

    char *argv[3];
    argv[0] = "ls";
    argv[1] = "-la";
    argv[2] = NULL;


    printf("%s", cmd[0]);

    if((fork()) != NULL) {
        int teste = waitpid(-1, &status, 0);
    } else {
        execvp (cmd[0], argv);
    }
        
    return 0;
}

void read_comand(char ** command){
   
    if(!fgets(*command, BUFFER, stdin)){
      printf("Erro");
    }
   
}

int split (const char *txt, char delim, char ***tokens)
{
    int *tklen, *t, count = 1;
    char **arr, *p = (char *) txt;

    while (*p != '\0') if (*p++ == delim) count += 1;
    t = tklen = calloc (count, sizeof (int));
    for (p = (char *) txt; *p != '\0'; p++) *p == delim ? *t++ : (*t)++;
    *tokens = arr = malloc (count * sizeof (char *));
    t = tklen;
    p = *arr++ = calloc (*(t++) + 1, sizeof (char *));
    while (*txt != '\0')
    {
        if (*txt == delim)
        {
            p = *arr++ = calloc (*(t++) + 1, sizeof (char *));
            txt++;
        }
        else *p++ = *txt++;
    }
    free (tklen);
    return count;
}