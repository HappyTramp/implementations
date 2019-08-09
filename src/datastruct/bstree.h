#ifndef __BSTREE_H__
# define __BSTREE_H__

# include <stdbool.h>
# include "btree.h"

typedef BTree BSTree;

void bstree_insert(BSTree **tree, void *data, int (*compar)(const void *, const void *));
bool bstree_search(BSTree *tree, void *data, int (*compar)(const void *, const void *));
void *bstree_min(BSTree *tree);
void *bstree_max(BSTree *tree);

#endif
