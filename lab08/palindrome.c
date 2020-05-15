// Author: Stephen Roche
// Date created: 26/04/16
// Tests if a string is a palindrome.

#include <stdio.h>

#define SIZE 1000

int main (void) {

    char ascii[SIZE];
    int nCharacters, i, palindrome;

    printf("Enter a string: ");

    fgets(ascii, SIZE, stdin);

    nCharacters = 0;
    while (ascii[nCharacters] != '\0') {
        nCharacters = nCharacters + 1;
    }

    palindrome = 1;

    i = 0;
    while (i <= (nCharacters - 2) / 2) {
        if (ascii[i] != ascii[nCharacters - 2 - i]) {
            palindrome = 0;
        }
        i++;
    }

    if (palindrome == 1) {
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    }

    return 0;
}

