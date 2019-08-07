#ifndef SORTING_H
# define SORTING_H

#include <stdbool.h>
#include <string.h>

// bubble.c - bubble sort
void bubble(void *base, size_t nmemb, size_t size,
		    int (*compar)(const void *, const void *));

// insertion.c - insertion sort
void insertion(void *base, size_t nmemb, size_t size,
		       int (*compar)(const void *, const void *));

// merge.c - merge sort
void merge(void *base, size_t nmemb, size_t size,
		   int (*compar)(const void *, const void *));

// selection.c - selection sort
void selection(void *base, size_t nmemb, size_t size,
		       int (*compar)(const void *, const void *));

/* helper.c
 * all sorts of functions (pund intended)
 */
bool sorted(void *base, size_t nmemb, size_t size,
            int (*compar)(const void *, const void *));
int cmp_int(const void *a,const void *b);
int cmp_int_rev(const void *a,const void *b);
void swap(void *a, void *b, size_t size);
size_t range_ptr(int **range, int min, int max);
int *randrange(size_t n);
void print_int_array(int* array, const int len);

#endif
