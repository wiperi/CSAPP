#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

    int pid = fork();
    int status;

    if (pid == 0) {
        printf("child sleeping\n");
        sleep(2);
        return 0;
    } else {
        printf("parent\n");
    }

    wait(&status);

    if (WIFEXITED(status)) {
        printf("child exited with status %d\n", WEXITSTATUS(status));
    } else {
        printf("child exited abnormally\n");
    }

    return 0;
}