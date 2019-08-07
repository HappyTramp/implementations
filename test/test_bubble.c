#include <stdlib.h>
#include "unity.h"
/* #include "cexception" */
#include "sorting.h"
/* #include "generate.c" */

#define HC_LEN 10
#define HC_SIZE sizeof(int)
#define RRANGE_LEN 100
#define RRANGE_SIZE sizeof(int)

static int hc[HC_LEN];
static int hc_sorted[HC_LEN];
static int *rrange;
static int *empty = NULL;

void setUp(void)
{
    int tmp[HC_LEN] = {2, 3, 5, 7, 1, 2, -1, -10, 1000, 20};
    memcpy(hc, tmp, HC_LEN * HC_LEN);
    int tmp_sorted[HC_LEN] = {-10, -1, 1, 2, 2, 3, 5, 7, 20, 1000};
    memcpy(hc_sorted, tmp_sorted, HC_LEN * HC_LEN);
    rrange = randrange(RRANGE_LEN);
}

void tearDown(void)
{
    free(rrange);
}

void test_bubble_basic(void)
{
    // happy little array
    int happy[3] = {1, 3, 2};
    int sorted_happy[3] = {1, 2, 3};
    bubble(happy, 3, sizeof(int), &cmp_int);
    TEST_ASSERT_TRUE(sorted(happy, 3, sizeof(int), &cmp_int));
    TEST_ASSERT_EQUAL_INT_ARRAY(sorted_happy, happy, 3);
    // longer hard coded array
    bubble(hc, HC_LEN, HC_SIZE, &cmp_int);
    TEST_ASSERT_TRUE(sorted(hc, HC_LEN, HC_SIZE, &cmp_int));
    TEST_ASSERT_EQUAL_INT_ARRAY(hc_sorted, hc, HC_LEN);
    // random array
    /* print_int_array(rrange, RRANGE_LEN); */
    bubble(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int);
    /* print_int_array(rrange, RRANGE_LEN); */
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int));
}

void test_bubble_rev(void)
{
    /* print_int_array(rrange, RRANGE_LEN); */
    bubble(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev);
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev));
    /* print_int_array(rrange, RRANGE_LEN); */
}

void test_bubble_strcmp(void)
{
    TEST_IGNORE();
}

void test_bubble_strlen(void)
{
    TEST_IGNORE();
}

void test_bubble_chrcmp(void)
{
    TEST_IGNORE();
}

/* void test_bubble_empty(void) */
/* { */
/*     CEXCEPTION_T e; */

/*     Try { */
/*         bubble(empty, 0, 0, &cmp_int); */
/*         TEST_FAIL_MESSAGE("empty array should throw"); */
/*     } */
/*     Catch (e) { */
/*     } */
/* } */
