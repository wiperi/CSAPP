//
// DPST1091 Lab 10 Exercise - Shift Operation in C
// 
// Introduction:
// This program shows the property of shift operation in C.
// 
// Reference
// 
// 
// Authors:
// Tianyang Chen (z5567323@unsw.edu.au)
// 
// Written: 19/03/2024
//
#include <stdio.h>

void int_to_binary(int x) {
    int i;
    for (i = 0; i < 32; i++) {
        printf("%d", (x >> (31 - i)) & 0x0001);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    printf("In C, right shift is arithmetic.\n");
    int a = 0x80000000;
    printf("a:\n");
    int_to_binary(a); // 10000000000000000000000000000000
    printf("a >> 4:\n");
    int_to_binary(a >> 16); // 11111111111111111000000000000000

    printf("\n");

    printf("Over size shifting. If shift too far, the shift distance will be mod by sizeof(data structure)\n");
    a = 0x1;
    printf("a:\n");
    int_to_binary(a);
    printf("a << 36 == a << 36 %% 32 == a << 4:\n");
    int_to_binary(a << 36);
}