#include <stdio.h>

int main (void) {
    int number, remainder, i;

    printf("Enter number: ");
    scanf("%d", &number);

    remainder = number;
    i = 2;
    while (remainder != 1 && i < number) {
        if (remainder % i == 0) {
            remainder /= i;

            if (remainder == number) {
                printf("The prime factorisation of %d is:\n", number);
            }

            printf("%d ", i);

            if (remainder != 1) {
                printf("* ");
            } else {
                printf("= %d\n", number);
            }

        } else {
            i++;
        }
    }

    if (remainder == number) {
        printf("%d is prime\n", number);
    }

    return 0;
}
