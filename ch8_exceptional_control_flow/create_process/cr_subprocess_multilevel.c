/**
 * Name:
 * Create childs and grandsons
 *
 * Introduction:
 * Create serveral childprocess, and see that child will also create their child too.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[], char* envp[]) {

    // the 1 iteration:
    // parent -> kid1
    // the 2 iteration:
    // parent -> kid2
    // kid1 -> kid3


    printf("Parent is %d\n", getpid());

    int pid;
    for (int i = 0; i < 2; i++) {

        if ((pid = fork()) == 0) {
            printf("Kid %d is running.\n", getpid());
        }
    }

    return 0;
}
