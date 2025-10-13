#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "caesar.h"

#include <stdlib.h> // for exit(1).

#define BUFFER_SIZE 80
#define SHIFT_KEY_MAX 26
#define SHIFT_KEY 15 //found after trying the first 80 characters for each key

void echo_file(char *file_name) {
    FILE* ptr;
    char str[BUFFER_SIZE];

    ptr = fopen(file_name, "r");

    if (ptr == NULL) {
        printf("Error.\n");
        exit(1);
    }

    // for (int i = 0; i < SHIFT_KEY_MAX; i++) {
    //     fgets(str, BUFFER_SIZE, ptr);
    //     printf("%d\n", i); 
    //     decrypt(i, str);
    //     printf("%s\n\n", str);
    // }

    while (fgets(str, BUFFER_SIZE, ptr) != NULL) {
        char line[BUFFER_SIZE];
        strcpy(line, str);               // copy so str stays intact if needed
        decrypt((char)SHIFT_KEY, line);
        printf("%s", line);
    //      for (int i = 0; i<SHIFT_KEY_MAX; i++) {
    //         char str_test[BUFFER_SIZE];
    //         strcpy(str_test, str);
    //         printf("%s\n", str_test);
    //         printf("%d\n", i);
    //         decrypt(i, str_test); //the problem is that i keep updating the same array and it is never reset per array
    //         printf("%s\n\n", str_test); //key is 15
    //      }
    //     break;
    }
}
// lab2 gcc bruteforce.c -o bruteforce
// Undefined symbols for architecture arm64:
//   "_decrypt", referenced from:
//       _echo_file in bruteforce-543a2a.o
// ld: symbol(s) not found for architecture arm64
// clang: error: linker command failed with exit code 1 (use -v to see invocation)
//     fclose(ptr);
// }
// Output when running initial compilation, Error was thrown because I forgot
// that since im referencing/using functions from caesar.h i must also compile and link
// this file with caesar.c's executable

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> (<file2> ...)\n", argv[0]);
        exit(1);
    }

    for (int i=1; i<argc; i++) {
        char* file_name = argv[i];
        printf("Key = %d\n", SHIFT_KEY);
        echo_file(file_name);
    }

    return 0;
}



