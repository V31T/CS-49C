#include <stdio.h>
#include <string.h>
#include <errno.h>

int main () {
   FILE *fp;

   fp = fopen("no_such_file.txt", "r");
   if (fp == NULL) {
      printf("Error: %s\n", strerror(errno));
   }

   return 0;
}
