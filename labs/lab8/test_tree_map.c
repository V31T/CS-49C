#include <stdio.h>

#include "tree_map.h"

int main() {
    TreeMap* m = new_map();

    set(m, "f", "foxtrot");
    set(m, "c", "charlie");
    set(m, "w", "whiskey");
    set(m, "a", "alfa");
    set(m, "b", "bravo");
    set(m, "y", "yankee");
    set(m, "d", "delta");
    set(m, "e", "echo");
    set(m, "t", "tango");
    set(m, "v", "victor");
    set(m, "z", "zulu");

    char* s = get(m, "a");
    printf("%s\n", s);
    s = get(m, "b");
    printf("%s\n", s);
    s = get(m, "c");
    printf("%s\n", s);
    s = get(m, "z");
    printf("%s\n", s);
}