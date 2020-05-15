// Author: Stephen Roche
// Date created: 08/04/16
// Counts similarities between two vectors.

#include <stdio.h>

int main (void) {

    #define NUMS 10
    int v1[NUMS], v2[NUMS];
    int i, matches;

    printf("Enter vector 1 of %d positive numbers: ", NUMS);
    i = 0;
    while (i < NUMS) {
        scanf("%d", &v1[i]);
        i = i + 1;
    }

    printf("Enter vector 2 of %d positive numbers: ", NUMS);
    i = 0;
    while (i < NUMS) {
        scanf("%d", &v2[i]);
        i = i + 1;
    }

    i = 0;
    matches = 0;
    while (i < NUMS) {
        if (v1[i] == v2[i]) {
            matches = matches + 1;
        }
        i = i + 1;
    }

    printf("Vectors match in %d positions.\n", matches);

    return 0;
}
