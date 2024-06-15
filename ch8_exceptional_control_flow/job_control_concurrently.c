#include "/home/ilwin/Documents/CSAPP/csapp.h"

/**
 * Introduction:
 * 
 * The goal is to run a new job in the subprocess and add it to the job list.
 * After receiving a SIGCHLD signal, the handler will reap the zombie child, then remove it 
 * from the job list.
 * 
 * The difficulty is that coun't make sure that deletejob() will run after addjob(). Since they
 * are concurrent and not atomic.
 * 
 * As a solution, we use signal blocking to make sure they run the right order.
 * 
 */

void initjobs() {
}

void addjob(int pid) {
}

void deletejob(int pid) {
}

/* $begin procmask2 */
void handler(int sig) {
    int olderrno = errno;
    sigset_t mask_all, prev_all;
    pid_t pid;

    Sigfillset(&mask_all);
    while ((pid = waitpid(-1, NULL, 0)) > 0) { /* Reap a zombie child */
        Sigprocmask(SIG_BLOCK, &mask_all, &prev_all);
        deletejob(pid); /* Delete the child from the job list */
        Sigprocmask(SIG_SETMASK, &prev_all, NULL);
    }
    if (errno != ECHILD)
        Sio_error("waitpid error");
    errno = olderrno;
}

int main(int argc, char** argv) {
    int pid;
    sigset_t mask_all, mask_one, prev_one;

    Sigfillset(&mask_all);
    Sigemptyset(&mask_one);
    Sigaddset(&mask_one, SIGCHLD);
    Signal(SIGCHLD, handler);
    initjobs(); /* Initialize the job list */

    while (1) {
        Sigprocmask(SIG_BLOCK, &mask_one, &prev_one);  /* Block SIGCHLD */
        if ((pid = Fork()) == 0) {                     /* Child process */
            Sigprocmask(SIG_SETMASK, &prev_one, NULL); /* Unblock SIGCHLD */
            Execve("/bin/date", argv, NULL);
        }
        Sigprocmask(SIG_BLOCK, &mask_all, NULL);   /* Parent process */
        addjob(pid);                               /* Add the child to the job list */
        Sigprocmask(SIG_SETMASK, &prev_one, NULL); /* Unblock SIGCHLD */
    }
    exit(0);
}
/* $end procmask2 */