#include <stdio.h>
#include <string.h>
#include "mycommands.h"

int cat(char *args[]) {

}

int clear() {
    printf("\033[2J"); //clears terminal for Linux
}

int cp(char *args[]) {
    FILE *fptr1, *fptr2;
    char c;

    // Open first file for reading
    fptr1 = fopen(args[1], "r");
    if (fptr1 == NULL) {
        printf("Cannot find file %s \n", args[1]);
        return 1;
    }

    // Opens other file for writing
    fptr2 = fopen(args[2], "w");
    if (fptr2 == NULL) {
        printf("Cannot open file %s \n", args[2]);
        return 1;
    }

    // Read contents from file
    c = fgetc(fptr1);
    while (c != EOF) {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }

    fclose(fptr1);
    fclose(fptr2);
}

int echo(char* command) {
    printf("%s", command+5);
}

int grep(char *args[]) {

}

int ls() {

}