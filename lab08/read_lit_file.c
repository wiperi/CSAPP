#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "r");
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
            fprintf(stderr, "Fail to read magic.\n");
            exit(1);
        }

        str[i] = ch;
    }
    if (strcmp(str, "LIT") != 0) {
        fprintf(stderr, "Wrong header.\n");
        exit(1);
    }

    // read the next byte
    int num_len = fgetc(file) - '0';
    if (num_len < 1 || num_len > 8) {
        fprintf(stderr, "Invalid number of integers. Only 0..8 allowed.\n");
        exit(1);
    }

    // read integers
    uint64_t res = 0;
    while (1) {
        for (int i = 0; i < num_len; i++) {
            ch = fgetc(file);
            if (ch == EOF) {
                return 1;
            }
            res |= ch << (i * 8);
        }
        printf("%li\n", res);
    }
}