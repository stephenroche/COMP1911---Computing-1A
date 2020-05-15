    // Stephen Roche
    // prism

#include <stdio.h>

int main(void) {
    int length, width, height, volume, area, edgeLength;
    printf("Please enter prism length: ");
    scanf("%d", &length);
    printf("Please enter prism height: ");
    scanf("%d", &width);
    printf("Please enter prism height: ");
    scanf("%d", &height);

    volume = length * width * height;
    area = 2 * (length * width + length * height + width * height);
    edgeLength = 4 * (length + width + height);

    printf("A prism with sides %d %d %d has:\n", length, width, height);    
    printf("Volume      = %d\n", volume);
    printf("Area        = %d\n", area);
    printf("Edge length = %d\n", edgeLength);

    return 0;
}
