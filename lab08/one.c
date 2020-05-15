// Author: Stephen Roche
// Date created: 26/04/16
// Prints characters one per line.

#include <stdio.h>

#define SIZE 1000

int main (void) {

    char ascii[SIZE];
    int nCharacters, i;

    printf("Enter a string: ");

    fgets(ascii, SIZE, stdin);

    nCharacters = 0;
    while (ascii[nCharacters] != '\0') {
        nCharacters = nCharacters + 1;
    }

    i = 0;
    while (i < (nCharacters - 1)) {
        if (ascii[i] != ' ') {
            putchar(ascii[i]);
        }
        printf("\n");
        i++;
    }

    return 0;
}

