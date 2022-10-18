#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s21_string.h"

START_TEST(test_s21_strlen) {
    char* test = "test_string\0";
    s21_size_t res = strlen(test);
    s21_size_t res2 = s21_strlen(test);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strlen_null_str) {
    char* test = "\0";
    s21_size_t res = strlen(test);
    s21_size_t res2 = s21_strlen(test);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strlen_invalid_str) {
    char* test = "";
    s21_size_t res = strlen(test);
    s21_size_t res2 = s21_strlen(test);
    ck_assert_int_eq(res, res2);
}
END_TEST

/*strspn tests*/
START_TEST(test_s21_strspn) {
    char* test_first = "test string";
    char* test_second = "set ";
    s21_size_t res = strspn(test_first, test_second);
    s21_size_t res2 = s21_strspn(test_first, test_second);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strspn_no_matches) {
    char* test_first = "test string";
    char* test_second = "1";
    s21_size_t res = strspn(test_first, test_second);
    s21_size_t res2 = s21_strspn(test_first, test_second);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strspn_all_matches) {
    char* test_first = "test string";
    char* test_second = "set ring";
    s21_size_t res = strspn(test_first, test_second);
    s21_size_t res2 = s21_strspn(test_first, test_second);
    ck_assert_int_eq(res, res2);
}
END_TEST

/*strcspn tests*/
START_TEST(test_s21_strcspn) {
    char* test_first = "test string";
    char* test_second = "ig ";
    s21_size_t res = strcspn(test_first, test_second);
    s21_size_t res2 = s21_strcspn(test_first, test_second);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strcspn_no_matches) {
    char* test_first = "test string";
    char* test_second = "1";
    s21_size_t res = strcspn(test_first, test_second);
    s21_size_t res2 = s21_strcspn(test_first, test_second);
    ck_assert_int_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strcspn_null_string) {
    char* test_first = "test string";
    char* test_second = "";
    s21_size_t res = strcspn(test_first, test_second);
    s21_size_t res2 = s21_strcspn(test_first, test_second);
    ck_assert_int_eq(res, res2);
}
END_TEST

/* sprintf tests */

START_TEST(test_s21_sprintf_d_i_lengths) {
    // long long int
    char str_result_ll[100];
    char real_str_result_ll[100];
    char* format_ll = "%021.20lli %lli %lld %lld";
    long long int n1_ll = -9223372036854775807;  // longest long long integers
    long long int n2_ll = 9223372036854775807;
    int result_ll = s21_sprintf(str_result_ll, format_ll, n1_ll, n2_ll, n1_ll, n2_ll);
    int real_result_ll = sprintf(real_str_result_ll, format_ll, n1_ll, n2_ll, n1_ll, n2_ll);
    ck_assert_str_eq(str_result_ll, real_str_result_ll);
    ck_assert_int_eq(result_ll, real_result_ll);

    // long int
    char str_result_l[100];
    char real_str_result_l[100];
    char* format_l = "%li %li %ld %ld";
    long int n1_l = -2147483647;  // longest long integers
    long int n2_l = 2147483647;
    int result_l = s21_sprintf(str_result_l, format_l, n1_l, n2_l, n1_l, n2_l);
    int real_result_l = sprintf(real_str_result_l, format_l, n1_l, n2_l, n1_l, n2_l);
    ck_assert_str_eq(str_result_l, real_str_result_l);
    ck_assert_int_eq(result_l, real_result_l);

    // int
    char str_result_i[100];
    char real_str_result_i[100];
    char* format_i = "%i %i %d %d";
    int n1_i = -2147483647;  // longest integers
    int n2_i = 2147483647;
    int result_i = s21_sprintf(str_result_i, format_i, n1_i, n2_i, n1_i, n2_i);
    int real_result_i = sprintf(real_str_result_i, format_i, n1_i, n2_i, n1_i, n2_i);
    ck_assert_str_eq(str_result_i, real_str_result_i);
    ck_assert_int_eq(result_i, real_result_i);

    // short int
    char str_result_h[100];
    char real_str_result_h[100];
    char* format_h = "%hi %hi %hd %hd";
    short int n1_h = -32767;  // longest short integers
    short int n2_h = 32767;
    int result_h = s21_sprintf(str_result_h, format_h, n1_h, n2_h, n1_h, n2_h);
    int real_result_h = sprintf(real_str_result_h, format_h, n1_h, n2_h, n1_h, n2_h);
    ck_assert_str_eq(str_result_h, real_str_result_h);
    ck_assert_int_eq(result_h, real_result_h);

    // signed char ("short short int")
    char str_result_hh[100];
    char real_str_result_hh[100];
    char* format_hh = "%hhi %hhi %hhd %hhd";
    short int n1_hh = -127;  // longest chars
    short int n2_hh = 127;
    int result_hh = s21_sprintf(str_result_hh, format_hh, n1_hh, n2_hh, n1_hh, n2_hh);
    int real_result_hh = sprintf(real_str_result_hh, format_hh, n1_hh, n2_hh, n1_hh, n2_hh);
    ck_assert_str_eq(str_result_hh, real_str_result_hh);
    ck_assert_int_eq(result_hh, real_result_hh);
} END_TEST

START_TEST(test_s21_sprintf_d_i) {
    // sign flags
    char str_result_space_plus[100];
    char real_str_result_space_plus[100];
    char* format_space_plus = "%+i %+i % i % i %+d %+d % d % d";
    int n1_space_plus = -10000000;
    int n2_space_plus = 10000;
    int result_space_plus = s21_sprintf(str_result_space_plus, format_space_plus, \
            n1_space_plus, n2_space_plus, n1_space_plus, n2_space_plus, n1_space_plus, \
            n2_space_plus, n1_space_plus, n2_space_plus);
    int real_result_space_plus = sprintf(real_str_result_space_plus, format_space_plus, \
            n1_space_plus, n2_space_plus, n1_space_plus, n2_space_plus, n1_space_plus, \
            n2_space_plus, n1_space_plus, n2_space_plus);
    ck_assert_str_eq(str_result_space_plus, real_str_result_space_plus);
    ck_assert_int_eq(result_space_plus, real_result_space_plus);

    // width & align
    char str_result_0_minus_width[100];
    char real_str_result_0_minus_width[100];
    // char* format_0_minus_width = "%0i %10i %-10i %-2i %10d %.-10d %*d % *d";
    char* format_0_minus_width = "%.-10d";  // %*d % *d";
    int n1_0_minus_width = -10000000;
    int n2_0_minus_width = 10000;
    int result_0_minus_width = s21_sprintf(str_result_0_minus_width, format_0_minus_width, \
            // n1_0_minus_width, n2_0_minus_width,  n1_0_minus_width, n2_0_minus_width, n1_0_minus_width,
            n2_0_minus_width, 15, n1_0_minus_width, -10, n2_0_minus_width);
    int real_result_0_minus_width = sprintf(real_str_result_0_minus_width, format_0_minus_width, \
            // n1_0_minus_width, n2_0_minus_width,  n1_0_minus_width, n2_0_minus_width, n1_0_minus_width,
            n2_0_minus_width, 15, n1_0_minus_width, -10, n2_0_minus_width);
    ck_assert_str_eq(str_result_0_minus_width, real_str_result_0_minus_width);
    ck_assert_int_eq(result_0_minus_width, real_result_0_minus_width);

    // precision
    char str_result_precision[100];
    char real_str_result_precision[100];
    // If both the converted value and the precision are ​0​ the conversion results in no characters
    // If the period is specified without an explicit value for precision, 0 is assumed
    char* format_precision = "%.0i %.i %.0i %.i %.10d %.d %.*d % .*d";
    int n1_precision = 0;
    int n2_precision = 10000;
    int n3_precision = -10;
    int result_precision = s21_sprintf(str_result_precision, format_precision, \
            n1_precision, n2_precision,  n3_precision, n1_precision, n2_precision, \
            n3_precision, 15, n1_precision, -10, n2_precision);
    int real_result_precision = sprintf(real_str_result_precision, format_precision, \
            n1_precision, n2_precision,  n3_precision, n1_precision, n2_precision, \
            n3_precision, 15, n1_precision, -10, n2_precision);
    ck_assert_str_eq(str_result_precision, real_str_result_precision);
    ck_assert_int_eq(result_precision, real_result_precision);

    // mix + too many arguments
    char str_result_mix[300];
    char real_str_result_mix[300];
    char* format_mix = "%020lli %+23.20lld %+-010.5d %+-.i % *.*i %+ d";
    long int n1_mix = -9223372036854775807;  // longest long long integers
    long long int n2_mix = 9223372036854775807;
    int n3_mix = -78305;
    int n4_mix = 0;
    int n5_mix = -0;
    int n6_mix = 100;
    int result_mix = s21_sprintf(str_result_mix, format_mix, n1_mix, \
            n2_mix, n3_mix, n4_mix, 7, -9, n6_mix, n5_mix, n3_mix, n3_mix);
    int real_result_mix = sprintf(real_str_result_mix, format_mix, n1_mix, \
            n2_mix, n3_mix, n4_mix, 7, -9, n6_mix, n5_mix, n3_mix, n3_mix);
    ck_assert_str_eq(str_result_mix, real_str_result_mix);
    ck_assert_int_eq(result_mix, real_result_mix);
}
END_TEST

