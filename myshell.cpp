#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mycommands.h"

char *read_line(void);
char **split_args(char *command);

int main() {
    char *command;
    char **args;
    int status = 1;

    do {
        printf("> ");
        command = read_line();
        args = split_args(command);
        //status = sh_execute(args);

        if(strcmp(args[0], "echo\n") == 0) {
            echo(command);
        }
        else if(strcmp(args[0], "exit") == 0) {
            return 0;
        }
    } while(status);
}

char *read_line(void) {
    char *line = NULL;
    size_t bufsize = 0; // have getline allocate a buffer for us
    getline(&line, &bufsize, stdin);
    return line;
}

#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM " \t\r\n\a"
char **split_args(char *command) {
    int i = 0;
    char **tokens = (char**)malloc(TOKEN_BUFSIZE * sizeof(char*));
    char *token = strtok(command, TOKEN_DELIM);

    /* walk through other tokens */
    while( token != NULL ) {
        tokens[i] = token;
        printf("%s", tokens[i]);
        i++;


        token = strtok(NULL, TOKEN_DELIM);
    }
    tokens[i] = NULL;
    return tokens;
}