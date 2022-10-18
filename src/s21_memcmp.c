#include "s21_string.h"

int s21_memcmp(const void *string1, const void *string2, s21_size_t num) {
    unsigned char *str1 = (unsigned char *)string1;
    unsigned char *str2 = (unsigned char *)string2;
    int dif = 0;
    for (s21_size_t i = 0; i < num; i++) {
        dif = *str1 - *str2;
        if (*str1 != *str2) break;
        str1++;
        str2++;
    }
    return dif;
}
