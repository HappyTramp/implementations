#ifndef __H_BSTREE__
#define __H_BSTREE__

#include "binarytree.h"
#include <stdbool.h>

typedef BTree BSTree, BSTNode;
typedef unsigned int Depth;
typedef int Height;

typedef enum {
    Preorder,  // data -> left -> right (DLR)
    Inorder,   // left -> data -> right (LDR)
    Postorder  // left -> right -> data (LRD)
} DepthTraversalOrder;

BSTree *bstree_new(void);
void bstree_destroy(BSTree *tree);
BSTree *bstree_insert(BSTree *tree, int value);
void *bstree_remove(BSTree *tree, int value);
bool bstree_search(BSTree *tree, int value);
int bstree_min(BSTree *tree);
int bstree_max(BSTree *tree);
Height bstree_height(BSTree *tree);
Depth bstree_depth(BSTree *root, BSTNode *node);
void bstree_breadth_first(BSTree *tree, void (*f)(BSTNode *n));
void bstree_depth_first(BSTree *tree, DepthTraversalOrder order,
                        void (*f)(BSTNode *n));
bool bstree_empty(BSTree *tree);

#endif
