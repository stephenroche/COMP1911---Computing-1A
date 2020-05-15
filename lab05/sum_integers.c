// Author: Stephen Roche
// Date created: 30/03/16
// Prints the sum of the integers from 1 to k.

#include <stdio.h>

int main(void) {
    #define MAX 20
    int k, sum;
    k = 1;
    sum = 0;

    printf(" k  sum\n\n");

    while(k <= MAX) {
        sum = sum + k;
        printf("%2d %4d\n", k, sum);
        k = k + 1;
    }

    return 0;
}
