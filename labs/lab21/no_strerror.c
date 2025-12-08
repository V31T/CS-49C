#include <stdio.h>
#include <errno.h>

int main () {
   FILE *fp;

   fp = fopen("no_such_file.txt", "r");
   if (fp == NULL) {
      printf("Error: %d\n", errno);
   }

   return 0;
}
