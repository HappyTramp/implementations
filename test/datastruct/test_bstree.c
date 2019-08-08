#include "unity.h"
#include "unity_fixture.h"
#include "../src/binarysearchtree.h"

TEST_GROUP(BSTree);

static BSTree *tree;

TEST_SETUP(BSTree)
{
    tree = bstree_new();
}

TEST_TEAR_DOWN(BSTree)
{
    bstree_destroy(tree);
}

TEST(BSTree, test_bstree_new)
{
    TEST_ASSERT_NULL(tree);
}

TEST(BSTree, test_bstree_insert)
{
    tree = bstree_insert(tree, 5);
    TEST_ASSERT_EQUAL(5, tree->value);
    TEST_ASSERT_NULL(tree->left);
    TEST_ASSERT_NULL(tree->right);
    tree = bstree_insert(tree, 2);
    TEST_ASSERT_EQUAL(2, tree->left->value);
    tree = bstree_insert(tree, 20);
    TEST_ASSERT_EQUAL(20, tree->right->value);
    tree = bstree_insert(tree, 3);
    TEST_ASSERT_EQUAL(3, tree->left->right->value);
    tree = bstree_insert(tree, 25);
    TEST_ASSERT_EQUAL(25, tree->right->right->value);
    tree = bstree_insert(tree, 15);
    TEST_ASSERT_EQUAL(15, tree->right->left->value);
    // equal
    tree = bstree_insert(tree, 15);
    TEST_ASSERT_EQUAL(15, tree->right->left->left->value);
}

TEST(BSTree, test_bstree_search)
{
    TEST_ASSERT_FALSE(bstree_search(tree, 3));
    tree = bstree_insert(tree, 3);
    TEST_ASSERT_TRUE(bstree_search(tree, 3));
    TEST_ASSERT_FALSE(bstree_search(tree, 1));
    tree = bstree_insert(tree, 1);
    TEST_ASSERT_TRUE(bstree_search(tree, 1));
    TEST_ASSERT_FALSE(bstree_search(tree, 30));
    tree = bstree_insert(tree, 30);
    TEST_ASSERT_TRUE(bstree_search(tree, 30));
    TEST_ASSERT_FALSE(bstree_search(tree, 25));
    tree = bstree_insert(tree, 25);
    TEST_ASSERT_TRUE(bstree_search(tree, 25));
}
TEST(BSTree, test_bstree_min)
{
    tree = bstree_insert(tree, 1);
    TEST_ASSERT_EQUAL(1, bstree_min(tree));
    tree = bstree_insert(tree, 3);
    TEST_ASSERT_EQUAL(1, bstree_min(tree));
    tree = bstree_insert(tree, -1);
    TEST_ASSERT_EQUAL(-1, bstree_min(tree));
    tree = bstree_insert(tree, 0);
    TEST_ASSERT_EQUAL(-1, bstree_min(tree));
}

TEST(BSTree, test_bstree_max)
{
    tree = bstree_insert(tree, 1);
    TEST_ASSERT_EQUAL(1, bstree_max(tree));
    tree = bstree_insert(tree, 3);
    TEST_ASSERT_EQUAL(3, bstree_max(tree));
    tree = bstree_insert(tree, -1);
    TEST_ASSERT_EQUAL(3, bstree_max(tree));
    tree = bstree_insert(tree, 10);
    TEST_ASSERT_EQUAL(10, bstree_max(tree));
}

TEST(BSTree, test_bstree_height)
{
    TEST_ASSERT_EQUAL(-1, bstree_height(tree));
    tree = bstree_insert(tree, 1);
    TEST_ASSERT_EQUAL(0, bstree_height(tree));
    tree = bstree_insert(tree, 2);
    TEST_ASSERT_EQUAL(1, bstree_height(tree));
    tree = bstree_insert(tree, 3);
    TEST_ASSERT_EQUAL(2, bstree_height(tree));
    tree = bstree_insert(tree, 0);
    TEST_ASSERT_EQUAL(2, bstree_height(tree));
    tree = bstree_insert(tree, -1);
    TEST_ASSERT_EQUAL(2, bstree_height(tree));
    tree = bstree_insert(tree, -2);
    TEST_ASSERT_EQUAL(3, bstree_height(tree));
    tree = bstree_insert(tree, -20);
    TEST_ASSERT_EQUAL(4, bstree_height(tree));
}

