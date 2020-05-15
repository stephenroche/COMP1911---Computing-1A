// Author: Stephen Roche
// Date created: 26/04/16
// Removes vowels from a string of characters.

#include <stdio.h>

#define SIZE 1000

int main (void) {

    char ascii[SIZE] = {'0'};
    int i, j;

    ascii[0] = getchar();

    i = 1;
    while (ascii[i - 1] != EOF) {
        ascii[i] = getchar();
        i++;
    }

    j = 0;
    while (j < (i - 1)) {
        if (ascii[j] != 'a' && ascii[j] != 'e' && ascii[j] != 'i' && ascii[j] != 'o' && ascii[j] != 'u') {
            putchar(ascii[j]);
        }
        j++;
    }

    return 0;
}

