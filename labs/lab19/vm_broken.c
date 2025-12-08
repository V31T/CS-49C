#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "opcodes.h"

#define STACK_SIZE 100

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

    int stack[STACK_SIZE];
    int stack_ptr = 0;
    int byte, x, y;

    while ((byte = fgetc(f)) != EOF) {
        switch (byte) {
            case PUSH_INT:
                if (stack_ptr >= STACK_SIZE) {
                    fprintf(stderr, "Error: stack size exceeded.\n");
                    exit(1);
                }
                x = fgetc(f);
                assert(x != EOF);
                stack[stack_ptr++] = x;
                break;
            case PRINT_OPCODE:
                x = stack[stack_ptr--];
                printf("%d\n", x);
                break;
            case ADD_OPCODE:
                x = stack[stack_ptr--];
                y = stack[stack_ptr--];
                stack[stack_ptr++] = x + y;
                break;
            default:
                fprintf(stderr, "Unrecognized opcode: %x\n", byte);
                exit(1);
        }
    }

    fclose(f);
}
