#include "s21_string.h"

char* s21_strcat(char *str, char *append) {
    s21_size_t i = s21_strlen(str);
    s21_size_t m = s21_strlen(append);
    for (s21_size_t n = 0; n < m; n++) {
        str[i] = append[n];
        i++;
    }
    str[i] = '\0';
    return str;
}
