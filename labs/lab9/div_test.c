#include <stdio.h>

int main() {
    int x = 3;
    int y = 4;

    double d = x / y;
    printf("%f\n", d);

    d = (double) x / y;
    printf("%f\n", d);
}
