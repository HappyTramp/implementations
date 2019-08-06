#include <stdlib.h>
#include <string.h>
#include "sorting.h"

/* int* setup_create_random_array(const int length, const int random_upper_range) */
/* { */
/*     int* array = malloc(sizeof(int) * length); */
/*     for (int i = 0; i < length; i++) */
/*         array[i] = rand() % random_upper_range; */
/*     return array; */
/* } */

/* void print_array(int* array, const int length) */
/* { */
/*     for (int i = 0; i < length; i++) */
/*     { */
/*         if (i % 10 == 0 && i != 0) */
/*             printf("\n"); */
/*         printf("%d, ", array[i]); */
/*     } */
/* } */

bool sorted(void *base, size_t nmemb, size_t size,
            int (*compar)(const void *, const void *))
{
    for (int i = 0; i < nmemb - 1; i++)
        if (compar(base + i * size, base + i * size + size) > 0)
            return false;
    return true;
}

int	cmp_int(const void *a,const void *b)
{
	if (*(int*)a < *(int*)b)
		return -1;
	if (*(int*)a == *(int*)b)
		return 0;
	return 1;
}

void swap(void *a, void *b, size_t size)
{
	void *c;

	if ((c = malloc(size + 100)) == NULL)
		return ;
	memcpy(c, a, size);
	memcpy(a, b, size);
	memcpy(b, c, size);
	free(c);
}
