#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node_ {
	int data;
	struct node_ *left;
	struct node_ *right;
} BST;

/**
 * For this PreLab you need to implement insert for 
 * a binary search tree (BST). A BST has the following
 * recursive definition:
 * 
 * A valid BST is either:
 *		NULL
 * 	OR
 *		A node whose right pointer points to a valid BST
 *		whose left pointer points to a BST whose values 
 *		are all less than the node or NULL
 * 		AND
 *		whose right pointer points to a BST whose values 
 *		are all greater than or equal to the node or NULL
 * 
 *      EX. 
 *				5
 *			 /    \
 *		    3	   8
 *		   / \	  / \
 * 	   NULL NULL 6  NULL
 * 
 * Parameters:
 *	- tree : A pointer to the head of a valid BST
 *  - data : A value to be inserted into the BST
 * Return:
 *  - The head of the BST with data inserted
 */
BST* insert(BST* tree, int data);

int main(void) {
	
	BST* tree = NULL;
	
	tree = insert(tree, 5);
	assert(tree->data == 5);
	assert(tree->left == NULL);
	assert(tree->right == NULL);
	
	tree = insert(tree, 3);
	assert(tree->left != NULL);
	assert(tree->left->data == 3);
	
	tree = insert(tree, 8);
	assert(tree->right != NULL);
	assert(tree->right->data == 8);
	
	tree = insert(tree, 6);
	assert(tree->right->left != NULL);
	assert(tree->right->left->data == 6);
	
	free(tree->right->left);
	free(tree->right);
	free(tree->left);
	free(tree);
	
	printf("You have completed the pre-lab\n");
}

BST* insert(BST* tree, int data) {
	//create new node and return
	if(tree == NULL)
	{
		BST* newNode = malloc(sizeof(BST));
		assert(newNode != NULL); //do we have mem
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	if(data > tree->data)
	{
		tree->right = insert(tree->right, data);
		return tree;
	}
	if(data < tree->data)
	{
		tree->left = insert(tree->left, data);
		return tree;
	}
}



