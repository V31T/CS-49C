#include <stdio.h>

#include "hash_table.h"

int main() {
    HashTable* ht = ht_create();

    char* key = "hello";
    char* val = "there";

    ht_set(ht, key, val);
    char* v = ht_get(ht, key);
    printf("%s=%s\n", key, v);

    ht_set(ht, key, "world");
    v = ht_get(ht, key);
    printf("%s=%s\n", key, v);

    if (ht_contains_key(ht, "hello")) printf("hi\n");
    if (ht_contains_key(ht, "goodbye")) printf("bye\n");

    ht_remove(ht, "hello");
    if (ht_contains_key(ht, "hello")) printf("hi again\n");

}
