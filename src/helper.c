#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "helper.h"

#define RAND_UPPER 1000

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
    return *(int*)a - *(int*)b;
}

int cmp_int_rev(const void *a,const void *b)
{
    return *(int*)b - *(int*)a;
}

void swap(void *a, void *b, size_t size)
{
	void *c;

	if ((c = malloc(size)) == NULL)
		return ;
	memcpy(c, a, size);
	memcpy(a, b, size);
	memcpy(b, c, size);
	free(c);
}

void swap_ptr(void **a, void **b)
{
    void  *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void *max(void *a, void *b, int (*compar)(const void *, const void *))
{
    int cmp = compar(a, b);
    return cmp >= 0 ? a : b;
}

size_t range_ptr(int **range, int min, int max)
{
	size_t i;

	if (min >= max)
	{
		*range = NULL;
		return 0;
	}
	if ((*range = (int*)malloc(sizeof(int) * (max - min))) == NULL)
		return -1;
    for (i = 0; i < max - min; i++)
		(*range)[i] = min + i;
	return i;
}

int *randrange(size_t n)
{
    int *rrange;

    rrange = malloc(sizeof(int) * n);
    while (n-- > 0)
        rrange[n] = rand() % RAND_UPPER;
    return rrange;
}

void print_int_array(int* array, const int len)
{
    for (int i = 0; i < len; i++)
    {
        if (i % 10 == 0 && i != 0)
            printf("\n");
        printf("%3d, ", array[i]);
    }
    printf("\n");
}
