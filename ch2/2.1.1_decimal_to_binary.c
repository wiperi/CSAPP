#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void decimal_to_binary_integer_part(int decimal) {
    // an array to store binary result
    int* binary = (int*)malloc(64 * sizeof(int));

    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

void decimal_to_binary_fraction_part(double decimal) {
    const int PRECISION = 100;
    printf(".");

    int i = 0;
    // binary result of 0.[i th] digit
    int temp = 0;
    while (i < PRECISION && decimal > 0.0) {
        temp = floor(decimal * 2);
        printf("%d", temp);
        decimal = decimal * 2 - temp;
        i++;
    }
}

void decimal_to_binary(double decimal) {
    int integer_part = (int)decimal;
    decimal_to_binary_integer_part(integer_part);
    decimal_to_binary_fraction_part(decimal - integer_part);
    printf("\n");
}

int main(int argc, char* argv[]) {

    // [10]10.3 = [2]1010.01001100...
    decimal_to_binary(10.3);
}