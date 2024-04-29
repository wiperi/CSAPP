#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    
    fork();
    waitpid(0, NULL, 0);

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
    }
    
}