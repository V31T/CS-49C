#include <stdio.h>
#include <stdlib.h>

/**
 * Encrypt the plaintext file (ptext_in_ptr) with the key file (key_in_ptr)
 * and write the result to the ciphertext file (ctext_out_ptr).
 */
void encrypt(FILE *ptext_in_ptr, FILE *key_in_ptr, FILE *ctext_out_ptr) {
    //
    // **YOUR CODE HERE**
    //
    // Read through the plaintext file and the key file character by character.
    // XOR them together to get the ciphertext, which you should write to the
    // ciphertext file.
    //
    // If the key length is too short for the message, terminate the program
    // with an error.
    //
    // You might find the functions fgetc and fputc helpful.
    //
}


/**
 * Main method.
 */
int main(int argc, char **argv) {

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <in:plaintext_filename> <in:key_filename> <out:ciphertext_filename>\n", argv[0]);
        exit(1);
    }

    char *plaintext_filename = argv[1];
    char *key_filename = argv[2];
    char *ciphertext_filename = argv[3];

    // Open the plaintext file and the key file for reading.
    FILE *ptext_in_ptr = fopen(plaintext_filename, "r");
    FILE *key_in_ptr = fopen(key_filename, "r");

    // Test that both files exist.
    if (ptext_in_ptr == NULL) {
        fprintf(stderr, "Plaintext file %s could not be opened.\n", plaintext_filename);
        exit(1);
    }
    if (key_in_ptr == NULL) {
        fprintf(stderr, "Key file %s could not be opened.\n", key_filename);
        exit(1);
    }

    // Open ciphertext file for writing.
    FILE *ctext_out_ptr = fopen(ciphertext_filename, "w");

    encrypt(ptext_in_ptr, key_in_ptr, ctext_out_ptr);


    // Close files.
    fclose(ptext_in_ptr);
    fclose(key_in_ptr);
    fclose(ctext_out_ptr);

    return 0;
}
