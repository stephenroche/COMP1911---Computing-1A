// Author: Stephen Roche
// Date created: 17/05/16
// Prints the number of whales of all whale species.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_NAME_LENGTH 128
#define MAX_SPECIES 128

int readCountName(int *countp, char name[MAX_NAME_LENGTH]);

int main(void) {
    int i, j, nameFound, count;
    int whaleCount[MAX_SPECIES] = {0};
    int podCount[MAX_SPECIES] = {0};
    char name[MAX_SPECIES][MAX_NAME_LENGTH];

    i = 0;
    nameFound = 0;
    while (readCountName(&count, name[i]) == 1) {
        j = 0;
        while (j <= i && nameFound == 0) {
            if (strcmp(name[i], name[j]) == 0) {
                nameFound = 1;
            }
            j++;
        }
        nameFound = 0;
        j--;

        whaleCount[j] += count;
        podCount[j]++;
        i++;
    }

    j = 0;
    while (j < i) {
        if (whaleCount[j] != 0) {
            printf("%d %s\n", whaleCount[j], name[j]);
        }
        j++;
    }

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
