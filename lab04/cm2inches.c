// Author: Stephen Roche
// Date created: 22/03/16
// Convert height from centimetres to inches.

#include <stdio.h>

#define CM_IN_INCH      2.54

int main (void) {
    int heightCentimetres;
    int heightInches;

    printf("Enter your height in centimetres: ");
    scanf("%d", &heightCentimetres);

    heightInches = heightCentimetres / CM_IN_INCH;

    printf("Your height in inches is %d\n", heightInches);

    return 0;
}

