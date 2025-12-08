#include <stdio.h>

#define MAX_POSSIBLE_PRIME 100

void initialize_array(int *primes) {
    for (int i=0; i<MAX_POSSIBLE_PRIME; i++) {
        primes[i] = i;
    }
}

void print_primes(int *primes) {
    for (int i=0; i<MAX_POSSIBLE_PRIME; i++) {
        if (primes[i] > 0) {
            printf("%i ", primes[i]);
        }
    }
}

void filter_nonprimes(int factor, int *primes) {
    int n = factor;
    do {
        n += factor;
        primes[n] = 0;
    } while (n < MAX_POSSIBLE_PRIME);
}

int get_next_prime(int factor, int *primes) {
    do {
        factor++;
    } while (primes[factor] == 0 && factor < MAX_POSSIBLE_PRIME);
    return factor;
}

int main(int argc, char **argv) {

    int primes[MAX_POSSIBLE_PRIME];

    initialize_array(primes);

    int p = 2;

    while (p*p < MAX_POSSIBLE_PRIME) {
        filter_nonprimes(p, primes);
        p = get_next_prime(p, primes);
    }

    print_primes(primes);
    printf("Primes printed.\n");

    return 0;
}