START_TEST(test_s21_sprintf_o) {
    // different lengths
    char str_result_dif_l[100];
    char real_str_result_dif_l[100];
    char* format_dif_l = "%llo %lo %o %ho %hho";
    // not the longest unsigned long long integer possible,
    // but the biggest value that is permitted by -Werror
    long long unsigned n1_dif_l = 9223372036854775807;
    long unsigned n2_dif_l = 4294967295;
    unsigned int n3_dif_l = 4294967295;
    unsigned short n4_dif_l = 65535;
    unsigned char n5_dif_l = 255;
    int result_dif_l = s21_sprintf(str_result_dif_l, format_dif_l, n1_dif_l, n2_dif_l, \
            n3_dif_l, n4_dif_l, n5_dif_l);
    int real_result_dif_l = sprintf(real_str_result_dif_l, format_dif_l, n1_dif_l, n2_dif_l, \
            n3_dif_l, n4_dif_l, n5_dif_l);
    ck_assert_str_eq(str_result_dif_l, real_str_result_dif_l);
    ck_assert_int_eq(result_dif_l, real_result_dif_l);

    // sign flags
    char str_result_sign[100];
    char real_str_result_sign[100];
    char* format_sign = "%+llo % lo % +o %+ ho %+hho";
    long long unsigned n1_sign = 9223372036854775807;
    long unsigned n2_sign = 4294967295;
    unsigned int n3_sign = 4294967295;
    unsigned short n4_sign = 65535;
    unsigned char n5_sign = 255;
    int result_sign = s21_sprintf(str_result_sign, format_sign, n1_sign, n2_sign, \
            n3_sign, n4_sign, n5_sign);
    int real_result_sign = sprintf(real_str_result_sign, format_sign, n1_sign, n2_sign, \
            n3_sign, n4_sign, n5_sign);
    ck_assert_str_eq(str_result_sign, real_str_result_sign);
    ck_assert_int_eq(result_sign, real_result_sign);

    // hash
    char str_result_hash[100];
    char real_str_result_hash[100];
    char* format_hash = "%#+llo % #lo %# +011.10o %+# ho %#+hho";
    long long unsigned n1_hash = 9223372036854775807;
    long unsigned n2_hash = 4294967295;
    unsigned int n3_hash = 4294967295;
    unsigned short n4_hash = 65535;
    unsigned char n5_hash = 255;
    int result_hash = s21_sprintf(str_result_hash, format_hash, n1_hash, n2_hash, \
            n3_hash, n4_hash, n5_hash);
    int real_result_hash = sprintf(real_str_result_hash, format_hash, n1_hash, n2_hash, \
            n3_hash, n4_hash, n5_hash);
    ck_assert_str_eq(str_result_hash, real_str_result_hash);
    ck_assert_int_eq(result_hash, real_result_hash);

    // width & align
    char str_result_0_minus_width[100];
    char real_str_result_0_minus_width[100];
    char* format_0_minus_width = "%0o %#10o %-10o %-2o %010o %-010o %*o % *o";
    int n1_0_minus_width = 10000000;
    int n2_0_minus_width = 10000;
    int result_0_minus_width = s21_sprintf(str_result_0_minus_width, format_0_minus_width, \
            n1_0_minus_width, n2_0_minus_width,  n1_0_minus_width, n2_0_minus_width, n1_0_minus_width, \
            n2_0_minus_width, 15, n1_0_minus_width, 10, n2_0_minus_width);
    int real_result_0_minus_width = sprintf(real_str_result_0_minus_width, format_0_minus_width, \
            n1_0_minus_width, n2_0_minus_width,  n1_0_minus_width, n2_0_minus_width, n1_0_minus_width, \
            n2_0_minus_width, 15, n1_0_minus_width, 10, n2_0_minus_width);
    ck_assert_str_eq(str_result_0_minus_width, real_str_result_0_minus_width);
    ck_assert_int_eq(result_0_minus_width, real_result_0_minus_width);

    // precision
    char str_result_precision[100];
    char real_str_result_precision[100];
    // If both the converted value and the precision are ​0​ the conversion results in no characters
    // If the period is specified without an explicit value for precision, 0 is assumed
    char* format_precision = "%.0o %.o %.0o %.o %.10o %.o %.*o % .*o";
    int n1_precision = 0;
    int n2_precision = 10000;
    int n3_precision = 10;
    int result_precision = s21_sprintf(str_result_precision, format_precision, \
            n1_precision, n2_precision,  n3_precision, n1_precision, n2_precision, \
            n3_precision, 15, n1_precision, 10, n2_precision);
    int real_result_precision = sprintf(real_str_result_precision, format_precision, \
            n1_precision, n2_precision,  n3_precision, n1_precision, n2_precision, \
            n3_precision, 15, n1_precision, 10, n2_precision);
    ck_assert_str_eq(str_result_precision, real_str_result_precision);
    ck_assert_int_eq(result_precision, real_result_precision);

    // mix + too many arguments
    char str_result_mix[300];
    char real_str_result_mix[300];
    char* format_mix = "%#020llo %+23.20llo %+-010.5o %+-.o %# *.*o %+ o";
    long int n1_mix = 9223372036854775807;
    long long int n2_mix = 9223372036854775807;
    int n3_mix = 78305;
    int n4_mix = 0;
    int n5_mix = 100;
    int result_mix = s21_sprintf(str_result_mix, format_mix, n1_mix,
            n2_mix, n3_mix, n4_mix, 7, 6, n5_mix, n5_mix, n3_mix, n3_mix);
    int real_result_mix = sprintf(real_str_result_mix, format_mix, n1_mix,
            n2_mix, n3_mix, n4_mix, 7, 6, n5_mix, n5_mix, n3_mix, n3_mix);
    ck_assert_str_eq(str_result_mix, real_str_result_mix);
    ck_assert_int_eq(result_mix, real_result_mix);
}
END_TEST

START_TEST(test_s21_sprintf_p) {
    char str_result[1000];
    char real_str_result[1000];
    char* format = "%p %-*.*p %.18p %18p %-18p";
    long long int p1 = 1000000000000000000;
    int p2 = 10000;
    int p3 = 1;
    int p4 = 10000000;
    int result = s21_sprintf(str_result, format, &p1, 15, 17, &p2, &p3, &p4, &p1);
    int real_result = sprintf(real_str_result, format, &p1, 15, 17, &p2, &p3, &p4, &p1);
    ck_assert_str_eq(str_result, real_str_result);
    ck_assert_int_eq(result, real_result);
}
END_TEST

START_TEST(test_s21_sprintf_X_x) {
    // different lengths
    char str_result_dif_l[100];
    char real_str_result_dif_l[100];
    char* format_dif_l = "%llx %lX %x %hX %hhx";
    // not the longest unsigned long long integer possible,
    // but the biggest value that is permitted by -Werror
    long long unsigned n1_dif_l = 9223372036854775807;
    long unsigned n2_dif_l = 4294967295;
    unsigned int n3_dif_l = 4294967295;
    unsigned short n4_dif_l = 65535;
    unsigned char n5_dif_l = 255;
    int result_dif_l = s21_sprintf(str_result_dif_l, format_dif_l, n1_dif_l, n2_dif_l, \
            n3_dif_l, n4_dif_l, n5_dif_l);
    int real_result_dif_l = sprintf(real_str_result_dif_l, format_dif_l, n1_dif_l, n2_dif_l, \
            n3_dif_l, n4_dif_l, n5_dif_l);
    ck_assert_str_eq(str_result_dif_l, real_str_result_dif_l);
    ck_assert_int_eq(result_dif_l, real_result_dif_l);

    // sign flags
    char str_result_sign[100];
    char real_str_result_sign[100];
    char* format_sign = "%+llx % lX % +x %+ hX %+hhx";
    long long unsigned n1_sign = 9223372036854775807;
    long unsigned n2_sign = 4294967295;
    unsigned int n3_sign = 4294967295;
    unsigned short n4_sign = 65535;
    unsigned char n5_sign = 255;
    int result_sign = s21_sprintf(str_result_sign, format_sign, n1_sign, n2_sign, \
            n3_sign, n4_sign, n5_sign);
    int real_result_sign = sprintf(real_str_result_sign, format_sign, n1_sign, n2_sign, \
            n3_sign, n4_sign, n5_sign);
    ck_assert_str_eq(str_result_sign, real_str_result_sign);
    ck_assert_int_eq(result_sign, real_result_sign);

    // hash
    char str_result_hash[100];
    char real_str_result_hash[100];
    char* format_hash = "%#+llx % #lX %# +X %+# hx %#+hhX";
    long long unsigned n1_hash = 9223372036854775807;
    long unsigned n2_hash = 4294967295;
    unsigned int n3_hash = 4294967295;
    unsigned short n4_hash = 65535;
    unsigned char n5_hash = 255;
    int result_hash = s21_sprintf(str_result_hash, format_hash, n1_hash, n2_hash, \
            n3_hash, n4_hash, n5_hash);
    int real_result_hash = sprintf(real_str_result_hash, format_hash, n1_hash, n2_hash, \
            n3_hash, n4_hash, n5_hash);
    ck_assert_str_eq(str_result_hash, real_str_result_hash);
    ck_assert_int_eq(result_hash, real_result_hash);

    // width & align
    char str_result_0_minus_width[100];
    char real_str_result_0_minus_width[100];
    char* format_0_minus_width = "%0x %#10x %-10x %-2X %010X %-010x %*x % *X";
    int n1_0_minus_width = 10000000;
    int n2_0_minus_width = 10000;
    int result_0_minus_width = s21_sprintf(str_result_0_minus_width, format_0_minus_width, \
            n1_0_minus_width, n2_0_minus_width,  n1_0_minus_width, n2_0_minus_width, n1_0_minus_width, \
            n2_0_minus_width, 15, n1_0_minus_width, 10, n2_0_minus_width);
    int real_result_0_minus_width = sprintf(real_str_result_0_minus_width, format_0_minus_width, \
            n1_0_minus_width, n2_0_minus_width,  n1_0_minus_width, n2_0_minus_width, n1_0_minus_width, \
            n2_0_minus_width, 15, n1_0_minus_width, 10, n2_0_minus_width);
    ck_assert_str_eq(str_result_0_minus_width, real_str_result_0_minus_width);
    ck_assert_int_eq(result_0_minus_width, real_result_0_minus_width);

    // precision
    char str_result_precision[100];
    char real_str_result_precision[100];
    // If both the converted value and the precision are ​0​ the conversion results in no characters
    // If the period is specified without an explicit value for precision, 0 is assumed
    char* format_precision = "%.0x %.x %.0X %.x %.10X %.x %.*x % .*x";
    int n1_precision = 0;
    int n2_precision = 10000;
    int n3_precision = 10;
    int result_precision = s21_sprintf(str_result_precision, format_precision, \
            n1_precision, n2_precision,  n3_precision, n1_precision, n2_precision, \
            n3_precision, 15, n1_precision, 10, n2_precision);
    int real_result_precision = sprintf(real_str_result_precision, format_precision, \
            n1_precision, n2_precision,  n3_precision, n1_precision, n2_precision, \
            n3_precision, 15, n1_precision, 10, n2_precision);
    ck_assert_str_eq(str_result_precision, real_str_result_precision);
    ck_assert_int_eq(result_precision, real_result_precision);

    // mix + too many arguments
    char str_result_mix[300];
    char real_str_result_mix[300];
    char* format_mix = "%#020llX %+23.20llx %+-010.5X %+-x %# *.*x %+ X";
    long int n1_mix = 9223372036854775807;
    long long int n2_mix = 9223372036854775807;
    int n3_mix = 78305;
    int n4_mix = 0;
    int n5_mix = 100;
    int result_mix = s21_sprintf(str_result_mix, format_mix, n1_mix,
            n2_mix, n3_mix, n4_mix, -7, 6, n5_mix, n5_mix, n3_mix, n3_mix);
    int real_result_mix = sprintf(real_str_result_mix, format_mix, n1_mix,
            n2_mix, n3_mix, n4_mix, -7, 6, n5_mix, n5_mix, n3_mix, n3_mix);
    ck_assert_str_eq(str_result_mix, real_str_result_mix);
    ck_assert_int_eq(result_mix, real_result_mix);
}
END_TEST

START_TEST(test_s21_sprintf_s) {
    char str_result[1000];
    char real_str_result[1000];
    char* format = "%9.6s %s %18s  %*.*s  %.6s";
    char* str1 = "teststring";
    char* str2 = "test2string";
    int result = s21_sprintf(str_result, format, str1, str2, str1, 6, 9, str1, NULL);
    int real_result = sprintf(real_str_result, format, str1, str2, str1, 6, 9, str1, NULL);
    ck_assert_str_eq(str_result, real_str_result);
    ck_assert_int_eq(result, real_result);

    char str_result_L[1000];
    char real_str_result_L[1000];
    char* format_L = "%ls %ls";
    wchar_t* str1_L = L"LONG";
    int result_L = s21_sprintf(str_result_L, format_L, str1_L, NULL);
    int real_result_L = sprintf(real_str_result_L, format_L, str1_L, NULL);
    ck_assert_str_eq(str_result_L, real_str_result_L);
    ck_assert_int_eq(result_L, real_result_L);
}
END_TEST

