#include <stdlib.h>
#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
    char *res = s21_NULL;

    if (src) {
        if (trim_chars && *trim_chars) {
            s21_size_t len = s21_strlen(src);
            s21_size_t chars_len = s21_strlen(trim_chars);

            s21_size_t m = 0;
                while (src && m != chars_len) {
                    if ((*src) == trim_chars[m]) {
                    src++;
                    len -= 1;
                    m = 0;
                    continue;
                    }
                    m++;
                    }
                if (len) {
                    s21_size_t e = 0;
                    s21_size_t t = len - 1;
                    while (src && e != chars_len) {
                        if (src[t] == trim_chars[e]) {
                            t--;
                            len--;
                            e = 0;
                            continue;
                            }
                            e++;
                        }
                }
            res = (char *)malloc(sizeof(char) * (len + 1));
            if (res) {
                for (s21_size_t i = 0; i < len + 1; i++) {
                    if (i < len) {
                        res[i] = src[i];
                    } else {
                        res[i] = '\0';
                    }
                }
            }
        } else {
            res = s21_trim(src, " \t\n");
        }
    }

    return res;
}
