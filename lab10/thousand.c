// Author: Stephen Roche
// Date created: 10/05/16
// Creates a file and fills it with the first 1000 integers.

#include <stdio.h>

int main (void) {

    FILE *fp = fopen("1000.txt", "w");

    for (int i = 1; i <= 1000; i++) {
    fprintf(fp, "%d\n", i);
    }

    fclose(fp);

    return 0;
}

