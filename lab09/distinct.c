// Author: Stephen Roche
// Date created: 02/05/16
// Reads lines from standard input until n different lines have been read.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 128
#define MAX_LINES 1024

int main (int argc, char *argv[]) {

    char lines[MAX_LINES][MAX_LINE_LENGTH];
    int i, nDistinct, lineCount, distinctCount, seenBefore;

    nDistinct = atoi(argv[1]);

    lineCount = 0;
    distinctCount = 0;

    while (distinctCount < nDistinct && fgets(lines[lineCount], MAX_LINE_LENGTH, stdin) != NULL) {
        seenBefore = 0;
        i = 0;
        while (i < lineCount) {
            if (strcmp(lines[i], lines[lineCount]) == 0) {
                seenBefore = 1;
            }
            i++;
        }

        if (seenBefore == 0) {
            distinctCount++;
        }

        lineCount++;
    }

    printf("%d distinct lines seen after %d lines read.\n", distinctCount, lineCount);

    return 0;
}

