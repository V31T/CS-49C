#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 256

/**
 * Returns true if a line matches the pattern.
 */
bool matches(char *line, const char *pat) {
    //
    // **YOUR CODE HERE**
    //
    // To solve this, use 2 pointers.
    // ptr1 should go through the line character at a time.
    //
    // For each character, see if begins a match for the pattern.
    // Ptr2 should go through the pattern character by character
    // and test against the possible match.
    //

    char *point1 = line;
    char *point2;

    while (*point1 != '\0') {

        point2 = (char*)pat;
        char *to_scan = point1;

        while (*to_scan != '\0' && *point2 != '\0' && *to_scan == *point2) { // read untill string terminators
            to_scan++;
            point2++;
        }
        // if point2 is at string terminator then it is a match
        if (*point2 == '\0') {
            return true;
        }

        // else restart 
        point1++;
    }

    return false;
}

/**
 * Reads through the file line by line.
 * Prints out any lines that match the pattern.
 */
void grep_lines(const char *pat, const char *file_name, FILE *f) {
    char line[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, f) != NULL) {
        if (matches(line, pat)) {
            if (file_name == NULL) {
                printf("%s", line);
            } else {
                printf("%s: %s", file_name, line);
            }
        }
    }
}

/**
 * Open a file, search for the pattern.
 */
void grep_file_name(const char *pat, bool show_file_name, const char *file_name) {
    FILE *f = fopen(file_name, "r");
    if (f == NULL) {
        perror("Error reading file");
        return;
    }

    grep_lines(pat, show_file_name ? file_name : NULL, f);

    fclose(f);
}


/**
 * Search the specified files for the given pattern,
 * or read from standard input if no files are given.
 * The first argument should be the pattern to match.
 */
int main(int argc, const char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <pattern> (<file> ...)\n", argv[0]);
        exit(1);
    }

    const char *pattern = argv[1];

    if (argc == 2) {
        grep_lines(pattern, NULL, stdin);
    } else if (argc == 3) {
        const char *file_name = argv[2];
        grep_file_name(pattern, true, file_name);
    } else {
        int i = 2;
        while (i < argc) {
            const char *file_name = argv[i];
            grep_file_name(pattern, true, file_name);
            i++;
        }
    }
}