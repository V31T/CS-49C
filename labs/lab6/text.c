#include "linked_list.h"

int main() {
    struct LinkedList *ll = new_list();

    add_at_beginning(ll, 42);
    add_at_beginning(ll, 13);

    print_list(ll);

}
