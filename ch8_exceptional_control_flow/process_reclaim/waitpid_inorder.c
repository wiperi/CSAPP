/* $begin waitpid2 */
/**
 * Introduction:
 *
 * Create N children, and wait for them to terminate in order.
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 2

int main() {
    int status, i;
    pid_t pid[N], retpid;

    /* Parent creates N children */
    for (i = 0; i < N; i++)
        if ((pid[i] = fork()) == 0) /* Child */ // line:ecf:waitpid2:fork
        {
            exit(100 + i);
        }

    /* Parent reaps N children in order */
    i = 0;
    while ((retpid = waitpid(pid[i++], &status, 0)) > 0) { // line:ecf:waitpid2:waitpid
        if (WIFEXITED(status))
            // kids terminated via exit()
            printf("child %d terminated normally with exit status=%d\n", retpid, WEXITSTATUS(status));
        else
            printf("child %d terminated abnormally\n", retpid);
    }

    /* The only normal termination is if there are no more children */
    if (errno != ECHILD)
        fprintf(stderr, "waitpid error");

    exit(0);
}
/* $end waitpid2 */