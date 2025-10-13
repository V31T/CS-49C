#include <stdio.h>

#include "associative_list.h"

void load_list(AssociativeList* lst) {
    // Making sure that the strings are on the stack
    // and will disappear after returning from the function.
    char k[10];
    char v[10];
    strcpy(k, "hello");
    strcpy(v, "there");

    // Setting the value this way will result in garbage
    // stored in the list.  Also, if we try to reset it
    // afterwards, the compiler will complain that we are
    // trying to free something that was not malloc'd.
    //set(lst, k, v);

    // This approach will ensure that heap memory is
    // used to store the value.
    // (Note that the key is stored on the heap by the
    // Associated list class itself.)
    char* v2 = strdup(v);
    set(lst, k, v2);

    // Adding a number to the heap
    int* x = malloc(sizeof(int));
    *x = 6;
    set(lst, "six", x);
}

int main() {
    AssociativeList* lst = new_list();

    load_list(lst);

    char* s = get(lst, "hello");
    printf("%s\n", s);

    int* vi = get(lst, "six");
    printf("%d\n", *vi);

    // Note that we are allocating memory for the value here.
    // The key's memory is allocated by the set method.
    set(lst, "hello", strdup("world"));
    s = get(lst, "hello");
    printf("%s\n", s);

    // This part will work -- the variable on the stack
    // would still be in scope.
    int x = 3;
    set(lst, "three", &x);
    int* y = get(lst, "three");
    printf("%d\n", *y);
}