#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ast.h"
#include "parser.h"

int interp(Ast* ast) {
    assert(ast->type != TOP);
    //
    // **YOUR CODE HERE**
    //
    // If a node is a VAL, you can simply return its value.
    //
    // For others, you will need to recursively evaluate their args
    // and combine the results appropriately; that is, add them,
    // subtract them, or multiply them.
    //
    // You may find it helpful to review the interp_file function.
    //
    // If an unrecognized type is found, print an error message and quit the program.
    //
}

/**
 * Evaluates all Scheme expressions and prints their results.
 */
void interp_file(Ast* ast) {
    assert(ast->type == TOP);
    for (int i=0; i<ast->arg_count; i++) {
        int result = interp(ast->args[i]);
        printf("%d\n", result);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <scheme file>\n", argv[0]);
        exit(1);
    }

    char* file_name = argv[1];
    Ast* ast = parse_file(file_name);
    interp_file(ast);

    return 0;
}
