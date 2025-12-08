#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "opcodes.h"

#define STACK_SIZE 100

/**
 * Utility function to show the current state of the stack
 * for debugging purposes.
 */
void show_stack(int* stack, int stack_size) {
    printf("|");
    for (int i=0; i<stack_size; i++) {
        printf(" %d", stack[i]);
    }
    printf("\n");
}


int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <bytecode file>\n", argv[0]);
        exit(1);
    }

    char* bytecode_file_name = argv[1];

    FILE* f = fopen(bytecode_file_name, "r");
    if (f == NULL) {
        perror("Error opening bytecode file");
    }

    // The stack, and the pointer to the current position on the stack.
    int stack[STACK_SIZE];
    int stack_ptr = 0;

    // The byte read from the bytecode, and the operand(s) read from the stack.
    int byte, x, y;

    while ((byte = fgetc(f)) != EOF) {
        //
        // **YOUR CODE HERE**
        //
        // If the next byte is PUSH_INT, read an extra byte and push
        // that byte on to the stack.  You can do this by:
        //
        //   stack[stack_ptr++] = x;
        //
        // if x holds the 2nd byte.
        //
        //
        // For PRINT_OPCODE, pop the top argument off of the stack and print
        // it out.  If you call:
        //
        //   x = stack[--stack_ptr];
        //
        // that pops the argument off of the stack and stores its value in 'x'.
        //
        //
        // For ADD_OPCODE, SUB_OPCODE, etc, pop the top 2 arguments off the
        // stack, perform the mathematical operation, and push the result back
        // on the stack.  For SUB_OPCODE in particular, make sure to swap the
        // order of the arguments.
        //
    }

    fclose(f);
}
