#include <stdarg.h>
#include <stdlib.h>
#include "s21_string.h"
#include <limits.h>

void* my_itoa(__int128 n, char * s, int radix, int sign, int precision);
void my_ftoa(__float128 n, char *s, int digits, int sign);

int s21_sprintf(char *str, const char *format, ...) {
    va_list vars;
    va_start(vars, format);
    struct flags flag = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int null_precision = 0;
    int null_p = -1;
    int nulls = 0;
    s21_strcpy(str, "");
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && !flag.format_f) {
            flag.format_f = 1;
            continue;
        }
        if (flag.format_f) {
            if (format[i] == '+') {
                flag.sign = 1;
            } else if (format[i] == ' ') {
                if (flag.sign != 1) {
                    flag.sign = 2;
                }
            } else if (format[i] == '-' && !flag.dot) {
                flag.align = 1;
                flag.zero_width = 0;
            } else if (format[i] == '-' && flag.dot) {
                flag.set_precision = 0;
                null_precision = 1;
            } else if (format[i] == '#') {
                flag.spec = 1;
            } else if (format[i] <= '9' && format[i] >= '0' && !flag.dot) {
                if (format[i] == '0' && !flag.align)
                    flag.zero_width = 1;
                while (format[i] <= '9' && format[i] >= '0') {
                    int n = format[i] - '0';
                    flag.width = flag.width * 10 + n;
                    i++;
                }
                i--;
            } else if (format[i] == '*' && !flag.dot) {
                flag.width = va_arg(vars, int);
                if (flag.width < 0) {
                    flag.width *= -1;
                    flag.align = 1;
                }
            } else if (format[i] == '.') {
                flag.dot = 1;
                flag.set_precision = 1;
            } else if (format[i] == '*' && flag.dot) {
                flag.precision = va_arg(vars, int);
                if (flag.precision < 0) {
                    flag.set_precision = 0;
                    null_precision = 1;
                }
            } else if (format[i] <= '9' && format[i] >= '0' && flag.dot) {
                while (format[i] <= '9' && format[i] >= '0') {
                    flag.precision = flag.precision * 10 + (format[i] - '0');
                    i++;
                }
                i--;
                if (null_precision) {
                    if (!flag.width) {
                        flag.width = flag.precision;
                        flag.align = 1;
                    }
                    flag.precision = 0;
                }
            } else {
                if (format[i] == 'h') {
                    flag.length -= 1;
                } else if (format[i] == 'l') {
                    flag.length += 1;
                } else if (format[i] == 'L') {
                    flag.double_length = 1;
                } else {
                    char new_string[1000] = {'\0'};
                    if (format[i] == 'd' || format[i] == 'i' \
                    || format[i] == 'o' || format[i] == 'x' || format[i] == 'X') {
                        if (!flag.set_precision) {
                            flag.precision = 1;
                        }
                        flag.if_num = 1;
                        int radix = 10;
                        if (format[i] == 'o') {
                            radix = 8;
                        } else if (format[i] == 'x' || format[i] == 'X') {
                            radix = 16;
                        }
                        if (format[i] == 'i' || format[i] == 'd') {
                            if (flag.set_precision)
                                flag.zero_width = 0;
                            else
                                flag.precision = 1;
                            __int128 n = va_arg(vars, long long int);
                            if (!(n || flag.precision)) {
                                if (flag.sign == 1)
                                    s21_strcpy(new_string, "+");
                                else if (flag.sign == 2)
                                    s21_strcpy(new_string, " ");
                            } else {
                                if (flag.length == -2) {
                                    short int m = (char) n;
                                    my_itoa(m, new_string, 10, flag.sign, flag.precision);
                                } else if (flag.length == -1) {
                                    short int m = (short int) n;
                                    my_itoa(m, new_string, 10, flag.sign, flag.precision);
                                } else if (flag.length == 1) {
                                    if (n == LONG_MIN) {
                                        s21_strcat(new_string, "-9223372036854775808");
                                    } else {
                                        long int m = (long int) n;
                                        my_itoa(m, new_string, 10, flag.sign, flag.precision);
                                    }
                                } else if (flag.length == 2) {
                                    my_itoa(n, new_string, 10, flag.sign, flag.precision);
                                } else {
                                    int m = (int) n;
                                    my_itoa(m, new_string, 10, flag.sign, flag.precision);
                                }
                            }
                        } else {
                            unsigned long long int n = va_arg(vars, long long int);
                            if (n == 0) {
                                flag.spec = 0;
                            }
                            if (!flag.set_precision)
                                flag.precision = 1;
                            if (n || flag.precision) {
                                if (flag.spec == 1 && format[i] == 'o')
                                    flag.precision--;
                                if (flag.length == -2) {
                                    unsigned short int m = (unsigned char) n;
                                    my_itoa(m, new_string, radix, 0, flag.precision);
                                } else if (flag.length == -1) {
                                    unsigned short int m = (unsigned short int) n;
                                    my_itoa(m, new_string, radix, 0, flag.precision);
                                } else if (flag.length == 1) {
                                    unsigned long int m = (unsigned long int) n;
                                    my_itoa(m, new_string, radix, 0, flag.precision);
                                } else if (flag.length == 2) {
                                    my_itoa(n, new_string, radix, 0, flag.precision);
                                } else {
                                    unsigned int m = (unsigned int) n;
                                    my_itoa(m, new_string, radix, 0, flag.precision);
                                }
                            }
                        }
                        if ((format[i] == 'X' || format[i] == 'x') && flag.spec) {
                            int k = (int) s21_strlen(new_string);
                            while (k != -1) {
                                new_string[k + 2] = new_string[k];
                                k--;
                            }
                            new_string[0] = '0';
                            new_string[1] = format[i];
                        } else if (format[i] == 'o' && flag.spec) {
                            int k = (int) s21_strlen(new_string);
                            while (k != -1) {
                                new_string[k + 1] = new_string[k];
                                k--;
                            }
                            new_string[0] = '0';
                        }
                    } else if (format[i] == 'e' || format[i] == 'E' || format[i] == 'g' || format[i] == 'G') {
                        flag.if_num = 1;
                        double num;
                        if (flag.double_length)
                            num = va_arg(vars, long double);
                        else
                            num = va_arg(vars, double);
                        double num_copy = num;
                        if (!flag.set_precision)
                            flag.precision = 6;
                        int exp = 0;
                        int num_sign = 1;
                        if (num < 0) {
                            num_sign = -1;
                            num = num * -1;
                        }
                        if (num >= 10) {
                            while (num > 10) {
                                num /= 10;
                                exp++;
                            }
                        } else if (num != 0) {
                            while (num * 10 < 10) {
                                num *= 10;
                                exp--;
                            }
                        }
                        char test_len_str[20];
                        char test_precision_str[20];
                        if (format[i] == 'e' || format[i] == 'E')
                            my_itoa(flag.precision, test_precision_str, 10, 0, 0);
                        else if (!(exp >= -4 && flag.precision > exp))
                            my_itoa(flag.precision - 1, test_precision_str, 10, 0, 0);
                        else if (flag.precision)
                            my_itoa(flag.precision - 1 - exp, test_precision_str, 10, 0, 0);
                        else
                            my_itoa(-exp, test_precision_str, 10, 0, 0);
                        char test_format[10] = "%.";
                        s21_strcat(test_format, test_precision_str);
                        s21_strcat(test_format, "f");
                        s21_sprintf(test_len_str, test_format, num);
                        if ((test_len_str[0] == '1' && test_len_str[1] == '0') || \
                        (test_len_str[1] == '1' && test_len_str[2] == '0')) {
                            num /= 10;
                            exp++;
                        }
                        char format_string[100] = "%";
                        if (flag.sign == 1) {
                            s21_strcat(format_string, "+");
                        } else if (flag.sign == 2) {
                            s21_strcat(format_string, " ");
                        }
                        if (flag.spec) {
                            s21_strcat(format_string, "#");
                        }
                        if (format[i] == 'g' || format[i] == 'G') {
                            if (exp >= -4 && flag.precision > exp) {
                                if (!flag.precision)
                                    flag.precision = 1;
                                flag.precision = flag.precision - exp - 1;
                                num = num_copy;
                                num_sign = 1;
                            } else {
                                flag.precision--;
                            }
                            if (flag.precision < 0)
                                flag.precision = 0;
                        }
                        char precision_str[20];
                        my_itoa(flag.precision, precision_str, 10, 0, 0);
                        s21_strcat(format_string, ".");
                        s21_strcat(format_string, precision_str);
                        if (format[i] == 'E') {
                            s21_strcat(format_string, "fE%+.2d");
                            s21_sprintf(new_string, format_string, num * num_sign, exp);
                        } else if (format[i] == 'e') {
                            s21_strcat(format_string, "fe%+.2d");
                            s21_sprintf(new_string, format_string, num * num_sign, exp);
                        } else {
                            s21_strcat(format_string, "f");
                            char trim_zeroes[20];
                            s21_sprintf(trim_zeroes, format_string, num * num_sign);
                            if (s21_strcspn(trim_zeroes, ".") != (s21_strlen(trim_zeroes) - 1)) {
                                s21_size_t str_len = s21_strlen(trim_zeroes) - 1;
                                while (trim_zeroes[str_len] == '0' || trim_zeroes[str_len] == '.') {
                                    if (trim_zeroes[str_len] == '.') {
                                        str_len--;
                                        break;
                                    }
                                    str_len--;
                                }
                                trim_zeroes[str_len + 1] = '\0';
                            }
                            if (num != num_copy && format[i] == 'g') {
                                s21_sprintf(new_string, "%se%+.2d", trim_zeroes, num * num_sign, exp);
                            } else if (num != num_copy && format[i] == 'G') {
                                s21_sprintf(new_string, "%sE%+.2d", trim_zeroes, num * num_sign, exp);
                            } else {
                                s21_sprintf(new_string, "%s", trim_zeroes, num, exp);
                            }
                        }
                    } else if (format[i] == 'c') {
                        if (flag.length > 0) {
                            wchar_t c = (wchar_t) va_arg(vars, unsigned long int);
                            if (c != '\0') {
                                new_string[0] = c;
                                new_string[1] = '\0';
                            } else {
                                if (null_p == -1) {
                                    if (!flag.align) {
                                        if (flag.width)
                                            null_p = s21_strlen(str) + flag.width - 1;
                                        else
                                            null_p = s21_strlen(str);
                                    } else {
                                        null_p = s21_strlen(str);
                                    }
                                    new_string[0] = 0;
                                }
                                flag.width -= 1;
                                nulls++;
                            }
                        } else {
                            unsigned char c = (unsigned char) va_arg(vars, int);
                            if (c != '\0') {
                                new_string[0] = c;
                                new_string[1] = '\0';
                            } else {
                                if (null_p == -1) {
                                    if (!flag.align) {
                                        if (flag.width)
                                            null_p = s21_strlen(str) + flag.width - 1;
                                        else
                                            null_p = s21_strlen(str);
                                    } else {
                                        null_p = s21_strlen(str);
                                    }
                                    new_string[0] = 0;
                                }
                                flag.width -= 1;
                                nulls++;
                            }
                        }
                    } else if (format[i] == 's') {
                        if (!flag.set_precision)
                            flag.precision = -1;
                        if (flag.length > 0) {
                            wchar_t *temp = va_arg(vars, wchar_t*);
                            if (temp != NULL) {
                                int j = 0;
                                if (flag.precision) {
                                    while (temp[j] != '\0' && (flag.precision) != 0) {
                                        new_string[j] = temp[j];
                                        j++;
                                        flag.precision--;
                                    }
                                }
                                new_string[j] = '\0';
                            } else {
                                if (flag.precision < 6 && flag.precision > 0)
                                    s21_strncpy(new_string, "(null)", flag.precision);
                                else if (flag.precision)
                                    s21_strcpy(new_string, "(null)");
                            }
                        } else {
                            char *temp = va_arg(vars, char*);
                            if (temp != NULL) {
                                if (flag.precision > 0)
                                    s21_strncpy(new_string, temp, flag.precision);
                                else if (flag.precision)
                                    s21_strcpy(new_string, temp);
                            } else {
                                if (flag.precision < 6 && flag.precision > 0)
                                    s21_strncpy(new_string, "(null)", flag.precision);
                                else if (flag.precision)
                                    s21_strcpy(new_string, "(null)");
                            }
                        }
                    } else if (format[i] == '%') {
                        new_string[0] = '%';
                        new_string[1] = '\0';
                        flag.width = 1;
                    } else if (format[i] == 'p') {
                        if (!flag.set_precision)
                            flag.precision = 1;
                        flag.if_num = 1;
                        int* a = va_arg(vars, int *);
                        my_itoa((long long int) a, new_string, 16, 0, flag.precision);
                        int k = (int) s21_strlen(new_string);
                        while (k != -1) {
                            new_string[k + 2] = new_string[k];
                            k--;
                        }
                        new_string[0] = '0';
                        new_string[1] = 'x';
                    } else if (format[i] == 'n') {
                        if (flag.length == -2)
                            *(char *) va_arg(vars, char *) = s21_strlen(str);
                        else if (flag.length == -1)
                            *(short int *) va_arg(vars, short int *) = s21_strlen(str);
                        else if (flag.length == 0)
                            *(int *) va_arg(vars, int *) = s21_strlen(str);
                        else if (flag.length == 1)
                            *(long int *) va_arg(vars, long int *) = s21_strlen(str);
                        else if (flag.length == 2)
                            *(long long int *) va_arg(vars, long long int *) = s21_strlen(str);
                        flag.width = 0;
                    } else if (format[i] == 'f') {
                        flag.if_num = 1;
                        if (!flag.set_precision)
                            flag.precision = 6;
                        if (flag.double_length)
                            my_ftoa(va_arg(vars, long double), new_string, flag.precision, flag.sign);
                        else
                            my_ftoa(va_arg(vars, double), new_string, flag.precision, flag.sign);
                        if (flag.spec && !flag.precision)
                            s21_strcat(new_string, ".");
                    } else if (format[i] == 'u') {
                        flag.if_num = 1;
                        __int128 n = (__int128) va_arg(vars, unsigned long long);
                        if (!flag.set_precision)
                            flag.precision = 1;
                        if (flag.precision || n) {
                            if (flag.length == -2) {
                                short unsigned int num = n % 256;
                                my_itoa(num, new_string, 10, 0, flag.precision);
                            } else if (flag.length == -1) {
                                short unsigned int num = (short unsigned int) n;
                                my_itoa(num, new_string, 10, 0, flag.precision);
                            } else if (flag.length == 1 || flag.length == 2) {
                                if (n == ULONG_MAX) {
                                    s21_strcpy(new_string, "18446744073709551615");
                                } else {
                                    long long unsigned int num = (long long unsigned int) n;
                                    if (n >= 0)
                                        my_itoa(n, new_string, 10, 0, flag.precision);
                                    else
                                        my_itoa(num, new_string, 10, 0, flag.precision);
                                }
                            } else {
                                unsigned int num = (unsigned int) n;
                                my_itoa(num, new_string, 10, 0, flag.precision);
                            }
                        }
                    } else {
                        new_string[0] = format[i];
                        new_string[1] = '\0';
                    }
                    if (s21_strlen(new_string) < (s21_size_t) flag.width) {
                        char* space = " \0";
                        if (flag.zero_width && flag.if_num) {
                            space = "0\0";
                            if (new_string[1] == 'x' || new_string[1] == 'X') {
                                char ch[3];
                                ch[0] = new_string[0];
                                ch[1] = new_string[1];
                                ch[2] = '\0';
                                s21_strcat(str, ch);
                                int k = 0;
                                while (new_string[k] != '\0') {
                                    new_string[k] = new_string[k + 2];
                                    k++;
                                }
                                new_string[k] = '\0';
                                flag.width = flag.width - 2;
                            } else if (new_string[0] > '9' || new_string[0] < '0') {
                                char ch[2];
                                ch[0] = new_string[0];
                                ch[1] = '\0';
                                s21_strcat(str, ch);
                                int k = 0;
                                while (new_string[k] != '\0') {
                                    new_string[k] = new_string[k + 1];
                                    k++;
                                }
                                new_string[k] = '\0';
                                flag.width = flag.width - 1;
                            }
                        }
                        flag.width -= s21_strlen(new_string);
                        if (flag.align) {
                            while (flag.width > 0) {
                                s21_strcat(new_string, space);
                                flag.width--;
                            }
                        } else {
                            while (flag.width > 0) {
                                s21_strcat(str, space);
                                flag.width--;
                            }
                        }
                    }
                    if (format[i] == 'x' || format[i] == 'g' || format[i] == 'e' \
                    || format[i] == 'p') {
                        for (int j = 0; new_string[j] != '\0'; j++) {
                            if (new_string[j] >= 'A' && new_string[j] <= 'H') {
                                new_string[j] = new_string[j] - 'A' + 'a';
                            }
                        }
                    }
                    s21_strcat(str, new_string);
                    flag.format_f = 0;
                    flag.sign = 0;
                    flag.precision = 0;
                    flag.set_precision = 0;
                    flag.width = 0;
                    flag.align = 0;
                    flag.length = 0;
                    flag.dot = 0;
                    flag.double_length = 0;
                    flag.spec = 0;
                    flag.if_num = 0;
                    flag.zero_width = 0;
                    null_precision = 0;
                }
            }
        } else {
            char ptr[2];
            ptr[0] = format[i];
            ptr[1] = '\0';
            s21_strcat(str, ptr);
        }
        va_end(vars);
    }
    s21_strcat(str, "\0");
    int len = (s21_strlen(str)) + nulls;
    while (null_p != len && null_p != -1) {
        str[null_p] = '\0';
        null_p++;
    }
    return len;
}

