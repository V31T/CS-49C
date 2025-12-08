#include "queue.h"

// initializes empty queue
Queue* q_create() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        return NULL;
    }
    q->head = NULL;
    q->tail = NULL;
    return q;
}

// adds item to the end of the queue
void q_add(Queue* q, char* data) {
    if (q == NULL) {
        return;
    }
    
    // allocate memory 
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return;
    }
    
    // allocate memory for the data and copy it
    new_node->data = (char*)malloc(strlen(data) + 1);
    if (new_node->data == NULL) {
        free(new_node);
        return;
    }
    strcpy(new_node->data, data);
    new_node->next = NULL;
    
    // add node to the queue
    if (q->tail == NULL) {
        // Queue is empty
        q->head = new_node;
        q->tail = new_node;
    } else {
        // Queue has elements
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

// removes the head of the queue, returning its contents
// returns null if the queue is empty
char* q_next(Queue* q) {
    if (q == NULL || q->head == NULL) {
        return NULL;
    }
    
    // get the head node
    Node* old_head = q->head;
    char* data = old_head->data;
    
    // Move head to next node
    q->head = old_head->next;
    
    // update tail if empty
    if (q->head == NULL) {
        q->tail = NULL;
    }
    
    // free the node
    free(old_head);
    
    return data;
}

