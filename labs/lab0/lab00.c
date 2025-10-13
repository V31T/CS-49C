#include <stdio.h>

#define MAX_POSSIBLE_PRIME 100

/**
 * Initializes the primes array to set every entry to its index.
 */
void initialize_array(int primes[]) {
    for (int i=0; i<MAX_POSSIBLE_PRIME; i++) {
        primes[i] = i;
    }
}

/**
 * Print out the primes array delimited by spaces.
 * A value of "0" indicates that this position is not a prime number
 * and the entry won't be printed.
 */
void print_primes(int *primes) {
    for (int i=0; i<MAX_POSSIBLE_PRIME; i++) {
        if (primes[i] > 0) {
            printf("%i ", primes[i]);
        }
    }
    printf("\n");
}

int main(int argc, char **argv) {

    int primes[MAX_POSSIBLE_PRIME];

    initialize_array(primes);

    //
    // **YOUR CODE HERE**
    //
    // go through the array and set all of the non-primes to 0
    // following the Sieve of Eratosthenes algorithm.
    // (See https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes).
    //
    // In short, first zero-out all factors of 2 (except 2 itself),
    // then zero-out all factors of 3, then zero-out all factors
    // of 5, and so on until you have gotten to MAX_POSSIBLE_PRIME.
    //
    // It might be helpful to have a couple of helper functions.
    // The two existing helper functions show you the 2 different
    // ways to pass an array in C.
	for (int i=2; i<MAX_POSSIBLE_PRIME/2; i++) {
		for (int j = i + 1; j < MAX_POSSIBLE_PRIME; j++) {
			if (primes[j] % i == 0) {
				primes[j] = 0;
			}
		}
        
	}

    print_primes(primes);

    return 0;
}
