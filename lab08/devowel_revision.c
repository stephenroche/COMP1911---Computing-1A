// Author: Stephen Roche
// Date created: 26/04/16
// Removes vowels from a string of characters.

#include <stdio.h>

int main (void) {

    char ch;

    ch = getchar();
    while (ch != EOF) {
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            putchar(ch);
        }
        ch = getchar();
    }

    return 0;
}

