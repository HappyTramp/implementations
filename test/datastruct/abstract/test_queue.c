#include "unity.h"
#include "unity_fixture.h"
#include "../src/queue.h"


TEST_GROUP(Queue);

static Queue* queue;
static int i3 = 3;
static int i5 = 5;
static int i7 = 7;

TEST_SETUP(Queue)
{
    queue = queue_new();
}

TEST_TEAR_DOWN(Queue)
{
    queue_destroy(queue);
    queue = NULL;
}

TEST(Queue, test_queue_new)
{
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_NULL(queue->front);
    TEST_ASSERT_NULL(queue->front);
}

TEST(Queue, test_queue_enqueue)
{
    queue = queue_enqueue(queue, &i3);
    TEST_ASSERT_EQUAL_PTR(&i3, queue->front->value);
    TEST_ASSERT_EQUAL(i3, *(int *)queue->front->value);
    TEST_ASSERT_EQUAL_PTR(&i3, queue->rear->value);
    TEST_ASSERT_EQUAL_PTR(queue->front, queue->rear);
    queue = queue_enqueue(queue, &i5);
    TEST_ASSERT_EQUAL_PTR(&i3, queue->front->value);
    TEST_ASSERT_EQUAL_PTR(&i5, queue->rear->value);
    TEST_ASSERT_EQUAL(i5, *(int *)queue->rear->value);
    queue = queue_enqueue(queue, &i7);
    TEST_ASSERT_EQUAL_PTR(&i3, queue->front->value);
    TEST_ASSERT_EQUAL_PTR(&i7, queue->rear->value);
    TEST_ASSERT_EQUAL(i7, *(int *)queue->rear->value);
}

TEST(Queue, test_queue_dequeue)
{
    queue = queue_enqueue(queue, &i3);
    queue = queue_enqueue(queue, &i5);
    queue = queue_enqueue(queue, &i7);
    TEST_ASSERT_EQUAL_PTR(&i3, queue->front->value);
    TEST_ASSERT_EQUAL_PTR(&i7, queue->rear->value);
    queue = queue_dequeue(queue);
    TEST_ASSERT_EQUAL_PTR(&i5, queue->front->value);
    TEST_ASSERT_EQUAL(i5, *(int *)queue->front->value);
    TEST_ASSERT_EQUAL_PTR(&i7, queue->rear->value);
    queue = queue_dequeue(queue);
    TEST_ASSERT_EQUAL_PTR(&i7, queue->front->value);
    TEST_ASSERT_EQUAL_PTR(&i7, queue->rear->value);
    TEST_ASSERT_EQUAL(i7, *(int *)queue->front->value);
    queue = queue_dequeue(queue);
    TEST_ASSERT_NULL(queue->front);
    TEST_ASSERT_NULL(queue->rear);
}

TEST(Queue, test_queue_peek)
{
    queue = queue_enqueue(queue, &i3);
    TEST_ASSERT_EQUAL_PTR(&i3, queue_peek(queue));
    queue = queue_enqueue(queue, &i5);
    TEST_ASSERT_EQUAL_PTR(&i3, queue_peek(queue));
    queue = queue_dequeue(queue);
    TEST_ASSERT_EQUAL_PTR(&i5, queue_peek(queue));
}
