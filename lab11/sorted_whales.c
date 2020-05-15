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

int main(int argc, char *argv[]) {
    int i, j, k, nameFound, count, tempCount;
    char tempName[MAX_NAME_LENGTH];
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

    if (argc >= 2 && strcmp(argv[1], "-s") == 0) {
        for (j = 0; j < i; j++) {
            for (k = 0; k < (i - 1); k++) {
                if (whaleCount[k + 1] > whaleCount[k] || (whaleCount[k + 1] == whaleCount[k] && strcmp(name[k + 1], name[k]) < 0)) {
                    strcpy(tempName, name[k]);
                    strcpy(name[k], name[k + 1]);
                    strcpy(name[k + 1], tempName);
                    tempCount = whaleCount[k];
                    whaleCount[k] = whaleCount[k + 1];
                    whaleCount[k + 1] = tempCount;
                }
            }
        }
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
