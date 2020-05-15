// Author: Stephen Roche
// Date created: 31/03/16
// Prints a diamond of a given size.

#include <stdio.h>

int main(void) {
    int side, i, j;
    i = 1;
    j = 1;
    
    printf("Enter side length: ");
    scanf("%d", &side);

    while (i <= side) {
        while (j <= (side - i)) {
            printf(" ");
            j = j + 1;
        }
        j = 1;

        printf("*");

        while (j <= (2 * i - 3)) {
            printf(" ");
            j = j + 1;
        }
        j = 1;

        if (i != 1) {
            printf("*\n");
        } else {
            printf("\n");
        }
        i = i + 1;
    }

    i = i - 2;
    while (i >= 1) {
        while (j <= (side - i)) {
            printf(" ");
            j = j + 1;
        }
        j = 1;

        printf("*");

        while (j <= (2 * i - 3)) {
            printf(" ");
            j = j + 1;
        }
        j = 1;

        if (i != 1) {
            printf("*\n");
        } else {
            printf("\n");
        }
        i = i - 1;
    }

    return 0;
}