START_TEST(test_s21_sprintf_c) {
    char str_result[100];
    char real_str_result[100];
    // точность, даже нулевая, не влияет на тип char
    char* format = "%10c %-10c %.c %c % .0c";
    char n1 = '0';
    char n2 = 10;
    char n3 = 'b';
    char n4 = '0';
    int result = s21_sprintf(str_result, format, n1, n2, n3, n4, n1, n2, n3, n4);
    int real_result = sprintf(real_str_result, format, n1, n2, n3, n4, n1, n2, n3, n4);
    ck_assert_str_eq(str_result, real_str_result);
    ck_assert_int_eq(result, real_result);

    char str_result_null[100];
    char real_str_result_null[100];
    char* format_null = " %1c %10c %.c %3c";
    int result_null = s21_sprintf(str_result_null, format_null, 0, n2, n3, 0);
    int real_result_null = sprintf(real_str_result_null, format_null, 0, n2, n3, 0);
    ck_assert_str_eq(str_result_null, real_str_result_null);
    ck_assert_int_eq(result_null, real_result_null);


    char str_result_w[100];
    char real_str_result_w[100];
    char* format_w = "%-2lc %-2lc %lc %-lc % .0lc";
    wchar_t nw = L'a';
    int result_w = s21_sprintf(str_result_w, format_w, nw, nw, 0, nw, nw);
    int real_result_w = sprintf(real_str_result_w, format_w, nw, nw, 0, nw, nw);

    ck_assert_int_eq(result_w, real_result_w);
    ck_assert_str_eq(str_result_w, real_str_result_w);
}
END_TEST

START_TEST(test_s21_sprintf_percent) {
    char str_result[100];
    char real_str_result[100];
    char* format = " %% %% %-%";
    int n1 = 0;
    int result = s21_sprintf(str_result, format, n1);
    int real_result = sprintf(real_str_result, format, n1);
    ck_assert_str_eq(str_result, real_str_result);
    ck_assert_int_eq(result, real_result);
}
END_TEST

START_TEST(test_s21_sprintf_f) {
    // basic check
    char str_result[100];
    char real_str_result[100];
    char* format = "%f %f %f %f";
    float n1 = 100000.0;
    float n2 = 9.999999;
    float n3 = -3.14;
    float n4 = 0.000001;
    int result = s21_sprintf(str_result, format, n1, n2, n3, n4);
    int real_result = sprintf(real_str_result, format, n1, n2, n3, n4);
    ck_assert_str_eq(str_result, real_str_result);
    ck_assert_int_eq(result, real_result);

    // precision
    char str_result_p[100];
    char real_str_result_p[100];
    char* format_p = "%.9f %.0f %.11f %.22f %.*f";
    float n5 = -0.000001;
    int result_p = s21_sprintf(str_result_p, format_p, n1, n2, n3, n4, 15, n5);
    int real_result_p = sprintf(real_str_result_p, format_p, n1, n2, n3, n4, 15, n5);
    ck_assert_str_eq(str_result_p, real_str_result_p);
    ck_assert_int_eq(result_p, real_result_p);

    // width, zero flag, align, hash
    char str_result_w[200];
    char real_str_result_w[200];
    char* format_w = "%#-17.9f %#-08.0f %010.11f %.1f %#*.*f";
    int result_w = s21_sprintf(str_result_w, format_w, n1, n2, n3, n4, 8, 0, n5);
    int real_result_w = sprintf(real_str_result_w, format_w,  n1, n2, n3, n4, 8, 0, n5);
    ck_assert_str_eq(str_result_w, real_str_result_w);
    ck_assert_int_eq(result_w, real_result_w);

    // sign flags
    char str_result_s[200];
    char real_str_result_s[200];
    char* format_s = "%+17.9f %# 08.0f %+-010.11f %+.1f % +#*.*f";
    int result_s = s21_sprintf(str_result_s, format_s, n1, n2, n3, n4, 8, 0, n5);
    int real_result_s = sprintf(real_str_result_s, format_s, n1, n2, n3, n4, 8, 0, n5);
    ck_assert_str_eq(str_result_s, real_str_result_s);
    ck_assert_int_eq(result_s, real_result_s);

    // long double
    char str_result_L[200];
    char real_str_result_L[200];
    long double n6 = 999999999.99999999999999999999;
    long double n7 = 0.00000000000000000001;
    long double n8 = -0.00000000000000001;
    char* format_L = "%30.25Lf %30.30Lf %30.20Lf";
    int result_L = s21_sprintf(str_result_L, format_L, n6, n7, n8);
    int real_result_L = sprintf(real_str_result_L, format_L, n6, n7, n8);
    ck_assert_str_eq(str_result_L, real_str_result_L);
    ck_assert_int_eq(result_L, real_result_L);
}
END_TEST

START_TEST(test_s21_sprintf_n) {
    char str_result[1000];
    char real_str_result[1000];
    char* format =
        "%.10hf %.1f %f %.10hf %.1f %f %.10hf %.1f %f %n %- 8.1f %+- 8.3f %-.10f %n";
    float n1 = 9.999;
    float n2 = 9.1;
    float n3 = -3.14;
    int n = 0;
    int nn = 0;
    int real_nn = 0;
    int real_n = 0;
    int result = s21_sprintf(str_result, format, n1, n2, n3, n1, n2, n3, n1, n2, n3, \
            &n, n2, n3, n1, &nn);
    int real_result =  sprintf(real_str_result, format, n1, n2, n3, n1, n2, n3, n1, n2, n3, \
            &real_n, n2, n3, n1, &real_nn);
    ck_assert_str_eq(str_result, real_str_result);
    ck_assert_int_eq(n, real_n);
    ck_assert_int_eq(nn, real_nn);
    ck_assert_int_eq(result, real_result);

    char str_result_hh[1000];
    char real_str_result_hh[1000];
    char *format_hh = "%s%s%s%s%s%s%s%s%s%s%s%s%hhn";
    char *s1 = "01234567890123456789012345678901234567890";
    int n_hh = 0;
    int real_n_hh = 0;
    int result_hh = s21_sprintf(str_result_hh, format_hh, s1, s1, s1, s1, s1, s1, s1, s1, s1, s1, s1, s1, \
            &n_hh);
    int real_result_hh =  sprintf(real_str_result_hh, format_hh, s1, s1, s1, s1, s1, s1, s1, s1, s1, s1, \
            s1, s1, &real_n_hh);
    ck_assert_str_eq(str_result_hh, real_str_result_hh);
    ck_assert_int_eq(n_hh, real_n_hh);
    ck_assert_int_eq(result_hh, real_result_hh);
}
END_TEST

START_TEST(test_s21_sprintf_u) {
    char str_result[100];
    char real_str_result[100];
    char* format = "%hhu %hu %u %lu %u %llu";
    long int n1 = 100000;
    long int n2 = 9223372036854775807;
    long long int n3 = -922337203685;
    long long int n4 = 10000;
    char n5 = -127;
    short int n6 = 10000;
    int result = s21_sprintf(str_result, format, n5, n6, n1, n2, n3, n4);
    int real_result = sprintf(real_str_result, format, n5, n6, n1, n2, n3, n4);
    ck_assert_str_eq(str_result, real_str_result);
    ck_assert_int_eq(result, real_result);

    char str_result_sign[100];
    char real_str_result_sign[100];
    char* format_sign = "%+16u % 16llu %#0.15u %-15u";
    int result_sign = s21_sprintf(str_result_sign, format_sign, n1, n2, n5, n6);
    int real_result_sign = sprintf(real_str_result_sign, format_sign, n1, n2, n5, n6);
    ck_assert_str_eq(str_result_sign, real_str_result_sign);
    ck_assert_int_eq(result_sign, real_result_sign);
}
END_TEST


START_TEST(test_s21_sprintf_e_E) {
    char str_result[100];
    char real_str_result[100];
    char* format = "%e %e %E %E";
    float n1 = -0.000001;
    float n2 = 0.999;
    float n3 = 10000.0;
    float n4 = 314.15;
    int result = s21_sprintf(str_result, format, n1, n2, n3, n4);
    int real_result = sprintf(real_str_result, format, n1, n2, n3, n4);
    ck_assert_str_eq(str_result, real_str_result);
    ck_assert_int_eq(result, real_result);

    char str_result_zero_p[100];
    char real_str_result_zero_p[100];
    char* format_zero_p = "%#.0e %.0e %.0E %#.0E %.0E";
    int result_zero_p = s21_sprintf(str_result_zero_p, format_zero_p, n1, n2, n3, n4, n1);
    int real_result_zero_p = sprintf(real_str_result_zero_p, format_zero_p, n1, n2, n3, n4, n1);
    ck_assert_str_eq(str_result_zero_p, real_str_result_zero_p);
    ck_assert_int_eq(result_zero_p, real_result_zero_p);

    char str_result_p[100];
    char real_str_result_p[100];
    char* format_p = "%.10e %.1e %.6E %.8E %.*E";
    int result_p = s21_sprintf(str_result_p, format_p, n1, n2, n3, n4, 1, n1);
    int real_result_p = sprintf(real_str_result_p, format_p, n1, n2, n3, n4, 1, n1);
    ck_assert_str_eq(str_result_p, real_str_result_p);
    ck_assert_int_eq(result_p, real_result_p);

    char str_result_w[100];
    char real_str_result_w[100];
    char* format_w = "%15.10e %10.1e %1.6E %10.8E %*.*E";
    int result_w = s21_sprintf(str_result_w, format_w, n1, n2, n3, n4, 12, 1, n1);
    int real_result_w = sprintf(real_str_result_w, format_w, n1, n2, n3, n4, 12, 1, n1);
    ck_assert_str_eq(str_result_w, real_str_result_w);
    ck_assert_int_eq(result_w, real_result_w);

    char str_result_L[200];
    char real_str_result_L[200];
    long double n1l = -0.000001;
    long double n2l = 0.999;
    long double n3l = 10000.0;
    long double n4l = 314.15;
    char* format_L = "%15.10Le %10.1Le %1.6LE %10.8LE %*.*LE";
    int result_L = s21_sprintf(str_result_L, format_L, n1l, n2l, n3l, n4l, 12, 1, n1l);
    int real_result_L = sprintf(real_str_result_L, format_L, n1l, n2l, n3l, n4l, 12, 1, n1l);
    ck_assert_str_eq(str_result_L, real_str_result_L);
    ck_assert_int_eq(result_L, real_result_L);
}
END_TEST


