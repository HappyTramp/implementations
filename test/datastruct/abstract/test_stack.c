/* #include "unity.h" */
/* #include "../src/stack.h" */

/* #define TEST_STACK_PUSHES 10 */
/* #define LEN(array) (sizeof array / sizeof(*array)) */

/* TEST_GROUP(Stack); */

/* static Stack *stack; */
/* static Stack *stack_pushed; */
/* /1* static void assert_stack(Stack *stack, int values[], int values_len); *1/ */

/* TEST_SETUP(Stack) */
/* { */
/*     stack = stack_new(); */
/*     stack_pushed = stack_new(); */
/*     for (int i = 0; i < TEST_STACK_PUSHES; i++) */
/*         stack_pushed = stack_push(stack_pushed, i); */
/* } */

/* TEST_TEAR_DOWN(Stack) */
/* { */
/*     stack = stack_destroy(stack); */
/*     stack_pushed = stack_destroy(stack_pushed); */
/* } */

/* TEST(Stack, test_stack_new) */
/* { */
/*     TEST_ASSERT_NULL(stack); */
/* } */

/* TEST(Stack, test_stack_destroy) */
/* { */
/*     stack = stack_destroy(stack); */
/*     TEST_ASSERT_NULL(stack); */
/*     stack_pushed = stack_destroy(stack_pushed); */
/*     TEST_ASSERT_NULL(stack_pushed); */
/* } */

/* TEST(Stack, test_stack_push) */
/* { */
/*     stack = stack_push(stack, 1); */
/*     TEST_ASSERT_NOT_NULL(stack); */
/*     TEST_ASSERT_EQUAL(1, stack->value); */
/*     TEST_ASSERT_NULL(stack->next); */

/*     Stack *cursor = stack_pushed; */
/*     for (int i = TEST_STACK_PUSHES - 1; i >= 0; i--) { */
/*         TEST_ASSERT_EQUAL(i, cursor->value); */
/*         cursor = cursor->next; */
/*     } */
/* } */

/* TEST(Stack, test_stack_pop) */
/* { */
/*     /1* stack = stack_pop(stack); ERROR *1/ */
/*     stack = stack_push(stack, 45); */
/*     TEST_ASSERT_EQUAL(45, stack->value); */
/*     TEST_ASSERT_NULL(stack->next); */
/*     stack = stack_pop(stack); */
/*     TEST_ASSERT_NULL(stack); */

/*     for (int i = TEST_STACK_PUSHES - 1; i > 1; i--) { */
/*         stack_pushed = stack_pop(stack_pushed); */
/*         TEST_ASSERT_EQUAL(i - 1, stack_pushed->value); */
/*         TEST_ASSERT_EQUAL(i - 2, stack_pushed->next->value); */
/*     } */
/*     TEST_ASSERT_NULL(stack_pushed->next->next); */
/* } */

/* TEST(Stack, test_stack_peek) */
/* { */
/*     /1* TEST_ASSERT_EQUAL(-1, stack_peek(stack)); ERROR *1/ */
/*     stack = stack_push(stack, 456); */
/*     TEST_ASSERT_EQUAL(456, stack_peek(stack)); */

/*     for (int i = TEST_STACK_PUSHES - 1; i >= 0; i--) { */
/*         TEST_ASSERT_EQUAL(i, stack_peek(stack_pushed)); */
/*         stack_pushed = stack_pop(stack_pushed); */
/*     } */
/* } */

/* TEST(Stack, test_stack_duplicate) */
/* { */
/*     stack = stack_push(stack, 36); */
/*     stack = stack_duplicate(stack); */
/*     TEST_ASSERT_EQUAL(36, stack->value); */
/*     TEST_ASSERT_EQUAL(36, stack->next->value); */

/*     stack_pushed = stack_duplicate(stack_pushed); */
/*     TEST_ASSERT_EQUAL(9, stack_pushed->value); */
/*     TEST_ASSERT_EQUAL(9, stack_pushed->next->value); */
/* } */

/* TEST(Stack, test_stack_swap) */
/* { */
/*     stack = stack_push(stack, 54); */
/*     stack = stack_push(stack, 45); */
/*     stack = stack_swap(stack); */
/*     TEST_ASSERT_EQUAL(54, stack->value); */
/*     TEST_ASSERT_EQUAL(45, stack->next->value); */

/*     stack_pushed = stack_swap(stack_pushed); */
/*     TEST_ASSERT_EQUAL(8, stack_pushed->value); */
/*     TEST_ASSERT_EQUAL(9, stack_pushed->next->value); */
/* } */

/* TEST(Stack, test_stack_rotate) */
/* { */
/*     TEST_IGNORE(); */
/*     // stack = stack_rotate(stack, n, dir) -> ERROR if n > stack length */
/*     stack = stack_push(stack, 0); */
/*     stack = stack_rotate(stack, 1, RotateLeft); */
/*     TEST_ASSERT_EQUAL(0, stack->value); */
/*     stack = stack_rotate(stack, 1, RotateRight); */
/*     TEST_ASSERT_EQUAL(0, stack->value); */
/*     stack = stack_push(stack, 1); */
/*     //stack_print(stack); */
/*     //stack = stack_rotate(stack, 2, RotateLeft); */
/*     //stack_print(stack); */
/*     //assert_stack(stack, (int[2]){1, 0}, 2); */
/*     //stack = stack_rotate(stack, 2, RotateRight); */
/*     //stack = stack_rotate(stack, 2, RotateRight); */
/*     //assert_stack(stack, (int[2]){0, 1}, 2); */
/* } */

/* TEST(Stack, test_stack_length) */
/* { */
/*     TEST_ASSERT_EQUAL(0, stack_length(stack)); */
/*     TEST_ASSERT_EQUAL(10, stack_length(stack_pushed)); */
/*     stack = stack_push(stack, 1); */
/*     TEST_ASSERT_EQUAL(1, stack_length(stack)); */
/* } */

/* /1* static void assert_stack(Stack *stack, int values[], int values_len) *1/ */
/* /1* { *1/ */
/* /1*     TEST_ASSERT_EQUAL(values_len, stack_length(stack)); *1/ */
/* /1*     for (int i = 0; stack != NULL; i++) { *1/ */
/* /1*         TEST_ASSERT_EQUAL(values[i], stack->value); *1/ */
/* /1*         stack = stack->next; *1/ */
/* /1*     } *1/ */
/* /1* } *1/ */
