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

int snooze(int t) {
    int left = sleep(t);
    printf("Sleep for %d seconds.\n", t - left);
    return left;
}

void sigint_handler() {
    return;
}

int main(int argc, char *argv[], char *envp[]) {

    if (argc != 2) {
        return 0;
    }
    
    signal(SIGINT, sigint_handler);

    snooze(atoi(argv[1]));
}