START_TEST(test_s21_sprintf_g_G) {
    char str_result[100];
    char real_str_result[100];
    char* format = "%+g % g %G %G";
    float n1 = 0.00001;
    float n2 = 1.999;
    float n3 = 10000.0;
    float n4 = 314.15;
    float n5 = -0.0001;
    int result = s21_sprintf(str_result, format, n1, n2, n3, n4);
    int real_result = sprintf(real_str_result, format, n1, n2, n3, n4);
    ck_assert_str_eq(str_result, real_str_result);
    ck_assert_int_eq(result, real_result);

    char str_result_zero_p[100];
    char real_str_result_zero_p[100];
    char* format_zero_p = "%#.0g %.0g %.0G %#.0G %.0G";
    int result_zero_p = s21_sprintf(str_result_zero_p, format_zero_p, n1, n2, n3, n4, n5);
    int real_result_zero_p = sprintf(real_str_result_zero_p, format_zero_p, n1, n2, n3, n4, n5);
    ck_assert_str_eq(str_result_zero_p, real_str_result_zero_p);
    ck_assert_int_eq(result_zero_p, real_result_zero_p);

    char str_result_p[100];
    char real_str_result_p[100];
    char* format_p = "%.10g %.1g %.6G %.8G %.*G";
    int result_p = s21_sprintf(str_result_p, format_p, n1, n2, n3, n4, 1, n1);
    int real_result_p = sprintf(real_str_result_p, format_p, n1, n2, n3, n4, 1, n1);
    ck_assert_str_eq(str_result_p, real_str_result_p);
    ck_assert_int_eq(result_p, real_result_p);

    char str_result_w[100];
    char real_str_result_w[100];
    char* format_w = "%15.10g %10.1g %1.6G %10.8G %*.*G";
    int result_w = s21_sprintf(str_result_w, format_w, n1, n2, n3, n4, 12, 1, n1);
    int real_result_w = sprintf(real_str_result_w, format_w, n1, n2, n3, n4, 12, 1, n1);
    ck_assert_str_eq(str_result_w, real_str_result_w);
    ck_assert_int_eq(result_w, real_result_w);

    char str_result_L[200];
    char real_str_result_L[200];
    long double n1l = -0.000001;
    long double n2l = 0.999;
    long double n3l = 10000.0;
    long double n4l = 314.15;
    char* format_L = "%15.10Lg %10.1Lg %1.6LG %10.8LG %*.*LG";
    int result_L = s21_sprintf(str_result_L, format_L, n1l, n2l, n3l, n4l, 12, 1, n1l);
    int real_result_L = sprintf(real_str_result_L, format_L, n1l, n2l, n3l, n4l, 12, 1, n1l);
    ck_assert_str_eq(str_result_L, real_str_result_L);
    ck_assert_int_eq(result_L, real_result_L);
}
END_TEST

START_TEST(tests_s21_memchr_letterexists) {
    char test1[100] = "test_string\0";
    char test2 = '_';
    char* res = memchr(test1, test2, 10);
    char* res2 = s21_memchr(test1, test2, 10);
    ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(tests_s21_memchr_letter_noexists) {
    char test1[100] = "test_string\0";
    char test2 = ' ';
    char* res = memchr(test1, test2, 10);
    char* res2 = s21_memchr(test1, test2, 10);
    ck_assert_pstr_eq(res, res2);
}
END_TEST

START_TEST(tests_s21_strrchr_letter_exists) {
    char test1[100] = "test_string\0";
    char test2 = 's';
    char* res = strrchr(test1, test2);
    char* res2 = s21_strrchr(test1, test2);
    ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(tests_s21_strrchr_letter_noexists) {
    char* test4 = " \n\0";
    char* test5 = " \0";
    char* test6 = "\n\0";

    char* res = strchr(test4, ' ');
    char* res2 = s21_strchr(test4, ' ');
    ck_assert_str_eq(res, res2);
    ck_assert_ptr_eq((s21_strrchr(test4, 'o')), strrchr(test4, 'o'));
    ck_assert_ptr_eq((strrchr(test5, ' ')), s21_strrchr(test5, ' '));
    ck_assert_ptr_eq((strrchr(test6, 'z')), s21_strrchr(test6, 'z'));
}
END_TEST

START_TEST(tests_s21_strchr_letter_exists) {
    char* strchr1 = "Hello world\0";
    char* strchr2 = "Hello world\n\0";
    char* strchr3 = "a\n\0";
    ck_assert_str_eq((strchr(strchr1, 'l')), s21_strchr(strchr1, 'l'));
    ck_assert_str_eq((strchr(strchr2, 'l')), s21_strchr(strchr2, 'l'));
    ck_assert_str_eq((strchr(strchr3, 'a')), s21_strchr(strchr3, 'a'));
}
END_TEST

START_TEST(tests_s21_strchr_letter_noexists) {
    char* strchr4 = " \n\0";
    char* strchr5 = " \0";
    char* strchr6 = "\nf\0";

    char* res = strchr(strchr4, ' ');
    char* res2 = s21_strchr(strchr4, ' ');

    ck_assert_str_eq(res, res2);
    ck_assert_str_eq((strchr(strchr5, ' ')), s21_strchr(strchr5, ' '));
    ck_assert_str_eq((strchr(strchr6, 'f')), s21_strchr(strchr6, 'f'));
}
END_TEST

START_TEST(tests_s21_strpbrk) {
    char* test1 = "Hello world\0";
    char* test2 = "Hello world\n\0";
    char* test3 = "a\n\0";
    char* test4 = " \n\0";
    char* test5 = " \0";
    char* test6 = "\n\0";

    ck_assert_pstr_eq(s21_strpbrk(test1, test1), (strpbrk(test1, test1)));
    ck_assert_pstr_eq(s21_strpbrk(test2, test1), (strpbrk(test2, test1)));
    ck_assert_pstr_eq(s21_strpbrk(test3, test1), (strpbrk(test3, test1)));
    ck_assert_pstr_eq(s21_strpbrk(test4, test1), (strpbrk(test4, test1)));
    ck_assert_pstr_eq(s21_strpbrk(test5, test1), (strpbrk(test5, test1)));
    ck_assert_pstr_eq(s21_strpbrk(test6, test1), (strpbrk(test6, test1)));
}
END_TEST

START_TEST(tests_s21_strstr) {
    char test1[100] = "test_string\0";
    char* test2 = "string";
    char* res = strstr(test1, test2);
    char* res2 = s21_strstr(test1, test2);
    ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strstr_second_empty_str) {
    char test[20] = "test me\0 love";
    char* res = strstr(test, "");
    char* res2 = s21_strstr(test, "");
    ck_assert_str_eq(res, res2);
}

START_TEST(test_s21_strstr_first_empty_str) {
    char test[20] = "test me\0 love";
    char* res = strstr("", test);
    char* res2 = s21_strstr("", test);
    ck_assert_ptr_eq(res, res2);
}

START_TEST(tests_s21_sscanf_char) {
    char a, b;
    char a11, b11;
    char a1[10], b1[10];
    ck_assert_int_eq((sscanf("2", "%c", &a)), s21_sscanf("2", "%c", &b));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("A", "%c", &a)), s21_sscanf("A", "%c", &b));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("Zz", "%c", &a)), s21_sscanf("Zz", "%c", &b));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("   2", "%c", &a)), s21_sscanf("   2", "%c", &b));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("2 5", "%c%c", &a, &a11)), s21_sscanf("2 5", "%c%c", &b, &b11));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq(a11, b11);
    ck_assert_int_eq((sscanf("2", "%1c", &a)), s21_sscanf("2", "%1c", &b));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("  ", "%c", &a)), s21_sscanf("  ", "%c", &b));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("Enterme", "%3c", a1)), s21_sscanf("Enterme", "%3c", b1));
    a1[3] = '\0';
    b1[3] = '\0';
    ck_assert_str_eq(a1, b1);
    ck_assert_int_eq((sscanf("Enterme", "%10c", a1)), s21_sscanf("Enterme", "%10c", b1));
    ck_assert_str_eq(a1, b1);
}
END_TEST

START_TEST(tests_s21_sscanf_decim) {
    int a, b;
    int i, z;
    ck_assert_int_eq((sscanf("6", "%d", &i)), s21_sscanf("6", "%d", &z));
    ck_assert_int_eq(i, z);
    ck_assert_int_eq((sscanf("6 4", "%d%d", &i, &a)), s21_sscanf("6 4", "%d%d", &z, &b));
    ck_assert_int_eq(i, z);
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("60000000 4213213123", "%d%d", &i, &a)), \
            s21_sscanf("60000000 4213213123", "%d%d", &z, &b));
    ck_assert_int_eq(i, z);
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("6", "%d", &i)), s21_sscanf("6", "%d", &z));
    ck_assert_int_eq((sscanf("6", "%d", &i)), s21_sscanf("6", "%d", &z));
    ck_assert_int_eq(i, z);
    ck_assert_int_eq((sscanf("14", "%d", &i)), s21_sscanf("14", "%d", &z));
    ck_assert_int_eq(i, z);
}


START_TEST(tests_s21_sscanf_int) {
    int i, z, a, b;
    int i1, z1, a1, b1;
    char str[100], str1[100];
    ck_assert_int_eq((sscanf("-27", "%i", &a)), s21_sscanf("-27", "%i", &b));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("32", "%i", &a)), s21_sscanf("32", "%i", &b));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("90 70 50 40", "%i%i%i%i", &a, &a1, &z, &z1)),
            s21_sscanf("90 70 50 40", "%i%i%i%i", &b, &b1, &i, &i1));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq(a1, b1);
    ck_assert_int_eq(z, i);
    ck_assert_int_eq(z1, i1);
    ck_assert_int_eq((sscanf("  90", "%*i%i", &a)), s21_sscanf("  90", "%*i%i", &b));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("7xFA2", "%i", &a)), s21_sscanf("7xFA2", "%i", &b));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("0xAAAAA2", "%i", &a)), s21_sscanf("0xAAAAA2", "%i", &b));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("58hello", "%i%s", &a, str)),
            s21_sscanf("58hello", "%i%s", &b, str1));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("58hello59", "%i%s%d%d", &a, str, &z1, &b1)),
            s21_sscanf("58hello59", "%i%s%d%d", &b, str1, &i1, &b));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq(i1, z1);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(tests_s21_sscanf_e_E) {
    float a, b;
    ck_assert_int_eq((sscanf("2.0311", "%E", &a)),
            s21_sscanf("2.0311", "%E", &b));
    ck_assert_float_eq(a, b);
    ck_assert_int_eq((sscanf("2.4321412412422222222222", "%e", &a)),
            s21_sscanf("2.4321412412422222222222", "%e", &b));
    ck_assert_float_eq(a, b);
} END_TEST;

