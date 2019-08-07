#include <stdlib.h>
#include "unity.h"
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

void test_insertion(void)
{
    insertion(hc, HC_LEN, HC_SIZE, cmp_int);
    /* print_int_array(hc, HC_LEN); */
    TEST_ASSERT_EQUAL_INT_ARRAY(hc_sorted, hc, HC_LEN);
    TEST_ASSERT_TRUE(sorted(hc, HC_LEN, HC_SIZE, cmp_int));

    bubble(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int);
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int));
}

void test_insertion_rev(void)
{
    insertion(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev);
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev));
}
