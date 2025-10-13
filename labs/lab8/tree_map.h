#ifndef TREE_MAP_H
#define TREE_MAP_H

#include <string.h>
#include <stdlib.h>

typedef struct _node {
    char* key;
    void* data;
    struct _node *left;
    struct _node *right;
} Node;

typedef struct _al {
    Node* root;
} TreeMap;

TreeMap* new_map();

void set(TreeMap*, char*, void*);

void* get(TreeMap*, char*);

#endif // TREE_MAP_H
