#include <stdio.h>
#include <string.h>

int main(void) {

    char array[100] = "Hello\n";

//    scanf("%s", array);

    int i = strlen(array);

    if (array[i - 1] == '\n') {
        printf("!!!\n");
    }

    if (array[i] == '\0') {
        printf("***\n");
    }

    printf("%s*\n", array);

    return 0;
}

