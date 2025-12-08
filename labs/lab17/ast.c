#include "ast.h"

/**
 * For simplicity's sake, we have a hard-coded number of arguments.
 */
Ast* ast_create(Ast* parent) {
    Ast* ast = (Ast*) malloc(sizeof(Ast));
    ast->parent = parent;
    ast->args = (Ast**) malloc(MAX_ARGS * sizeof(Ast));
    ast->arg_count = 0;
    ast->val = -1;
    return ast;
}

/**
 * Use build_val when you parse a number.
 */
Ast* build_val(Ast* parent, int x) {
    Ast* ast = ast_create(parent);
    ast->type = VAL;
    ast->val = x;
    // Values don't have any arguments.
    free(ast->args);
    ast->args = NULL;
    return ast;
}

