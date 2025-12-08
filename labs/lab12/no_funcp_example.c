#include <stdio.h>
#include <string.h>

int search_5_letters(char** poem, int size) {
    for (int i=0; i<size; i++) {
        if (strlen(poem[i]) == 5) return i;
    }
    return -1;
}

int search_first_cap(char** poem, int size) {
    for (int i=0; i<size; i++) {
        if (poem[i][0] >= 'A' && poem[i][0] <= 'Z') return i;
    }
    return -1;
}

int main() {
    char *road_not_taken[] = {
        "Two", "roads", "diverged", "in", "a", "wood", "and", "I",
        "I", "took", "the", "one", "less", "traveled", "by",
        "And", "that", "has", "made", "all", "the", "difference"
    };
    int word_count = 22;

    int ind = search_5_letters(road_not_taken, word_count);
    if (ind != -1) {
        printf("%d: %s\n", ind, road_not_taken[ind]);
    }

    ind = search_first_cap(road_not_taken, word_count);
    if (ind != -1) {
        printf("%d: %s\n", ind, road_not_taken[ind]);
    }
}

