#include <string.h>
#include "sorting.h"

#include <stdio.h>
void bubble(void *base, size_t nmemb, size_t size,
		    int (*compar)(const void *, const void *))
{
    while (!sorted(base, nmemb, size, compar))
        for (int i = 0; i < nmemb - 1; i++)
            if (compar(base + i * size, base + i * size + size) > 0)
                swap(base + i * size, base + i * size + size, size);
}
