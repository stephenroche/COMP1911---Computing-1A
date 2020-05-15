// Author: Stephen Roche
// Date created: 22/03/16
// Prints all fibonacci numbers between a given range.

#include <stdio.h>

int main(void) {
    int i, start, finish;
    double a, b, store, r;

    a = 1;
    b = 0;
    store = 0;
    r = 1;    

    printf("Enter start term: ");
    scanf("%d", &start);
    printf("Enter finish term: ");
    scanf("%d", &finish);

    i = 1;

    while (i <= finish) {
        if (i >= start) {
            printf("%d: %.0lf   %.20lf\n", i, a, r);
        }
        store = a;
        a = a + b;
        b = store;
        r = a / b;

        i = i + 1;
    }

    return 0;
}
