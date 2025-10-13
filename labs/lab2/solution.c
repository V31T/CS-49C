#include <stdio.h> 
#include <stdlib.h>

#include "caesar.h"

#define BUFFER_SIZE 80

void decrypt_file(char key, char *file_name) {
    FILE* ptr; 
    char str[BUFFER_SIZE];
    ptr =fopen(file_name, "r");

    if (ptr == NULL) {
        fprintf(stderr, "Error. \n"); 
        exit(1);
    }

    while (fgets(str, BUFFER_SIZE, ptr) != NULL) {
        decrypt(key, str);
        printf("%s", str); 
    }

    fclose(ptr); 
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input)file> \n", argv[0]); //prints file name located at argv
    }

    char *file_name = argv[1];
    char key = 1;

    while (key < 26) {
        printf("KEY = %i\n------------\n", key)
        decrypt_file(key,);
    }

    return 0;
}
