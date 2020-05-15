#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char array[10][1024];
    int line, i;

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        return 1;
    }

    line= 0;
    while (fgets(array[line % 10], 1024, fp) != NULL) {
        line++;
    }
    line--;

    i = line - 9;
    if (i < 0) {
        i = 0;
    }

    while (i <= line) {
        printf("%s", array[i % 10]);
        i++;
    }

    fclose(fp);

    return 0;
}
