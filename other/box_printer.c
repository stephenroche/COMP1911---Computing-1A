// Author: Stephen Roche
// Date created: 27/03/16
// Prints a box of a given width and height.

#include <stdio.h>

int main(void) {
    int width, height, i, j;

    i = 1;
    j = 1;

    printf("Enter box width: ");
    scanf("%d", &width);
    printf("Enter box height: ");
    scanf("%d", &height);

    printf(" ");

    while (i <= width) {
        printf("__");
        i = i + 1;
    }
    i = 1;

    printf("\n");

    while (j <= (height - 1)) {
        printf("|");
        
        while (i <= width) {
            printf("  ");
            i = i + 1;
        }
        i = 1;

        printf("|\n");
        j = j + 1;
    }

    printf("|");

    while (i <= width) {
        printf("__");
        i = i + 1;
    }

    printf("|\n");

    return 0;
}
