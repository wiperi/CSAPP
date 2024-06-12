#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    
    while (1) {
        eval();

        if (is_exit()) {
            break;
        }

        do_command();
    }

    return 0;
}