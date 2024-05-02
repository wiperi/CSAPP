// Given an UTF-8 string, return the index of the first invalid byte.
// If there are no invalid bytes, return -1.

// Do NOT change this function's return type or signature.

#include <stdint.h>

int invalid_utf8_byte(char* utf8_string) {

    // TODO: implement this function

    for (int i = 0; utf8_string[i] != '\0'; i++) {

        uint8_t ch = utf8_string[i];

        if ((ch >> 7) == 0) {
            // 0xxx = good
            continue;
        } else {
            // 1xxx = there are followings
            int k = 7;
            int len = 0;
            while (k >= 0) {
                if (((ch >> k) & 1) == 1) {
                    len++;
                } else {
                    break;
                }
                k--;
            }

            // check successive byte
            for (int j = 0; j < len; j++) {
                i++;
                ch = utf8_string[i];
                printf("%02x\n", ch);

                if ((ch >> 6) == 0b10) {
                    continue;
                } else {
                    return i + 1;
                }
            }
        }
    }

    return -1;
}
