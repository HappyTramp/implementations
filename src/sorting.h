#ifndef SORTING_H
# define SORTING_H

#include <stdbool.h>
#include <string.h>

void bubble_sort(void *base, size_t nmemb, size_t size,
		         int (*compar)(const void *, const void *));
void insertion_sort(void *base, size_t nmemb, size_t size,
		            int (*compar)(const void *, const void *));
void shell_sort(void *base, size_t nmemb, size_t size,
		        int (*compar)(const void *, const void *));
void selection_sort(void *base, size_t nmemb, size_t size,
		            int (*compar)(const void *, const void *));
void merge_sort(void *base, size_t nmemb, size_t size,
		        int (*compar)(const void *, const void *));
void quicksort(void *base, size_t nmemb, size_t size,
		       int (*compar)(const void *, const void *));
void cocktail_sort(void *base, size_t nmemb, size_t size,
		           int (*compar)(const void *, const void *));

#endif
