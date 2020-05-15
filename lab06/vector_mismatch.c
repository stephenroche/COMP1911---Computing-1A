// Author: Stephen Roche
// Date created: 08/04/16
// Counts matches and mismatches between two vectors.

#include <stdio.h>

int main (void) {

    #define NUMS 10
    int v1[NUMS], v2[NUMS];
    int i, j, matches, mismatches, count1, count2, alreadyCounted;
    matches = 0;
    mismatches = 0;

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

    // This section counts the total number of matches and mismatches:
    i = 0;
    while (i < NUMS) {
        // Has the number been counted before in v1?
        j = 0;
        alreadyCounted = 0;
        while (j < i) {
            if (v1[i] == v1[j]) {
                alreadyCounted = 1;
            }
            j = j + 1;
        }

        if (alreadyCounted == 0) {
            // Number of times number appears in v1:
            j = 0;
            count1 = 0;
            while (j < NUMS) {
                if (v1[j] == v1[i]) {
                    count1 = count1 + 1;
                }
                j = j + 1;
            }

            // Number of times number appears in v2:
            j = 0;
            count2 = 0;
            while (j < NUMS) {
                if (v2[j] == v1[i]) {
                    count2 = count2 + 1;
                }
                j = j + 1;
            }

            if (count1 <= count2) {
                mismatches = mismatches + count1;
            } else {
                mismatches = mismatches + count2;
            }
        }
        i = i + 1;
    }

    // This section counts the number of matches:
    i = 0;
    while (i < NUMS) {
        if (v1[i] == v2[i]) {
            matches = matches + 1;
        }
        i = i + 1;
    }

    mismatches = mismatches - matches;

    printf("Vectors match in %d positions.\n", matches);
    printf("Vectors mismatch in %d positions.\n", mismatches);

    return 0;
}
