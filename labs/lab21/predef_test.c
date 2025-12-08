#include <stdio.h>

int main() {
    // Note that all are strings.
    printf("This program is named %s. "
           "It was compiled on %s at %s.\n",
           __FILE__, __DATE__, __TIME__);

    // The C standard version is stored as a long.
    printf("The C standard version is %ld.\n",
           __STDC_VERSION__);

    printf("The line numbers are %d and %d\n",
            __LINE__,
            __LINE__);
}
