#ifndef MERKLE_TREE_H
#define MERKLE_TREE_H

#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "sha256.h"


typedef struct _mt {
    char** hashes;
    unsigned num_hashes;
    unsigned num_items;
} MerkleTree;

typedef struct _node {
    char* sib_hash;
    bool is_left;
    struct _node* next;
} PathNode;


MerkleTree* mt_create(char** items, unsigned num_items);

char* mt_root_hash(MerkleTree* mt);

PathNode* mt_get_path(MerkleTree* mt, char* it);

void print_path(PathNode* path);

bool mt_contains_item(MerkleTree* mt, char* it);

bool path_is_valid(PathNode* path, char* it, char* merkle_root_given);

#endif // MERKLE_TREE_H

