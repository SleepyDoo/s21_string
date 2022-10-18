#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include "s21_string.h"

/* format − This is the C string that contains one or more of the followin
   g items: Whitespace character, Non-whitespace character and Format specifiers. 
   A format specifier for print functions follows this prototype:
   %[flags][width][.precision][length]specifier. 
   A format specifier for scan functions follows this prototype:
   %[*][width][length]specifier. */


int s21_num_analyzer(const char *str);
unsigned int s21_digitizer(char c);
long double s21_atof(const char* str, char ** str_end, int width);
long s21_strtol(const char* format, char ** str_end, int base, int width);
int s21_isdigit(const char c, int base);
int s21_isspace(const char *str);
char* s21_strtos(const char *str, char ** str_end, int width);
long s21_num2numLONG(const char* format, int base, int width);
long s21_num2num(const char* format, int base);
int s21_size_check(const char * format, int base, int width);

int s21_sscanf(const char *str, const char *format, ...) {
    char *strend;
    char *strstart = (char*) str;
    int res = 0;
    int is_supress = 0;
    s21_size_t char_sum = 0;
    mod flag;
    int string_check = 1;
    int string_null = 0;
    long no_assignment = -1683532;
    flag.width = 0;
    flag.flag = 0;
    int num_specifier = 0;
    int string_int = 0;
    va_list arg;
    long long result;
    // TODO(Artemii):
    va_start(arg, format);
    for (; *format; format++) {
        if (*format == '%') {
            format++;
            num_specifier++;
            flag.flag++;
        }
        if (*format == '*') {
            is_supress = 1;
            continue;
        } else if (s21_isdigit(*format, 10)) {
            if (*(format - 1) != '-') {
                flag.width = s21_strtol(format, &strend, 10, 0);
                if (flag.width < 0) flag.width = 0;
                format = strend;
            } else {
                flag.width = 0;
            }
        }
        if (*format == 'h') {
            flag.length_s = 2;
            format++;
        } else if (*format == 'l') {
            flag.length_s = 4;
            format++;
            if (*format == 'l') {
                flag.length_s = 5;
                format++;
            }
        } else if (*format == 'L') {
            flag.length_s = 9;
            format++;
        }
        if (*format == ' ') flag.flag++;
        if ((string_check) && (flag.flag)) {
            switch (*format) {
                case 'c':
                    if (flag.width) {
                        char* string = malloc(1020 * sizeof(char));
                        char* new_string;
                        int count = 0;
                        int free_flag = 0;
                        if (string) {
                            while ((flag.width--) && (*str != '\0')) {
                                string[count] = *str;
                                count++;
                                str++;
                                new_string = realloc(string, (count+2) * sizeof(char));
                                if (new_string) {
                                    string = new_string;
                                } else {
                                    free(new_string);
                                    free_flag++;
                                    break;
                                }
                            }
                            char_sum += count;
                            if (is_supress == 0) {
                                s21_memcpy(((char *) va_arg(arg, char*)), string, count);
                                res++;
                            }
                            free(string);
                        }
                    } else {
                        if (is_supress == 0) {
                            *(char *)va_arg(arg, char *) = (char) *str;
                            res++;
                        }
                        str++;
                        char_sum++;
                    }
                    break;
                case 'i':
                    result = s21_strtol(str, &strend, 0, flag.width);
                    if ((result != no_assignment) && (is_supress == 0)) {
                        if (flag.length_s == 2) {
                            *(short int *)va_arg(arg, short int *) = result;
                        } else if (flag.length_s == 4) {
                            *(long int *)va_arg(arg, long int *) = result;
                        } else if (flag.length_s == 5) {
                            *(long long int *)va_arg(arg, long long int *) = result;
                        } else {
                            *(int *)va_arg(arg, int *) = result;
                        }
                        res++;
                    }
                    str = strend;
                    char_sum += (strend - strstart) - char_sum;
                    break;
                case 'd':
                    result = s21_strtol(str, &strend, 10, flag.width);
                    if ((result != no_assignment) && (is_supress == 0)) {
                        if (flag.length_s == 2) {
                            *(short int *)va_arg(arg, short int *) = result;
                        } else if (flag.length_s == 4) {
                            *(long int *)va_arg(arg, long int *) = result;
                        } else if (flag.length_s == 5) {
                            *(long long int *)va_arg(arg, long long int *) = result;
                        } else {
                            *(int *)va_arg(arg, int *) = result;
                        }
                        res++;
                    }
                    str = strend;
                    char_sum += (strend - strstart) - char_sum;
                    break;
                case 'u': {}
                          result = s21_strtol(str, &strend, 10, flag.width);
                          if ((result != no_assignment) && (is_supress == 0)) {
                              if (flag.length_s == 2) {
                                  *(unsigned short int *)va_arg(arg, unsigned short int *) = result;
                              } else if (flag.length_s == 4) {
                                  *(unsigned long int *)va_arg(arg, unsigned long int *) = result;
                              } else if (flag.length_s == 5) {
                                  *(unsigned long long int *)va_arg(arg, unsigned long long int *) = result;
                              } else {
                                  *(unsigned int *)va_arg(arg, unsigned int *) = result;
                              }
                              res++;
                          }
                          str = strend;
                          char_sum += (strend - strstart) - char_sum;
                          break;
                case 'a':
                case 'A':
                case 'e':
                case 'E':
                case 'g':
                case 'G':
                case 'F':
                case 'f': {}
                          long double result = s21_atof(str, &strend, flag.width);
                          if ((result != no_assignment) && (is_supress == 0)) {
                              if (flag.length_s == 9) {
                                  *(long double *)va_arg(arg, long double *) = result;
                              } else if (flag.length_s == 4) {
                                  *(double *)va_arg(arg, double *) = result;
                              } else {
                                  *(float *)va_arg(arg, float *) = result;
                              }
                              res++;
                          }
                          str = strend;
                          char_sum += (strend - strstart) - char_sum;
                          break;
                case 's': {}
                            char *string;
                              int space_count = 0;
                              if (is_supress == 0) {
                                  if (s21_isspace(str)) {
                                      while ((s21_isspace(str)) && (*str != '\0')) {
                                          str++;
                                          space_count++;
                                      }
                                  }
                                  string = s21_strtos(str, &strend, flag.width);
                                  str = strend;
                                  char_sum += s21_strlen(string) + space_count;
                                  if ((s21_strcpy(((char *) va_arg(arg, char*)), string))) res++;
                                  if (string) free(string);
                              } else {
                                  is_supress = 0;
                              }
                          break;
                case 'p':
                          if (is_supress == 0) {
                              long check = s21_strtol(str + 2, &strend, 16, flag.width);
                              *(void **) va_arg(arg, void**) = (void*) check;
                              res++;
                              str = strend;
                              char_sum += (strend - strstart) - char_sum;
                          } else {
                              is_supress = 0;
                          }
                          break;
                case 'o':
                          result = s21_strtol(str, &strend, 8, flag.width);
                          if ((result != no_assignment) && (is_supress == 0)) {
                              if (flag.length_s == 2) {
                                  *(unsigned short int *)va_arg(arg, unsigned short int *) = result;
                              } else if (flag.length_s == 4) {
                                  *(unsigned long int *)va_arg(arg, unsigned long int *) = result;
                              } else if (flag.length_s == 5) {
                                  *(unsigned long long int *)va_arg(arg, unsigned long long int *) = result;
                              } else {
                                  *(unsigned int *)va_arg(arg, unsigned int *) = result;
                              }
                              res++;
                          }
                          str = strend;
                          char_sum += (strend - strstart) - char_sum;
                          break;
                case 'x':
                case 'X':
                          if ((s21_strlen(str) > 2) && (*(str) == '0') && ((*(str + 1) == 'x'))) str += 2;
                          result = s21_strtol(str, &strend, 16, flag.width);
                          if ((result != no_assignment) && (is_supress == 0)) {
                              if (flag.length_s == 2) {
                                  *(unsigned short int *)va_arg(arg, unsigned short int *) = result;
                              } else if (flag.length_s == 4) {
                                  *(unsigned long int *)va_arg(arg, unsigned long int *) = result;
                              } else if (flag.length_s == 5) {
                                  *(unsigned long long int *)va_arg(arg, unsigned long long int *) = result;
                              } else {
                                  *(unsigned int *)va_arg(arg, unsigned int *) = result;
                              }
                              res++;
                          }
                          str = strend;
                          char_sum += (strend - strstart) - char_sum;
                          break;
                case 'n':
                          if (flag.length_s == 2) {
                              *(short int *)va_arg(arg, short int *) = char_sum;
                          } else if (flag.length_s == 4) {
                              *(long int *)va_arg(arg, long int *) = char_sum;
                          } else if (flag.length_s == 5) {
                              *(long long int *)va_arg(arg, long long int *) = char_sum;
                          } else {
                              *(int *)va_arg(arg, int *) = char_sum;
                          }
                          break;
                case ' ':
                          if (s21_isspace(str)) {
                              for (; s21_isspace(str); str++) {
                                  char_sum++;
                                  string_int++;
                              }
                          }
                          break;
                case '%':
                default:
                          if (*str != *format) {
                              string_check = 0;
                          } else {
                              if (*str != '\0') {
                                  str++;
                                  char_sum++;
                                  string_int++;
                              } else {
                                  string_check = 0;
                              }
                          }
                          break;
            }
        } else if ((!s21_isspace(format)) && (flag.flag == 0)) {
            if (*str != *format) {
                string_check = 0;
            } else {
                if ((*str != '\0')) {
                    str++;
                    char_sum++;
                    string_int++;
                } else {
                    string_check = 0;
                }
            }
        }
        flag.width = 0;
        flag.length_s = 0;
        flag.flag = 0;
        is_supress = 0;
        if (*str == '\0') {
            string_null = 1;
        }
    }
    if ((string_null == 1) && (res == 0) && (string_int == 0) && (num_specifier > 0)) res = -1;
    va_end(arg);
    return res;
}

