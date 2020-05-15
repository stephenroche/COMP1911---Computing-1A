// Author: anonymous
// Date created: ?
// Convert height from centimetres to feet.

#include <stdio.h>

#define INCHES_IN_FOOT  12
#define CM_IN_INCH      2.54

int main (void) {
    int heightCentimetres;
    int heightFeet;

    printf("Enter your height in centimetres: ");
    scanf("%d", &heightCentimetres);

    heightFeet = (heightCentimetres / CM_IN_INCH) / INCHES_IN_FOOT;

    printf("Your height in feet is %d\n", heightFeet);

    return 0;
}

