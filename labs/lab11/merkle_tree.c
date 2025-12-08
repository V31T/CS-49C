#include "merkle_tree.h"

#define DIGEST_SIZE 65
#define MERKLE_PAIR_SIZE 129

/**
 * Hashes all of the items into the MerkleTree,
 * including calculating the inner nodes.
 */
void build_hashes(MerkleTree* mt, char** items) {
    int leaf_hashes_ind = mt->num_hashes / 2;

    // Hash the items
    for (int i=0; i<mt->num_items; i++) {
        char digest[DIGEST_SIZE];
        sha256_easy_hash_hex(items[i], strlen(items[i]), digest);
        mt->hashes[i + leaf_hashes_ind] = strdup(digest);
        //printf("%d. H(%s) = %s\n", i+leaf_hashes_ind, items[i], digest);
    }

    // Hash the inner nodes, going from the end to the beginning, going by pairs.
    for (int i=mt->num_hashes-1; i>0; i-=2) {
        // Building the input for the inner-node hash
        char hash_in[MERKLE_PAIR_SIZE];
        hash_in[0] = '\0';
        strcat(hash_in, mt->hashes[i-1]);
        strcat(hash_in, mt->hashes[i]);

        // Calculating the inner-node hash.
        int dest_hash_ind = (i/2) - 1;
        char digest[DIGEST_SIZE];
        sha256_easy_hash_hex(hash_in, strlen(hash_in), digest);
        // Allocating memory for the string.
        mt->hashes[dest_hash_ind] = strdup(digest);
        //printf("%d. H(%s) = %s\n", dest_hash_ind, hash_in, digest);
    }
}

/**
 * Given a list of items, constructs a Merkle tree of hashes
 * for those items.
 */
MerkleTree* mt_create(char** items, unsigned num_items) {
    MerkleTree* mt = (MerkleTree*) malloc(sizeof(MerkleTree));
    assert(mt != NULL);

    mt->num_items = num_items;

    // For n elements, there will be n "leaf" hashes and n-1 inner hashes.
    mt->num_hashes = num_items * 2 - 1;

    // Allocating memory for string pointers.
    // Allocating space for the hashes themselves will be done later.
    mt->hashes = (char**) malloc(mt->num_hashes * sizeof(char*));
    assert(mt->hashes != NULL);

    build_hashes(mt, items);

    return mt;
}

/**
 * Returns the Merkle root of the Merkle tree.
 */
char* mt_root_hash(MerkleTree* mt) {
    return mt->hashes[0];
}

/**
 * Returns the index of the item's hash in the Merkle tree,
 * or -1 if the item's hash is not found.
 */
int get_path_ind(MerkleTree* mt, char* it) {
    char digest[DIGEST_SIZE];
    sha256_easy_hash_hex(it, strlen(it), digest);
    int item_ind = mt->num_hashes - mt->num_items;
    while (item_ind < mt->num_hashes) {
        if (strcmp(digest, mt->hashes[item_ind]) == 0) {
            return item_ind;
        }
        item_ind++;
    }
    return -1;
}

/**
 * Creates a new path node, tracking the sibling hash
 * and whether the sibling is the left or right node.
 */
PathNode* new_node(char* sib_hash, bool is_left) {
    PathNode* n = (PathNode*) malloc(sizeof(PathNode));
    assert(n != NULL);
    n->sib_hash = strdup(sib_hash);
    n->is_left = is_left;
    return n;
}

/**
 * Returns the Merkle path for a specified item,
 * or NULL, if the item is not in the Merkle tree.
 */
PathNode* mt_get_path(MerkleTree* mt, char* it) {
    //
    // **YOUR CODE HERE**
    //
    // Get the index of the specified item.
    // If it is not found, return NULL.
    // Otherwise, calculate the Merkle path.
    //
    // The Merkle path will be a linked list of nodes from
    // the item's hash to the root.  Somewhat counterintuitively,
    // the path should be the **sibling** hashes of the parents
    // of the item's hash.  It is also useful to keep track of
    // whether the node is the left or right sibling of the node.
    // (Note that the struct currently has items for both of these
    // pieces of information.)
    //
}

/**
 * Prints out the hashes of the Merkle path,
 * for debugging purposes.
 */
void print_path(PathNode* path) {
    if (path == NULL) return;
    printf("%s\n", path->sib_hash);
    print_path(path->next);
}

/**
 * Returns true if the hash of an item is included
 * in the Merkle tree.
 */
bool mt_contains_item(MerkleTree* mt, char* it) {
    return get_path_ind(mt, it) != -1;
}

/**
 * Returns true if the path and the item match the specified Merkle root.
 */
bool path_is_valid(PathNode* path, char* it, char* merkle_root_given) {
    //
    // **YOUR CODE HERE**
    //
    // Return true if the path of the node and the hash of the specified item
    // match up with the Merkle root specified.
    //
    // For each step of the path, combine the current hash with the sibling
    // hash specified by the path.  Hash those hashes together to get the
    // hash value one level up in the tree.
    //
    // Once you have reached the root, you can compare against merkle_root_given
    // with strcmp.
}

