#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // check for filename
    if (argc < 2) {
        fprintf(stderr, "Error: No file specified. Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    // open file
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }
    
    // print lines with '#'
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] == '#') {
            printf("%s", line);
        }
    }
    
    // close file
    fclose(file);
    
    return 0;
}
