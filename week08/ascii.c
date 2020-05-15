#include <stdio.h>

int main(void) {
    int ascii;
    ascii = 0;
    while (ascii < 128) {
        printf("In ASCII %d prints as %c\n", ascii, ascii);
        ascii = ascii + 1;
    }
    return 0;
}
