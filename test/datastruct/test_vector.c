#include "unity.h"
#include "unity_fixture.h"
#include "vector.h"

TEST_GROUP(Vector);

static Vector *vector;

TEST_SETUP(Vector)
{
    vector = vector_new();
}

TEST_TEAR_DOWN(Vector)
{
    if (vector != NULL)
        vector = vector_destroy(vector);
}

TEST(Vector, vector_new)
{
    TEST_ASSERT_NOT_NULL(vector);
    TEST_ASSERT_EQUAL(0, vector->capacity);
    TEST_ASSERT_EQUAL(0, vector->size);
    TEST_ASSERT_NULL(vector->under);
}

TEST(Vector, vector_destroy)
{
    vector = vector_destroy(vector);
    TEST_ASSERT_NULL(vector);
}

TEST(Vector, vector_get)
{
    // vector_get(vector, -1) ERROR
    // vector_get(vector, 1) ERROR
    vector = vector_push(vector, 39);
    TEST_ASSERT_EQUAL(39, vector_get(vector, 0));
    vector = vector_push(vector, 9);
    TEST_ASSERT_EQUAL(9, vector_get(vector, 1));
}

TEST(Vector, vector_set)
{
    // vector_get(vector, -1) ERROR
    // vector_get(vector, 1) ERROR
    vector = vector_push(vector, 29);
    vector = vector_push(vector, 2);
    vector = vector_push(vector, 6);

    vector = vector_set(vector, 0, 96);
    TEST_ASSERT_EQUAL(96, vector->under[0]);
    vector = vector_set(vector, 1, 456);
    TEST_ASSERT_EQUAL(456, vector->under[1]);
    vector = vector_set(vector, 2, 457);
    TEST_ASSERT_EQUAL(457, vector->under[2]);
}

TEST(Vector, vector_push)
{
    vector = vector_push(vector, 34);
    TEST_ASSERT_EQUAL(1, vector->capacity);
    TEST_ASSERT_EQUAL(1, vector->size);
    TEST_ASSERT_EQUAL(34, vector->under[0]);
    vector = vector_push(vector, 4);
    TEST_ASSERT_EQUAL(2, vector->capacity);
    TEST_ASSERT_EQUAL(2, vector->size);
    TEST_ASSERT_EQUAL(4, vector->under[1]);
}

TEST(Vector, vector_pop)
{
    // vector_pop(vector) // ERROR
    vector = vector_push(vector, 45);
    vector = vector_push(vector, 5);
    TEST_ASSERT_EQUAL(2, vector->capacity);
    TEST_ASSERT_EQUAL(2, vector->size);
    TEST_ASSERT_EQUAL(45, vector->under[0]);
    TEST_ASSERT_EQUAL(5, vector->under[1]);
    vector = vector_pop(vector);
    TEST_ASSERT_EQUAL(2, vector->capacity);
    TEST_ASSERT_EQUAL(1, vector->size);
    TEST_ASSERT_EQUAL(45, vector->under[0]);
    vector = vector_pop(vector);
    TEST_ASSERT_EQUAL(2, vector->capacity);
    TEST_ASSERT_EQUAL(0, vector->size);
}

TEST(Vector, vector_unshift)
{
    vector = vector_unshift(vector, 56);
    TEST_ASSERT_EQUAL(1, vector->capacity);
    TEST_ASSERT_EQUAL(1, vector->size);
    TEST_ASSERT_EQUAL(56, vector->under[0]);
    vector = vector_unshift(vector, 5);
    TEST_ASSERT_EQUAL(2, vector->capacity);
    TEST_ASSERT_EQUAL(2, vector->size);
    TEST_ASSERT_EQUAL(5, vector->under[0]);
    TEST_ASSERT_EQUAL(56, vector->under[1]);
    vector = vector_unshift(vector, 45);
    TEST_ASSERT_EQUAL(45, vector->under[0]);
    TEST_ASSERT_EQUAL(5, vector->under[1]);
    TEST_ASSERT_EQUAL(56, vector->under[2]);
}

TEST(Vector, vector_shift)
{
    // vector_shift(vector) // ERROR
    vector = vector_push(vector, 34);
    vector = vector_push(vector, 3);
    vector = vector_push(vector, 4);
    TEST_ASSERT_EQUAL(34, vector->under[0]);
    vector = vector_shift(vector);
    TEST_ASSERT_EQUAL(3, vector->under[0]);
    TEST_ASSERT_EQUAL(2, vector->size);
    TEST_ASSERT_EQUAL(3, vector->capacity);
    vector = vector_shift(vector);
    TEST_ASSERT_EQUAL(4, vector->under[0]);
    TEST_ASSERT_EQUAL(1, vector->size);
    TEST_ASSERT_EQUAL(3, vector->capacity);
    vector = vector_shift(vector);
    TEST_ASSERT_EQUAL(0, vector->size);
    TEST_ASSERT_EQUAL(3, vector->capacity);
}
