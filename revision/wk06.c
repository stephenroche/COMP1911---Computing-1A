#include <stdio.h>

#define VECTOR_LENGTH 10

int main(void) {

    int v1[VECTOR_LENGTH], v2[VECTOR_LENGTH];
    int i, j, matches, mismatches;

    printf("Enter vector 1 of %d postive numbers: ", VECTOR_LENGTH);
    for (i = 0; i < VECTOR_LENGTH; i++) {
        scanf("%d", &v1[i]);
    }

    printf("Enter vector 2 of %d postive numbers: ", VECTOR_LENGTH);
    for (i = 0; i < VECTOR_LENGTH; i++) {
        scanf("%d", &v2[i]);
    }

    matches = 0;
    for (i = 0; i < VECTOR_LENGTH; i++) {
        if (v1[i] == v2[i]) {
            matches++;
            v1[i] = -1;
            v2[i] = -1;
        }
    }

    mismatches = 0;
    for (i = 0; i < VECTOR_LENGTH; i++) {
        j = 0;
        while (v1[i] != -1 && j < VECTOR_LENGTH) {
            if (v1[i] == v2[j]) {
                mismatches++;
                v1[i] = -1;
                v2[j] = -1;
            }
            j++;
        }
    }

    printf("Vectors match in %d positions.\n", matches);
    printf("Vectors mismatch in %d positions.\n", matches);

    return 0;
}
