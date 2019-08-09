#ifndef __BTREE_H__
# define __BTREE_H__

# include <string.h>

typedef struct BTree {
    struct BTree *left;
    struct BTree *right;
    void *data;
} BTree;

BTree *btree_create_elem(void *data);
void btree_destroy(BTree **tree, void (*free_fn)(void *));
void btree_clear(BTree *tree, void (*free_fn)(void *));
BTree *btree_join(BTree *left, BTree *right, void *data);
size_t btree_count(BTree *tree);
size_t btree_level_count(BTree *tree);

#endif
