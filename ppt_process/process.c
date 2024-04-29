#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    printf("%d\n", getpid());

    fork();

    for (int i = 0; i < 100; i++) {
        printf("%d: %d\n", getpid(), i);
    }
}