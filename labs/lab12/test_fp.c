#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int (*add_func_ptr)(int, int);

    // Note that the '&' is optional.
    add_func_ptr = &add;

    int x = (*add_func_ptr)(4, 5);
    printf("x is %d\n", x);

    int y = add_func_ptr(3, 7);
    printf("y is %d\n", y);
}
