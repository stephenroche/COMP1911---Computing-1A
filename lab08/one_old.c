// Author: Stephen Roche
// Date created: 26/04/16
// Prints characters one per line.

#include <stdio.h>

int main (void) {

    char ascii[1000] = {'0'};
    int i, j;

    printf("Enter a string: ");

    ascii[0] = getchar();

    i = 1;
    while (ascii[i - 1] != '\n') {
        ascii[i] = getchar();
        i++;
    }

    j = 0;
    while (j < (i - 1)) {
        if (ascii[j] != ' ') {
            putchar(ascii[j]);
        }
        printf("\n");
        j++;
    }

    return 0;
}

