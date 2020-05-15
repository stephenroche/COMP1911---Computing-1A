// Author: Stephen Roche
// Date created: 22/03/16
// Convert height from centimetres to feet and inches.

#include <stdio.h>

#define INCH_IN_FOOT    12
#define CM_IN_INCH      2.54

int main (void) {
    int heightCentimetres;
    int heightFeet;
    int heightInches;

    printf("Enter your height in centimetres: ");
    scanf("%d", &heightCentimetres);

    heightFeet = heightCentimetres / CM_IN_INCH / INCH_IN_FOOT;
    heightInches = (heightCentimetres - (heightFeet * CM_IN_INCH * INCH_IN_FOOT)) / CM_IN_INCH;

    printf("Your height is %d feet %d inches\n", heightFeet, heightInches);

    return 0;
}

