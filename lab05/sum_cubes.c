// Author: Stephen Roche
// Date created: 30/03/16
// Prints the sum of the cubes of the integers from 1 to k.

#include <stdio.h>

int main(void) {
    #define MAX 20
    int k, sum;
    k = 1;
    sum = 0;

    printf(" k  cubes\n\n");

    while(k <= MAX) {
        sum = sum + (k * k * k);
        printf("%2d %6d\n", k, sum);
        k = k + 1;
    }

    return 0;
}
