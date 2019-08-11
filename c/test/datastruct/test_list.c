#include "unity.h"
#include "list.h"

#include "stub_data.h"

void free_not(void *data) {}
bool is_even(void *data) { return *(int*)data % 2 == 0; }
bool is_odd(void *data) { return *(int*)data % 2 == 1; }
void debug_elem(void *data) { printf("%d, ", *(int*)data); }
void debug_list(List *list) { list_print(list, debug_elem); printf("\n"); }

/* GENERATE_STATIC_INT(); */
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
static List *list;
static List *range_list;
static List *rand_list;

void setUp(void)
{
    list = NULL;
    range_list = list_create_elem(&i9);
    list_push_front(&range_list, &i8);
    list_push_front(&range_list, &i7);
    list_push_front(&range_list, &i6);
    list_push_front(&range_list, &i5);
    list_push_front(&range_list, &i4);
    list_push_front(&range_list, &i3);
    list_push_front(&range_list, &i2);
    list_push_front(&range_list, &i1);
    list_push_front(&range_list, &i0);
    rand_list = list_create_elem(&i2);
    list_push_front(&rand_list, &i0);
    list_push_front(&rand_list, &i8);
    list_push_front(&rand_list, &i2);
    list_push_front(&rand_list, &i9);
}

void tearDown(void)
{
    list_destroy(&list, free_not);
    list_destroy(&range_list, free_not);
    list_destroy(&rand_list, free_not);
}

void test_list_create_elem(void)
{
    list = list_create_elem(&i0);
    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_NULL(list->next);
    TEST_ASSERT_EQUAL_PTR(&i0, list->data);
    TEST_ASSERT_EQUAL_INT(i0, *(int*)list->data);
}

void test_list_destroy(void)
{
    list_destroy(&list, free_not);
    TEST_ASSERT_NULL(list);
}

void test_list_push_front(void)
{
    list_push_front(&list, &i1);
    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_NULL(list->next);
    TEST_ASSERT_EQUAL_PTR(&i1, list->data);
    list_push_front(&list, &i8);
    list_push_front(&list, &i7);
    TEST_ASSERT_NULL(list->next->next->next);
    TEST_ASSERT_EQUAL_PTR(&i1, list->next->next->data);
    TEST_ASSERT_EQUAL_PTR(&i8, list->next->data);
    TEST_ASSERT_EQUAL_PTR(&i7, list->data);
}

void test_list_push_back(void)
{
    list_push_back(&list, &i1);
    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_EQUAL_PTR(&i1, list->data);
    TEST_ASSERT_NULL(list->next);
    list_push_back(&list, &i8);
    list_push_back(&list, &i7);
    TEST_ASSERT_NULL(list->next->next->next);
    TEST_ASSERT_EQUAL_PTR(&i7, list->next->next->data);
    TEST_ASSERT_EQUAL_PTR(&i8, list->next->data);
    TEST_ASSERT_EQUAL_PTR(&i1, list->data);
}

void test_list_remove_if(void)
{
    list_remove_if(&range_list, is_even, free_not);
    TEST_ASSERT_EQUAL(i1, *(int*)range_list->data);
    TEST_ASSERT_EQUAL(i3, *(int*)range_list->next->data);
    TEST_ASSERT_EQUAL(i5, *(int*)range_list->next->next->data);
    TEST_ASSERT_EQUAL(i7, *(int*)range_list->next->next->next->data);
    TEST_ASSERT_EQUAL(i9, *(int*)range_list->next->next->next->next->data);
    TEST_ASSERT_NULL(range_list->next->next->next->next->next);
    list_remove_if(&range_list, is_odd, free_not);
    TEST_ASSERT_NULL(range_list);
}

void test_list_remove_at(void)
{
}

void test_list_reverse(void)
{
    // empty
    list_reverse(&list);
    TEST_ASSERT_NULL(list);
    // one element
    list = list_create_elem(&i1);
    list_reverse(&list);
    TEST_ASSERT_EQUAL(i1, *(int*)list->data);
    TEST_ASSERT_NULL(list->next);
    // multiple element
    list_push_front(&list, &i2);
    list_push_front(&list, &i3);
    list_reverse(&list);
    TEST_ASSERT_EQUAL(i1, *(int*)list->data);
    TEST_ASSERT_EQUAL(i2, *(int*)list->next->data);
    TEST_ASSERT_EQUAL(i3, *(int*)list->next->next->data);
    TEST_ASSERT_NULL(list->next->next->next);
}

void test_list_reverse_rec(void)
{
    // empty
    list = list_reverse_rec(list);
    TEST_ASSERT_NULL(list);
    // one element
    list_push_front(&list, &i1);
    list = list_reverse_rec(list);
    TEST_ASSERT_EQUAL(i1, *(int*)list->data);
    TEST_ASSERT_NULL(list->next);
    // multiple element
    list_push_front(&list, &i2);
    list_push_front(&list, &i3);
    list = list_reverse_rec(list);
    TEST_ASSERT_EQUAL(i1, *(int*)list->data);
    TEST_ASSERT_EQUAL(i2, *(int*)list->next->data);
    TEST_ASSERT_EQUAL(i3, *(int*)list->next->next->data);
    TEST_ASSERT_NULL(list->next->next->next);
}

void test_list_at(void)
{
    TEST_ASSERT_EQUAL(i1, *(int*)list_at(range_list, 1)->data);
    TEST_ASSERT_EQUAL(i2, *(int*)list_at(range_list, 2)->data);
    TEST_ASSERT_EQUAL(i3, *(int*)list_at(range_list, 3)->data);
    TEST_ASSERT_NULL(list_at(range_list, 9)->next);
}

void test_list_size(void)
{
    TEST_ASSERT_EQUAL(0, list_size(list));
    list_push_front(&list, &i1);
    TEST_ASSERT_EQUAL(1, list_size(list));
    list_push_front(&list, &i1);
    TEST_ASSERT_EQUAL(2, list_size(list));
    TEST_ASSERT_EQUAL(10, list_size(range_list));
    TEST_ASSERT_EQUAL(5, list_size(rand_list));
}
