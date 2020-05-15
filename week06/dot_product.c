#include <stdio.h>

int main (void) {

    #define LENGTH 6
    int v1[LENGTH];
    int v2[LENGTH];
    int i;
    int dotProduct = 0;

    printf("Enter vector 1 of %d integers: ", LENGTH);
    
    i = 0;
    while (i < LENGTH) {
        scanf("%d", &v1[i]);
        i = i + 1;
    }

    printf("Enter vector 2 of %d integers: ", LENGTH);
    
    i = 0;
    while (i < LENGTH) {
        scanf("%d", &v2[i]);
        i = i + 1;
    }

    i = 0;
    while (i < LENGTH) {
        dotProduct = dotProduct + (v1[i] * v2[i]);
        i = i + 1;
    }

    printf("Their dot-product is %d\n", dotProduct);

    return 0;
}
