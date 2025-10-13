#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hash_table.h"

#define INIT_HASH_SIZE 10
#define LOAD_FACTOR 0.75

/**
 * To hash a key, we add the ASCII values of the characters.
 * This hash is **not** a cryptographic-quality hash function,
 * but should work fine for our purposes.
 */
unsigned long hash(HashTable* ht, char* key) {
    int len = strlen(key);
    unsigned long hv = 0;
    for (int i = 0; i < len; i++) {
        hv += key[i];
    }
    return hv % ht->bucket_count;
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
    // calloc is similar to malloc, but specifies a count as well as a node size.
    ht->buckets = (HashNode**) calloc(ht->bucket_count, sizeof(HashNode*));
    return ht;
}

/**
 * If the key is already in the hash table, this function
 * updates the value associated with that key.  Otherwise,
 * it creates a new node w/ the key/value in the hash table.
 */
void ht_set(HashTable* ht, char* key, char* value) {
    // figure out which bucket this key belongs in
    unsigned hv = hash(ht, key);
    HashNode* head = ht->buckets[hv];

    // look for the key in this bucket
    HashNode* found = find_in_list(head, key);

    if (found != NULL) {
        // key already exists, just replace the value
        free(found->data);
        found->data = strdup(value);
        return;
    }

    // if not found, make a new node and put it at the start
    HashNode* new = new_node(key, value);
    new->next = head;
    ht->buckets[hv] = new;
    ht->num_elements++;

    // check if we need to resize the table
    double load = (double) ht->num_elements / ht->bucket_count;
    if (load > LOAD_FACTOR) {
        int old_size = ht->bucket_count;
        HashNode** old_buckets = ht->buckets;

        // double the size
        ht->bucket_count *= 2;
        ht->buckets = (HashNode**) calloc(ht->bucket_count, sizeof(HashNode*));
        ht->num_elements = 0;

        // re-add all nodes to the new table
        for (int i = 0; i < old_size; i++) {
            HashNode* curr = old_buckets[i];
            while (curr != NULL) {
                ht_set(ht, curr->key, curr->data);
                curr = curr->next;
            }
        }

        // free old memory
        free(old_buckets);
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
    // figure out which bucket to check
    unsigned hv = hash(ht, key);
    HashNode* curr = ht->buckets[hv];
    HashNode* prev = NULL;

    // loop through the bucket to find the node
    while (curr != NULL) {
        if (strcmp(curr->key, key) == 0) {
            // if it's the first node
            if (prev == NULL)
                ht->buckets[hv] = curr->next;
            else
                prev->next = curr->next;

            delete_node(curr);  // free memory
            ht->num_elements--;
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}
