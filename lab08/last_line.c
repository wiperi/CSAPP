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

    int ch;
    int bias = 0;
    int cursor;
    while (1) {
        if (fseek(file, -1 * bias, SEEK_END) == -1) {
            perror(argv[1]);
            exit(1);
        }

        ch = fgetc(file);
        if (bias > 0 && !isprint(ch) && ch == '\n') {
            // find the init of target line
            break;
        }

        bias++;
    }

    while ((ch = fgetc(file)) != EOF && isprint(ch)) {
        putchar(ch);
    }
    if (ch != '\n') {
        printf("\n");
    }
}