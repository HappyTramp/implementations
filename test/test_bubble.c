#include <stdlib.h>
#include "unity.h"
/* #include "cexception" */
#include "sorting.h"
#include "stub_array.h"

static int hc[HC_LEN];
static int hc_sorted[HC_LEN];
static int *rrange;
static int *empty = NULL;

void setUp(void)
{
    memcpy(hc, HC_LITERAL, HC_LEN * HC_SIZE);
    memcpy(hc_sorted, HC_SORTED, HC_LEN * HC_SIZE);
    rrange = randrange(RRANGE_LEN);
}

void tearDown(void)
{
    free(rrange);
}

void test_bubble_basic(void)
{
    // hard coded array
    bubble(hc, HC_LEN, HC_SIZE, &cmp_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(hc_sorted, hc, HC_LEN);
    TEST_ASSERT_TRUE(sorted(hc, HC_LEN, HC_SIZE, &cmp_int));
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

/* void test_bubble_strcmp(void) */
/* { */
/* } */

/* void test_bubble_strlen(void) */
/* { */
/* } */

/* void test_bubble_chrcmp(void) */
/* { */
/* } */

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
