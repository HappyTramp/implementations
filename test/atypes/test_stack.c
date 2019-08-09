#include "unity.h"
#include "unity_helper.h"
#include "list.h"
#include "stack.h"

void free_not(void *data) {}
void debug_elem(void *data) { printf("%d, ", *(int*)data); }
void debug_list(List *list) { list_print(list, debug_elem); printf("\n"); }

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
static Stack *stack;
static Stack *stack_pushed;

void setUp(void)
{
    stack = NULL;
    stack_pushed = NULL;
    stack_push(&stack_pushed, &i0);
    stack_push(&stack_pushed, &i1);
    stack_push(&stack_pushed, &i2);
    stack_push(&stack_pushed, &i3);
    stack_push(&stack_pushed, &i4);
    stack_push(&stack_pushed, &i5);
    stack_push(&stack_pushed, &i6);
    stack_push(&stack_pushed, &i7);
    stack_push(&stack_pushed, &i8);
    stack_push(&stack_pushed, &i9);
}

void tearDown(void)
{
    stack_destroy(&stack, free_not);
    stack_destroy(&stack_pushed, free_not);
}

void test_stack_destroy(void)
{
    stack_destroy(&stack, free_not);
    TEST_ASSERT_NULL(stack);
    stack_destroy(&stack_pushed, free_not);
    TEST_ASSERT_NULL(stack_pushed);
}

void test_stack_push(void)
{
    stack_push(&stack, &i1);
    TEST_ASSERT_NOT_NULL(stack);
    TEST_ASSERT_NULL(stack->next);
    TEST_ASSERT_EQUAL(i1, *(int*)stack->data);

    Stack *cursor = stack_pushed;
    for (int i = 9; i >= 0 && cursor; i--, cursor = cursor->next)
        TEST_ASSERT_EQUAL(i, *(int*)cursor->data);
}

void test_stack_pop(void)
{
    stack_push(&stack, &i1);
    TEST_ASSERT_EQUAL(i1, *(int*)stack->data);
    TEST_ASSERT_NULL(stack->next);
    stack_pop(&stack, free_not);
    TEST_ASSERT_NULL(stack);

    for (int i = 9; i > 0; i--) {
        TEST_ASSERT_EQUAL(i, *(int*)stack_pushed->data);
        stack_pop(&stack_pushed, free_not);
    }
    TEST_ASSERT_NULL(stack_pushed->next);
}

void test_stack_peek(void)
{
    stack_push(&stack, &i1);
    TEST_ASSERT_EQUAL(i1, *(int*)stack_peek(stack));

    for (int i = 9 ; i >= 0; i--) {
        TEST_ASSERT_EQUAL(i, *(int*)stack_peek(stack_pushed));
        stack_pop(&stack_pushed, free_not);
    }
}

void test_stack_duplicate(void)
{
    stack_push(&stack, &i2);
    stack_duplicate(&stack);
    TEST_ASSERT_EQUAL(i2, *(int*)stack->data);
    TEST_ASSERT_EQUAL(i2, *(int*)stack->next->data);

    stack_duplicate(&stack_pushed);
    TEST_ASSERT_EQUAL(i9, *(int*)stack_pushed->data);
    TEST_ASSERT_EQUAL(i9, *(int*)stack_pushed->next->data);
}

void test_stack_swap(void)
{
    stack_push(&stack, &i1);
    stack_push(&stack, &i2);
    stack_swap(&stack);
    TEST_ASSERT_EQUAL(i1, *(int*)stack->data);
    TEST_ASSERT_EQUAL(i2, *(int*)stack->next->data);

    stack_swap(&stack_pushed);
    TEST_ASSERT_EQUAL(i8, *(int*)stack_pushed->data);
    TEST_ASSERT_EQUAL(i9, *(int*)stack_pushed->next->data);
}

void test_stack_rotate_right(void)
{
    TEST_MISSING();
}

void test_stack_rotate_left(void)
{
    TEST_MISSING();
}

void test_stack_size(void)
{
    TEST_ASSERT_EQUAL(0, stack_size(stack));
    TEST_ASSERT_EQUAL(10, stack_size(stack_pushed));
    stack_push(&stack, &i1);
    TEST_ASSERT_EQUAL(1, stack_size(stack));
}
