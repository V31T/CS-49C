#include <stdio.h>

#include "associative_list.h"

AssociativeList* new_list() {
    AssociativeList* al = (AssociativeList*) malloc(sizeof(AssociativeList));
    al->head = NULL;
    return al;
};


Node* new_node(char* key, void* data) {
    Node *n = (Node*) malloc(sizeof(Node));
    n->key = strdup(key);
    //n->data = strdup(data);
    n->data = data;
    n->next = NULL;
    return n;
}

Node* find_in_list(AssociativeList* al, char* key) {
    Node* n = al->head;
    while (n != NULL) {
        if (strcmp(n->key, key) == 0) {
            return n;
        }
        n = n->next;
    }

    return NULL;
}

void add_at_beginning(AssociativeList* al, char* key, void* data) {
    Node* n = new_node(key, data);
    n->next = al->head;
    al->head = n;
}

void set(AssociativeList* al, char* key, void* data) {
    Node* n = find_in_list(al, key);
    if (n == NULL) {
        add_at_beginning(al, key, data);
    } else {
        free(n->data);
        //n->data = strdup(data);
        n->data = data;
    }
}

void* get(AssociativeList* al, char* key) {
    Node* n = find_in_list(al, key);
    if (n == NULL) {
        return NULL;
    } else {
        return n->data;
    }
}

void remove_item(AssociativeList* al, char* key) {
    Node* n = al->head;
    Node* prev = NULL;
    do {
        if (n->key == key) {
            // Check to see if this was the first node.
            if (prev == NULL) {
                al->head = n->next;
            } else {
                prev->next = n->next;
            }
            // Freeing the node's memory.
            free(n->key);
            free(n->data);
            free(n);
            return;
        }
        prev = n;
        n = n->next;
    } while (n != NULL);
}

