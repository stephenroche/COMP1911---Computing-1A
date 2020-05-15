#include <stdio.h>
#include <string.h>

int main(void) {

    char array[5][100];
    FILE *fp = fopen("scanf_test2.c", "r");

    if (fp == NULL) {
        printf("File open failed\n");
        return 0;
    }

    fscanf(fp, "%s%s", array[0], array[1]);

    printf("%s*\n", array[0]);
    printf("%s*\n", array[1]);

    fclose(fp);

    return 0;
}

