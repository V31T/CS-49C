#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_NUM_LINES 10
#define BUFFER_LENGTH 256

int main(int argc, char** argv) {
    if (argc < 2) {
        goto usage;
    }

    int num_lines = DEFAULT_NUM_LINES;

    //
    // **YOUR CODE HERE**
    //

    return 0;

usage:
    fprintf(stderr, "Usage: %s [-n <count>] file ...\n", argv[0]);
    return 1;
}

