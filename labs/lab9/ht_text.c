#include <stdio.h>

#include "hash_table.h"

int main() {
    HashTable* ht = ht_create();

    ht_set(ht, "a", "alfa");
    ht_set(ht, "b", "bravo");
    ht_set(ht, "c", "charlie");
    ht_set(ht, "d", "delta");
    ht_set(ht, "e", "echo");
    ht_set(ht, "f", "foxtrot");
    ht_set(ht, "g", "golf");
    ht_set(ht, "h", "hotel");
    ht_set(ht, "i", "india");
    ht_set(ht, "k", "kilo");
    ht_set(ht, "l", "lima");
    ht_set(ht, "m", "mike");
    ht_set(ht, "n", "november");
    ht_set(ht, "o", "oscar");
    ht_set(ht, "p", "papa");
    ht_set(ht, "q", "quebec");
    ht_set(ht, "r", "romeo");
    ht_set(ht, "s", "sierra");
    ht_set(ht, "t", "tango");
    ht_set(ht, "u", "uniform");
    ht_set(ht, "v", "victor");
    ht_set(ht, "w", "whiskey");
    ht_set(ht, "x", "x-ray");
    ht_set(ht, "y", "yankee");
    ht_set(ht, "z", "zulu");

    char* s = ht_get(ht, "a");
    printf("%s\n", s);
    s = ht_get(ht, "b");
    printf("%s\n", s);
    s = ht_get(ht, "c");
    printf("%s\n", s);
    s = ht_get(ht, "z");
    printf("%s\n", s);
}