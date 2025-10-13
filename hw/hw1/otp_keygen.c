#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * WARNING!!!!!!
 * THIS IS A **BAD** KEYGEN IMPLEMENTATION.
 *
 * This function is designed to (poorly) generate a random
 * key file for use in a one-time pad.  The size of the key
 * (in bytes) and the name of the file must be specified
 *
 * However, it does **not** used cryptographic-quality random
 * numbers, meaning that a clever attacker might be able to
 * deduce the key.
 */
void generate_key(int num_bytes, char *key_filename) {

    FILE *key_out_ptr = fopen(key_filename, "wb");

    // Setting the seed for the randomization.
    srand(time(NULL));

    for (int i=0; i<num_bytes; i++) {
        // Trimming the random value to a single byte
        int key_byte = rand();
        fputc(key_byte, key_out_ptr);
    }

    fclose(key_out_ptr);
}


/**
 * Main method.
 * No arguments are needed.
 */
int main(int argc, char **argv) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <size> <key_filename>\n", argv[0]);
    }

    int key_size = atoi(argv[1]);
    char *key_filename = argv[2];

    generate_key(key_size, key_filename);

    return 0;
}
