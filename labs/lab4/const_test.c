#include <stdio.h>

int main() {
    int x = 3;
    //const int x = 3;
    // x++; // fails
    int *x_ptr;
    x_ptr = &x; // generates warning
    *x_ptr = 5; // write ignored
    printf("x=%d\n", x);
}