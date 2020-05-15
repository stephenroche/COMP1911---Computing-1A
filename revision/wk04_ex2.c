#include <stdio.h>

int main (void) {
    int height, feet, inches;

    printf("Enter your height in centimetres: ");
    scanf("%d", &height);

    feet = height / (2.54 * 12);
    inches = (height - feet * (2.54 * 12)) / 2.54;

    printf("Your height is %d feet %d inches.\n", feet, inches);

    return 0;
}
