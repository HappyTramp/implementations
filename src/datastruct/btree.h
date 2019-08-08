#ifndef __H_BTREE__
#define __H_BTREE__


typedef struct BTree {
    struct BTree *parent;
    struct BTree *left;
    struct BTree *right;
    int value;
} BTree;

BTree *btree_new(int value);
void btree_destroy(BTree *tree);
BTree *btree_join(BTree *left, BTree *right, int value);
void btree_add_leaf(BTree *parent, int value);
int btree_count(BTree *tree);
/* bool btree_are_siblings(BTree *node1, BTree *node2); */
/* bool btree_is_internal(BTree *node);  // at least one child */
/* bool btree_is_ancestor_of(BTree *child, BTree *ancestor);  // follow link */
/* bool btree_is_descendent_of(BTree *ancestor, BTree *child); */
/* bool btree_is_leaf(BTree *node); */
void btree_print(BTree *tree);
//BTree *btree_add_node_left(BTree *tree);
//BTree *btree_add_node_right(BTree *tree);
//BTree *btree_remove_node_left(BTree *tree);
//BTree *btree_remove_node_right(BTree *tree);

#endif
