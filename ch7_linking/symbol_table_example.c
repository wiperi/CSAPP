// to see the symbol table of hello.o
// $linux> objdump -t *.o
#include <stdio.h>

// weak global symbol, symbol entry in COMMON section of object file
int weak;

// strong global symbol, symbol entry in .DATA section of object file
int strong = 1;

// strong global symbol, symbol entry in .BSS section of object file
int strong2 = 0;

// strong global symbol, symbol entry in .text section of object file
void func1() {

}

void func2() {

}

void func3();

int main(int argc, char *argv[], char *envp[]) {

    // strong global symbol, symbol entry in .DATA section of object file, named a.0
    static int a = 1;

    // local symbol, not included in symbol table of object file
    // will be handled by assembler, appear in the runtime usr stack
    int local = 0;

    // undefined symbol, waiting to be resolved by linker
    scanf("%d", &a);
    printf("hello.\n");

    // undefined symbol, waiting to be resolved by linker
    func3();
}