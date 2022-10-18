#include "s21_string.h"


void* s21_memchr(const void*str, int c, s21_size_t n) {
    const char * str_c = (const char *) str;
    s21_size_t tmp = n;
    void* tp = s21_NULL;
    unsigned char A;
    while (tmp--) {
        A = * (unsigned char *) str_c;
        if (A == (unsigned char) c) {
            tp = (void *) str_c;
            break;
        }
        str_c++;
    }
    return tp;
}
