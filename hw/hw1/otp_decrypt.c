#include <stdio.h>
#include <stdlib.h>

/**
 * Main method.
 */
int main(int argc, char **argv) {

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <in:ciphertext_filename> <in:key_filename> (<out:plaintext_filename>)\n", argv[0]);
        exit(1);
    }

    char *ciphertext_filename = argv[1];
    char *key_filename = argv[2];

    //
    // **YOUR CODE HERE**
    //
    // If there is a third argument specified (that is, argv[3]), write the
    // decrypted plaintext to that file.  Otherwise, write the plaintext to
    // stdout instead.
    //
    // To decrypt the file, read byte at a time from both the ciphertext file
    // and the key file.  XOR those bytes together to get the plaintext
    // character.  If the key is too short, print a message to stderr and
    // terminate the program.
    //
    // Note that decryption is very similar to encryption, so you may pattern
    // your decryption approach after your encryption solution.

    return 0;
}