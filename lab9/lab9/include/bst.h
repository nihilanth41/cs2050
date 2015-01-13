#ifndef __BST_H_
#define __BST_H_

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct node_ { 
	int data;
	struct node_* left;
	struct node_* right;
} BST;

BST* insert(BST* tree, int data);
BST* find(BST* tree, int data);
void print(BST* tree);
void destroy_tree(BST* tree);
//bonus
BST* nearest_to(BST* tree, int data);

#endif
