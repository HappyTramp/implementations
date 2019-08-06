#include <stdlib.h>
#include "unity.h"
#include "sorting.h"

static int* array_int;

void setUp(void)
{
    int tmp[10] = {2, 3, 5, 7, 1, 2, -1, -10, 1000, 20};
    array_int = (int*)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
        array_int[i] = tmp[i];
}

void tearDown(void)
{
    free(array_int);
}

void test_bubble(void)
{
    int a[3] = {1, 3, 2};
    bubble(a, sizeof a / sizeof(int), sizeof(int), &cmp_int);
    TEST_ASSERT_TRUE(sorted(a, sizeof a / sizeof(int), sizeof(int), &cmp_int));
    bubble(array_int, sizeof array_int / sizeof(int), sizeof(int), &cmp_int);
    TEST_ASSERT_TRUE(sorted(a, sizeof a / sizeof(int), sizeof(int), &cmp_int));
}
