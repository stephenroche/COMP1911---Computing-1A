// Author: Stephen Roche
// Date created: 30/03/16
// Prints factors of a number and indicates if it is perfect.

#include <stdio.h>

int main(void) {
    int number, sumFactors, i;
    i = 1;
    sumFactors = 0;

    printf("Enter number: ");
    scanf("%d", &number);
    printf("The factors of %d are:\n", number);

    while (i <= number) {
        if ((number % i) == 0) {
            printf("%d\n", i);
            sumFactors = sumFactors + i;
        }
        i = i + 1;
    }

    printf("Sum of factors = %d\n", sumFactors);
    if (sumFactors == (2 * number)) {
        printf("%d is a perfect number\n", number);
    } else {
        printf("%d is not a perfect number\n", number);
    }

    return 0;
}
