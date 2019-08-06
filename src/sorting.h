#ifndef SORTING_H
# define SORTING_H

#include <stdbool.h>
#include <string.h>

// bubble.c - bubble sort
void bubble(void *base, size_t nmemb, size_t size,
		    int (*compar)(const void *, const void *));

/* helper.c
 * all sort of functions
 */
bool sorted(void *base, size_t nmemb, size_t size,
            int (*compar)(const void *, const void *));
int	 cmp_int(const void *a,const void *b);
void swap(void *a, void *b, size_t size);

#endif
