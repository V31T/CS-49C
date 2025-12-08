#include "parser.h"

// We're going to limit numbers to a single byte, non-negative only.
#define MAX_DIGITS 3

int parse_num(char first_dig, FILE* f) {
    //
    // **YOUR CODE HERE**
    //
    // Keep calling fgetc until you get a non-digit.
    // Store all of the digits in a string and use atoi to convert
    // the string to a number, which should be the return value.
    //
    // You may need to put back the last character that you read;
    // the ungetc function will do this for you.
    //
}

Ast* parse_file(char* file_name) {
    FILE* f;
    int ch;

    Ast* ast = ast_create(NULL);
    ast->type = TOP;

    f = fopen(file_name, "r");
    if (f == NULL) {
        perror("Error opening file");
        exit(1);
    }

    while ((ch = fgetc(f)) != EOF) {
        if (ch == '(') {
            Ast* child_ast = ast_create(ast);
            ast->args[ast->arg_count++] = child_ast;
            ast = child_ast;
        } else if (ch == ')') {
            ast = ast->parent;
        } else if (isdigit(ch)) {
            Ast* v = build_val(ast, parse_num(ch, f));
            ast->args[ast->arg_count++] = v;
        } else {
            //
            // **YOUR CODE HERE**
            //
            // Add additional cases to handle other characters.
            //
            // If you get a '+', '-', or '*', set the ast's type appropriately.
            //
            // If you get a whitespace character (tab, newline, etc.) ignore it.
            //
            // If you get a ';', keep getting characters until you reach a newline.
            //
            fprintf(stderr, "Invalid character: %c\n", ch);
            exit(1);
        }
    }

    fclose(f);

    if (ast->parent != NULL) {
        fprintf(stderr, "program is not well formed.\n");
    }

    return ast;
}
