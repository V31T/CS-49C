#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
};

struct LinkedList* new_list();

void add_at_end(struct LinkedList*, int);

void add_at_beginning(struct LinkedList*, int);

struct Node* find_in_list(struct LinkedList*, int);

void remove_from_list(struct LinkedList*, int);

int remove_from_beginning(struct LinkedList*);

void print_list(struct LinkedList*);

void print_from_node(struct Node*);



#endif // LINKED_LIST_H
