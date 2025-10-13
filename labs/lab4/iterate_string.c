#include <stdio.h>

int main() {
    char s[] = "hello";

    char *c_ptr = s;
    while (*c_ptr != '\0') {
        printf("%c", *c_ptr);
        c_ptr++;
    }
    printf("\n");
}
