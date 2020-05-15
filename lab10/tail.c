// Author: Stephen Roche
// Date created: 10/05/16
// Prints the last n lines of a file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 1024

int main (int argc, char *argv[]) {

    int startLine, i;
    char line[MAX_CHAR];

    if (argc != 2) {
        fprintf(stderr, "%s: incorrect number of arguments.\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        fprintf(stderr, "%s: file could not be opened.\n", argv[0]);
        return 1;
    }

    i = 0;
    while (fgets(line, MAX_CHAR, fp) != NULL) {
        i++;
    }

    startLine = i - 10;
    rewind(fp);
    i = 0;

    while (fgets(line, MAX_CHAR, fp) != NULL) {\
        if (i >= startLine) {
            fputs(line, stdout);
        }
        i++;
    }

    fclose(fp);

    return 0;
}