START_TEST(tests_s21_sscanf_f) {
    float a, b, g, c;
    ck_assert_int_eq((sscanf("2.231", "%f", &a)), s21_sscanf("2.231", "%f", &b));
    ck_assert_float_eq(a, b);
    ck_assert_int_eq((sscanf("b2.23.1", "%f", &a)), s21_sscanf("b2.23.1", "%f", &b));
    ck_assert_float_eq(a, b);
    ck_assert_int_eq((sscanf("3124124.21312112312312", "%f", &a)), \
            s21_sscanf("3124124.21312112312312", "%f", &b));
    ck_assert_float_eq(a, b);
    ck_assert_int_eq((sscanf("2.2E+1S31", "%f", &a)), s21_sscanf("2.2E+1S31", "%f", &b));
    ck_assert_float_eq(a, b);
    ck_assert_int_eq((sscanf("2.2S31", "%f", &a)), s21_sscanf("2.2S31", "%f", &b));
    ck_assert_float_eq(a, b);
    ck_assert_int_eq((sscanf("22.31E+4", "%f", &a)),
            s21_sscanf("22.31E+4", "%f", &b));
    ck_assert_float_eq(a, b);
    ck_assert_int_eq((sscanf("2222223.31E-10 5", "%f%f", &a, &g)),
            s21_sscanf("2222223.31E-10 5", "%f%f", &b, &c));
    ck_assert_float_eq(a, b);
    ck_assert_float_eq(g, c);
    ck_assert_int_eq((sscanf("2.031.1", "%a", &a)),
            s21_sscanf("2.031.1", "%a", &b));
    ck_assert_float_eq(a, b);
    ck_assert_int_eq((sscanf("2.0311E-2", "%A", &a)),
            s21_sscanf("2.0311E-2", "%A", &b));
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(tests_s21_sscanf_g_G) {
    float a, b;
    ck_assert_int_eq((sscanf("  2.0311", "%G", &a)),
            s21_sscanf("  2.0311", "%G", &b));
    ck_assert_float_eq(a, b);
    ck_assert_int_eq((sscanf("2.031231231", "%g", &a)),
            s21_sscanf("2.031231231", "%g", &b));
    ck_assert_float_eq(a, b);
} END_TEST

START_TEST(tests_s21_sscanf_o) {
    int a, b;
    int z, g;
    ck_assert_int_eq((sscanf("014", "%o", &a)), (s21_sscanf("014", "%o", &b)));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("010", "%o", &a)), (s21_sscanf("010", "%o", &b)));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("710", "%o", &a)), (s21_sscanf("710", "%o", &b)));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("577", "%o", &a)), (s21_sscanf("577", "%o", &b)));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("888", "%o", &a)), (s21_sscanf("888", "%o", &b)));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("0", "%o", &a)), (s21_sscanf("0", "%o", &b)));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq((sscanf("010 10", "%o%d", &a, &z)),
            (s21_sscanf("010 10", "%o%d", &b, &g)));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq(z, g);
    ck_assert_int_eq((sscanf("     71234542 10", "%o%d", &a, &z)),
            (s21_sscanf("     71234542 10", "%o%d", &b, &g)));
    ck_assert_int_eq(a, b);
    ck_assert_int_eq(z, g);
}
END_TEST

START_TEST(tests_s21_sscanf_string) {
    char a[500], b[500];
    char a1[50], b1[50];
    char *str = "tthisthisthisthisthisthisthisthisthisthisthisthisthisthisthisthisthisthisthisthisthisthis";
    ck_assert_int_eq((sscanf(str, "%s", a)), s21_sscanf(str, "%s", b));
    ck_assert_str_eq(a, b);
    ck_assert_int_eq((sscanf("that is", "%s%s", a, a1)), s21_sscanf("that is", "%s%s", b, b1));
    ck_assert_str_eq(a, b);
    ck_assert_str_eq(a1, b1);
    ck_assert_int_eq((sscanf(" that is", "%s%s", a, a1)), s21_sscanf(" that is", "%s%s", b, b1));
    ck_assert_str_eq(a, b);
    ck_assert_str_eq(a1, b1);
    ck_assert_int_eq((sscanf("cccheckheckcheckheckheckcheckcheckheckcheckheckheckcheck", "%10s", a)),
            s21_sscanf("cccheckheckcheckheckheckcheckcheckheckcheckheckheckcheck", "%10s", b));
    ck_assert_str_eq(a, b);
    ck_assert_int_eq((sscanf("check check", "%*s%s", a)),
            s21_sscanf("check check", "%*s%s", b));
    ck_assert_str_eq(a, b);
    ck_assert_int_eq((sscanf("  check check", "%*s%s", a)),
            s21_sscanf("  check check", "%*s%s", b));
    ck_assert_str_eq(a, b);
}
END_TEST


START_TEST(tests_s21_sscanf_u) {
    unsigned int a, b;
    ck_assert_int_eq((sscanf("514", "%u", &a)), (s21_sscanf("514", "%u", &b)));
    ck_assert_uint_eq(a, b);
    ck_assert_int_eq((sscanf(" 10", "%u", &a)), (s21_sscanf(" 10", "%u", &b)));
    ck_assert_uint_eq(a, b);
    ck_assert_int_eq((sscanf(" 80", "%u", &a)), (s21_sscanf(" 80", "%u", &b)));
    ck_assert_uint_eq(a, b);
    ck_assert_int_eq((sscanf("310", "%u", &a)), (s21_sscanf("310", "%u", &b)));
    ck_assert_uint_eq(a, b);
    ck_assert_int_eq((sscanf("S10", "%u", &a)), (s21_sscanf("S10", "%u", &b)));
    ck_assert_uint_eq(a, b);
    ck_assert_int_eq((sscanf(".10", "%u", &a)), (s21_sscanf(".10", "%u", &b)));
    ck_assert_uint_eq(a, b);
}

START_TEST(tests_s21_sscanf_x_X) {
    unsigned int a, b;
    ck_assert_int_eq((sscanf("514", "%x", &a)), (s21_sscanf("514", "%x", &b)));
    ck_assert_uint_eq(a, b);
    ck_assert_int_eq((sscanf("  10", "%x", &a)), (s21_sscanf("  10", "%x", &b)));
    ck_assert_uint_eq(a, b);
    ck_assert_int_eq((sscanf(" F10F E10", "%x", &a)), \
            (s21_sscanf(" F10F E10", "%x", &b)));
    ck_assert_uint_eq(a, b);
    ck_assert_int_eq((sscanf("AAB", "%X", &a)), (s21_sscanf("AAB", "%X", &b)));
    ck_assert_uint_eq(a, b);
    ck_assert_int_eq((sscanf("DEEE", "%x", &a)), \
            (s21_sscanf("DEEE", "%x", &b)));
    ck_assert_uint_eq(a, b);
    ck_assert_int_eq((sscanf("DEF", "%X", &a)), (s21_sscanf("DEF", "%X", &b)));
    ck_assert_uint_eq(a, b);
    ck_assert_int_eq((sscanf("def", "%x", &a)), (s21_sscanf("def", "%x", &b)));
    ck_assert_uint_eq(a, b);
}
END_TEST


START_TEST(tests_s21_sscanf_p) {
    int val = 1234123;
    char buf[100];
    void *ptr;
    void *ptr1;
    sprintf(buf, "%p", (void*)&val);
    ck_assert_int_eq((sscanf(buf, "%p", &ptr)), s21_sscanf(buf, "%p", &ptr1));
    int *iPtr1 = ptr1;
    int *iPtr = ptr;
    ck_assert_int_eq(*iPtr1, val);
    ck_assert_ptr_eq(iPtr1, &val);
    ck_assert_ptr_eq(iPtr, &val);
    char *hello = "I am characters";
    sprintf(buf, "%p", (void*)&hello);
    ck_assert_int_eq((sscanf(buf, "%p", &ptr)), s21_sscanf(buf, "%p", &ptr1));
    char *iPr1 = ptr1;
    char *iPr = ptr;
    ck_assert_ptr_eq(iPr1, &hello);
    ck_assert_ptr_eq(iPr, &hello);
} END_TEST

START_TEST(tests_s21_sscanf_n) {
    int a, b, a1, b1;
    int z, z1;
    char str[100];
    char str1[100];
    char st[100];
    char st1[100];
    ck_assert_int_eq((sscanf("514", "%u%n", &a, &a1)), s21_sscanf("514", "%u%n", &b, &b1));
    ck_assert_int_eq(a1, b1);
    ck_assert_int_eq((sscanf("  312", "%u%n", &a, &a1)), (s21_sscanf("  312", "%u%n", &b, &b1)));
    ck_assert_int_eq(a1, b1);
    ck_assert_int_eq((sscanf("312 iamstring", "%u%n%s%n", &a, &a1, str, &z)),
            (s21_sscanf("312 iamstring", "%u%n%s%n", &b, &b1, str1, &z1)));
    ck_assert_int_eq(a1, b1);
    ck_assert_int_eq(z, z1);
    ck_assert_int_eq((sscanf("hello,enterio", "%s%n", st, &a1)),
            s21_sscanf("hello,enterio", "%s%n", st1, &b1));
    ck_assert_int_eq(a1, b1);
    ck_assert_int_eq((sscanf("reallybigreallybig opa ozhidal?", "%s%n", st, &a1)),
            s21_sscanf("reallybigreallybig opa ozhidal?", "%s%n", st1, &b1));
    ck_assert_int_eq(a1, b1);
} END_TEST

START_TEST(tests_s21_sscanf_percent) {
    char a[100], b[100];
    ck_assert_int_eq((sscanf("% check  check", "%%%s", a)),
            s21_sscanf("% check check", "%%%s", b));
    ck_assert_str_eq(a, b);
    ck_assert_int_eq((sscanf("checkcheck", "%s%%", a)),
            s21_sscanf("checkcheck", "%s%%", b));
    ck_assert_str_eq(a, b);
    ck_assert_int_eq((sscanf("checkcheck", "%s%%", a)),
            s21_sscanf("checkcheck", "%s%%", b));
    ck_assert_str_eq(a, b);
    ck_assert_int_eq((sscanf(" check%check", "%%%s", a)),
            s21_sscanf(" check%check", "%%%s", b));
    ck_assert_str_eq(a, b);
} END_TEST

START_TEST(tests_s21_sscanf_width) {
    char a[100], b[100];
    ck_assert_int_eq((sscanf("check check", "%22s", a)),
            s21_sscanf("check check", "%22s", b));
    ck_assert_str_eq(a, b);
    ck_assert_int_eq((sscanf("check check", "%2s", a)),
            s21_sscanf("check check", "%2s", b));
    ck_assert_str_eq(a, b);
    ck_assert_int_eq((sscanf("check check", "%1s", a)),
            s21_sscanf("check check", "%1s", b));
    ck_assert_str_eq(a, b);
} END_TEST

START_TEST(tests_s21_sscanf_length_h) {
    short int z1, v1;
    ck_assert_int_eq((sscanf("-512", "%hd", &z1)),
            s21_sscanf("-512", "%hd", &v1));
    ck_assert_int_eq(z1, v1);
    ck_assert_int_eq((sscanf("512", "%hi", &z1)),
            s21_sscanf("512", "%hd", &v1));
    ck_assert_int_eq(z1, v1);
    ck_assert_int_eq((sscanf("2", "%2hi", &z1)),
            s21_sscanf("2", "%2hd", &v1));
    ck_assert_int_eq(z1, v1);
    ck_assert_int_eq((sscanf("512", "%ho", &z1)),
            s21_sscanf("512", "%ho", &v1));
    ck_assert_int_eq(z1, v1);
    ck_assert_int_eq((sscanf("512", "%hX", &z1)),
            s21_sscanf("512", "%hX", &v1));
    ck_assert_int_eq(z1, v1);
} END_TEST

