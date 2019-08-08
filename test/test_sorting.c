#include <stdlib.h>
#include "unity.h"
#include "stub_array.h"
#include "sorting.h"
#include "helper.h"

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

void test_bubble_sort(void)
{
    /* print_int_array(hc, HC_LEN); */
    bubble_sort(hc, HC_LEN, HC_SIZE, &cmp_int);
    /* print_int_array(hc, HC_LEN); */
    TEST_ASSERT_EQUAL_INT_ARRAY(hc_sorted, hc, HC_LEN);
    TEST_ASSERT_TRUE(sorted(hc, HC_LEN, HC_SIZE, &cmp_int));
    /* print_int_array(rrange, RRANGE_LEN); */
    bubble_sort(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int);
    /* print_int_array(rrange, RRANGE_LEN); */
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int));
    bubble_sort(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev);
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev));
}

void test_insertion_sort(void)
{
    insertion_sort(hc, HC_LEN, HC_SIZE, cmp_int);
    /* print_int_array(hc, HC_LEN); */
    TEST_ASSERT_EQUAL_INT_ARRAY(hc_sorted, hc, HC_LEN);
    TEST_ASSERT_TRUE(sorted(hc, HC_LEN, HC_SIZE, cmp_int));

    insertion_sort(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int);
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int));
    insertion_sort(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev);
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev));
}

void test_shell_sort(void)
{
    shell_sort(hc, HC_LEN, HC_SIZE, cmp_int);
    /* print_int_array(hc, HC_LEN); */
    TEST_ASSERT_EQUAL_INT_ARRAY(hc_sorted, hc, HC_LEN);
    TEST_ASSERT_TRUE(sorted(hc, HC_LEN, HC_SIZE, cmp_int));

    shell_sort(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int);
    /* print_int_array(rrange, RRANGE_LEN); */
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int));
    shell_sort(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev);
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev));
}

void test_selection_sort(void)
{
    selection_sort(hc, HC_LEN, HC_SIZE, cmp_int);
    /* print_int_array(hc, HC_LEN); */
    TEST_ASSERT_EQUAL_INT_ARRAY(hc_sorted, hc, HC_LEN);
    TEST_ASSERT_TRUE(sorted(hc, HC_LEN, HC_SIZE, cmp_int));

    selection_sort(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int);
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int));
    selection_sort(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev);
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev));
}

void test_merge_sort(void)
{
    merge_sort(hc, HC_LEN, HC_SIZE, cmp_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(hc_sorted, hc, HC_LEN);
    TEST_ASSERT_TRUE(sorted(hc, HC_LEN, HC_SIZE, cmp_int));

    merge_sort(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int);
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int));
    merge_sort(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev);
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev));
}

void test_quicksort(void)
{
    quicksort(hc, HC_LEN, HC_SIZE, cmp_int);
    /* print_int_array(hc, HC_LEN); */
    TEST_ASSERT_EQUAL_INT_ARRAY(hc_sorted, hc, HC_LEN);
    TEST_ASSERT_TRUE(sorted(hc, HC_LEN, HC_SIZE, cmp_int));

    quicksort(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int);
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int));
    quicksort(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev);
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev));
    /* print_int_array(rrange, RRANGE_LEN); */
}

void test_cocktail_sort(void)
{
    print_int_array(hc, HC_LEN);
    cocktail_sort(hc, HC_LEN, HC_SIZE, cmp_int);
    print_int_array(hc, HC_LEN);
    TEST_ASSERT_EQUAL_INT_ARRAY(hc_sorted, hc, HC_LEN);
    TEST_ASSERT_TRUE(sorted(hc, HC_LEN, HC_SIZE, cmp_int));

    cocktail_sort(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int);
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int));
    cocktail_sort(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev);
    TEST_ASSERT_TRUE(sorted(rrange, RRANGE_LEN, RRANGE_SIZE, &cmp_int_rev));
    /* print_int_array(rrange, RRANGE_LEN); */
}
