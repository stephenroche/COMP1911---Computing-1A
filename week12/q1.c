#include <stdio.h>

int main (void) {
    int upper, lower;
    printf("Enter lower: ");
    scanf("%d", &lower);
    printf("Enter upper: ");
    scanf("%d", &upper);

    for (int i = lower + 1; i < upper; i++) {
        if (i % 2 == 0) {
            printf("%d %d\n", i, i*i);
        }
    }


    return 0;
}
