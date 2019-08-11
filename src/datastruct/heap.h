#ifndef __HEAP_H__
# define __HEAP_H__

# include <string.h>
# include "vector.h"

/* max heap */
typedef Vector Heap;

Heap *heap_new(size_t data_size);
void heap_destroy(Heap **heap, void (*free_fn)(void *));
void *heap_find_max(Heap *heap);
void heap_insert(Heap *heap, void *data, int (*compar)(const void *, const void *));
void heap_stash_max(Heap *heap, int (*compar)(const void *, const void *));
void heap_delete_max(Heap *heap,int (*compar)(const void *, const void *),
                     void (*free_fn)(void *));
Heap *heap_heapify(void *datas, size_t nmemb, size_t size,
                   int (*compar)(const void *, const void *));
void heap_heapify_array(void *datas, size_t nmemb, size_t size,
                        int (*compar)(const void *, const void *));
/* void *heap_extract_max(Heap *heap); */
/* void *heap_replace(Heap *heap, void *data, int (*compar)(const void *, const void *)); */

#endif
