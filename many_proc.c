#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[], char* envp[]) {

    for (int t = 0; t < 2; t++) {
        int pid = fork();
        if (pid == 0) {
            printf("child %d\n", t);
        }
    }
}