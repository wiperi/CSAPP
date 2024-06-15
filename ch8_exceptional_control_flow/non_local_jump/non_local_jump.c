#include "/home/ilwin/Documents/CSAPP/csapp.h"

/**
 * Introduction:
 *
 * Jump from one function to another without returning to the caller.
 *
 * setjmp() will return twice, once when it is called and once when longjmp() is
 * called. First time setjmp() is called, it will return 0. When longjmp() is
 * called, it will return the value passed to longjmp().
 *
 */
jmp_buf buf;

int call = 0;

void foo(void), bar(void);

int main() {
    switch (setjmp(buf)) {
    case 0:
        foo();
        break;
    case 1:
        printf("Detected an error 1 condition in foo\n");
        break;
    case 2:
        printf("Detected an error 2 condition in bar\n");
        break;
    default:
        printf("Unknown error condition\n");
    }
    exit(0);
}

/* Deeply nested function foo */
void foo(void) {
    if (call > 10) longjmp(buf, 1);
    call++;
    bar();
}

void bar(void) {
    if (call > 10) longjmp(buf, 2);
    call++;
    foo();
}
/* $end setjmp */