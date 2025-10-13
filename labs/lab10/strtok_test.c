#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "Hi     everyone how are you?";

    char* token = strtok(s, " ");

    while (token != NULL) {
        printf("tok: %s\n", token);
        token = strtok(NULL, " ");
    }
}