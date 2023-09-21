#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define TRUE 1
#define BUFFER 127

void read_comand(char *);
void splice_by_space();

int main(void) {
    char* comannds;
    read_comand(comannds);

    return 0;
}

void read_comand(char *command){
    command = (char*) malloc(BUFFER * sizeof(char));

    if(fgets(command, BUFFER* sizeof(char), stdin) != NULL)
        {
            printf("%s", command);
        }
    
}