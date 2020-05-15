// Author: Stephen Roche
// Date created: 26/04/16
// Tests if a string is a palindrome.

#include <stdio.h>
#include <ctype.h>

#define SIZE 1000

int main (void) {

    char ascii[SIZE];
    char letters[SIZE];
    int nCharacters, i, j, palindrome, nLetters;

    printf("Enter a string: ");

    fgets(ascii, SIZE, stdin);

    nCharacters = 0;
    while (ascii[nCharacters] != '\0') {
        nCharacters = nCharacters + 1;
    }
    nCharacters--;

    i = 0;
    j = 0;
    while (j < nCharacters) {
        if (isalpha(ascii[j]) != 0) {
            letters[i] = tolower(ascii[j]);
            i++;
        }
        j++;
    }

    nLetters = i;
    palindrome = 1;

    i = 0;
    while (i <= (nLetters - 1) / 2) {
        if (letters[i] != letters[nLetters - 1 - i]) {
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

