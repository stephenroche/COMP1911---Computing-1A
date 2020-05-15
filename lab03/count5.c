    // Stephen Roche
    // Counting to 5

#include <stdio.h>

int main(void) {
    int testInteger;
    printf("Please enter an integer:\n");
    scanf("%d", &testInteger);
    
    printf("You entered:\n");

    if (testInteger == 1) {
        printf ("one\n");
    } else if (testInteger == 2) {
        printf ("two\n");
    } else if (testInteger == 3) {
        printf ("three\n");
    } else if (testInteger == 4) {
        printf ("four\n");
    } else if (testInteger == 5) {
        printf ("five\n");
    } else if (testInteger < 1) {
        printf ("a number less than one\n");
    } else {
        printf ("a number greater than five\n");
    }

    return 0;
}
