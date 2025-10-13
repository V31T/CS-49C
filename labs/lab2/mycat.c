#include <stdio.h>
#include <stdlib.h> // for exit(1).

#define BUFFER_SIZE 80

void echo_file(char *file_name) {
    FILE* ptr;
    char str[BUFFER_SIZE];

    ptr = fopen(file_name, "r");

    if (ptr == NULL) {
        printf("Error.\n");
        exit(1);
    }

    while (fgets(str, BUFFER_SIZE, ptr) != NULL) {
        printf("%s", str);
    }

    fclose(ptr);
}

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> (<file2> ...)\n", argv[0]);
        exit(1);
    }

    for (int i=1; i<argc; i++) {
        char* file_name = argv[i];

        echo_file(file_name);
    }

    return 0;
}

