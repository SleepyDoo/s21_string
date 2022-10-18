#include"s21_string.h"
#include<stdlib.h>

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char* out;
    int flag = 0;
    if (src == s21_NULL || start_index > s21_strlen(src)) flag++;
    if (!flag) {
        out = malloc(sizeof(char) * (s21_strlen(str) + s21_strlen(src) + 1));
        if (out == s21_NULL) flag++;
        if (!flag) {
            s21_strncpy(out, src, start_index);
            s21_size_t n = 0;
            for (s21_size_t i = start_index; n < s21_strlen(str); i++) {
                out[i] = str[n];
                n++;
            }
            for (s21_size_t i = start_index + s21_strlen(str); i < s21_strlen(str) + s21_strlen(src); i++) {
                out[i] = src[i - s21_strlen(str)];
            }
            out[s21_strlen(str) + s21_strlen(src)] = '\0';
        }
    }
    return !flag ? out : s21_NULL;
}
