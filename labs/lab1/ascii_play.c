#include <stdio.h>

#define UPPER_LOWER_DIFF 32

int main() {
    int ch = 'A';

    printf("%d\n", ch);

    printf("%c\n", ch);
    printf("%c\n", ch + 3);
    printf("%c\n", ch + UPPER_LOWER_DIFF);

    printf("Sigh...  Get it out of your system."
           "%c%c%c\n", 7, 7, 7);

    return 0;
}