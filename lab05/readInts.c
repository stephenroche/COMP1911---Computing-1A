#include <stdio.h>

int main (void) {

    int num;
    int returnValue;
    printf("Please enter some integers:\n");

    returnValue = scanf("%d", &num);
    int i = 0;
    while (returnValue == 1) {
        i++;
        returnValue = scanf("%d", &num);
    }

    printf("You entered %d integers\n", i);

    return 0;
}
