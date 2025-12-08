#include <stdlib.h>
#include <string.h>

typedef struct _n {
    char* data;
    struct _n *next; 
} Node;

typedef struct _qu {
    Node* head;
    Node* tail;
} Queue;

Queue* q_create();

// Adds item to the end of the queue.
void q_add(Queue*, char*);

//Removes the head of the queue. returning its contents 
// Returns Null if the Qeueu is empty
char* q_next(Queue*);