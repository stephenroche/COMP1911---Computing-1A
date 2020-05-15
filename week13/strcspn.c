#include <stdio.h>
#include <string.h>

int main(void) {

    char array[] = "Hello\n";
    char array2[] = "Hi!";
    char array3[100];
    strcpy(array3, array);

    printf("strlen: %d\n", strlen(array));

    printf("strcat: %s*\n", &strcat(array3, array2)[1]);

    printf("strncmp: %d\n", strncmp(array2, array, 1));

    printf("strchr: %c\n", strchr(array, 'l')[-1]);

    printf("strrchr: %c\n", strrchr(array, 'l')[1]);

    printf("strstr: %c\n", strstr(array, "el")[-1]);

    printf("strpbrk: %c\n", strpbrk(array, "Balloon\n")[-1]);

    printf("strspn: %d\n", strspn(array, "erbgelH"));

    printf("strcspn: %d\n", strcspn(array, "hi!\n"));

    return 0;
}
