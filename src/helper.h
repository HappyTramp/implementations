#ifndef HELPER_H
# define HELPER_H

#include <stdbool.h>
#include "string.h"

bool sorted(void *base, size_t nmemb, size_t size,
            int (*compar)(const void *, const void *));
int cmp_int(const void *a,const void *b);
int cmp_int_rev(const void *a,const void *b);
void swap(void *a, void *b, size_t size);
size_t range_ptr(int **range, int min, int max);
int *randrange(size_t n);
void print_int_array(int* array, const int len);

#endif
