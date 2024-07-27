//
// Name: Inplace Swap
//
// Introduction:
// Swap two integers without using a temporary variable.
//
// Reference
// CSAPP Pratice Problem 2.10 pg.90
//
// Authors:
// Tianyang Chen (z5567323@unsw.edu.au)
//
// Written: 19/03/2024
//
#include <stdio.h>

/**
 * The swap has 3 steps.
 * 1. y = x ^ y
 * 2. x = x ^ (x ^ y) = y
 * 3. y = y ^ (x ^ y) = x
 * 
 * Noticed that this method doesn't have performance advantage.
 */
void inplace_swap(int* x, int* y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

int main(int argc, char* argv[]) {
    int a = 123;
    int b = 456;
    printf("Before swap: a = %d, b = %d\n", a, b);
    inplace_swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);
}