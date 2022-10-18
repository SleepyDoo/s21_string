#include"s21_string.h"

char* s21_strerror(int num) {
    static char str[200];
    if (num < 0 || num > AMOUNT_ERROR) {
#if __linux__
        s21_sprintf(str, "Unknown error %d", num);
#endif
#if __APPLE__
        s21_sprintf(str, "Unknown error: %d", num);
#endif
    } else {
    ERROR_ARRAY
        s21_sprintf(str, "%s", errorstr[num]);
    }
    return str;
}
