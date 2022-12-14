#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *save = dest;
  while (*src && n) {
    *dest++ = *src++;
    n--;
  }
  while (n--) {
    *dest++ = '\0';
  }
  return save;
}
