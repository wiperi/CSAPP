/**
 * Name:
 * Create child only via parent process
 *
 * Introduction:
 * Create serveral childprocess, but childprocess are not allowed to create childprocess.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[], char* envp[]) {

    int pid = 0;

    for (int i = 0; i < 3; i++) {
        if ((pid = fork()) == 0) {
            // only child will excute these code

            printf("Kid process %d running.\n", getpid());

            // make sure child proces ends here, so they won't go to new iteration and create more grandson process
            exit(0);
        }
    }
}
