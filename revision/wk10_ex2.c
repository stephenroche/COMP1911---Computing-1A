#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int i;
    FILE *fp = fopen(argv[3], "w");    

    if (fp == NULL) {
        return 1;
    }

    for (i = atoi(argv[1]); i <= atoi(argv[2]); i++) {
        fprintf(fp, "%d\n", i);
    }

    fclose(fp);

    return 0;
}
