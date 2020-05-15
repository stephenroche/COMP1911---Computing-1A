// Author: Stephen Roche
// Date created: 10/05/16
// Prints the first n lines of a file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 1024

int main (int argc, char *argv[]) {

    int numLines, i;
    char filename[MAX_CHAR];
    char line[MAX_CHAR];

    if (argc == 1) {
        fprintf(stderr, "%s: incorrect number of arguments.\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-n") == 0) {
        if (argc != 4) {
            fprintf(stderr, "%s: incorrect number of arguments.\n", argv[0]);
            return 1;
        }
        numLines = atoi(argv[2]);
        strcpy(filename, argv[3]);

    } else {
        if (argc != 2) {
            fprintf(stderr, "%s: incorrect number of arguments.\n", argv[0]);
            return 1;
        }
        numLines = 10;
        strcpy(filename, argv[1]);
    }

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "%s: file could not be opened.\n", argv[0]);
        return 1;
    }

    i = 0;
    while (i < numLines && fgets(line, MAX_CHAR, fp) != NULL) {
        fputs(line, stdout);
        i++;
    }

    fclose(fp);

    return 0;
}

