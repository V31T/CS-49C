#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "ast.h"

Ast* parse_file(char*);

#endif // PARSER_H

