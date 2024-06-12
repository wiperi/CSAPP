#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sigint_handler() {
    printf("SIGINT caught.\n");

}

int main(int argc, char *argv[], char *envp[]) {

    signal(SIGINT, sigint_handler);

    pause();

    return 0;
    
}