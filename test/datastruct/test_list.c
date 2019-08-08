#include "unity.h"
#include "unity_fixture.h"
#include "../src/linkedlist.h"

TEST_GROUP(LinkedList);

static LList *llist;

TEST_SETUP(LinkedList)
{
    llist = llist_new();
}

TEST_TEAR_DOWN(LinkedList)
{
    llist_destroy(llist);
}

TEST(LinkedList, test_llist_new)
{
    TEST_ASSERT_NULL(llist);
}

TEST(LinkedList, test_llist_insert)
{
    llist = llist_insert(llist, 0, 4);
    TEST_ASSERT_NOT_NULL(llist);
    TEST_ASSERT_EQUAL(4, llist->value);
    TEST_ASSERT_NULL(llist->next);
    llist = llist_insert(llist, 1, 3);
    TEST_ASSERT_EQUAL(3, llist->next->value);
    TEST_ASSERT_NULL(llist->next->next);
    llist = llist_insert(llist, 2, 5);
    TEST_ASSERT_EQUAL(5, llist->next->next->value);
    llist = llist_insert(llist, 0, 46);
    TEST_ASSERT_EQUAL(46, llist->value);
    TEST_ASSERT_EQUAL(4, llist->next->value);
}

TEST(LinkedList, test_llist_remove)
{
    llist = llist_insert(llist, 0, 1);
    llist = llist_insert(llist, 0, 2);
    llist = llist_insert(llist, 0, 3);
    llist = llist_remove(llist, 0);
    TEST_ASSERT_EQUAL(2, llist->value);
    llist = llist_remove(llist, 1);
    TEST_ASSERT_EQUAL(2, llist->value);
    TEST_ASSERT_NULL(llist->next);
}

TEST(LinkedList, test_llist_reverse)
{
    // empty
    llist = llist_reverse(llist);
    TEST_ASSERT_NULL(llist);
    // one element
    llist = llist_insert(llist, 0, 1);
    llist = llist_reverse(llist);
    TEST_ASSERT_EQUAL(1, llist->value);
    TEST_ASSERT_NULL(llist->next);
    // multiple element
    llist = llist_insert(llist, 0, 2);
    llist = llist_insert(llist, 0, 3);
    llist = llist_reverse(llist);
    TEST_ASSERT_EQUAL(1, llist->value);
    TEST_ASSERT_EQUAL(2, llist->next->value);
    TEST_ASSERT_EQUAL(3, llist->next->next->value);
    TEST_ASSERT_NULL(llist->next->next->next);
}

TEST(LinkedList, test_llist_reverse_rec)
{
    // empty
    llist = llist_reverse_rec(llist);
    TEST_ASSERT_NULL(llist);
    // one element
    llist = llist_insert(llist, 0, 1);
    /* llist = llist_reverse_rec(llist); */
    TEST_ASSERT_EQUAL(1, llist->value);
    TEST_ASSERT_NULL(llist->next);
    // multiple element
    llist = llist_insert(llist, 0, 2);
    llist = llist_insert(llist, 0, 3);
    llist = llist_reverse_rec(llist);
    TEST_ASSERT_EQUAL(1, llist->value);
    TEST_ASSERT_EQUAL(2, llist->next->value);
    TEST_ASSERT_EQUAL(3, llist->next->next->value);
    TEST_ASSERT_NULL(llist->next->next->next);
}

TEST(LinkedList, test_llist_at)
{
    llist = llist_insert(llist, 0, 1);
    llist = llist_insert(llist, 0, 2);
    llist = llist_insert(llist, 0, 3);
    TEST_ASSERT_EQUAL(3, llist_at(llist, 0)->value);
    TEST_ASSERT_EQUAL(2, llist_at(llist, 1)->value);
    TEST_ASSERT_EQUAL(1, llist_at(llist, 2)->value);
    TEST_ASSERT_NULL(llist_at(llist, 2)->next);
}

TEST(LinkedList, test_llist_length)
{
    TEST_ASSERT_EQUAL(0, llist_length(llist));
    llist = llist_insert(llist, 0, 1);
    TEST_ASSERT_EQUAL(1, llist_length(llist));
    llist = llist_insert(llist, 0, 2);
    TEST_ASSERT_EQUAL(2, llist_length(llist));
    llist = llist_insert(llist, 0, 3);
    TEST_ASSERT_EQUAL(3, llist_length(llist));
    llist = llist_remove(llist, 0);
    TEST_ASSERT_EQUAL(2, llist_length(llist));
    llist = llist_remove(llist, 0);
    TEST_ASSERT_EQUAL(1, llist_length(llist));
    llist = llist_remove(llist, 0);
    TEST_ASSERT_EQUAL(0, llist_length(llist));
}
