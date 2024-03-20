#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    int a = -55;
    unsigned int b = (unsigned int) a;
    double c = a;
    printf("a: %d\n", a);
    show_bytes((byte_pointer) &a, sizeof(int));
    printf("b: %u\n", b);
    show_bytes((byte_pointer) &b, sizeof(unsigned int));
    printf("c: %lf\n", c);
    show_bytes((byte_pointer) &c, sizeof(double));
}