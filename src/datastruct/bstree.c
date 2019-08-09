#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "btree.h"
#include "bstree.h"

void bstree_insert(BSTree **tree, void *data, int (*compar)(const void *, const void *))
{
    if (*tree == NULL)
        *tree = btree_create_elem(data);
    else if (compar(data, (*tree)->data) > 0)
        bstree_insert(&(*tree)->right, data, compar);
    else
        bstree_insert(&(*tree)->left, data, compar);
}

bool bstree_search(BSTree *tree, void *data, int (*compar)(const void *, const void *))
{
    if (tree == NULL)
        return false;
    if (compar(data, tree->data) > 0)
        return bstree_search(tree->right, data, compar);
    if (compar(data, tree->data) < 0)
        return bstree_search(tree->left, data, compar);
    return true;
}

void *bstree_min(BSTree *tree)
{
    if (tree->left == NULL)
        return tree->data;
    return bstree_min(tree->left);
}

void *bstree_max(BSTree *tree)
{
    if (tree->right == NULL)
        return tree->data;
    return bstree_max(tree->right);
}
