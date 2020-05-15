// Author: Stephen Roche
// Date created: 30/03/16
// Prints the prime factorisation of a number.

#include <stdio.h>

int main(void) {
    int number, i, remainder;
    i = 2;

    printf("Enter number: ");
    scanf("%d", &number);
    remainder = number;
    
    while ((i <= remainder) && (i < number)) {
        if ((remainder % i) == 0) {
            if (remainder == number) {

// i.e. If this is the first factor

                printf("The prime factorization of %d is:\n", number);
            }
            printf("%d ", i);
            if (remainder != i) {

// i.e. If this is not the last factor

                printf("* ");
            }
            remainder = remainder / i;
            
        } else {
            i = i + 1;
        }
    }

    if (remainder != number) {
        printf("= %d\n", number);
    } else {
        printf("%d is prime\n", number);
    }

    return 0;
}
