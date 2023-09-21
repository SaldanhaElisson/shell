#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define TRUE 1

void read_comand(char *);

int main(void) {
    char* comannds;
    read_comand(comannds);

    return 0;
}

void read_comand(char *command){
    command = (char*) malloc(2 * sizeof(char));

    if(fgets(command, 2* sizeof(char), stdin) != NULL)
        {
            printf("%s", command);
        }

}