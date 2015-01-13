#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BST.h"
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

BST* delete_node(BST* root, int data) {
	
	if(root == NULL)
		return root;

	//key is > root --> traverse right tree
	if(data > root->data)
	{
		root->right = delete_node(root->right, data);
		return root;	
	}

	//key is < root --> traverse left tree	
	if(data < root->data)
	{
		root->left = delete_node(root->left, data);
		return root;
	}

	if(data == root->data)
	{
		//left sub null 
		if(root->left == NULL)
		{
			//record location of right subtree
			BST* right = root->right;
			//free current node
			free(root); 
			root = right;
			//return ptr to right node
			return root;
		}

		//right sub null 
		if(root->right == NULL)
		{
			BST* left = root->left;
			//free current node
			free(root);
			root = left;
			//return ptr to left node
			return root;
		}
			
		//neither subtree is null
		//pick min(right) which is the next node in tree and copy the data to current root
		BST* bstMin = min(root->right);
		//root->data = root->right->data;
		root->data = bstMin->data;
		root->right = delete_node(root->right, root->data);
		return root;
	}
}

BST* min(BST* root) {
	//return leftmost node until we reach the end (left node is always smaller)
	if(root->left != NULL)
		return min(root->left);
	//end of left tree reached
	return root; 
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
    int i;

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

BST* mirror(BST* root) {
	if(root == NULL)
		return NULL;
	else
	{
		//alloc memory for new BST
		BST* newBst = malloc(sizeof(BST));
		//copy data at current node
		newBst->data = root->data;
		//recursively set left tree equal to mirror of right tree
		newBst->left = mirror(root->right);
		//recursively set right tree equal to mirror of left tree
		newBst->right = mirror(root->left);
		
		return newBst;
	}
}

