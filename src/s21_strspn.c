#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t i = 0;
    int flag = 0;
    for (; str1[i]; i++) {
        for (int j=0; str2[j]; j++)
            if (str1[i] == str2[j]) {
                flag = 1;
                break;
            }
        if (flag == 0)
            break;
        flag = 0;
    }
    return i;
}
