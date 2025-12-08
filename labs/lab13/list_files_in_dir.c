#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void list_directory_files(char* path) {
    DIR* dir = opendir(path);
    struct dirent* file;
    if (dir) {
        while ((file = readdir(dir)) != NULL)
            printf("%s\n", file->d_name);
        closedir(dir);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <dir_name>\n", argv[0]);
        exit(1);
    }
    list_directory_files(argv[1]);
}

