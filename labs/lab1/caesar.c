#include <stdio.h>
#include <stdbool.h> 
// PART2: I dont think I need to use this library since my code doesn't use 
// any boolean values
#include <string.h>
// change function parameters and is used within encrypt and decrypt

#define ALPHABET_SIZE 26
#define UPPER_LOWER_DIFF 32
#define UPPER_BOUND 65
#define LOWER_BOUND 97
#define SHIFT_KEY 13

/**
 * Encrypt the string s using the shift cipher.
 * The key should be a number between 1 and 25.
 * The length of the plaintext must be specified.
 */
void encrypt(char key, char *s) {
    //
    // ***YOUR CODE HERE***
    //
    // Iterate through the string and replace each character with the equivalent
    // ciphertext character (using the shift cipher where they shift is specified by "key").
    //
    // Shift to the **left** for encryption.
    for (int i=0; i<strlen(s); i++) {
        //check if letter
        if (s[i] >= UPPER_BOUND && s[i] < LOWER_BOUND+ALPHABET_SIZE) {
            //check if lower or upper
            if (s[i] < LOWER_BOUND) { //this is capitalized letters
                //check if go backwards for a, b, c
                int ch = s[i] - SHIFT_KEY;
                if (ch < UPPER_BOUND) {
                    ch = ch + ALPHABET_SIZE;
                }
                s[i] = ch; 
            }
            else {
                int ch = s[i] - SHIFT_KEY;
                if (ch < LOWER_BOUND) {
                    ch = ch + ALPHABET_SIZE;
                }
                s[i] = ch;
            }
        }


    }
}

/**
 * Decrypt the string s using the shift cipher.
 * The key should be a number between 1 and 25.
 * The length of the plaintext must be specified.
 */
void decrypt(char key, char *s) {
    //
    // ***YOUR CODE HERE***
    //
    // Iterate through the string and replace each character with the equivalent
    // plaintext character (using the shift cipher where they shift is specified by "key").
    //
    // Shift to the **right** for encryption.

    // just swapped `-`, `+`, `<`, and `>`
        for (int i=0; i<strlen(s); i++) {
        //check if letter
        if (s[i] >= UPPER_BOUND && s[i] < LOWER_BOUND+ALPHABET_SIZE) {
            //check if lower or upper
            if (s[i] < LOWER_BOUND) { //this is capitalized letters
                //check if go backwards for A, B, C
                int ch = s[i] + SHIFT_KEY;
                if (ch >= UPPER_BOUND +ALPHABET_SIZE) {
                    ch = ch - ALPHABET_SIZE;
                }
                s[i] = ch; 
            }
            else {
                int ch = s[i] + SHIFT_KEY;
                if (ch >= LOWER_BOUND + ALPHABET_SIZE) {
                    ch = ch - ALPHABET_SIZE;
                }
                s[i] = ch;
            }
        }


    }
}

/**
 * checks if element in string is a letter
 */
void is_letter(char c){
    //jk dont feel like doing it this way
}

/**
 * Encrypts and decrypts the plaintext, printing out the text at each step.
 * The key and the length of the plaintext must be specified.
 */
void test_encryption(char key, char* plaintext) {
    printf("Plaintext: %s\n", plaintext);

    encrypt(key,plaintext);
    printf("Ciphertext: %s\n", plaintext);

    // encrypt(key,plaintext);
    // printf("Ciphertext: %s\n", plaintext);

    decrypt(key, plaintext);
    printf("Plaintext: %s\n\n", plaintext);
}

/**
 * Main method.
 * No arguments are needed.
 */
int main(int argc, char **argv) {

    printf("EXAMPLE 1\n-----------\n");
    char came_saw_conquered[18] = "veni, vidi, vici.";
    test_encryption(3,came_saw_conquered);

    printf("EXAMPLE 2\n-----------\n");
    char test_string[27];
    int i = 0;
    char c = 'A';
    while (c <= 'Z') {
        test_string[i++] = c++;
    }
    // test_string[i] = '\0';
    test_encryption(7,test_string);

}

// PART 4 ANSWERS:

// ENCRYPTING TWICE w/ SHIFTKEY = 3 
// results in just decrypting to the output of the 
// first encryption
// OUTPUT FROM TERMINAL: 
// EXAMPLE 1
// -----------
// Plaintext: veni, vidi, vici.
// Ciphertext: sbkf, sfaf, sfzf.
// Ciphertext: pyhc, pcxc, pcwc.
// Plaintext: sbkf, sfaf, sfzf.

// EXAMPLE 2
// -----------
// Plaintext: ABCDEFGHIJKLMNOPQRSTUVWXYZ
// Ciphertext: XYZABCDEFGHIJKLMNOPQRSTUVW
// Ciphertext: UVWXYZABCDEFGHIJKLMNOPQRST
// Plaintext: XYZABCDEFGHIJKLMNOPQRSTUVW

// ENCRYPTING TWICE w/ Shiftkey = 13
// EXAMPLE 1
// -----------
// Plaintext: veni, vidi, vici.
// Ciphertext: irav, ivqv, ivpv.
// Ciphertext: veni, vidi, vici.
// Plaintext: irav, ivqv, ivpv.

// EXAMPLE 2
// -----------
// Plaintext: ABCDEFGHIJKLMNOPQRSTUVWXYZ
// Ciphertext: NOPQRSTUVWXYZABCDEFGHIJKLM
// Ciphertext: ABCDEFGHIJKLMNOPQRSTUVWXYZ
// Plaintext: NOPQRSTUVWXYZABCDEFGHIJKLM

// despite deleting the return statement the program
// still compiles and is executable

// uhm, i know getting rid of the null terminator should make my 
// code not work anymore due to strlen() relying on the null terminator 
// but despite commenting out the null terminator for example 1
// my program still compiles and executes normally. output below
// EXAMPLE 1
// -----------
// Plaintext: veni, vidi, vici.
// Ciphertext: irav, ivqv, ivpv.
// Plaintext: veni, vidi, vici.

// EXAMPLE 2
// -----------
// Plaintext: ABCDEFGHIJKLMNOPQRSTUVWXYZ
// Ciphertext: NOPQRSTUVWXYZABCDEFGHIJKLM
// Plaintext: ABCDEFGHIJKLMNOPQRSTUVWXYZ