START_TEST(tests_s21_sscanf_length_l) {
    long z1, v1;
    ck_assert_int_eq((sscanf("512", "%ld", &z1)),
            s21_sscanf("512", "%ld", &v1));
    ck_assert_int_eq(z1, v1);
    ck_assert_int_eq((sscanf("1111512", "%ld", &z1)),
            s21_sscanf("1111512", "%ld", &v1));
    ck_assert_int_eq(z1, v1);
    ck_assert_int_eq((sscanf("912321512", "%ld", &z1)),
            s21_sscanf("912321512", "%ld", &v1));
    ck_assert_int_eq(z1, v1);
    ck_assert_int_eq((sscanf("5z2", "%ld", &z1)),
            s21_sscanf("5z2", "%ld", &v1));
    ck_assert_int_eq(z1, v1);
    long long ba, ga;
    ck_assert_int_eq((sscanf("5z2", "%lld", &ba)),
            s21_sscanf("5z2", "%lld", &ga));
    ck_assert_int_eq(ba, ga);
    ck_assert_int_eq((sscanf("5.2", "%ld", &z1)),
            s21_sscanf("5.2", "%ld", &v1));
    ck_assert_int_eq(z1, v1);
    ck_assert_int_eq((sscanf("5 Oi Mate", "%ld", &z1)),
            s21_sscanf("5 Oi Mate", "%ld", &v1));
    ck_assert_int_eq(z1, v1);
} END_TEST

START_TEST(tests_s21_sscanf_length_L) {
    long double z1, v1;
    char *num = "512.0123456789123456789123213123123123123213123123123123124135235462";
    ck_assert_int_eq((sscanf("512.0123456789123456789", "%Lf", &z1)),
            s21_sscanf("512.0123456789123456789", "%Lf", &v1));
    ck_assert_float_eq(z1, v1);
    ck_assert_int_eq((sscanf(num, "%Lf", &z1)),
            s21_sscanf(num, "%Lf", &v1));
    ck_assert_float_eq(z1, v1);
    ck_assert_int_eq((sscanf("2.0123456789123456789", "%Lf", &z1)),
            s21_sscanf("2.0123456789123456789", "%Lf", &v1));
    ck_assert_float_eq(z1, v1);
    ck_assert_int_eq((sscanf("s   2.0123456789123456789", "%Lf", &z1)),
            s21_sscanf("s   2.0123456789123456789", "%Lf", &v1));
    ck_assert_float_eq(z1, v1);
    ck_assert_int_eq((sscanf("9123213123123321321512", "%Lf", &z1)),
            s21_sscanf("9123213123123321321512", "%Lf", &v1));
    ck_assert_float_eq(z1, v1);
    ck_assert_int_eq((sscanf("2.0123456789123456789", "%Lf", &z1)),
            s21_sscanf("2.0123456789123456789", "%Lf", &v1));
    ck_assert_float_eq(z1, v1);
} END_TEST

START_TEST(test_s21_strcat) {
    char test1[100] = "test_string\0";
    char* test2 = "second_string\0";
    char* res = strcat(test1, test2);
    char* res2 = s21_strcat(test1, test2);
    ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strcmp) {
    char* str1 = "abcd";
    char* str2 = "Abcd";
    char* str4 = "";
    ck_assert_int_eq(s21_strcmp(str1, str1), strcmp(str1, str1));
    int a = s21_strcmp(str1, str2);
    int b = strcmp(str1, str2);
    if (a < -1) a = -1;
    if (b < -1) b = -1;
    if (a > 1) a = 1;
    if (b > 1) b = 1;
    ck_assert_int_eq(a, b);
    ck_assert((s21_strcmp(str1, str4) < 0 && strcmp(str1, str4) < 0) || (s21_strcmp(str1, str4) > 0 &&\
                strcmp(str1, str4) > 0) || (s21_strcmp(str1, str4) == 0 && strcmp(str1, str4) == 0));
    ck_assert((s21_strcmp(str4, str1) < 0 && strcmp(str4, str1) < 0) || (s21_strcmp(str4, str1) > 0 &&\
                strcmp(str4, str1) > 0) || (s21_strcmp(str4, str1) == 0 && strcmp(str4, str1) == 0));
    ck_assert((s21_strcmp(str4, str4) < 0 && strcmp(str4, str4) < 0) || (s21_strcmp(str4, str4) > 0 &&\
                strcmp(str4, str4) > 0) || (s21_strcmp(str4, str4) == 0 && strcmp(str4, str4) == 0));
    char* str5 = " ";
    ck_assert((s21_strcmp(str4, str5) < 0 && strcmp(str4, str5) < 0) || (s21_strcmp(str4, str5) > 0 &&\
                strcmp(str4, str5) > 0) || (s21_strcmp(str4, str5) == 0 && strcmp(str4, str5) == 0));
    char* str6 = "123456";
    ck_assert_int_eq(s21_strcmp(str6, str6), strcmp(str6, str6));
}
END_TEST

START_TEST(test_s21_strcmp_2) {
    char* str1 = "Abcd";
    char* str2 = "abcd";
    ck_assert((s21_strcmp(str1, str2) < 0 && strcmp(str1, str2) < 0) || (s21_strcmp(str1, str2) > 0 &&\
                strcmp(str1, str2) > 0) || (s21_strcmp(str1, str2) == 0 && strcmp(str1, str2) == 0));
}
END_TEST

START_TEST(s21_strncmp_test) {
    char* str1 = "abcd";
    char* str2 = "abcdef";
    char* str3 = "Abcd";
    char* str4 = "";
    ck_assert_int_eq(s21_strncmp(str1, str1, 4), strncmp(str1, str1, 4));
    ck_assert_int_eq(s21_strncmp(str1, str1, 1), strncmp(str1, str1, 1));
    ck_assert_int_eq(s21_strncmp(str1, str2, 4), strncmp(str1, str2, 4));
    ck_assert((s21_strncmp(str1, str2, 5) < 0 && strncmp(str1, str2, 5) < 0) ||\
            (s21_strncmp(str1, str2, 5) > 0 &&
             strncmp(str1, str2, 5) > 0) || (s21_strncmp(str1, str2, 5) == 0 && strncmp(str1, str2, 5) == 0));
    int a = s21_strncmp(str1, str3, 4);
    int b = strncmp(str1, str3, 4);
    if (a < -1) a = -1;
    if (b < -1) b = -1;
    if (a > 1) a = 1;
    if (b > 1) b = 1;
    ck_assert_int_eq(a, b);
    ck_assert_int_eq(s21_strncmp(str1, str4, 0), strncmp(str1, str4, 0));
    ck_assert_int_eq(s21_strncmp(str4, str1, 0), strncmp(str4, str1, 0));
    ck_assert_int_eq(s21_strncmp(str4, str4, 0), strncmp(str4, str4, 0));
    char* str5 = " ";
    ck_assert_int_eq(s21_strncmp(str4, str5, 0), strncmp(str4, str5, 0));
    char* str6 = "123456";
    ck_assert_int_eq(s21_strncmp(str6, str6, 3), strncmp(str6, str6, 3));
}
END_TEST

START_TEST(s21_memcmp_test) {
    char str1[] = "ABCDE";
    char str2[] = "5";
    char str3[] = "aBCDE";
    char str4[] = "5432";
    char str5[] = "53";
    char str6[] = "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
    char str7[] = "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASd";

    ck_assert((s21_memcmp(str1, str1, 0) < 0 && memcmp(str1, str1, 0) < 0) ||\
    (s21_memcmp(str1, str1, 0) > 0 && memcmp(str1, str1, 0) > 0) || (s21_memcmp(str1, str1, 0) == 0 &&\
     memcmp(str1, str1, 0) == 0));
    // ck_assert_int_eq(s21_memcmp(str1, str1, 0), memcmp(str1, str1, 0));
    ck_assert_int_eq(s21_memcmp(str1, str1, 3), memcmp(str1, str1, 3));
    ck_assert((s21_memcmp(str1, str3, 1) < 0 && memcmp(str1, str3, 1) < 0) ||\
    (s21_memcmp(str1, str3, 1) > 0 && memcmp(str1, str3, 1) > 0) || (s21_memcmp(str1, str3, 1) == 0 &&\
     memcmp(str1, str3, 1) == 0));
    ck_assert_int_eq(s21_memcmp(str2, str2, 0), memcmp(str2, str2, 0));
    ck_assert_int_eq(s21_memcmp(str2, str4, 1), memcmp(str2, str4, 1));
    ck_assert_int_eq(s21_memcmp(str4, str4, 2), memcmp(str4, str4, 2));
    ck_assert((s21_memcmp(str4, str5, 2) < 0 && memcmp(str4, str5, 2) < 0) ||\
    (s21_memcmp(str4, str5, 2) > 0 && memcmp(str4, str5, 2) > 0) || (s21_memcmp(str4, str5, 2) == 0 &&\
     memcmp(str4, str5, 2) == 0));
    ck_assert_int_eq(s21_memcmp(str6, str6, 71), memcmp(str6, str6, 71));
    ck_assert((s21_memcmp(str6, str7, 71) < 0 && memcmp(str6, str7, 71) < 0) ||\
    (s21_memcmp(str6, str7, 71) > 0 && memcmp(str6, str7, 71) > 0) || (s21_memcmp(str6, str7, 71) == 0 &&\
     memcmp(str6, str7, 71) == 0));
}
END_TEST

START_TEST(test_s21_trim_both) {
    char* test1 = s21_NULL;
    test1 = s21_trim("", "");
    char* test2 = "";
    ck_assert_str_eq(test1, test2);
    if (test1) free(test1);
}
END_TEST


START_TEST(test_s21_trim_first_zero_str) {
    char* test3 = s21_NULL;
    test3 = s21_trim("", "qwer123!&$");
    char* test4 = "";
    ck_assert_str_eq(test3, test4);
    if (test3) free(test3);
}
END_TEST


START_TEST(test_s21_trim_second_zero_str) {
    char* test5 = s21_NULL;
    test5 = s21_trim("qwer123!&$", "");
    char* test6 = "qwer123!&$";
    ck_assert_str_eq(test5, test6);
    if (test5) free(test5);
}
END_TEST


START_TEST(test_s21_trim_same_str) {
    char* test7 = s21_NULL;
    test7 = s21_trim("qwer123!&$", "qwer123!&$");
    char* test8 = "";
    ck_assert_str_eq(test7, test8);
    if (test7) free(test7);
}
END_TEST


START_TEST(test_s21_trim) {
    char* test9 = s21_NULL;
    test9 = s21_trim("!!-+giga00!+", "!+-0");
    char* test10 = "giga";
    ck_assert_str_eq(test9, test10);
    if (test9) free(test9);
}
END_TEST


