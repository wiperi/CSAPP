// generate the encoded binary for an addi instruction, including opcode and operands

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "addi.h"

// return the encoded binary MIPS for addi $t,$s, i
uint32_t addi(int t, int s, int i) {

    assert(t > 0 && t < 32);
    assert(s > 0 && s < 32);
    assert(i < (1 << 16));

    uint32_t res = 0;

    // build opcode
    res = 0b001000 << 26;

    // build source
    res |= s << 21;

    // build dest
    res |= t << 16;

    // build imm val
    res |= i;

    return res;
}

int main(int argc, char const* argv[]) {
    addi(9, 27, 42);

    return 0;
}
