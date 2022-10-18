#include "s21_string.h"

int s21_strcmp(const char *string1, const char *string2) {
    int res = 0;
    if (string1 != s21_NULL && string2 != s21_NULL) {
        s21_size_t len_str1 = s21_strlen(string1);
        s21_size_t len_str2 = s21_strlen(string2);
        if (len_str2 > len_str1) {
            res = -string2[len_str1];
        } else if (len_str2 < len_str1) {
            len_str1 = len_str2;
            res = string1[len_str2];
        }
        s21_size_t i = 0;
        while (i < len_str1 && string1[i] == string2[i]) {
            i++;
        }
        if (i < len_str1 && string1[i] > string2[i]) {
            res = 1;
        } else if (i < len_str1 && string1[i] < string2[i]) {
            res = -1;
        }
    }
    return res;
}
