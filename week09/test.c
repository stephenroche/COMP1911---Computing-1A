// Author: Stephen Roche
// Date created: 03/05/16
// Test

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 128
#define MAX_LINES 1024

int notInIntArray(int nums[], int n, int x);

int main (void) {

    int input[100];

    int i = 0;
    while (i < 100 && scanf("%d", &input[i]) == 1) {
        i++;
    }
    
    int test;
    printf("Number to look for in array: ");
    scanf("%d", &test);

    int isIn = notInIntArray(input, i, test);

    if (isIn == 1) {
        printf("It's not in there.\n");
    } else {
        printf("It's in there.\n");
    }



    return 0;
}

int notInIntArray(int nums[], int n, int x) {
    
    int isNotIn = 1;
    int i = 0;
    while (i < n) {
        if (nums[i] == x) {
            isNotIn = 0;
        }

        i++;
    }

    return isNotIn;
}
