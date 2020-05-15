#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define MAX_CHAR 128

int main(int argc, char *argv[]) {

    char array[MAX_LINES][MAX_CHAR];
    int n, distinct, i, j, newLine;

    n = atoi(argv[1]);
    distinct = 0;

    i = 0;
    while (distinct < n && fgets(array[i], MAX_CHAR, stdin) != NULL) {
        newLine = 1;
        for (j = 0; j < i; j++) {
            if (strcmp(array[j], array[i]) == 0) {
                newLine = 0;
            }
        }
        distinct += newLine;
        i++;
    }

    printf("%d distinct lines seen after %d lines read.\n", distinct, i);

    return 0;
}
