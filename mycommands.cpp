#include <stdio.h>
#include <string.h>
#include "mycommands.h"

int clear() {
    printf("\033[2J");
}

int echo(char command[]) {
    print_echo(command, 5);
}

int print_echo(char args[], int c) {
    if (c <= sizeof(args)) {
        printf("%c", args[c]);
        print_echo(args, c + 1);
    }
}