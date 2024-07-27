#include <stdio.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_binary(byte_pointer start, size_t len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d", (start[i] >> (7 - j)) & 0x1);
        }
        printf(" ");
    }
    printf("\n");
}

int main(int argc, char* argv[]) {

    // signed expanded to int
    short s = 0xaaff;
    int i = s;
    printf("s: %d\n", s);
    show_bytes((byte_pointer) &s, sizeof(short));
    show_binary((byte_pointer) &s, sizeof(short));
    printf("i: %d\n", i);
    show_bytes((byte_pointer) &i, sizeof(int));
    show_binary((byte_pointer) &i, sizeof(int));
}