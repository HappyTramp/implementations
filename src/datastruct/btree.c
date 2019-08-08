#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "logger.h"
#include "binarytree.h"


static void print_value(BTree *tree);
static bool empty(BTree *tree);


BTree *btree_new(int value)
{
    BTree *tree = malloc(sizeof(BTree));
    if (empty(tree))
        log_error_exit("tree allocation");
    tree->parent = NULL;
    tree->left = NULL;
    tree->right = NULL;
    tree->value = value;
    log_info("tree created");
    return tree;
}

void btree_destroy(BTree *tree)
{
    if (empty(tree))
        return;
    btree_destroy(tree->left);
    btree_destroy(tree->right);
    free(tree);
    /* log_info("tree destroyed"); */
}

BTree *btree_join(BTree *left, BTree *right, int value)
{
    BTree *joint = btree_new(value);
    joint->left = left;
    joint->right = right;
    if (!empty(left))
        left->parent = joint;
    if (!empty(right))
        right->parent = joint;
    return joint;
}

int btree_count(BTree *tree)
{
    if (empty(tree))
        return 0;
    return (btree_count(tree->left) + btree_count(tree->right) + 1);
}

/* void btree_add_leaf(BTree *parent, int value) */
/* { */
/*     BTree *leaf = btree_new(value); */
/*     leaf->parent = parent; */
/*     parent-> */

/* } */

static bool empty(BTree *tree)
{
    return tree == NULL;
}

void btree_print(BTree *tree)
{
    print_value(tree->parent);
    printf(" -> ");
    printf("%d -> ", tree->value);
    print_value(tree->left);
    printf(" ");
    print_value(tree->right);
    printf("\n");
}

static void print_value(BTree* tree)
{
    if (!empty(tree))
        printf("%d", tree->value);
    else
        printf("_");
}
