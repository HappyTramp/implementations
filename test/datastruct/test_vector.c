#include "unity.h"
#include "unity_helper.h"
#include "vector.h"

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
static Vector *vector;

void setUp(void)
{
    vector = vector_new();
}

void tearDown(void)
{
    if (vector != NULL)
        vector_destroy(&vector, free_not);
}

void test_vector_new(void)
{
    TEST_ASSERT_NOT_NULL(vector);
    TEST_ASSERT_EQUAL(0, vector->capacity);
    TEST_ASSERT_EQUAL(0, vector->size);
    TEST_ASSERT_NULL(vector->under);
}

void test_vector_destroy(void)
{
    vector_destroy(&vector, free_not);
    TEST_ASSERT_NULL(vector);
}

void test_vector_get(void)
{
    vector_push(vector, &i3);
    TEST_ASSERT_INT_DATA(i3, vector_get(vector, 0));
    vector_push(vector, &i9);
    TEST_ASSERT_INT_DATA(i9, vector_get(vector, 1));
}

void test_vector_set(void)
{
    vector_push(vector, &i9);
    vector_push(vector, &i8);
    vector_push(vector, &i7);

    vector_set(vector, 0, &i1);
    TEST_ASSERT_INT_DATA(i1, vector->under[0]);
    vector_set(vector, 1, &i2);
    TEST_ASSERT_INT_DATA(i2, vector->under[1]);
    vector_set(vector, 2, &i3);
    TEST_ASSERT_INT_DATA(i3, vector->under[2]);
}

void test_vector_push(void)
{
    vector_push(vector, &i6);
    TEST_ASSERT_EQUAL(1, vector->capacity);
    TEST_ASSERT_EQUAL(1, vector->size);
    TEST_ASSERT_INT_DATA(i6, vector->under[0]);
    vector_push(vector, &i4);
    TEST_ASSERT_EQUAL(2, vector->capacity);
    TEST_ASSERT_EQUAL(2, vector->size);
    TEST_ASSERT_EQUAL(&i4, vector->under[1]);
}

void test_vector_pop(void)
{
    vector_push(vector, &i4);
    vector_push(vector, &i5);
    TEST_ASSERT_EQUAL(2, vector->capacity);
    TEST_ASSERT_EQUAL(2, vector->size);
    TEST_ASSERT_INT_DATA(i4, vector->under[0]);
    TEST_ASSERT_INT_DATA(i5, vector->under[1]);
    vector_pop(vector, free_not);
    TEST_ASSERT_EQUAL(2, vector->capacity);
    TEST_ASSERT_EQUAL(1, vector->size);
    TEST_ASSERT_INT_DATA(i4, vector->under[0]);
    vector_pop(vector, free_not);
    TEST_ASSERT_EQUAL(2, vector->capacity);
    TEST_ASSERT_EQUAL(0, vector->size);
}

void test_vector_unshift(void)
{
    vector_unshift(vector, &i5);
    TEST_ASSERT_EQUAL(1, vector->capacity);
    TEST_ASSERT_EQUAL(1, vector->size);
    TEST_ASSERT_INT_DATA(i5, vector->under[0]);
    vector_unshift(vector, &i1);
    TEST_ASSERT_EQUAL(2, vector->capacity);
    TEST_ASSERT_EQUAL(2, vector->size);
    TEST_ASSERT_INT_DATA(i1, vector->under[0]);
    TEST_ASSERT_INT_DATA(i5, vector->under[1]);
    vector_unshift(vector, &i2);
    TEST_ASSERT_INT_DATA(i2, vector->under[0]);
    TEST_ASSERT_INT_DATA(i1, vector->under[1]);
    TEST_ASSERT_INT_DATA(i5, vector->under[2]);
}

void test_vector_shift(void)
{
    vector_push(vector, &i1);
    vector_push(vector, &i2);
    vector_push(vector, &i3);
    vector_shift(vector, free_not);
    TEST_ASSERT_EQUAL(2, vector->size);
    TEST_ASSERT_EQUAL(3, vector->capacity);
    TEST_ASSERT_INT_DATA(i2, vector->under[0]);
    vector_shift(vector, free_not);
    TEST_ASSERT_EQUAL(1, vector->size);
    TEST_ASSERT_EQUAL(3, vector->capacity);
    TEST_ASSERT_INT_DATA(i3, vector->under[0]);
    vector_shift(vector, free_not);
    TEST_ASSERT_EQUAL(0, vector->size);
    TEST_ASSERT_EQUAL(3, vector->capacity);
}
