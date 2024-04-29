#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t p = getpid();

    pid_t pp = getppid();

    printf("%d\n", p);
}