/**
 * Name:
 * Create child only via parent process
 *
 * Introduction:
 * Create serveral childprocess, but childprocess are not allowed to create childprocess.
 */
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
