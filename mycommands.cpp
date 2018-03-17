#include <stdio.h>
#include <string.h>
#include "mycommands.h"


int echo(char args[]) {
    print_echo(args, 5);
}

int print_echo(char args[], int c) {
    if (c <= sizeof(args)) {
        printf("%c", args[c]);
        print_echo(args, c + 1);
    }
}