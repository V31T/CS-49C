#ifndef ASSOCIATIVE_LIST_H
#define ASSOCIATIVE_LIST_H

#include <string.h>
#include <stdlib.h>

typedef struct _node {
    char* key;
    void* data;
    struct _node *next;
} Node;

typedef struct _al {
    Node* head;
} AssociativeList;

AssociativeList* new_list();

void set(AssociativeList*, char*, void*);

void* get(AssociativeList*, char*);

void remove_item(AssociativeList*, char*);

#endif // ASSOCIATIVE_LIST_H
