#include "s21_string.h"

char* s21_strpbrk(const char *str1, const char *str2) {
    int tmp = (int)  s21_strlen(str1);
    int mp =  (int) s21_strlen(str2);
    const char * str_f = (const char *) str1;
    const char * str_s = (const char *) str2;
    char* tp = s21_NULL;
    for (int i = 0; i < (mp); i++) {
        for (int j = 0; j < tmp; j++) {
            if ((*str_f) == (*str_s)) {
                tp = (char *) str_f;
                break;
            }
            str_f++;
        }
        if (tp != s21_NULL) {
            break;
        }
        str_s++;
        str_f = str1;
    }
    return tp;
}

