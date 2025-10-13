#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ht_node {
    char* key;
    char* data;
    struct _ht_node *next;
} HashNode;

typedef struct _ht {
    HashNode** buckets;
    unsigned int num_elements;
    unsigned int bucket_count;
} HashTable;


// The 'void' here explicitly states that there are no arguments.
// Note that this is very different than 'void*';
HashTable* ht_create(void);

void ht_set(HashTable* ht, char* key, char* value);

char* ht_get(HashTable* ht, char* key);

bool ht_contains_key(HashTable* ht, char* key);

void ht_remove(HashTable* ht, char* key);
