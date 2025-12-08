#include <stdio.h>

union Number {
    int i;
    float f;
};


int main() {
    union Number n;

    n.i = 42;
    printf("%d\n", n.i);

    n.f = 3.14;
    printf("%f\n", n.f);
    printf("%d\n", n.i);

}