int s21_isdigit(const char c, int base) {
    int s21_num = 0;
    if (base == 10) {
        s21_num = ((c >= 48) && (c <= 57)) ? 1 : 0;
    } else if (base == 8) {
        s21_num = ((c >= 48) && (c < 56)) ? 1 : 0;
    } else if (base == 16) {
        s21_num = (((c >= 97) && (c <= 102)) || \
                (((c >= 65) && (c <= 70))) || \
                ((c >= 48) && (c <= 57)))  ? 1 : 0;
    }
    return s21_num;
}


int s21_isspace(const char *str) {
    return (((*str == '\n') || (*str == ' ') || (*str == '\t')) ? 1 : 0);
}

unsigned int s21_digitizer(const char c) {
    int res = 0;
    if (c >= '0' && c <= '9')
        res = c - '0';
    if (c >= 'A' && c <= 'F')
        res = c - 'A' + 10;
    if (c >= 'a' && c <= 'f')
        res = c - 'a' + 10;
    return res;
}

long s21_strtol(const char* format, char ** str_end, int base, int width) {
    long result = -1683532;
    int s21_size;
    int flag = 0;
    if (s21_isspace(format)) {
        while ((*format != '\0')  && (s21_isspace(format)))  {
            format++;
        }
    }
    if (width == 0) width = -1;
    char sign = *format;
    if (((width != 0)) && ((sign == '-') || (sign == '+'))) {
        format++;
        width--;
        if ((*format == '-') || (*format == '+')) flag++;
    }
    if ((width != 0) && (flag == 0)) {
        if (0 == base) {
            base = s21_num_analyzer(format);
            if (16 == base) format += 2;
        }
        if (width != 0) {
            result = s21_num2numLONG(format, base, width);
            s21_size = s21_size_check(format, base, width);
            for (; s21_size > 0; s21_size--) format++;
        }
        *str_end = (char*) format;
    }
    if (result != -1683532) {
        result = (sign == '-') ? -result : result;
    }
    return result;
}


