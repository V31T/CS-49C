#include <stdio.h>

#define NDEBUG

#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n",\
        __FILE__, __LINE__, ##__VA_ARGS__)
#endif


int main() {
    debug("Starting program in %d, %d, %d, %d.", 4, 3, 2, 1);
    printf("Hello, world!\n");
    debug("Program completed.");
}
