// Author: Stephen Roche
// Date created: 08/04/16
// Prints min, max and mean of a list.

#include <stdio.h>

int main (void) {

    #define NUMS 10
    int numbers[NUMS];
    int i, max, min, scan, total;
    double avg;
    scan = 1;

    printf("Enter vector of %d numbers: ", NUMS);

    i = 0;
    while ((i < NUMS) && (scan == 1)) {
        scan = (scanf("%d", &numbers[i]));
        i = i + 1;
    }

    if (scan != 1) {
        printf("Sorry I couldn't read enough numbers\n");
        return 0;
    }

    i = 1;
    min = numbers[0];
    max = numbers[0];
    total = numbers[0];
    while (i < NUMS) {
        if (numbers[i] < min) {
            min = numbers [i];
        }
        if (numbers[i] > max) {
            max = numbers [i];
        }
        total = total + numbers[i];
        i = i + 1;
    }

    avg = total * 1.0 / NUMS;

    printf("Minimum vector value is %d\n", min);
    printf("Maximum vector value is %d\n", max);
    printf("Average vector value is %.1f\n", avg);


    return 0;
}
