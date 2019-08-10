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
