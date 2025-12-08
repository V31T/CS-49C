#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "hash_table.h"

#define BUFF_SIZE 256

#define DELIM " -;,.!?_\n\\[]()\"\'"

#define MIN_COUNT 1

#define TOTAL_COUNT_KEY "TOTAL_COUNT_KEY"

void update_hash(HashTable* word_counts, char* word) {
    //
    // **YOUR CODE HERE**
    //
    // When updating the word counts, you need to account for data that
    // has not yet been seen.  This process is called "smoothing".
    //
    // For simplicity, we'll use plus one smoothing.  In this approach,
    // we add 1 to the count of words for every word.  To make the math
    // work out, we add the vocabulary size (that is, the total number of
    // unique words that we have found) to our total count.
    //
    // What this means in your code:
    //
    // 1) If the word is already in word_counts, increase the count for that word by 1.
    //
    // 2) If the word is _not_ in word_counts:
    //  a. Set the count for that word to '2' (1 for the word found, and 1 for the smoothing).
    //  b. Increase the count of total words by 1 (in addition to the +1 from the load_corpus function).
}

HashTable* load_corpus(char* file_name) {
    HashTable* ht = ht_create();
    FILE* f = fopen(file_name, "r");
    assert(f != NULL);

    char line[BUFF_SIZE];

    // Setting the total count of words to 0 initially.
    // Note that we are storing this value in the HashTable itself.
    ht_set(ht, TOTAL_COUNT_KEY, 0);

    //
    // **YOUR CODE HERE**
    //
    // Similar to the password breaking lab, you should read this file in line by line
    // and tokenize each line using strtok. (Use the DELIM constant -- you can update it
    // if I missed any punctuation that shows up in the texts.)
    //
    // For each word found, call update_hash to update the count of that word.
    // You will need to implement that function.
    //
    // Also, increment the total count of words by 1.  We are storing this count in
    // the Hashtable with the key of "TOTAL_COUNT_KEY".
    //

    fclose(f);
    return ht;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <corpus_file> <word>\n", argv[0]);
        exit(1);
    }

    char* corpus_file_name = argv[1];
    char* word = argv[2];

    HashTable* ht = load_corpus(corpus_file_name);

    unsigned int count = ht_get(ht, word);
    if (count == 0) count = MIN_COUNT;

    double total_count = (double) ht_get(ht, TOTAL_COUNT_KEY);

    double word_freq = count / total_count;

    printf("The (smoothed) frequency of %s in %f\n", word, word_freq);

    return 0;
}