START_TEST(test_s21_trim_numbers) {
    char* test11 = s21_NULL;
    test11 = s21_trim("AB2CD3", "123");
    char* test12 = "AB2CD";
    ck_assert_str_eq(test11, test12);
    if (test11) free(test11);
}
END_TEST

START_TEST(test_s21_trim_2) {
    char* test13 = s21_NULL;
    test13 = s21_trim("!  ABCD3  !", "123! ");
    char* test14 = "ABCD";
    ck_assert_str_eq(test13, test14);
    if (test13) free(test13);
}
END_TEST

START_TEST(test_s21_strncat) {
    char test1[100] = "test_string\0";
    char* test2 = "second_string\0";
    char* res = strncat(test1, test2, 3);
    char* res2 = s21_strncat(test1, test2, 3);
    ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strncat_zero) {
    char test1[100] = "test_string\0";
    char* test2 = "second_string\0";
    char* res = strncat(test1, test2, 0);
    char* res2 = s21_strncat(test1, test2, 0);
    ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strerror) {
    int n = 1;
    char* res = strerror(n);
    char* res2 = s21_strerror(n);
    ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strerror_linux_max) {
    int n = 133;
    char* res = strerror(n);
    char* res2 = s21_strerror(n);
    ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strerror_error_0) {
    int n = 0;
    char* res = strerror(n);
    char* res2 = s21_strerror(n);
    ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strerror_no_error) {
    int n = 144;
    char* res = strerror(n);
    char* res2 = s21_strerror(n);
    ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strtok) {
    char test1[100] = "tik tok tik.tok\0";
    char* test2 = " .\0";
    char* res = strtok(test1, test2);
    char* res2 = s21_strtok(test1, test2);
    ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strtok_double) {
    char test1[100] = "tik tok tak.tok\0";
    char test3[100] = "tik tok tak.tok\0";
    char* test2 = " .\0";
    char* res = strtok(test1, test2);
    char* res2 = s21_strtok(test3, test2);
    res = strtok(test1, test2);
    res2 = s21_strtok(test3, test2);
    res = strtok(test1, test2);
    res2 = s21_strtok(test3, test2);
    ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strtok_NULL) {
    char test1[100] = "tik tok tik.tok\0";
    char test3[100] = "tik tok tik.tok\0";
    char* test2 = " .\0";
    char* res = strtok(test1, test2);
    char* res2 = s21_strtok(test3, test2);
    res = strtok(NULL, test2);
    res2 = s21_strtok(s21_NULL, test2);
    ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(test_s21_strtok_first_NULL) {
    char* test2 = "OK";
    char* res = strtok(NULL, test2);
    char* res2 = s21_strtok(s21_NULL, test2);
    res = strtok(NULL, test2);
    res2 = s21_strtok(s21_NULL, test2);
    ck_assert_ptr_eq(res, res2);
}
END_TEST

START_TEST(test_s21_to_upper) {
    char* res = s21_NULL;
    char* test = "My little123 ponny";
    res = s21_to_upper(test);
    char* res2 = "MY LITTLE123 PONNY";
    ck_assert_str_eq(res, res2);
    if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_upper_NULL) {
    char* res = s21_NULL;
    res = s21_to_upper(s21_NULL);
    char* res2 = NULL;
    ck_assert_ptr_eq(res, res2);
    if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_upper_zero_str) {
    char* res1 = s21_NULL;
    res1 = s21_to_upper("");
    ck_assert_str_eq(res1, "");
    if (res1) free(res1);
}
END_TEST

START_TEST(test_s21_to_lower) {
    char* test = "MY LITTLE123 PONNY";
    char* res = s21_NULL;
    res = s21_to_lower(test);
    char* res2 = "my little123 ponny";
    ck_assert_str_eq(res, res2);
    if (res) free(res);
}
END_TEST


START_TEST(test_s21_to_lower_NULL) {
    char* res = s21_NULL;
    res = s21_to_lower(s21_NULL);
    char* res2 = NULL;
    ck_assert_ptr_eq(res, res2);
    if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_lower_zero_str) {
    char* res1 = s21_NULL;
    res1 = s21_to_lower("");
    ck_assert_str_eq(res1, "");
    if (res1) free(res1);
}
END_TEST

START_TEST(test_s21_insert) {
    char* res = s21_NULL;
    res = s21_insert("I Groot", "am", 1);
    char* res2 = "Iam Groot";
    ck_assert_str_eq(res, res2);
    if (res) free(res);
}
END_TEST

START_TEST(test_s21_insert_index_zero) {
    char* res = s21_NULL;
    res = s21_insert("I am Groot", "OK:", 0);
    char* res2 = "OK:I am Groot";
    ck_assert_str_eq(res, res2);
    if (res) free(res);
}
END_TEST

START_TEST(test_s21_insert_index_greater_than_length) {
    char* res = s21_NULL;
    res = s21_insert("12345", "OK", 7);
    char* res2 = NULL;
    ck_assert_ptr_eq(res, res2);
    if (res) free(res);
}
END_TEST

START_TEST(test_s21_insert_index_less_than_zero) {
    char* res = s21_NULL;
    res = s21_insert("12345", "OK", -2);
    char* res2 = NULL;
    ck_assert_ptr_eq(res, res2);
    if (res) free(res);
}
END_TEST

START_TEST(test_s21_strcpy) {
    char dest[10] = {0};
    const char *str = "hello";
    s21_strcpy(dest, str);
    char dest2[10] = {0};
    strcpy(dest2, str);

    ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_strcpy_info_after_null) {
    char dest[10] = {0};
    const char *str = "123 \0 123";
    s21_strcpy(dest, str);
    char dest2[10] = {0};
    strcpy(dest2, str);

    ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_strcpy_q) {
    char dest[10] = {0};
    const char *str = "\0123";
    s21_strcpy(dest, str);
    char dest2[10] = {0};
    strcpy(dest2, str);

    ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_strncpy) {
    s21_size_t num = 6;
    char dest[10] = {0};
    const char *str = "louder then";
    s21_strncpy(dest, str, num);
    char dest2[10] = {0};
    strncpy(dest2, str, num);

    ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_strncpy_info_after_null) {
    s21_size_t num = 7;
    char dest[10] = {0};
    const char *str = "123 \0 2";
    s21_strncpy(dest, str, num);
    char dest2[10] = {0};
    strncpy(dest2, str, num);

    ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_strncpy_zero_num) {
    s21_size_t num = 0;
    char dest[10] = {0};
    const char *str = "12345p";
    s21_strncpy(dest, str, num);
    char dest2[10] = {0};
    strncpy(dest2, str, num);

    ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_memcpy) {
    s21_size_t num = 6;
    char dest[10] = {0};
    const char *str = "louder then";
    s21_memcpy(dest, str, num);
    char dest2[10] = {0};
    memcpy(dest2, str, num);

    ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_memcpy_info_after_null) {
    s21_size_t num = 6;
    char dest[10] = {0};
    const char *str = "louder then";
    s21_memcpy(dest, str, num);
    char dest2[10] = {0};
    memcpy(dest2, str, num);

    ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_memcpy_zero_num) {
    s21_size_t num = 0;
    char dest[10] = {0};
    const char *str = "louder then";
    s21_memcpy(dest, str, num);
    char dest2[10] = {0};
    memcpy(dest2, str, num);

    ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_memmove) {
    s21_size_t num = 6;
    char dest[10] = {0};
    const char *str = "louder then";
    s21_memmove(dest, str, num);
    char dest2[10] = {0};
    memmove(dest2, str, num);

    ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_memmove_zero_num) {
    s21_size_t num = 0;
    char dest[10] = {0};
    const char *str = "1234";
    s21_memmove(dest, str, num);
    char dest2[10] = {0};
    memmove(dest2, str, num);

    ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_memmove_info_after_null) {
    s21_size_t num = 8;
    char dest[10] = {0};
    const char *str = "123 \0 34";
    s21_memmove(dest, str, num);
    char dest2[10] = {0};
    memmove(dest2, str, num);

    ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(test_s21_memmove_new) {
    s21_size_t num = 8;
    char func1[10] = "123456789";
    char func2[10] = "987654321";
    char answ1[10] = {0};
    char answ2[10] = {0};
    if (&func1 < &func2) {
        s21_memmove(func1, func2, num);
        strcpy(answ1, func1);
        memmove(func1, func2, num);
        strcpy(answ2, func1);
    } else {
        s21_memmove(func2, func1, num);
        strcpy(answ1, func2);
        memmove(func2, func1, num);
        strcpy(answ2, func2);
    }

    ck_assert_str_eq(answ1, answ2);
}
END_TEST

START_TEST(test_s21_memset) {
    s21_size_t num = 6;
    int c = 43;
    char str[7] = "louder";
    char str2[7] = "louder";
    s21_memset(str, c, num);
    memset(str2, c, num);

    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_s21_memset_zero_num) {
    s21_size_t num = 0;
    int c = 43;
    char str[7] = "louder";
    char str2[7] = "louder";
    s21_memset(str, c, num);
    memset(str2, c, num);

    ck_assert_str_eq(str, str2);
}
END_TEST

Suite* insert_suite(void) {
    Suite* s;
    TCase* tc_core;
    TCase* tc_limits;

    s = suite_create("insert");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_s21_insert);
    tcase_add_test(tc_core, test_s21_insert_index_zero);
    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");
    tcase_add_test(tc_limits, test_s21_insert_index_greater_than_length);
    tcase_add_test(tc_limits, test_s21_insert_index_less_than_zero);
    suite_add_tcase(s, tc_limits);

    return s;
}

Suite* memchr_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("memchr");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, tests_s21_memchr_letter_noexists);
    tcase_add_test(tc_core, tests_s21_memchr_letterexists);
    suite_add_tcase(s, tc_core);

    return s;
}

Suite* to_upper_suite(void) {
    Suite* s;
    TCase* tc_core;
    TCase* tc_limits;

    s = suite_create("to_upper");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_s21_to_upper);
    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");
    tcase_add_test(tc_limits, test_s21_to_upper_NULL);
    tcase_add_test(tc_limits, test_s21_to_upper_zero_str);
    suite_add_tcase(s, tc_limits);

    return s;
}

Suite* to_lower_suite(void) {
    Suite* s;
    TCase* tc_core;
    TCase* tc_limits;

    s = suite_create("to_lower");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_s21_to_lower);
    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");
    tcase_add_test(tc_limits, test_s21_to_lower_NULL);
    tcase_add_test(tc_limits, test_s21_to_lower_zero_str);

    suite_add_tcase(s, tc_limits);

    return s;
}

Suite* strerror_suite(void) {
    Suite* s;
    TCase* tc_core;
    TCase* tc_limits;

    s = suite_create("strerror");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_s21_strerror);
    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");
    tcase_add_test(tc_limits, test_s21_strerror_linux_max);
    tcase_add_test(tc_limits, test_s21_strerror_error_0);
    tcase_add_test(tc_limits, test_s21_strerror_no_error);
    suite_add_tcase(s, tc_limits);

    return s;
}

