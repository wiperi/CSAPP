/* $begin waitpid1 */
#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <semaphore.h>
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define N 2

int main() {
    int status, i;
    pid_t pid;

    /* Parent creates N children */
    for (i = 0; i < N; i++)                  // line:ecf:waitpid1:for
        if ((pid = fork()) == 0) /* Child */ // line:ecf:waitpid1:fork
            exit(100 + i);                   // line:ecf:waitpid1:exit

    /* Parent reaps N children in no particular order */
    while ((pid = waitpid(-1, &status, 0)) > 0) {                                                   // line:ecf:waitpid1:waitpid
        if (WIFEXITED(status))                                                                      // line:ecf:waitpid1:wifexited
            printf("child %d terminated normally with exit status=%d\n", pid, WEXITSTATUS(status)); // line:ecf:waitpid1:wexitstatus
        else
            printf("child %d terminated abnormally\n", pid);
    }

    /* The only normal termination is if there are no more children */
    if (errno != ECHILD) // line:ecf:waitpid1:errno
        fprintf(stderr, "waitpid error");

    exit(0);
}
/* $end waitpid1 */