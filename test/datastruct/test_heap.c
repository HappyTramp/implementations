#include "unity.h"
#include "unity_helper.h"
#include "helper.h"
#include "vector.h"
#include "heap.h"

void free_not(void *data) {}
static int i0 = 0;
static int i1 = 1;
static int i2 = 2;
static int i3 = 3;
static int i4 = 4;
static int i5 = 5;
static int i6 = 6;
static int i7 = 7;
static int i8 = 8;
static int i9 = 9;
static Heap *heap;

void setUp(void)
{
    heap = heap_new();
}

void tear_down(void)
{
    heap_destroy(&heap, free_not);
}

void test_heap_new(void)
{
    TEST_ASSERT_NOT_NULL(heap);
    TEST_ASSERT_EQUAL(0, heap->capacity);
    TEST_ASSERT_EQUAL(0, heap->size);
    TEST_ASSERT_NULL(heap->under);
}

void test_heap_destroy(void)
{
    heap_destroy(&heap, free_not);
    TEST_ASSERT_NULL(heap);
}

void test_find_max(void)
{
    TEST_ASSERT_NULL(heap_find_max(heap));
    vector_push(heap, &i1);
    TEST_ASSERT_INT_DATA(i1, heap_find_max(heap));
}

void test_heap_insert(void)
{
    heap_insert(heap, &i1, cmp_int);
    TEST_ASSERT_INT_DATA(i1, heap->under[0]);
    heap_insert(heap, &i2, cmp_int);
    TEST_ASSERT_INT_DATA(i2, heap->under[0]);
    TEST_ASSERT_INT_DATA(i1, heap->under[1]);
    heap_insert(heap, &i3, cmp_int);
    TEST_ASSERT_INT_DATA(i3, heap->under[0]);
    TEST_ASSERT(*(int*)heap->under[1] < i3);
    TEST_ASSERT(*(int*)heap->under[2] < i3);
    heap_insert(heap, &i0, cmp_int);
    TEST_ASSERT_INT_DATA(i3, heap->under[0]);
    TEST_ASSERT(*(int*)heap->under[1] < i3);
    TEST_ASSERT(*(int*)heap->under[2] < i3);
    TEST_ASSERT(*(int*)heap->under[3] < i3);
    TEST_ASSERT(*(int*)heap->under[3] < *(int*)heap->under[1]);
}

void test_heap_stash_max(void)
{
    heap_insert(heap, &i4, cmp_int);
    heap_insert(heap, &i3, cmp_int);
    heap_insert(heap, &i2, cmp_int);
    heap_insert(heap, &i1, cmp_int);
    heap_insert(heap, &i0, cmp_int);
    heap_stash_max(heap, cmp_int);
    TEST_ASSERT_INT_DATA(i3, heap_find_max(heap));
    TEST_ASSERT_EQUAL(4, heap->size);
    TEST_ASSERT_INT_DATA(i4, heap->under[heap->size]);
    heap_stash_max(heap, cmp_int);
    TEST_ASSERT_INT_DATA(i2, heap_find_max(heap));
    TEST_ASSERT_EQUAL(3, heap->size);
    TEST_ASSERT_INT_DATA(i3, heap->under[heap->size]);
    TEST_ASSERT_INT_DATA(i4, heap->under[heap->size + 1]);
}

void test_heap_delete_max(void)
{
    heap_insert(heap, &i4, cmp_int);
    heap_insert(heap, &i3, cmp_int);
    heap_insert(heap, &i2, cmp_int);
    heap_insert(heap, &i1, cmp_int);
    heap_insert(heap, &i0, cmp_int);
    heap_delete_max(heap, cmp_int, free_not);
    TEST_ASSERT_INT_DATA(i3, heap_find_max(heap));
    TEST_ASSERT_EQUAL(4, heap->size);
    heap_delete_max(heap, cmp_int, free_not);
    TEST_ASSERT_INT_DATA(i2, heap_find_max(heap));
    TEST_ASSERT_EQUAL(3, heap->size);
}
void test_heap_heapify(void)
{
    Vector *vector = vector_new();
    vector_push(vector, &i1);
    vector_push(vector, &i8);
    vector_push(vector, &i3);
    vector_push(vector, &i2);
    vector_push(vector, &i5);
    Heap *heapified = heap_heapify(vector->under, vector->size, cmp_int);
    TEST_ASSERT_EQUAL(vector->size, heapified->size);
    TEST_ASSERT_INT_DATA(i8, heap_find_max(heapified));
    TEST_ASSERT(*(int*)heapified->under[1] < i8);
    TEST_ASSERT(*(int*)heapified->under[2] < i8);
    TEST_ASSERT(*(int*)heapified->under[3] < *(int*)heapified->under[1]);
    TEST_ASSERT(*(int*)heapified->under[4] < *(int*)heapified->under[1]);
}

void test_heap_heapify_array(void)
{
    int *datas[5] = {&i1, &i8, &i3, &i2, &i5};
    heap_heapify_array((void**)datas, 5, cmp_int);
    TEST_ASSERT_INT_DATA(i8, datas[0]);
    TEST_ASSERT(*(int*)datas[1] < i8);
    TEST_ASSERT(*(int*)datas[2] < i8);
    TEST_ASSERT(*(int*)datas[3] < *(int*)datas[1]);
    TEST_ASSERT(*(int*)datas[4] < *(int*)datas[1]);
}