Suite* strncat_suite(void) {
    Suite* s;
    TCase* tc_core;
    TCase* tc_limits;

    s = suite_create("strcat");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_s21_strncat);
    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");
    tcase_add_test(tc_limits, test_s21_strncat_zero);
    suite_add_tcase(s, tc_limits);

    return s;
}

Suite* strcat_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("strcat");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_strcat);
    suite_add_tcase(s, tc_core);

    return s;
}

Suite* strtok_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("strtok");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_strtok);
    tcase_add_test(tc_core, test_s21_strtok_NULL);
    tcase_add_test(tc_core, test_s21_strtok_first_NULL);
    tcase_add_test(tc_core, test_s21_strtok_double);
    suite_add_tcase(s, tc_core);

    return s;
}

Suite* strchr_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("strchr");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, tests_s21_strchr_letter_exists);
    tcase_add_test(tc_core, tests_s21_strchr_letter_noexists);
    suite_add_tcase(s, tc_core);

    return s;
}

Suite* strpbrk_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("strpbrk");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, tests_s21_strpbrk);
    suite_add_tcase(s, tc_core);

    return s;
}

Suite* strstr_suite(void) {
    Suite* s;
    TCase* tc_core;
    TCase* tc_limits;

    s = suite_create("strstr");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, tests_s21_strstr);
    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");
    tcase_add_test(tc_limits, test_s21_strstr_first_empty_str);
    tcase_add_test(tc_limits, test_s21_strstr_second_empty_str);
    suite_add_tcase(s, tc_limits);

    return s;
}
Suite* sscanf_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("sscanf");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, tests_s21_sscanf_char);
    tcase_add_test(tc_core, tests_s21_sscanf_decim);
    tcase_add_test(tc_core, tests_s21_sscanf_int);
    tcase_add_test(tc_core, tests_s21_sscanf_e_E);
    tcase_add_test(tc_core, tests_s21_sscanf_f);
    tcase_add_test(tc_core, tests_s21_sscanf_g_G);
    tcase_add_test(tc_core, tests_s21_sscanf_o);
    tcase_add_test(tc_core, tests_s21_sscanf_string);
    tcase_add_test(tc_core, tests_s21_sscanf_u);
    tcase_add_test(tc_core, tests_s21_sscanf_x_X);
    tcase_add_test(tc_core, tests_s21_sscanf_p);
    tcase_add_test(tc_core, tests_s21_sscanf_n);
    tcase_add_test(tc_core, tests_s21_sscanf_percent);
    tcase_add_test(tc_core, tests_s21_sscanf_width);
    tcase_add_test(tc_core, tests_s21_sscanf_length_h);
    tcase_add_test(tc_core, tests_s21_sscanf_length_l);
    tcase_add_test(tc_core, tests_s21_sscanf_length_L);
    suite_add_tcase(s, tc_core);

    return s;
}

Suite* strrchr_suite(void) {
    Suite* s;
    TCase* e;

    s = suite_create("strrchr");
    e = tcase_create("e");

    tcase_add_test(e, tests_s21_strrchr_letter_exists);
    tcase_add_test(e, tests_s21_strrchr_letter_noexists);
    suite_add_tcase(s, e);

    return s;
}

Suite* strncmp_suite(void) {
    Suite* suite;
    TCase* getCase;
    suite = suite_create("strncmp");
    getCase = tcase_create("core");
    tcase_add_test(getCase, s21_strncmp_test);
    suite_add_tcase(suite, getCase);
    return suite;
}

Suite* strcmp_suite(void) {
    Suite* suite;
    TCase* getCase;
    suite = suite_create("strcmp");
    getCase = tcase_create("core");
    tcase_add_test(getCase, test_s21_strcmp);
    tcase_add_test(getCase, test_s21_strcmp_2);
    suite_add_tcase(suite, getCase);
    return suite;
}

Suite* memcmp_suite(void) {
    Suite* suite;
    TCase* getCase;
    suite = suite_create("memcmp");
    getCase = tcase_create("core");
    tcase_add_test(getCase, s21_memcmp_test);
    suite_add_tcase(suite, getCase);
    return suite;
}


Suite* sprintf_suite(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("sprintf");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_sprintf_c);
    tcase_add_test(tc_core, test_s21_sprintf_d_i);
    tcase_add_test(tc_core, test_s21_sprintf_d_i_lengths);
    tcase_add_test(tc_core, test_s21_sprintf_e_E);
    tcase_add_test(tc_core, test_s21_sprintf_f);
    tcase_add_test(tc_core, test_s21_sprintf_g_G);
    tcase_add_test(tc_core, test_s21_sprintf_o);
    tcase_add_test(tc_core, test_s21_sprintf_s);
    tcase_add_test(tc_core, test_s21_sprintf_u);
    tcase_add_test(tc_core, test_s21_sprintf_X_x);
    tcase_add_test(tc_core, test_s21_sprintf_p);
    tcase_add_test(tc_core, test_s21_sprintf_n);
    tcase_add_test(tc_core, test_s21_sprintf_percent);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite* len_suite(void) {
    Suite* s;
    TCase* tc_core;
    TCase* tc_limits;

    s = suite_create("strlen");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_s21_strlen);
    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");
    tcase_add_test(tc_limits, test_s21_strlen_null_str);
    tcase_add_test(tc_limits, test_s21_strlen_invalid_str);
    suite_add_tcase(s, tc_limits);

    return s;
}

Suite* strspn_suite(void) {
    Suite* s;
    TCase* tc_core;
    TCase* tc_limits;

    s = suite_create("strpsn");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_s21_strspn);
    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");
    tcase_add_test(tc_limits, test_s21_strspn_no_matches);
    tcase_add_test(tc_limits, test_s21_strspn_all_matches);
    suite_add_tcase(s, tc_limits);

    return s;
}

Suite* strcspn_suite(void) {
    Suite* s;
    TCase* tc_core;
    TCase* tc_limits;

    s = suite_create("strcspn");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_s21_strcspn);
    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");
    tcase_add_test(tc_limits, test_s21_strcspn_no_matches);
    tcase_add_test(tc_limits, test_s21_strcspn_null_string);
    suite_add_tcase(s, tc_limits);

    return s;
}

Suite* trim_suite(void) {
    Suite* suite;
    TCase* getCase;
    TCase *tc_limits;
    suite = suite_create("trim");
    getCase = tcase_create("core");
    tcase_add_test(getCase, test_s21_trim);
    tcase_add_test(getCase, test_s21_trim_2);
    tcase_add_test(getCase, test_s21_trim_numbers);
    suite_add_tcase(suite, getCase);
    tc_limits = tcase_create("Limits");
    tcase_add_test(tc_limits, test_s21_trim_both);
    tcase_add_test(tc_limits, test_s21_trim_first_zero_str);
    tcase_add_test(tc_limits, test_s21_trim_same_str);
    tcase_add_test(tc_limits, test_s21_trim_second_zero_str);
    suite_add_tcase(suite, tc_limits);
    return suite;
}

Suite * s21_strcpy_suite(void) {
    Suite *s;
    TCase *tc_core;
    TCase *tc_limits;

    s = suite_create("strcpy");

    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_strcpy);
    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");
    tcase_add_test(tc_limits, test_s21_strcpy_info_after_null);
    tcase_add_test(tc_limits, test_s21_strcpy_q);

    suite_add_tcase(s, tc_limits);

    return s;
}

Suite * s21_strncpy_suite(void) {
    Suite *s;
    TCase *tc_core;
    TCase *tc_limits;

    s = suite_create("strncpy");

    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_strncpy);
    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");
    tcase_add_test(tc_limits, test_s21_strncpy_info_after_null);
    tcase_add_test(tc_limits, test_s21_strncpy_zero_num);

    suite_add_tcase(s, tc_limits);

    return s;
}

Suite * s21_memcpy_suite(void) {
    Suite *s;
    TCase *tc_core;
    TCase *tc_limits;

    s = suite_create("memcpy");

    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_memcpy);
    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");
    tcase_add_test(tc_core, test_s21_memcpy_info_after_null);
    tcase_add_test(tc_core, test_s21_memcpy_zero_num);
    suite_add_tcase(s, tc_limits);

    return s;
}

Suite * s21_memmove_suite(void) {
    Suite *s;
    TCase *tc_core;
    TCase *tc_limits;

    s = suite_create("memmove");

    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_memmove);
    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");
    tcase_add_test(tc_core, test_s21_memmove_info_after_null);
    tcase_add_test(tc_core, test_s21_memmove_zero_num);
    tcase_add_test(tc_core, test_s21_memmove_new);
    suite_add_tcase(s, tc_limits);

    return s;
}

Suite * s21_memset_suite(void) {
    Suite *s;
    TCase *tc_core;
    TCase *tc_limits;

    s = suite_create("memset");

    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_memset);
    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");
    tcase_add_test(tc_core, test_s21_memset_zero_num);
    suite_add_tcase(s, tc_limits);

    return s;
}

int main() {
    int no_failed = 0;
    Suite *a, *b, *c, *d, *e, *f, *g, *k, *m, *n, *v, *z, *y, *l, *q, *w, *r, *t,
          *u, *p, *o;
    Suite *strcpy21, *strncpy21, *memcpy21, *memmove21, *memset21;
    SRunner* runner;

    a = memchr_suite();
    b = strchr_suite();
    c = strpbrk_suite();
    d = strstr_suite();
    e = strrchr_suite();
    f = sscanf_suite();
    k = memcmp_suite();
    l = sprintf_suite();
    m = strspn_suite();
    n = strcspn_suite();
    v = len_suite();
    z = strcmp_suite();
    y = strncmp_suite();
    q = strtok_suite();
    w = strcat_suite();
    r = strncat_suite();
    t = strerror_suite();
    u = to_lower_suite();
    g = to_upper_suite();
    p = insert_suite();
    o = trim_suite();
    strcpy21 = s21_strcpy_suite();
    strncpy21 = s21_strncpy_suite();
    memcpy21 = s21_memcpy_suite();
    memmove21 = s21_memmove_suite();
    memset21 = s21_memset_suite();
    runner = srunner_create(a);
    srunner_add_suite(runner, b);
    srunner_add_suite(runner, c);
    srunner_add_suite(runner, d);
    srunner_add_suite(runner, e);
    srunner_add_suite(runner, f);
    srunner_add_suite(runner, k);
    srunner_add_suite(runner, l);
    srunner_add_suite(runner, m);
    srunner_add_suite(runner, n);
    srunner_add_suite(runner, v);
    srunner_add_suite(runner, z);
    srunner_add_suite(runner, y);
    srunner_add_suite(runner, q);
    srunner_add_suite(runner, w);
    srunner_add_suite(runner, r);
    srunner_add_suite(runner, t);
    srunner_add_suite(runner, u);
    srunner_add_suite(runner, g);
    srunner_add_suite(runner, p);
    srunner_add_suite(runner, o);
    srunner_add_suite(runner, strcpy21);
    srunner_add_suite(runner, strncpy21);
    srunner_add_suite(runner, memcpy21);
    srunner_add_suite(runner, memmove21);
    srunner_add_suite(runner, memset21);

    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