long double s21_atof(const char* str, char ** str_end, int width) {
    double res;
    double res_beforedot = 0.0;
    double res_afterdot = 0.0;
    // int s21_size;
    double a_exponent = 0.1;
    double digit;
    char sign_e;
    char sign;
    int flag = 0;
    int job = 0;
    int count = -1;
    if (s21_isspace(str)) {
        for (; s21_isspace(str); str++) continue;
    }
    sign = *str;
    if (width == 0) width = -1;
    if ((sign == '+') || (sign == '-')) {
        str++;
        width--;
    }
    while ((width != 0) && (*str != '\0') && (s21_isdigit(*str, 10))) {
        digit = s21_digitizer(*str);
        res_beforedot = res_beforedot * 10;
        res_beforedot += digit;
        str++;
        job++;
        width--;
    }
    if ((*str == '.') && (width != 0)) {
        str++;
        while ((width != 0) && (*str != '\0') && (s21_isdigit(*str, 10))) {
            res_afterdot += (s21_digitizer(*str) * pow(10, count));
            count--;
            str++;
            job++;
            width--;
        }
    }
    if ((('E' == *str) || ('e' == *str)) && (width != 0)) {
        str++;
        sign_e = *str;
        if ((sign_e == '+') || (sign_e == '-')) {
            str++;
            int count = s21_size_check(str, 10, width);
            a_exponent = s21_num2numLONG(str, 10, width);
            flag++;
            for (; count > 0; count--) str++;
        }
    }
    res = res_beforedot + res_afterdot;
    if (flag) {
        for (; a_exponent; a_exponent--) {
            if (sign_e == '+') res *= 10;
            if (sign_e == '-') res *= 0.1;
        }
    }
    if (sign == '-') res = - res;  // sign conversion
    if (job == 0) res = -1683532;
    if ((s21_strlen(str) >= 3) && ((*str == 'i') || (*str == 'I')) && ((*(str+1) == 'n') || \
                (*(str+1) == 'N')) && ((*(str+2) == 'f') || (*(str+2) == 'F'))) {   // inf conversion
        res = INFINITY;
        str += 3;
    }
    if ((s21_strlen(str) > 3) && ((*str == 'N') || (*str == 'n')) && ((*(str+1) == 'a') || (*(str+1) == 'A'))\
            && ((*(str+2) == 'N') || (*(str+2) == 'n'))) {  // NAN conversion
        res = NAN;
        str += 3;
    }
    *str_end = (char *) str;
    return res;
}


