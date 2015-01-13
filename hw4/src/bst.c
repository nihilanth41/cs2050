#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"
/**
 * param a: an int array
 * param low: the lowest valid indice in the array
 * param high: the highest valid indice in the array
 *
 * return: the root of a balanced BST
 *
 * This function should build a balanced bst from a sorted array. 
 * Hint: This function should look similar to binary search. 
 *
 * NOTES: Balanced BST tries to keep height as small as possible. 
 * Therefore we want to find the middle value of the array and make that the root of the tree
 */
BST* build_balanced_tree(int a[], int low, int high) {
	//base case
	if(low > high)
		return NULL;
	//get middle element and make it the root of the tree
	int midpoint = (low + high)/2;
	BST *bstRoot = malloc(sizeof(BST));
	assert(bstRoot != NULL);
	bstRoot->data = a[midpoint];
	//construct left tree recurisvely
	bstRoot->left = build_balanced_tree(a, low, midpoint-1);
	//construct right tree recursively
	bstRoot->right = build_balanced_tree(a, midpoint+1, high);
	return bstRoot;
}

void print(BST* root) {
	structure(root, 0);
}
 
void padding(char ch, int n) {
    int i;

    for (i = 0; i < n; ++i) {
        putchar(ch);
    }
}

void structure(BST* root, int level) {
    if (root == NULL) {
        padding('\t', level);
        puts("~");
    } else {
        structure(root->right, level+1);
        padding('\t', level);
        printf("%d\n", root->data);
        structure(root->left, level+1);
    }
}

//recursively free each node in BST
void destroy_tree(BST *root) {
	if(root == NULL)
		return;
	else
	{
		destroy_tree(root->right);
		destroy_tree(root->left);
		free(root);
	}
}


