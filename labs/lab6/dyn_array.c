#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int length = 10;

    arr = (int*) malloc(length * sizeof(int));

    for (int i=0; i<length; i++) {
        arr[i] = i * i;
    }
    for (int i=0; i<length; i++) {
        printf("%d\n", arr[i]);
    }

    free(arr);
    arr = NULL;
}