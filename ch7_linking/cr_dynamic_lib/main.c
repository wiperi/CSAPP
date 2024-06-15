#include <stdio.h>
#include "libvec.h"

int main(int argc, char* argv[], char* envp[]) {
    int x[2] = {1, 2};
    int y[2] = {3, 4};

    int z[2];

    addvec(x, y, z, 2);
    printf("z = [%d %d]\n", z[0], z[1]);

    mulvec(x, y, z, 2);
    printf("z = [%d %d]\n", z[0], z[1]);

    printf("addvec_count = %d\n", addvec_count);
    printf("mulvec_count = %d\n", mulvec_count);

    return 0;
}