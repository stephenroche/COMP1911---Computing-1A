    // Stephen Roche
    // Dating Age Ranges

#include <stdio.h>

int main(void) {
    int age, minAge, maxAge;
    printf("Enter your age: ");
    scanf("%d", &age);

    minAge = age / 2 + 7;
    maxAge = (age - 7) * 2;

    if (minAge > maxAge) {
        printf("You are too young to be dating.\n");
    } else {
        printf("Your dating range is %d to %d years old.\n", minAge, maxAge);
    }

    return 0;
}
