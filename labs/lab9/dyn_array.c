#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _da {
    int* arr;
    unsigned size;
    unsigned capacity;
} DynArray;


DynArray* new_dyn_array(unsigned cap) {
    DynArray* dyn = (DynArray*) malloc(sizeof(DynArray));
    dyn->size = 0;
    dyn->capacity = cap;
    dyn->arr = (int*) malloc(cap * sizeof(int));
    return dyn;
}

bool grow_array(DynArray* dyn) {
    unsigned new_cap = dyn->capacity * 2;
    //int* new_arr = realloc(dyn->arr, new_cap * sizeof(int));
    int* new_arr = malloc(new_cap * sizeof(int));
    if (new_arr == NULL) {
        return false;
    }
    // Extra steps needed w/o realloc
    for (int i=0; i<dyn->size; i++) {
        new_arr[i] = dyn->arr[i];
    }
    free(dyn->arr);
    // End of extra steps
    dyn->arr = new_arr;
    dyn->capacity = new_cap;
    return true;
}

void add_elem(DynArray* dyn, int elem) {
    printf("Adding %d of %d available.\n", dyn->size+1, dyn->capacity);
    if (dyn->size >= dyn->capacity) {
        bool success = grow_array(dyn);
        if (!success) {
            fprintf(stderr, "Unable to allocate new memory.\n");
            exit(1);
        }
        printf("**Growing array to %u.\n", dyn->capacity);
    }
    dyn->arr[dyn->size] = elem;
    dyn->size = dyn->size + 1;
}

void print_arr(DynArray* dyn) {
    printf("Dynamic array, %d/%d used.  Contents:\n", dyn->size, dyn->capacity);
    for (int i=0; i<dyn->size; i++) {
        printf("  %d\n", dyn->arr[i]);
    }
}

int main() {
    DynArray* dyn = new_dyn_array(5);

    for (int i=0; i<100; i++) {
        add_elem(dyn, i*i);
    }

    print_arr(dyn);
}