void* my_itoa(__int128 n, char * s, int radix, int sign, int precision) {
    int i = 0;
    s21_strcpy(s, "");
    char* alphabet = "0123456789ABCDEFGH";
    if (n < 0) {
        n = -n;
        s[0] = '-';
        i++;
    } else if (sign == 1) {
        s[0] = '+';
        i++;
    } else if (sign == 2) {
        s[0] = ' ';
        i++;
    }
    __int128 m = 1;
    int n_len = 1;
    while ((m * radix) <= (long long unsigned) n) {
        m = m * radix;
        n_len += 1;
    }
    while (n_len < precision) {
        precision--;
        s[i] = '0';
        i++;
    }
    while (m > 0) {
        s[i++] = alphabet[(n / m) % radix];
        n = n % m;
        m = m / radix;
    }
    s[i++] = '\0';
    return 0;
}

void my_ftoa(__float128 n, char *s, int digits, int sign) {
    int i = 0;
    int no_dot = digits;
    if (n < 0.0) {
        n = -n;
        s[0] = '-';
        i++;
    } else if (sign == 1) {
        s[0] = '+';
        i++;
    } else if (sign == 2) {
        s[0] = ' ';
        i++;
    }
    __float128 frac = n - (__int128) n;
    char frac_str[50];
    __int128 whole;
    int bank = 0;
    if (frac == 0.5 && digits == 0) {
        bank = 1;
    }
    if (digits != 0) {
        s21_size_t frac_len = (s21_size_t) digits;
        while (digits != 0) {
            frac *= 10;
            digits--;
        }
        frac += 0.5;
        my_itoa((__int128) frac, frac_str, 10, 0, frac_len);
        whole = (__int128) n;
        if (s21_strlen(frac_str) > frac_len) {
            if (whole < 0) {
                whole -= 1;
            } else {
                whole += 1;
            }
            int i;
            for (i = 0; frac_str[i] != '\0'; i++) {
                frac_str[i] = frac_str[i + 1];
            }
        }
        frac_str[frac_len] = '\0';
    } else {
        if (!bank) {
            n += 0.5;
            whole = (__int128) n;
        } else {
            if (((__int128) n) % 2 == 0) {
                whole = (__int128) n;
            } else {
                whole = (__int128) (n + 0.5);
            }
        }
    }
    char whole_str[50];
    my_itoa(whole, whole_str, 10, 0, 0);
    s21_strcat(s, whole_str);
    if (no_dot != 0) {
        s21_strcat(s, ".");
        s21_strcat(s, frac_str);
    }
}
