#include <stdio.h>
#include <string.h>
#include "mycommands.h"

int cat(char *args[]) {

}

int clear() {
    //clears terminal for Linux
    printf("\033[2J");
}

int cp(char *args[]) {

}

int echo(char* command) {
    printf("%s", command+5);
}

int grep(char *args[]) {

}

int ls() {

}