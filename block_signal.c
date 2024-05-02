#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h"
// #include </usr/include/x86_64-linux-gnu/bits/sigaction.h>

// #include "/usr/include/x86_64-linux-gnu/bits/sigaction.h"
#include <x86_64-linux-gnu/bits/sigaction.h>

void handle_signal(int signum) {
    // Handle the signal here if needed
}

int main() {
    // Register the signal handler
    signal(SIGINT, handle_signal);

    // Block the SIGINT signal
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    printf("SIGINT signal blocked. Press Ctrl+C to test.\n");

    // Sleep for a while to simulate blocking the signal
    sleep(5);

    // Unblock the SIGINT signal
    sigprocmask(SIG_UNBLOCK, &mask, NULL);

    printf("SIGINT signal unblocked. Press Ctrl+C again to exit.\n");

    // Keep the program running until Ctrl+C is pressed again
    while (1) {
        // Do nothing
    }

    return 0;
}