#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "binarytree.h"
#include "binarysearchtree.h"

static bool empty(BSTree *tree);
static bool leaf(BSTree *tree);
static int max(int a, int b);
static BSTNode *new_node(int value);

BSTree *bstree_new(void) { return NULL; }

void bstree_destroy(BSTree *tree) { btree_destroy(tree); }

BSTree *bstree_insert(BSTree *tree, int value)
{
    if (empty(tree))
        tree = new_node(value);
    else if (value > tree->value)
        tree->right = bstree_insert(tree->right, value);
    else if (value <= tree->value)
        tree->left = bstree_insert(tree->left, value);
    return tree;
}

/* void *bstree_remove(BSTree *tree, int value) */
/* { */

/* } */

bool bstree_search(BSTree *tree, int value)
{
    if (empty(tree)) return false;
    if (value > tree->value)
        return bstree_search(tree->right, value);
    else if (value < tree->value)
        return bstree_search(tree->left, value);
    return true;
}

int bstree_min(BSTree *tree)
{
    if (empty(tree)) exit(1);
    if (empty(tree->left))
        return tree->value;
    return bstree_min(tree->left);
}

int bstree_max(BSTree *tree)
{
    if (empty(tree)) exit(1);
    if (empty(tree->right))
        return tree->value;
    return bstree_max(tree->right);
}

Height bstree_height(BSTree *tree)
{
    if (empty(tree)) return -1;
    return 1 + max(bstree_height(tree->left), bstree_height(tree->right));
}

/* Depth bstree_depth(BSTree *root, BSTNode *node) */
/* { */
/*     if (node == root) return 0; */
/*     return 1 + bstree_depth(root->left) */

/* } */

// traverse the tree by levequeue_empty(queue)l-order
void bstree_breadth_first(BSTree *tree, void (*f)(BSTNode *n))
{
    if (empty(tree)) return;
    Queue *discovered = queue_enqueue(discovered, tree);
    BSTNode *current;
    while (!queue_empty(discovered)) {
        current = (BSTNode *)queue_peek(discovered);
        f(current);
        if (tree->left != NULL)
            discovered = queue_enqueue(discovered, current->left);
        if (tree->right != NULL)
            discovered = queue_enqueue(discovered, current->right);
        discovered = queue_dequeue(discovered);
    }

}

void bstree_depth_first(BSTree *tree, DepthTraversalOrder order,
                        void (*f)(BSTNode *n))
{
    if (empty(tree)) return;

    switch (order) {
    case Preorder:
        f(tree);
        bstree_depth_first(tree->left, order, f);
        bstree_depth_first(tree->right, order, f);
        break;
    case Inorder:
        bstree_depth_first(tree->left, order, f);
        f(tree);
        bstree_depth_first(tree->right, order, f);
        break;
    case Postorder:
        bstree_depth_first(tree->left, order, f);
        bstree_depth_first(tree->right, order, f);
        f(tree);
        break;
    default: exit(1);
    }
}

bool bstree_empty(BSTree *tree) { return tree == NULL; }

static bool empty(BSTree *tree) { return bstree_empty(tree); }

static bool leaf(BSTree *tree)
{
    return empty(tree->left) && empty(tree->right);
}

static int max(int a, int b) { return a > b ? a : b; }

static BSTNode *new_node(int value)
{
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

