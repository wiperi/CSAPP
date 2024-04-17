#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]) {
    char c;

    int input = 255;

    c = input;

    printf("%d %d\n", c, input);

    if (c == EOF) {
        printf("%c\n", input);
    }
}