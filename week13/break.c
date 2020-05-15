#include <stdio.h>

int main (void) {

    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d %d\n", i, j);
            if (j == 3) {
                break;
            }
        }
        if (i == 2) {
            break;
        }
    }

    return 0;
}
