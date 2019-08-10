#ifndef __HELPER_H__
# define __HELPER_H__

# include <stdbool.h>
# include "string.h"

bool sorted(void *base, size_t nmemb, size_t size,
            int (*compar)(const void *, const void *));
int cmp_int(const void *a,const void *b);
int cmp_int_rev(const void *a,const void *b);
void swap(void *a, void *b, size_t size);
void swap_ptr(void **a, void **b);
void *max(void *a, void *b, int (*compar)(const void *, const void *));
size_t range_ptr(int **range, int min, int max);
int *randrange(size_t n);
void print_int_array(int* array, const int len);

#endif
