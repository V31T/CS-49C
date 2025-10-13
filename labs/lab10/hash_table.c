#include <stdio.h>

#include "hash_table.h"

#define INIT_HASH_SIZE 100000

#define LOAD_FACTOR 0.75

/**
 * SDBM Hash.
 * Taken from Google.
 */
unsigned long hash(HashTable* ht, char* key) {
    unsigned long hash = 0;
    int c;
    while ((c = *key++)) {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash % ht->bucket_count;
}

/**
 * Creates a new node.  For simplicity, we use 'char*'
 * for the data type; we saw last class how to make the
 * value type more generic, at the cost of usability.
 */
HashNode* new_node(char* key, char* data) {
    HashNode *n = (HashNode*) malloc(sizeof(HashNode));
    n->key = strdup(key);
    n->data = strdup(data);
    n->next = NULL;
    return n;
}

/**
 * Frees the memory allocated for this node.
 */
void delete_node(HashNode* n) {
    free(n->key);
    free(n->data);
    free(n);
}

/**
 * Note that this is a 'private' helper function.
 * Returns the first element in the list that matches
 * the key, or NULL if there are no matches.
 */
HashNode* find_in_list(HashNode* n, char* key) {
    while (n != NULL) {
        if (strcmp(n->key, key) == 0) {
            return n;
        }
        n = n->next;
    }

    return NULL;
}

/**
 * Creates a new hash table, allocating the necessary space.
 */
HashTable* ht_create() {
    HashTable* ht = (HashTable*) malloc(sizeof(HashTable));
    ht->num_elements = 0;
    ht->bucket_count = INIT_HASH_SIZE;
    ht->buckets = (HashNode**) calloc(ht->bucket_count, sizeof(HashNode));
    return ht;
}

void resize_if_needed(HashTable* ht) {
    if ((float)ht->num_elements / ht->bucket_count < LOAD_FACTOR) {
        // No need to resize.
        return;
    }

    //printf("Time to resize...\n");
    unsigned old_bucket_count = ht->bucket_count;
    HashNode** old_buckets = ht->buckets;

    ht->bucket_count *= 2;
    ht->buckets = (HashNode**) calloc(ht->bucket_count, sizeof(HashNode));

    for (int i=0; i<old_bucket_count; i++) {
        HashNode* n = old_buckets[i];
        while (n != NULL) {
            // Storing the next node for iteration.
            HashNode* next = n->next;
            unsigned hv = hash(ht, n->key);
            n->next = ht->buckets[hv];
            //printf("Re-adding %s:%s to bucket %u\n", n->key, n->data, hv);
            ht->buckets[hv] = n;
            n = next;
        }
    }

    // Free the memory for the old buckets.
    free(old_buckets);
}

/**
 * If the key is already in the hash table, this function
 * updates the value associated with that key.  Otherwise,
 * it creates a new node w/ the key/value in the hash table.
 */
void ht_set(HashTable* ht, char* key, char* value) {
    unsigned hv = hash(ht, key);
    //printf("Adding %s:%s to bucket %u\n", key, value, hv);
    HashNode* head = ht->buckets[hv];
    HashNode* n = find_in_list(head, key);
    if (n == NULL) {
        // New element
        n = new_node(key, value);
        n->next = ht->buckets[hv];
        ht->buckets[hv] = n;
        ht->num_elements++;
        resize_if_needed(ht);
    } else {
        // Update
        free(n->data);
        n->data = strdup(value);
    }
}

/**
 * Returns the value matching the key in the hash table,
 * or NULL if there is no matching value.
 */
char* ht_get(HashTable* ht, char* key) {
    unsigned hv = hash(ht, key);
    HashNode* head = ht->buckets[hv];
    HashNode* n = find_in_list(head, key);
    if (n == NULL) {
        return NULL;
    } else {
        return n->data;
    }
}

/**
 * Returns true if the key is in the hash table.
 */
bool ht_contains_key(HashTable* ht, char* key) {
    unsigned hv = hash(ht, key);
    HashNode* head = ht->buckets[hv];
    HashNode* n = find_in_list(head, key);
    return n != NULL;
}

/**
 * Removes the node from the hash table that matches the
 * specified key, freeing up the memory.
 */
void ht_remove(HashTable* ht, char* key) {
    unsigned hv = hash(ht, key);
    HashNode* n = ht->buckets[hv];
    HashNode* prev = NULL;
    do {
        if (strcmp(n->key, key) == 0) {
            // Check to see if this was the first node.
            if (prev == NULL) {
                ht->buckets[hv] = n->next;
            } else {
                prev->next = n->next;
            }

            // Update the count
            ht->num_elements--;

            // Freeing the node's memory.
            delete_node(n);
            return;
        }
        prev = n;
        n = n->next;
    } while (n != NULL);
}

