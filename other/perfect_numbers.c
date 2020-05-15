// Author: Stephen Roche
// Date created: 30/03/16
// Prints factors of a number and indicates if it is perfect.

#include <stdio.h>
#define MAX 100000

int main(void) {
    int number, sumFactors, i;
    i = 1;
    sumFactors = 0;
    number = 1;

    while (number <= MAX) {
        while (i < number) {
            if ((number % i) == 0) {
                sumFactors = sumFactors + i;
            }
            i = i + 1;
        }
        i = 1;
        if (sumFactors == number) {
            printf("%d\n", number);
        }
        sumFactors = 0;
        number = number + 1;
    }

    return 0;
}
