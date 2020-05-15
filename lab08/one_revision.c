// Author: Stephen Roche
// Date created: 26/04/16
// Prints characters one per line.

#include <stdio.h>
#include <string.h>

#define SIZE 1000

int main (void) {

    char ascii[SIZE];
    int i;

    printf("Enter a string: ");
    fgets(ascii, SIZE, stdin);

    i = 0;
    while (ascii[i] != '\n' && ascii[i] != '\0') {
        printf("%c\n", ascii[i]);
        i++;
    }

    return 0;
}

