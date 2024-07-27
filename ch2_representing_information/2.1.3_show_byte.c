/**
 * Name:
 * Show byte
 * 
 * Introduction:
 * Show the byte representation of a data structure.
 */
#include <stdio.h>

typedef unsigned char* byte_pointer;

/**
 * This function treats the given data structure as an array of bytes.
 * Then it prints the value of each byte in the memory.
 * 
 * @param start the start address of the data structure
 * @param len the length of the data structure
 */
void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void* x) {
    show_bytes((byte_pointer) &x, sizeof(void*));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int* pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main(int argc, char* argv[]) {
    int val = 12345;
    printf("calling test_show_bytes\n");
    test_show_bytes(val);

    return 0;
}