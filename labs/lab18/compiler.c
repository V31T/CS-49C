#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "ast.h"
#include "parser.h"
#include "opcodes.h"

void write_bytecode(FILE* f, Ast* ast) {
    assert(ast->type != TOP);
    //
    // **YOUR CODE HERE**
    //
    // Switch on ast->type.
    //
    // For 'VAL', write out the PUSH_INT opcode and then ast->val.
    // Your might find fputc useful here.
    //
    // For 'ADD_OP', recursively call write_bytecode on all of the arguments
    // in ast->args and then write 'ADD_OPCODE'.
    //
    // Note that there is a bit of a challenge here; while '+' takes any number
    // of arguments in Scheme, 'ADD_OPCODE' only takes 2 arguments.  So a
    // Scheme program of (+ 1 2 3 4 5) would translate to:
    //
    //  PUSH_INT 1, PUSH_INT 2, ADD, PUSH_INT 3, ADD, PUSH_INT 4, ADD, PUSH_INT 5, ADD
    //
    // Also note the extra 'PUSH' at the beginning of the opcode sequence above.
    //
    // 'SUB_OP' and 'MUL_OP' should be handled in a similar manner.
    //
    // Any other opcode should be treated as an error.
    //
}

void compile(char* bytecode_file_name, Ast* ast) {
    assert(ast->type == TOP);
    FILE* f = fopen(bytecode_file_name, "wb");
    if (f == NULL) {
        perror("Error writing to bytecode file");
        exit(1);
    }
    for (int i=0; i<ast->arg_count; i++) {
        write_bytecode(f, ast->args[i]);
        fputc(PRINT_OPCODE, f);
    }
    fclose(f);
}

/**
 * Returns a new heap-allocated string representing the bytecode
 * file name, derived from the Scheme file name.
 */
char* determine_bytcode_file_name(char* scheme_file_name) {
    int len = strlen(scheme_file_name);
    if (len < 4) goto error;

    if (strcmp(scheme_file_name + (len-4), ".scm") != 0) goto error;

    char* s = strdup(scheme_file_name);
    if (s == NULL) {
        perror("Error determining bytecode file name");
        exit(1);
    }

    char* ext = s + (len-3);
    *ext = 'b';
    *(ext+1) = 'y';
    *(ext+2) = 't';

    return s;

error:
    fprintf(stderr, "Invalid file name: %s. File must end with .scm.\n", scheme_file_name);
    exit(1);
}


int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <scheme file>\n", argv[0]);
        exit(1);
    }

    char* scm_file_name = argv[1];
    char* bytecode_file_name = determine_bytcode_file_name(scm_file_name);

    printf("Compiling %s to %s.\n", scm_file_name, bytecode_file_name);

    Ast* ast = parse_file(scm_file_name);
    compile(bytecode_file_name, ast);

    return 0;
}
