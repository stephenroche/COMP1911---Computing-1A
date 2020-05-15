#include <stdio.h>

int main (void) {

    int nums, i, j, store;
    int array[100];
    i = 0;
    j = 1;

    printf("Enter numbers, finish with a letter:\n");
    while (j == 1) {
        j = scanf("%d ", &array[i]);
        i = i + 1;
    }
    nums = i - 1;
    i = 0;
    j = 0;

    while (i < nums) {
        while (j < (nums - 1)) {
            if (array[j + 1] > array[j]) {
                store = array[j];
                array[j] = array[j + 1];
                array[j + 1] = store;
            }
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
    i = 0;

    printf("Largest:\n");
    while (i < nums) {
        printf("%2d: %d\n", i + 1, array[i]);
        i = i + 1;
    }
    printf("Smallest\n");

    return 0;
}
