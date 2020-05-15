#include <stdio.h>

int main (void) {

    int array[100];
    int i = 0;

    while (scanf("%d", &array[i]) == 1 && i < 100) {
        i++;
    }

    printf("Even numbers were:");

    for (int j = 0; j < i; j++) {
        if (array[j] % 2 == 0) {
            printf(" %d", array[j]);
        }
    }

    printf("\n");

//    printf("%d\n", i);

    return 0;
}
