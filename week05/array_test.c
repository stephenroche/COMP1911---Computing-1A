#include <stdio.h>

int main (void) {

    int i;
    i = 0;
    int array[3];

    while (i < 4) {
        array[i] = i + 1;
        i = i + 1;
    }

    i = 0;
    while (i < 3) {
        printf("%d\n", array[i]);
        i = i + 1;
    }


    return 0;
}
