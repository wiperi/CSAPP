#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
        exit(1);
    }

    FILE* file = open(argv[1]);
    if (file == NULL) {
        fprintf(stderr, "Open file failed.\n");
        exit(1);
    }

    // read the first 3 byte
    int ch;
    char str[10] = {};
    for (int i = 0; i < 3; i++) {
        ch = fgetc(file);
        if (ch == EOF) {
            fprintf(stderr, "File size too small for header.\n");
            exit(1);
        }

        str[i] = ch;
    }
    if (strcmp(str, "LIT") != 0) {
        fprintf(stderr, "Wrong header.\n");
        exit(1);
    }


    // read the next byte
    int n_bytes = atoi(fgetc(file));
    if (n_bytes < 1 || n_bytes > 8) {
        fprintf(stderr, "Invalid number of integers. Only 0..8 allowed.\n");
        exit(1);
    }
    
    // read integers
    while ((ch = fgetc(file)) != EOF) {
        printf("%d\n", ch);
    }


    
}