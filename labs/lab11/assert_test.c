#include <stdio.h>
#include <assert.h>

void fraction(int denom) {
    assert(denom != 0);
    printf("1/%d = %f\n", denom, 1.0/denom);
}

int main() {
    fraction(42);
    fraction(0);
    fraction(7);
}
