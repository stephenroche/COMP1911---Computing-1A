// Author: Stephen Roche
// Date created: 10/05/16
// Creates a file with a range of integers in it.

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    int num1, num2;

    if (argc != 4) {
        fprintf(stderr, "%s: incorrect number of arguments.\n", argv[0]);
        return 1;
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);

    FILE *fp = fopen(argv[3], "w");

    if (fp == NULL) {
        fprintf(stderr, "%s: file could not be opened.\n", argv[0]);
        return 1;
    }

    for (int i = num1; i <= num2; i++) {
        fprintf(fp, "%d\n", i);
    }

    fclose(fp);

    return 0;
}

