#include "s21_string.h"

char* s21_strncat(char *str, char *append, s21_size_t kol) {
    int n = 0;
    int i = s21_strlen(str);
    while (i < (int)(s21_strlen(str) + s21_strlen(append)) && n < (int)kol) {
        str[i] = append[n];
        i++;
        n++;
    }
    str[i] = '\0';
    return str;
}
