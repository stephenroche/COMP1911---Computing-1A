#include <stdio.h>

int main (void) {
    int lower, upper, age;

    printf("Enter your age: ");
    scanf("%d", &age);

    lower = age / 2 + 7;
    upper = 2 * (age - 7);

    if (lower > upper) {
        printf("You are too young to be dating\n");
    } else {
        printf("Your dating range is %d to %d years old.\n", lower, upper);
    }

    return 0;
}
