#include <stdint.h>
#include <stdio.h>

uint32_t delta = 0x4e3679e6;

/*
 * This function should take in 64-bits of plaintext and a 128 bit key.
 * It should encrypt the text in place.  Note that text[0] is the left 32
 * bits of the plaintext and text[1] is the right 32 bits of plaintext.
 * Also, note that the key is stored in 4 32-bit blocks.
 */
void encrypt(uint32_t* text, uint32_t* key) {
    //
    // **YOUR CODE HERE**
    //
    // Follow the encryption formula from the slides.
    //
}

/*
 * This function should take in 64-bits of ciphertext and a 128 bit key.
 * It should decrypt the text in place.
 */
void decrypt(uint32_t* text, uint32_t* key) {
    //
    // **YOUR CODE HERE**
    //
    // Follow the decryption formula from the slides.
    //
}

/*
 * Utility function to print your results.
 */
void print_arr (uint32_t* arr, int size) {
    int i;
    for (i=0; i<size; i++) {
        printf("%02X ", arr[i]);
    }
    printf("\n");
}

/*
 * This function encrypts several blocks with the espresso cipher,
 * using electronic codebook mode (ECB).
 */
void ecb_mode_test() {
    int i;
    uint32_t key[] = {0x7e7a9cb4, 0x89a201f3, 0x14d6fed4, 0xbe21afea};

    // Each line represents one block (2 half blocks).
    // Note that the 1st and 2nd blocks are identical.
    uint32_t text[] = { 0x9e4587e3, 0xe49383a2,
                        0x9e4587e3, 0xe49383a2,
                        0xe1432902, 0xbe790210,
                        0xa39ffe11, 0x93333276,
                        0x21247348, 0x85956106,
                        0x169f5ea6, 0xdb8a7137 };

    int count_half_blocks = sizeof(text) / sizeof(uint32_t);

    printf("(ECB) plaintext = ");
    print_arr(text, count_half_blocks);

    // Note that we iterate by += 2, since the array represents pairs of
    // half blocks; in other words, text+i points to the left half of the
    // block and text+1+1 points to the right half of the block.
    for (i=0; i<count_half_blocks; i+=2) {
        encrypt(text+i, key);
    }

    printf("(ECB) ciphertext= ");
    print_arr(text, count_half_blocks);

    // Using i+=2 again.
    for (i=0; i<count_half_blocks; i+=2) {
        decrypt(text+i, key);
    }

    printf("(ECB) plaintext = ");
    print_arr(text, count_half_blocks);
}

/*
 * This function (when you make your changes) should encrypt several blocks
 * using the espresso cipher, but in cipher block chaining (CBC) mode.
 *
 * Use the same encrypt and decrypt functions as ECB mode.
 */
void cbc_mode_test() {
    int i;
    uint32_t key[] = {0x7e7a9cb4, 0x89a201f3, 0x14d6fed4, 0xbe21afea};

    uint32_t text[] = { 0x9e4587e3, 0xe49383a2,
                        0x9e4587e3, 0xe49383a2,
                        0xe1432902, 0xbe790210,
                        0xa39ffe11, 0x93333276,
                        0x21247348, 0x85956106,
                        0x169f5ea6, 0xdb8a7137 };

    int count_half_blocks = sizeof(text) / sizeof(uint32_t);

    /* XOR (the ^ operator in C) these values with the first two half-blocks of your plaintext */
    uint32_t iv[] = { 0x74f78c88, 0x8d8844a1 };

    printf("(CBC) plaintext = ");
    print_arr(text, count_half_blocks);

    //
    // **YOUR CODE HERE**
    //
    // Follow the formula for CBC mode encryption.
    // Remember to xor the first two half-blocks with the IV.
    //

    printf("(CBC) ciphertext= ");
    print_arr(text, count_half_blocks);

    //
    // **YOUR CODE HERE**
    //
    // Follow the formula for CBC mode decryption.
    // Remember to xor the first two half-blocks with the IV
    // in order to remove it.
    //

    printf("(CBC) plaintext = ");
    print_arr(text, count_half_blocks);
}

/*
 * This function (when you make your changes) should encrypt several blocks
 * using the espresso cipher, but in counter (CTR) mode.
 *
 * Use the same encrypt function as ECB mode.
 *
 * You will not need the decrypt function.
 */
void ctr_mode_test() {
    //
    // **YOUR CODE HERE**
    //
    // Implement CTR mode following the formula given in the slides.
    // You can use the previous two functions as templates.
    //
}


int main(int argc, const char* argv[]) {
    printf("\nECB mode test\n");
    ecb_mode_test();

    printf("\nCBC mode test\n");
    cbc_mode_test();

    printf("\nCTR mode test\n");
    ctr_mode_test();

    return 0;
}


