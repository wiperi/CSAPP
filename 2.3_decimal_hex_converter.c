//
// Practice Problem 2.3 - convert decimal to hex and hex to decimal
//
// Introduction:
// Get a number from user, and print the hex and decimal of the number.
//
// Reference:
// NONE
//
// Authors:
// Tianyang Chen (z5567323@unsw.edu.au)
//
// Written: 2/6/2024
//
#include <stdio.h>
#include <math.h>
#include <string.h>

/**
 * Converts a decimal number to hexadecimal.
 *
 * To convert a decimal number x to hexadecimal, we can repeatedly divide x by 16,
 * giving a quotient q and a remainder r, such that x = q * 16 + r. We then use the
 * hexadecimal digit representing r as the least significant digit and generate the
 * remaining digits by repeating the process on q.
 *
 * @param n The decimal number to be converted to hexadecimal.
 */
void decimal_to_hex(int n) {
    if (n == 0) {
        return;
    }

    decimal_to_hex(n / 16); // pre-order traversal

    int remainder = n % 16;
    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", 'A' + remainder - 10);
    }
}

int to_decimal(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else {
        return hex - 'A' + 10;
    }
}

/**
 * Converts a hexadecimal number to decimal.
 *
 * @param n The hexadecimal number to be converted.
 */
void hex_to_decimal(char* n, int length) {
    int ret = 0;
    for (int i = 0; i < length; i++) {
        ret += to_decimal(n[i]) * pow(16, i);
    }
    printf("%d", ret);
}

int main() {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    printf("The hexadecimal representation is: ");
    decimal_to_hex(n);
    printf("\n");

    char hex[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    printf("The decimal representation is: ");
    hex_to_decimal(hex, strlen(hex));
    printf("\n");

    return 0;
}