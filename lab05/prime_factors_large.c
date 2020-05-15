// Author: Stephen Roche
// Date created: 30/03/16
// Prints the prime factorisation of a number.

#include <stdio.h>

int main(void) {
    long long number, i, remainder, test;
    int j, root, composite;
    i = 2;

    printf("Enter number: ");
    scanf("%lld", &number);
    remainder = number;

    test = number;
    j = 0;
    root = 1;
    composite = 0;

    while (test >= 10) {
        test = test / 10;
        j = j + 1;
    }
    j = (j + 2) / 2;
    while (j > 0) {    
        root = root * 10;
        j = j - 1;
    }

    while ((i <= remainder) && ((composite == 1) || (i < root)) && (i < number)) {
        if ((remainder % i) == 0) {
            if (remainder == number) {

// i.e. If this is the first factor

                printf("The prime factorization of %lld is:\n", number);
                composite = 1;
            }
            printf("%lld ", i);
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
        printf("= %lld\n", number);
    } else {
        printf("%lld is prime\n", number);
    }

    return 0;
}
