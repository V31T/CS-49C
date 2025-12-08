#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>

#include "hash_table.h"

#define NUM_WORDS 2048
#define BUFF_SIZE 100

#define DEFAULT_WORDLIST "english.txt"
#define DEFAULT_MNEMONIC_LENGTH 12

/**
 * Loads the list of words into 2 maps.
 * nums2wors is an array of the words, allowing us to map number->word.
 * words2nums is a hashtable, allowing us to map word->number.
 */
void load_word_list(const char* file_name, char** nums2words, HashTable* words2nums) {
    //
    // **YOUR CODE HERE**
    //
    // Open the word list file and read through it line by line.
    // Be sure to strip out the trailing newline.
    //
    // Store the words in the nums2words array;
    // this will serve as a number->word look-up table for determining
    // the line number.
    //
    // Also store the words in the words2nums hashtable,
    // with the word as the key and the value set to the number.
    //
}

/**
 * Generates and prints a mnemonic as a space-separated list of words.
 */
void show_mnemonic(char** nums2words, int n) {
    //
    // **YOUR CODE HERE**
    //
    // Using the rand function, generate 12, 18, or 24 random words
    // from the nums2words list as specifice by 'n'.
    // The words should be separated by spaces.
    //
}

/**
 * Given a mapping of words to numbers and a list of mnemonic words,
 * prints out the key in hex format.  (We'll pretend that the word
 * gives us 12 bits -- the problem gets a lot uglier if we want to
 * treat it as 11 bits.)
 */
void decode_mnemonic(HashTable* words2nums, char* mnemonic_words) {
    //
    // **YOUR CODE HERE**
    //
    // Use strtok to parse the mnemonic_words string.
    // For each word, print out the corresponding 3-character hex value.
    // With printf, you can use the formatting string "%03x" to accomplish this.
    //
    // We are cheating slightly -- 3 hex characters represents 12 bits;
    // each word only represents 11 bits.
    //
}

int main(int argc, char** argv) {
    //
    // **YOUR CODE HERE**
    //
    // Use the getopt library, as we did in homework 2.
    //
    // Either the -g or the -m options should be specified, but not both.
    //
    // If the -g option is specified, load the list of mnemonic words
    // and call the show_mnemonic function.  The default number of
    // generated words is 12, though 18 or 24 could be explicitly
    // specified with the -n option; other values for the -n parameter
    // should result in an error.
    //
    // If the -m option is specified instead, load the list of mnemmonic
    // words and call the decode_mnemonic function. The -n parameter in
    // this case is ignored.
    //
    // In either case, the -f option can be used to specify an alternate
    // word file.  The default is "english.txt", but word lists in other
    // languages do exist.
    //
}

