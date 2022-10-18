#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *new = dest;
  const unsigned char *old = src;
  for (s21_size_t i = 0; i < n; i++) {
    new[i] = old[i];
  }
  return dest;
}
