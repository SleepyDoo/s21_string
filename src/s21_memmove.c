#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *d = dest;
  const char *s = src;
  if (d < s) {
    while (n--) {
      *d++ = *s++;
    }
  } else {
      while (n--) {
        d[n] = s[n];
      }
  }
  return dest;
}
