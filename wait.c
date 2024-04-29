#include <stdio.h>
#include <unistd.h>

unsigned int  snooze(int sec) {
    unsigned int left = sleep(sec);
    printf("Slept for %d of %d seconds\n", sec - left, sec);
    return left;
}

int main(int argc, char* argv[]) {

    execve("/home/ilwin/Documents/csapp/CSAPP/bin/p", NULL, NULL);
    
    printf("father end.\n");

    return 0;
}