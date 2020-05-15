#include <stdio.h>

int main (void) {
    int nums[10000];
    int i = 0;
    int j;

    while (i < 10000) {
        scanf("%d", &nums[i]);
        for (j = 0; j < i; j++) {
            if (nums[i] == nums[j]) {
                printf("Snap: %d\n", nums[i]);
                return 0;
            }
        }
        i++;
    }

    return 0;
}
