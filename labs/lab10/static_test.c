#include <stdio.h>

void foo() {
    int i=0;
    printf("%d\n", i);
    i++;
}

void bar() {
    static int i=0;
    printf("%d\n", i);
    i++;
}

int main() {
    foo();
    foo();
    foo();
    foo();

    bar();
    bar();
    bar();
    bar();
}
