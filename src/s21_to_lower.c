#include"s21_string.h"
#include<stdlib.h>

void *s21_to_lower(const char* start) {
    char *str;
    int flag = 0;
    if (start == s21_NULL) flag++;
    if (!flag) {
        str = malloc(sizeof(char) * s21_strlen(start) + 1);
        if (str == s21_NULL) flag++;
        if (!flag) {
            s21_strcpy(str, start);
            for (int i = 0; i < (int)s21_strlen(start); i++) {
                if (str[i] >= 'A' && str[i] <= 'Z') str[i] +=32;
            }
        }
    }
    if (!flag)  str[s21_strlen(start)] = '\0';
    if (flag) str = s21_NULL;
    return !flag ? str : s21_NULL;
}
