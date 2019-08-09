#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "btree.h"

BTree *btree_create_elem(void *data)
{
    BTree *tree = malloc(sizeof(BTree));
    if (tree == NULL)
        return NULL;
    tree->left = NULL;
    tree->right = NULL;
    tree->data = data;
    return tree;
}

void btree_destroy(BTree **tree, void (*free_fn)(void *))
{
    btree_clear(*tree, free_fn);
    *tree = NULL;
}

void btree_clear(BTree *tree, void (*free_fn)(void *))
{
    if (tree == NULL)
        return;
    btree_clear(tree->left, free_fn);
    btree_clear(tree->right, free_fn);
    free_fn(tree->data);
    free(tree);
}

BTree *btree_join(BTree *left, BTree *right, void *data)
{
    BTree *join = btree_create_elem(data);
    if (join == NULL)
        return NULL;
    join->left = left;
    join->right = right;
    return join;
}

size_t btree_count(BTree *tree)
{
    if (tree == NULL)
        return 0;
    return (btree_count(tree->left) + btree_count(tree->right) + 1);
}

size_t btree_level_count(BTree *tree)
{
    int left_level;
    int right_level;

    if (tree == NULL)
        return (0);
    left_level = 0;
    right_level = 0;
    if (tree->left != NULL) // unnecessary
        left_level = btree_level_count(tree->left);
    if (tree->right != NULL)
        right_level = btree_level_count(tree->right);
    if (left_level >= right_level)
        return (1 + left_level);
    else
        return (1 + right_level);
}
