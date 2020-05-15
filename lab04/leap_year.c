// Author: Stephen Roche
// Date created: 22/03/16
// Prints all leap years between a year range.

#include <stdio.h>

int main(void) {
    int i, startYear, finishYear;

    printf("Enter start year: ");
    scanf("%d", &startYear);
    printf("Enter finish year: ");
    scanf("%d", &finishYear);

    i = startYear;

// A leap year must be:
// A multiple of 4,
// NOT a multiple of 100, unless it is a multiple of 400

    while (i <= finishYear) {
        if ((i % 4 == 0) && ((i % 100 != 0) || (i % 400 == 0))) {
            printf("%d\n", i);
        }
        i = i + 1;
    }

    return 0;
}
