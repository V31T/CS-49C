#include <stdio.h>
#include <stdlib.h>

void decrypt(FILE *ctext_in_ptr, FILE *key_in_ptr, FILE *ptext_out_ptr) {
    int cch, kch;

    // same as encrypt, XOR with key
    while ((cch = fgetc(ctext_in_ptr)) != EOF) {
        kch = fgetc(key_in_ptr);
        if (kch == EOF) {
            fprintf(stderr, "Error: key file too short.\n");
            exit(1);
        }
        fputc(cch ^ kch, ptext_out_ptr);
    }
}


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
    FILE *ctext_in_ptr = fopen(ciphertext_filename, "r");
    FILE *key_in_ptr = fopen(key_filename, "r");
    FILE *ptext_out_ptr = (argc == 4) ? fopen(argv[3], "w") : stdout;

    if (!ctext_in_ptr) {
        fprintf(stderr, "Couldn’t open ciphertext file %s\n", ciphertext_filename);
        exit(1);
    }
    if (!key_in_ptr) {
        fprintf(stderr, "Couldn’t open key file %s\n", key_filename);
        exit(1);
    }
    if (argc == 4 && !ptext_out_ptr) {
        fprintf(stderr, "Couldn’t open output file %s\n", argv[3]);
        exit(1);
    }

    decrypt(ctext_in_ptr, key_in_ptr, ptext_out_ptr);

    fclose(ctext_in_ptr);
    fclose(key_in_ptr);
    if (ptext_out_ptr != stdout) fclose(ptext_out_ptr);
    

    return 0;
}