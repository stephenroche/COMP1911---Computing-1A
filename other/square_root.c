// Author: Stephen Roche
// Date created: 28/03/16
// Calculates the square root of a number.

#include <stdio.h>

int main(void) {

    #define LOOPS 100

    int i;
    double n, a;

    i = 1;
    a = 1;

    printf("Enter number: ");
    scanf("%lf", &n);
   
    while (i <= LOOPS) {
        a = (a + (n / a)) / 2;
        i = i + 1;
    }

    printf ("The square root of %lf is %lf\n", n, a);

    return 0;
}
