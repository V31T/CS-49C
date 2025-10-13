#include <stdio.h>

#include "linked_list.h"

struct LinkedList* new_stack() {
    return new_list();
}

void push(struct LinkedList* stack, int data) {
    add_at_beginning(stack, data);
}

int pop(struct LinkedList* stack) {
    return remove_from_beginning(stack);
}

int peek(struct LinkedList* stack) {
    return stack->head->data;
}

int main() {
    struct LinkedList* stack = new_stack();
    for (int i=0; i<10; i++) {
        push(stack, i);
    }

    printf("Peeking: %d\n\n", peek(stack));

    printf("Popping:\n");
    for (int i=0; i<10; i++) {
        printf("%d\n", pop(stack));
    }
}
