//* // // // // // DO NOT MODIFY THIS FILE // // // // // // *//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef main
#undef main
#endif

#define BUF_INIT_SIZE 1024

int invalid_utf8_byte(char* utf8_string);
int get_utf_len(unsigned int ch);

int main(void) {
    char* buf = malloc(BUF_INIT_SIZE);
    assert(buf != NULL);

    int buf_size = BUF_INIT_SIZE;
    int buf_used = 0;

    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        if (buf_used == buf_size - 1) {
            buf_size *= 2;
            buf = realloc(buf, buf_size);
            assert(buf != NULL);
        }
        buf[buf_used++] = c;
    }

    buf[buf_used] = '\0';

    int result = invalid_utf8_byte(buf);

    if (result == -1) {
        printf("No invalid bytes found.\n");
    } else {
        printf("Invalid byte found at index %d.\n", result);
    }

    return 0;
}

int get_utf_len(unsigned int ch) {
    int i = 7;
    int len = 0;
    while (i >= 0) {
        if (((ch >> i) & 1) == 1) {
            len++;
        } else {
            return len;
        }
        i--;
    }
}

int invalid_utf8_byte(char* utf8_string) {

    // TODO: implement this function

    for (int i = 0; utf8_string[i] != '\0'; i++) {

        unsigned int ch = utf8_string[i];

        if ((ch >> 7) == 0) {
            // 0xxx = good
            continue;
        } else {
            // 1xxx = there are followings
            int len = get_utf_len(ch);

            // check successive byte
            for (int j = 0; j < len; j++) {
                i++;
                ch = utf8_string[i];

                if ((ch >> 6) == 0b10) {
                    continue;
                } else {
                    return i;
                }
            }
        }
    }

    return -1;
}
