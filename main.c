#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#define TRUE 1
#define BUFFER 127
#define MAX_COMANNDS 5
#define MAX_COMMANDS_SIZE 5

void read_comand(char **);
void split(char *[MAX_COMMANDS_SIZE], char *, const char);

int main(void)
{
        char *comannds;
        int status;
        char *cmdarr[MAX_COMANNDS]; 
        comannds = (char *)malloc(BUFFER * sizeof(char));

        read_comand(&comannds);

        split(cmdarr, comannds, ' ');

        char *cmdmain = cmdarr[0];

        if (!(fork()))
        {
            int result = waitpid(-1, &status, 0);
        }
        else
        {
            execvp(cmdarr[0], cmdarr);
        }

        free(comannds);
        comannds = NULL;
       
    return 0;
}

void read_comand(char **command)
{

    if (!fgets(*command, BUFFER, stdin))
    {
        printf("Erro");
    }
}

void split(char *arr[MAX_COMMANDS_SIZE], char *comannds, const char a_delim)
{
    int line = 0;
    int col = 0;
    int i = 0;
    arr[line] = malloc(MAX_COMMANDS_SIZE * sizeof(char) + 1); 


    while (TRUE)
    {
        if (*(comannds + i) == ' ')
        {
            printf("\n");
            col = 0;
            line++;
            i++;
            arr[line] = malloc(MAX_COMMANDS_SIZE * sizeof(char) + 1); 
            continue;
        }

        if ((int)*(comannds + i) == 10)
        {
            arr[line + 1] = malloc(MAX_COMMANDS_SIZE * sizeof(char) + 1); 
            arr[line+1]= (char)0;
            break;
        }

        arr[line][col] = *(comannds + i);
        col++;
        i++;
    }

}