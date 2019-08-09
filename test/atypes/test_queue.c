#include "unity.h"
#include "list.h"
#include "queue.h"

void free_not(void *data) {}
/* void debug_elem(void *data) { printf("%d, ", *(int*)data); } */
/* void debug_list(List *list) { list_print(list, debug_elem); printf("\n"); } */
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
static Queue* queue;

void setUp(void)
{
    queue = queue_new();
}

void tearDown(void)
{
    if (queue != NULL)
        queue_destroy(&queue, free_not);
}

void test_queue_new(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_NULL(queue->front);
    TEST_ASSERT_NULL(queue->front);
}

void test_queue_destroy(void)
{
    queue_destroy(&queue, free_not);
    /* TEST_ASSERT_NULL(queue); */
}

void test_queue_enqueue(void)
{
    queue_enqueue(queue, &i3);
    TEST_ASSERT_EQUAL_PTR(&i3, queue->front->data);
    TEST_ASSERT_EQUAL(i3, *(int*)queue->front->data);
    TEST_ASSERT_EQUAL_PTR(&i3, queue->back->data);
    TEST_ASSERT_EQUAL_PTR(queue->front, queue->back);
    queue_enqueue(queue, &i5);
    TEST_ASSERT_EQUAL_PTR(&i3, queue->front->data);
    TEST_ASSERT_EQUAL_PTR(&i5, queue->back->data);
    TEST_ASSERT_EQUAL(i5, *(int *)queue->back->data);
    queue_enqueue(queue, &i7);
    TEST_ASSERT_EQUAL_PTR(&i3, queue->front->data);
    TEST_ASSERT_EQUAL_PTR(&i7, queue->back->data);
    TEST_ASSERT_EQUAL(i7, *(int *)queue->back->data);
}

void test_queue_dequeue(void)
{
    queue_enqueue(queue, &i3);
    queue_enqueue(queue, &i5);
    queue_enqueue(queue, &i7);
    TEST_ASSERT_EQUAL_PTR(&i3, queue->front->data);
    TEST_ASSERT_EQUAL_PTR(&i7, queue->back->data);
    queue_dequeue(queue, free_not);
    TEST_ASSERT_EQUAL_PTR(&i5, queue->front->data);
    TEST_ASSERT_EQUAL(i5, *(int*)queue->front->data);
    TEST_ASSERT_EQUAL_PTR(&i7, queue->back->data);
    queue_dequeue(queue, free_not);
    TEST_ASSERT_EQUAL_PTR(&i7, queue->front->data);
    TEST_ASSERT_EQUAL_PTR(&i7, queue->back->data);
    TEST_ASSERT_EQUAL(i7, *(int*)queue->front->data);
    queue_dequeue(queue, free_not);
    TEST_ASSERT_NULL(queue->front);
    TEST_ASSERT_NULL(queue->back);
}

void test_queue_peek(void)
{
    queue_enqueue(queue, &i3);
    TEST_ASSERT_EQUAL_PTR(&i3, queue_peek(queue));
    queue_enqueue(queue, &i5);
    TEST_ASSERT_EQUAL_PTR(&i3, queue_peek(queue));
    queue_dequeue(queue, free_not);
    TEST_ASSERT_EQUAL_PTR(&i5, queue_peek(queue));
}

void test_queue_size(void)
{
    TEST_ASSERT_EQUAL(0, queue_size(queue));
    queue_enqueue(queue, &i3);
    TEST_ASSERT_EQUAL(1, queue_size(queue));
    queue_enqueue(queue, &i3);
    TEST_ASSERT_EQUAL(2, queue_size(queue));
    queue_enqueue(queue, &i3);
    TEST_ASSERT_EQUAL(3, queue_size(queue));
    queue_dequeue(queue, free_not);
    TEST_ASSERT_EQUAL(2, queue_size(queue));
}
