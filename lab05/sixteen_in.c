// Convert string of binary digits to 16-bit signed integer

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define N_BITS 16

int16_t sixteen_in(char* bits);

int main(int argc, char* argv[]) {

    // for (int arg = 1; arg < argc; arg++) {
    //     printf("%d\n", sixteen_in(argv[arg]));
    // }

    char input[17];
    fgets(input, 17, stdin);
    
    printf("%d\n", sixteen_in(input));

    return 0;
}

//
// given a string of binary digits ('1' and '0')
// return the corresponding signed 16 bit integer
//
int16_t sixteen_in(char* bits) {

    // U2T(x) = x - 2^w (x > Tmax)

    int16_t res = 0;

    if (*bits == '0') {
        return (int16_t) atoi(bits);
    } else {
        return (int16_t) atoi(bits) - ((int) pow(2, 16));
    }
    

    return 0;
}
