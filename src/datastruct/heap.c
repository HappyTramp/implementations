#include <stdlib.h>
#include <string.h>
#include "helper.h"
#include "vector.h"
#include "heap.h"

static void sift_up(Heap *heap, size_t i, int (*compar)(const void *, const void *));
static void sift_down(Heap *heap, size_t i, int (*compar)(const void *, const void *));
static void *heap_left(Heap *heap, size_t i);
static void *heap_right(Heap *heap, size_t i);
static void *heap_parent(Heap *heap, size_t i);
static inline size_t heap_left_i(size_t i);
static inline size_t heap_right_i(size_t i);
static inline size_t heap_parent_i(size_t i);
static void dummy_free(void *data) {}

Heap *heap_new(void)
{
    return vector_new();
}

void heap_destroy(Heap **heap, void (*free_fn)(void *))
{
    vector_destroy(heap, free_fn);
}

void *heap_find_max(Heap *heap)
{
    return vector_at(heap, 0);
}

void heap_insert(Heap *heap, void *data, int (*compar)(const void *, const void *))
{
    vector_push(heap, data);
    sift_up(heap, heap->size - 1, compar);
}

void heap_stash_max(Heap *heap, int (*compar)(const void *, const void *))
{
    /* void *max = heap_find_max(heap); */
    /* void *last = vector_last(heap); */
    swap_ptr(heap->under, heap->under + heap->size - 1);
    heap->size--;
    sift_down(heap, 0, compar);
}

void heap_delete_max(Heap *heap,int (*compar)(const void *, const void *),
                     void (*free_fn)(void *))
{
    heap_stash_max(heap, compar);
    heap->size++;
    vector_pop(heap, free_fn);
}

Heap *heap_heapify(void **datas, size_t size,
                   int (*compar)(const void *, const void *))
{
    Heap *heap = heap_new();
    for (size_t i = 0; i < size; i++)
        heap_insert(heap, datas[i], compar);
    return heap;
}

void heap_heapify_array(void **datas, size_t size,
                        int (*compar)(const void *, const void *))
{
    Heap *tmp = heap_heapify(datas, size, compar);
    memcpy(datas, tmp->under, size * sizeof(void*));
    heap_destroy(&tmp, dummy_free);
}

static void sift_up(Heap *heap, size_t i, int (*compar)(const void *, const void *))
{
    void *current = vector_get(heap, i);
    void *parent = heap_parent(heap, i);
    if (i == 0 || compar(current, parent) <= 0)
        return;
    swap_ptr(heap->under + i, heap->under + heap_parent_i(i));
    sift_up(heap, heap_parent_i(i), compar);
}

static void sift_down(Heap *heap, size_t i, int (*compar)(const void *, const void *))
{
    void *node = vector_get(heap, i);
    if (node == NULL)
        return;
    void *left = heap_left(heap, i);
    void *right = heap_right(heap, i);
    if (left == NULL && right == NULL)
        return;
    if (right == NULL)
        swap_ptr(heap->under + heap_left_i(i), heap->under + i);
    else if (left == NULL)
        swap_ptr(heap->under + heap_right_i(i), heap->under + i);
    else
    {
        int cmp = compar(left, right);
        size_t max_index = cmp >= 0 ? heap_left_i(i) : heap_right_i(i);
        if (compar(vector_get(heap, max_index), node) > 0);
            swap_ptr(heap->under + max_index, heap->under + i);
    }
    sift_down(heap, heap_left_i(i), compar);
    sift_down(heap, heap_right_i(i), compar);
}

static void *heap_left(Heap *heap, size_t i)
{
    return vector_at(heap, heap_left_i(i));
}

static void *heap_right(Heap *heap, size_t i)
{
    return vector_at(heap, heap_right_i(i));
}

static void *heap_parent(Heap *heap, size_t i)
{
    return vector_at(heap, heap_parent_i(i));
}

static inline size_t heap_left_i(size_t i)
{
    return i * 2 + 1;
}

static inline size_t heap_right_i(size_t i)
{
    return i * 2 + 2;
}

static inline size_t heap_parent_i(size_t i)
{
    return (i - 1) / 2;
}
