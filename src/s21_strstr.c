#include "s21_string.h"


char* s21_strstr(const char *haystack, const char *needle) {
    const char * search = needle;
    const char * stopper = needle;
    const char * hay = haystack;
    const char * hays = haystack;
    char* tp = s21_NULL;
    while (*haystack != '\0') {
        hay = (const char *) haystack;
        if (*search == *hay) {
            while (*search == *hay) {
            search++;
            hay++;
            if (*(search) == '\0') {
                tp = (char *) haystack;
                break;
            }
            }
        }
        search = (const char *) stopper;
        haystack++;
    }
    if (s21_strlen(needle) == 0) tp = (char*)hays;
    return tp;
}
