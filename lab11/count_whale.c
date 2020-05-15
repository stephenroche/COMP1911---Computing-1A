// Author: Stephen Roche
// Date created: 17/05/16
// Prints the number of a given whale species.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_NAME_LENGTH 128

int readCountName(int *countp, char name[MAX_NAME_LENGTH]);

int main(int argc, char *argv[]) {
    int count;
    int whaleCount = 0;
    int podCount = 0;
    char name[MAX_NAME_LENGTH];

    while (readCountName(&count, name) == 1) {
        if (strcmp(name, argv[1]) == 0) {
            whaleCount += count;
            podCount++;
        }
    }

    printf("%s count: %d pods containing %d whales\n", argv[1], podCount, whaleCount);

    return 0;
}



int readCountName(int *countp, char name[MAX_NAME_LENGTH]) {
    char line[MAX_LINE_LENGTH];
    int i,j;
    if (scanf("%d", countp) != 1) {
        return 0;
    }

    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
        return 0;
    }

    i = 0;
    while (isspace(line[i]) && line[i] != '\0') {
        i = i + 1;
    }

    j = 0;
    while (line[i] != '\0' && line[i] != '\n') {
        name[j] = line[i];
        j = j + 1;
        i = i + 1;
    }
    name[j] = '\0';

    return 1;
}
