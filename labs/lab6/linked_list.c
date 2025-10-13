#include "linked_list.h"

/**
 * Creates a LinkedList struct.
 * The pointers to the head and tail are initially NULL.
 */
struct LinkedList* new_list() {
    struct LinkedList* ll = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    ll->head = NULL;
    ll->tail = NULL;
    return ll;
};


/**
 * Creates a new instance of a node.
 */
struct Node* new_node(int data) {
    //
    // **YOUR CODE HERE**
    //
    // Initialize a node of the appropriate size, then set the 'data'
    // field  of the node to the 'data' input argument.
    // Set the 'next' field of the node to NULL.
    struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL; 

    return new_node;
}

/**
 * Adds an element to the beginning ot the linked list.
 */
void add_at_beginning(struct LinkedList* ll, int data) {
    struct Node* n = new_node(data);
    n->next = ll->head; // same thing as (*p).head (basically acessing a variable in a struct)
    ll->head = n;
}

// methods from linked_list.h
void add_at_end(struct LinkedList* ll, int data) {
    struct Node* n = new_node(data);
    if (ll->head == NULL) { // list empty
        ll->head = n;
        ll->tail = n;
    } else {
        ll->tail->next = n;
        ll->tail = n;
    }
}

void add_at_beginning(struct LinkedList* ll, int data) {
    struct Node* n = new_node(data);
    n->next = ll->head;
    ll->head = n;
    if (ll->tail == NULL) { // list was empty
        ll->tail = n;
    }
}

struct Node* find_in_list(struct LinkedList* ll, int data) {
    struct Node* curr = ll->head;
    while (curr != NULL) {
        if (curr->data == data) return curr;
        curr = curr->next;
    }
    return NULL;
}

void remove_from_list(struct LinkedList* ll, int data) {
    if (ll->head == NULL) return;

    struct Node* curr = ll->head;
    struct Node* prev = NULL;

    while (curr != NULL) {
        if (curr->data == data) {
            if (prev == NULL) { // remove head
                ll->head = curr->next;
                if (ll->tail == curr) ll->tail = NULL;
            } else {
                prev->next = curr->next;
                if (ll->tail == curr) ll->tail = prev;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int remove_from_beginning(struct LinkedList* ll) {
    if (ll->head == NULL) return -1;

    struct Node* to_remove = ll->head;
    int val = to_remove->data;

    ll->head = to_remove->next;
    if (ll->head == NULL) ll->tail = NULL;

    free(to_remove);
    return val;
}


/**
 * Prints out the nodes value and every subsequent node.
 */
void print_from_node(struct Node* n) {
    if (n == NULL) {
        printf("NULL\n");
        return;
    }
    printf("[%d", n->data);
    while (n->next != NULL) {
        n = n->next;
        printf(", %d", n->data);
    }
    printf("]\n");
}

/**
 * Prints out the list.
 */
void print_list(struct LinkedList* ll) {
    print_from_node(ll->head);
}
