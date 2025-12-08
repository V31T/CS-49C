#include "merkle_tree.h"

int main() {
    int size = 8;
    char* items[size];
    items[0] = "a";
    items[1] = "b";
    items[2] = "c";
    items[3] = "d";
    items[4] = "e";
    items[5] = "f";
    items[6] = "g";
    items[7] = "h";

    MerkleTree* mt = mt_create(items, size);

    printf("root: %s\n\n", mt_root_hash(mt));

    // Getting path for "a".
    PathNode* path = mt_get_path(mt, "a");
    print_path(path);

    // Testing valid path -- the first message should print.
    if (path_is_valid(path, "a", mt_root_hash(mt))) {
        printf("Path matches Merkle root.\n");
    } else {
        printf("Path does **NOT** match Merkle root.\n");
    }

    // Testing path for "a" against item "d" -- the second message should print.
    if (path_is_valid(path, "d", mt_root_hash(mt))) {
        printf("(Incorrect) path matches Merkle root.\n");
    } else {
        printf("(Incorrect) path does **NOT** match Merkle root.\n");
    }

    return 0;
}
