#include "csapp.h"
/* $begin signal1 */

/**
 * Introduction:
 * 
 * This program demonstrates the use of signal handlers to reap zombie children.
 * Every time a SIGCHLD signal is recieved, the handler will try to reap as many child as possible.
 */

void handler1(int sig) {
    int olderrno = errno;

    // Wrong, reap on each time will lost some child.
    // because some signal will be lost since signal don't queue
    if ((waitpid(-1, NULL, 0)) < 0)
        sio_error("waitpid error");
    Sio_puts("Handler reaped child\n");
    Sleep(1);
    errno = olderrno;
}

void handler2(int sig) {
    int olderrno = errno;

    // Right
    // Reap as many as possible
    while (waitpid(-1, NULL, 0) > 0) {
        Sio_puts("Handler reaped child\n");
    }
    if (errno != ECHILD)
        Sio_error("waitpid error");
    Sleep(1);
    errno = olderrno;
}

int main() {
    int i, n;
    char buf[MAXBUF];

    if (signal(SIGCHLD, handler1) == SIG_ERR)
        unix_error("signal error");

    /* Parent creates children */
    for (i = 0; i < 3; i++) {
        if (Fork() == 0) {
            printf("Hello from child %d\n", (int)getpid());
            exit(0);
        }
    }

    /* Parent waits for terminal input and then processes it */
    if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0)
        unix_error("read");

    printf("Parent processing input\n");
    while (1)
        ;

    exit(0);
}
/* $end signal1 */