// Author: Stephen Roche
// Date created: 22/03/16
// Sorts three integers from largest to smallest.

#include <stdio.h>

int main(void) {
    int integerOne;
    int integerTwo;
    int integerThree;

    printf("Please enter three integers:\n");
    scanf("%d %d %d", &integerOne, &integerTwo, &integerThree);

    printf("Your integers after sorting:\n");

    if ((integerOne >= integerTwo) && (integerOne >= integerThree)) {
        printf ("%d " , integerOne);
        if (integerTwo >= integerThree) {
            printf ("%d %d\n" , integerTwo, integerThree);
        } else {
            printf ("%d %d\n" , integerThree, integerTwo);
        }
    } else if ((integerTwo >= integerOne) && (integerTwo >= integerThree)) {
        printf ("%d " , integerTwo);
        if (integerOne >= integerThree) {
            printf ("%d %d\n" , integerOne, integerThree);
        } else {
            printf ("%d %d\n" , integerThree, integerOne);
        }
    } else {
        printf ("%d " , integerThree);
        if (integerOne >= integerTwo) {
            printf ("%d %d\n" , integerOne, integerTwo);
        } else {
            printf ("%d %d\n" , integerTwo, integerOne);
        }

    }

    return 0;
}
