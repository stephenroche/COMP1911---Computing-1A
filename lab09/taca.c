// Author: Stephen Roche
// Date created: 02/05/16
// Reverses command line arguments.

#include <stdio.h>

int main (int argc, char *argv[]) {

    int i;

    i = argc - 1;
    while (i > 0) {
        printf("%s\n", argv[i]);
        i--;
    }

    return 0;
}

