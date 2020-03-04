#ifndef _TREE_H_
#define _TREE_H_
#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1
#define DOUBLE 2
#define FAILURE 0
#define DATA_NOT_FOUND 0

typedef int data_t;

typedef struct binary_search_tree
{
	struct binary_search_tree *l_child;
	data_t data;
	struct binary_search_tree *r_child;
}Tree;

Tree *bst_create();
Tree *bst_insert(Tree *root, data_t info);
int bst_delete_node(Tree *root, data_t info);
data_t find_min(Tree *root);
data_t find_max(Tree *root);
data_t search_node(Tree *root, data_t info);
void inorder(Tree *root);
void preorder(Tree *root);
void postorder(Tree *root);

#endif