long s21_num2numLONG(const char* format, int base, int width) {
    long a = 0;
    int count = s21_size_check(format, base, width) - 1;
    int flag = 0;
    if (width == 0) width -= 1;
    while (((*format != '\0')) && (s21_isdigit(*format, base))  && (width != 0)) {
        a += (s21_digitizer(*format) * pow(base, count));
        count--;
        format++;
        flag++;
        width--;
    }
    return (flag) ? a : -1683532;
}

int s21_size_check(const char * format, int base, int width) {
    int count = 0;
    if (width == 0) width = -1;
    while ((*format != '\0') && ((s21_isdigit(*format, base)) && (width != 0))) {
        format++;
        count++;
        width--;
    }
    return count;
}  // 123123V

int s21_num_analyzer(const char *str) {
    int base = 0;
    if ((str[0] == '0') && ((str[1] == 'x') || (str[1] == 'X'))) {
        base = 16;
    } else if ((str[0] == '0')) {
        base = 8;
    } else {
        base = 10;
    }
    return base;
}

char* s21_strtos(const char *str, char ** str_end, int width) {
    int count = 0;
    char *string = malloc(124 * sizeof(char));
    char *new_string;
    if (string != s21_NULL) {
        if (width) {
            while (((!s21_isspace(str)) && (*str != '\0')) \
                    && (count < width)) {
                string[count] = *str;
                str++;
                count++;
                new_string = realloc(string, (count+1) * sizeof(char));
                if (new_string) {
                    string = new_string;
                } else {
                    free(new_string);
                    break;
                }
            }
        } else {
            while ((!s21_isspace(str)) && (*str != '\0')) {
                string[count] = *str;
                str++;
                count++;
                new_string = realloc(string, (count+1) * sizeof(char));
                if (new_string) {
                    string = new_string;
                } else {
                    free(new_string);
                    break;
                }
            }
        }
        *str_end = (char *) str;
        string[count] = '\0';
    }
    return string;
}

