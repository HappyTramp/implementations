#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "stack.h"
#include "list.h"
#include "parse.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_parse_is_balenced(void)
{
    char *parenthesis = "()";
    char *closures = "(){}[]";
    char *happy_path = "(bon)";
    char *more = "(bon(je)sui(pre((a) b)))";
    char *big_balanced = "(x * [4 - 1] + {log_2 (4)})";
    char *bad_clos = "()[]{";
    char *not_balanced = "(bon";
    char *not_more = "(bon[basd[asdf]{asq}}";

    TEST_ASSERT_TRUE(parse_is_balanced(happy_path, parenthesis));
    TEST_ASSERT_TRUE(parse_is_balanced(more, parenthesis));
    TEST_ASSERT_TRUE(parse_is_balanced(big_balanced, closures));
    TEST_ASSERT_FALSE(parse_is_balanced(happy_path, bad_clos));
    TEST_ASSERT_FALSE(parse_is_balanced(not_balanced, closures));
    TEST_ASSERT_FALSE(parse_is_balanced(not_more, closures));
}
