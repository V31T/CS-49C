#include <stdio.h>
#include <string.h>
#include "tree_map.h"

Node* new_node(char* key, void* data) {
    Node* node = malloc(sizeof(Node));
    if (!node) {
        perror("couldn't make node");
        exit(1);
    }

    node->key = strdup(key);   // copy key
    node->data = data;         // store data
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeMap* new_map() {
    TreeMap* map = malloc(sizeof(TreeMap));
    if (!map) {
        perror("couldn't make map");
        exit(1);
    }

    map->root = NULL;
    return map;
}

void set(TreeMap* map, char* key, void* data) {
    if (map->root == NULL) {
        map->root = new_node(key, data);
        return;
    }

    Node* curr = map->root;
    Node* prev = NULL;

    while (curr != NULL) {
        int cmp = strcmp(key, curr->key);

        if (cmp == 0) {  // key exists, update it
            free(curr->data);
            curr->data = data;
            return;
        }

        prev = curr;
        curr = (cmp > 0) ? curr->right : curr->left;
    }

    Node* node = new_node(key, data);
    if (strcmp(key, prev->key) > 0)
        prev->right = node;
    else
        prev->left = node;
}

void* get(TreeMap* map, char* key) {
    Node* curr = map->root;

    while (curr != NULL) {
        int cmp = strcmp(key, curr->key);

        if (cmp == 0)
            return curr->data;
        curr = (cmp > 0) ? curr->right : curr->left;
    }

    return NULL;
}
