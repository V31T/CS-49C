#include <stdio.h>
#include <unistd.h>

int main() {
    int i=0;
    while (i++ < 5) {
        printf("Hi!\n");
        // Sleeping for half a second
        usleep(500000);
    }
}