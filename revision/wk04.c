#include <stdio.h>

int main (void) {
    int start, finish;

    printf("Enter start year: ");
    scanf("%d", &start);
    printf("Enter finish year: ");
    scanf("%d", &finish);

    for (int i = start; i <= finish; i++) {
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
