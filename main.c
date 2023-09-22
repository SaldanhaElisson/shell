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
char ** strsplit( const char * , const char *  );


int main(void) {
    char *comannds;
    char **cmd;
    int status;

    comannds = (char*) malloc(BUFFER * sizeof(char));
    cmd = (char **) malloc (sizeof (char *) * MAX_COMANNDS);
    for(int i = 0; i < MAX_COMANNDS; i++){
        cmd[i] = (char *) malloc (sizeof (char) * MAX_COMMANDS_SIZE);
    }
    
    read_comand(&comannds);
   
    cmd = strsplit(*comannds, " ");

    printf("%s", cmd[0]);

    if((fork()) != NULL) {
        int teste = waitpid(-1, &status, 0);
    } else {
        execvp (cmd[0], cmd);
    }
        
    return 0;
}

void read_comand(char ** command){
   
    if(!fgets(*command, BUFFER, stdin)){
      printf("Erro");
    }
   
}

char ** strsplit( const char * src, const char * delim )
{
    char * pbuf = NULL;
    char * ptok = NULL;
    int count = 0;
    int srclen = 0;
    char ** pparr = NULL;

    srclen = strlen( src );

    pbuf = (char*) malloc( srclen + 1 );

    if( !pbuf )
        return NULL;

    strcpy( pbuf, src );

    ptok = strtok( pbuf, delim );

    while( ptok )
    {
        pparr = (char**) realloc( pparr, (count+1) * sizeof(char*) );
        *(pparr + count) = strdup(ptok);

        count++;
        ptok = strtok( NULL, delim );
    }

    pparr = (char**) realloc( pparr, (count+1) * sizeof(char*) );
    *(pparr + count) = NULL;

    free(pbuf);

    return pparr;
}