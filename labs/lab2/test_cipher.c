#include <stdio.h>
#include <stdlib.h>

// Note that quotes are used for user-defined header files.
#include "caesar.h"

#define TEST_STRING "Why so serious?"

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        exit(1);
    }

    int key = atoi(argv[1]);

    char text[] = TEST_STRING;

    encrypt(key, text);
    printf("Ciphertext: %s\n", text);

    decrypt(key, text);
    printf("Plaintext: %s\n", text);
}
