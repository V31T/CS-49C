#include <stdio.h>
#include <string.h>

void capitalize_string(char *s) {
    // No '*' below -- we're passing in the address.
    int len = strlen(s);
    for (int i=0; i<len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
    }
}

int main() {
    // Declaring "char *s1 = ..." instead would cause a bus error.
    char s1[] = "All right, but apart from the sanitation, the medicine, "
                "education, wine, public order, irrigation, roads, the "
                "fresh water system, and public health, what have the "
                "Romans ever done for us?";
    capitalize_string(s1);
    printf("%s\n", s1);
}