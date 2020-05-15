// Author: Stephen Roche
// Date created: 17/05/16
// Prints tnumber of orcas.

#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define MAX_LINE_LENGTH 256
#define MAX_NAME_LENGTH 128
#define MAX_WHALE_SPECIES 128

int readCountName(int *countp, char name[MAX_NAME_LENGTH]);

int main(void) {
    int count, lastCount;
    char name[MAX_NAME_LENGTH + 1];
    char lastName[MAX_NAME_LENGTH + 1] = {0};

    if (readCountName(&lastCount, lastName) != 1) {
        return 0;
    }
    while (readCountName(&count, name) == 1) {
        if (strcmp(name, lastName) == 0) {
            lastCount = lastCount + count;
        } else {
            printf("%d %s\n", lastCount, lastName);
            strcpy(lastName, name);
            lastCount = count;
        }
    }
    printf("%d %s\n", lastCount, lastName);
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
