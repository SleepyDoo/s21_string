#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t i;
    s21_size_t j;
    for (i=0; str1[i]; i++) {
        for (j=0; str2[j]; j++)
            if (str1[i] == str2[j])
                break;
        if (str1[i] == str2[j])
            break;
    }
    return i;
}

