#include "s21_string.h"

char* s21_strrchr(const char *str, int c) {
    char* tp = s21_NULL;
    if (str != s21_NULL) {
        do {
        if ((*str) == (unsigned char)c) {
            tp = (char *) str;
        }
        } while (*str++);
    }
    return tp;
}

