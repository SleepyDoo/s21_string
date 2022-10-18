#include "s21_string.h"


char* s21_strchr(const char *str, int c) {
    char* null_check = s21_NULL;
    int flag = 0;
    for (; *str != (unsigned char) c; str++) {
        if (*str == '\0') {
            flag++;
            break;
        }
    }
    return (!flag) ? (char*) str : null_check;
}
