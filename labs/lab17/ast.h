#ifndef AST_H
#define AST_H

#include <stdlib.h>

#define MAX_ARGS 64

typedef enum {
    ADD_OP,
    MUL_OP,
    SUB_OP,
    VAL,
    TOP,
} AstType;

/**
 * An Ast represents the tree structure of a program.
 *
 * The 'type' field tells you what kind of node you have.
 * There should only be one 'TOP' type, and it should be the root of the Ast.
 *
 * For VAL Ast's, the 'args' and 'arg_count' parameters are not used.
 * They simply contain a number from 0-255 in the 'val' field.
 *
 * For other Ast's, 'val' is not used.
 * They represent function calls to add, subtract, or multiply
 * as indicated by the type.
 */
typedef struct _ast {
    AstType type;
    struct _ast** args;
    struct _ast* parent;
    unsigned arg_count;
    int val;
} Ast;

Ast* ast_create(Ast*);

Ast* build_val(Ast*, int);

#endif // AST_H

