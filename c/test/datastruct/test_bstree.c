#include "unity.h"
#include "unity_helper.h"
#include "helper.h"
#include "btree.h"
#include "bstree.h"

void free_not(void *data) {}
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
static BSTree *tree;

void setUp(void)
{
    tree = NULL;
}

void tearDown(void)
{
    btree_destroy(&tree, free_not);
}

void test_bstree_insert(void)
{
    TEST_IGNORE();
    bstree_insert(&tree, &i5, cmp_int);
    TEST_ASSERT_INT_DATA(i5, tree->data);
    TEST_ASSERT_NULL(tree->left);
    TEST_ASSERT_NULL(tree->right);
    bstree_insert(&tree, &i2, cmp_int);
    TEST_ASSERT_INT_DATA(i2, tree->left->data);
    bstree_insert(&tree, &i9, cmp_int);
    TEST_ASSERT_INT_DATA(i9, tree->right->data);
    bstree_insert(&tree, &i3, cmp_int);
    TEST_ASSERT_INT_DATA(i3, tree->left->right->data);
    /* bstree_insert(&tree, &i25, cmp_int); */
    /* TEST_ASSERT_EQUAL(25, tree->right->right->data); */
    /* bstree_insert(&tree, &i15, cmp_int); */
    /* TEST_ASSERT_EQUAL(15, tree->right->left->data); */
    /* // equal */
    /* bstree_insert(&tree, &i15, cmp_int); */
    /* TEST_ASSERT_EQUAL(15, tree->right->left->left->data); */
}

void test_bstree_search(void)
{
    TEST_IGNORE();
    TEST_ASSERT_FALSE(bstree_search(tree, &i3, cmp_int));
    bstree_insert(&tree, &i3, cmp_int);
    TEST_ASSERT_TRUE(bstree_search(tree, &i3, cmp_int));
    TEST_ASSERT_FALSE(bstree_search(tree, &i1, cmp_int));
    bstree_insert(&tree, &i1, cmp_int);
    TEST_ASSERT_TRUE(bstree_search(tree, &i1, cmp_int));
    TEST_ASSERT_FALSE(bstree_search(tree, &i4, cmp_int));
    bstree_insert(&tree, &i4, cmp_int);
    TEST_ASSERT_TRUE(bstree_search(tree, &i4, cmp_int));
    TEST_ASSERT_FALSE(bstree_search(tree, &i5, cmp_int));
    bstree_insert(&tree, &i5, cmp_int);
    TEST_ASSERT_TRUE(bstree_search(tree, &i5, cmp_int));
}

void test_bstree_min(void)
{
    TEST_IGNORE();
    bstree_insert(&tree, &i1, cmp_int);
    TEST_ASSERT_EQUAL(1, bstree_min(tree));
    bstree_insert(&tree, &i3, cmp_int);
    TEST_ASSERT_EQUAL(1, bstree_min(tree));
    bstree_insert(&tree, &i0, cmp_int);
    TEST_ASSERT_EQUAL(-1, bstree_min(tree));
    bstree_insert(&tree, &i0, cmp_int);
    TEST_ASSERT_EQUAL(-1, bstree_min(tree));
}

void test_bstree_max(void)
{
    TEST_IGNORE();
    bstree_insert(&tree, &i1, cmp_int);
    TEST_ASSERT_EQUAL(1, bstree_max(tree));
    bstree_insert(&tree, &i3, cmp_int);
    TEST_ASSERT_EQUAL(3, bstree_max(tree));
    bstree_insert(&tree, &i0, cmp_int);
    TEST_ASSERT_EQUAL(3, bstree_max(tree));
    bstree_insert(&tree, &i9, cmp_int);
    TEST_ASSERT_EQUAL(9, bstree_max(tree));
}
