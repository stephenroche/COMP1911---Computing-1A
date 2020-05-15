#include <stdio.h>
#include <ctype.h>

#define LEN 4096

int main(void) {

    char string[LEN + 2], palin[LEN + 2];
    int i, j, isPalindrome;

    printf("Enter a string: ");
    fgets(string, LEN, stdin);

    i = 0;
    j = 0;
    while (string[i] != '\0') {
        if (isalpha(string[i]) != 0) {
            palin[j] = tolower(string[i]);
            j++;
        }
        i++;
    }
    j--;

    isPalindrome = 1;

    for (i = 0; i < j; i++) {
        if (palin[i] != palin[j - i]) {
            isPalindrome = 0;
        }
    }

    if (isPalindrome == 1) {
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    }

    return 0;
}
