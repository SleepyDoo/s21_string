#include"s21_string.h"

char* s21_strtok(char* str, const char* delim) {
    int flag = 0;
    static char* last = 0;
    char* start = s21_NULL;
    if (str) last = str;
    if ((last == 0) || (*last == 0)) flag++;
    if (!flag) {
        char* ch = last;
        while (s21_strchr(delim, *ch)) ch++;
        if (*ch == 0) flag++;
        if (!flag) {
            start = ch;
            while (*ch && (s21_strchr(delim, *ch) == 0)) ch++;
            if (*ch == 0) {
                last = ch;
                flag++;
            }
            if (!flag) {
                *ch = 0;
                last = ch + 1;
            }
        }
    }
    return start;
}
