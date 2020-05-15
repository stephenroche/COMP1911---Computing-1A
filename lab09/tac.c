// Author: Stephen Roche
// Date created: 02/05/16
// Reverses lines of input.

#include <stdio.h>

#define MAX_LINE_LENGTH 128
#define MAX_LINES 1024

int main (void) {

    char lines[MAX_LINES][MAX_LINE_LENGTH];
    int i;

    i = 0;
    while (fgets(lines[i], MAX_LINE_LENGTH, stdin) != NULL) {
        i++;
    }

    i--;
    while (i >= 0) {
        printf("%s", lines[i]);
        i--;
    }

    return 0;
}

