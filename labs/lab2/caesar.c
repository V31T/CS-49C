#include "caesar.h"

#define ALPHABET_SIZE 26

/**
 * Returns true if the input character is an alphabetic character.
 */
bool is_valid_character(char c) {
    if (c >= 'A' && c <= 'Z') {
        return true;
    } else if (c >= 'a' && c <= 'z') {
        return true;
    } else {
        return false;
    }
}

/**
 * Returns true if c is a lowercase character.
 */
bool is_lowercase(char c) {
    return c >= 'a' && c <= 'z';
}

/**
 * Encrypt the string s using the shift cipher.
 * The key should be a number between 1 and 25.
 */
void encrypt(char key, char *s) {
    int len = strlen(s);
    int i=0;
    for (int i=0; i<len; i++) {
        if (!is_valid_character(s[i])) continue;

        // Lowercase letters may need special handling.
        bool ptext_is_lowercase = is_lowercase(s[i]);

        s[i] -= key;

        // If the encryption wrapped around, we need to add 26 to the ciphertext.
        if (!is_valid_character(s[i])) {
            s[i] += ALPHABET_SIZE;
        } else if (ptext_is_lowercase && !is_lowercase(s[i])) {
            s[i] += ALPHABET_SIZE;
        }
    }
}

/**
 * Decrypt the string s using the shift cipher.
 * The key should be a number between 1 and 25.
 */
void decrypt(char key, char *s) {
    int len = strlen(s);
    int i=0;
    for (int i=0; i<len; i++) {
        if (!is_valid_character(s[i])) continue;
        s[i] += key;
        if (!is_valid_character(s[i])) {
            s[i] -= ALPHABET_SIZE;
        }
    }
}

