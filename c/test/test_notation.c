#include "unity.h"
#include "list.h"
#include "stack.h"
#include "notation.h"

static char add[] = "+ 3 4";
static int add_res = 7;
static char sub[] = "- 3 4";
static int sub_res = -1;
static char mul[] = "* 3 4";
static int mul_res = 12;
static char dvi[] = "/ 6 3";
static int dvi_res = 2;
static char addsub[] = "+ - 7 6 3";
static int addsub_res = 4;
static char divmul[] = "/ * 2 6 3";
static int divmul_res = 4;


void setUp(void) {}

void tearDown(void) {}

void test_notation_prefix(void)
{
    TEST_ASSERT_EQUAL(add_res, notation_prefix(add));
    TEST_ASSERT_EQUAL(sub_res, notation_prefix(sub));
    TEST_ASSERT_EQUAL(mul_res, notation_prefix(mul));
    TEST_ASSERT_EQUAL(dvi_res, notation_prefix(dvi));
    TEST_ASSERT_EQUAL(addsub_res, notation_prefix(addsub));
    /* TEST_ASSERT_EQUAL(divmul_res, notation_prefix(divmul)); */
}
