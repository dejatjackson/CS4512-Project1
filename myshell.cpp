#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mycommands.h"

char *read_line(void);
char **split_args(char *command);

int main() {
    char *command;
    char **args;
    printf("Welcome to our shell Program!\n"); 
    do {
        printf("> ");
        command = read_line();
        args = split_args(command);

        if(strcmp(args[0], "cat") == 0) {
            cat(args);
            printf("\n");
        }
        else if(strcmp(args[0], "clear") == 0) {
            clear();
        }
        else if(strcmp(args[0], "cp") == 0) {
            cp(args);
        }
        else if(strcmp(args[0], "echo") == 0) {
            echo(command);
        }
        else if(strcmp(args[0], "exit") == 0) {
            return 0;
        }
        else if(strcmp(args[0], "grep") == 0) {
            grep(args);
        }
        else if(strcmp(args[0], "help") == 0) {
            printf("cat filename\nclear\ncp file1 file2\necho [string]\nexit\ngrep pattern file1 file2 ...\nhelp\nls [-l]\n");
        }
        else if(strcmp(args[0], "ls") == 0) {
            ls();
            printf("\n");
        }
        else {
            printf("Command not recognised, type help for valid commands\n");
        }
    } while(true);
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
    char *cmdcopy = strdup(command); //deep copy
    int i = 0;
    char **tokens = (char**)malloc(TOKEN_BUFSIZE * sizeof(char*));
    char *token = strtok(cmdcopy, TOKEN_DELIM);

    /* walk through other tokens */
    while( token != NULL ) {
        tokens[i] = token;
        //printf("%s", tokens[i]);
        i++;

        token = strtok(NULL, TOKEN_DELIM);
    }
    tokens[i] = NULL;
    return tokens;
}
