#define PI 3.14

// Avoiding importing stdio.  Yes, this actually works.
int printf(const char * restrict format, ... );

int main() {
    printf("Pi is %.2f.\n", PI);
}
