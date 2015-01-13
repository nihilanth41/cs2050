//Zachary Rump 
//ZRRM74
//Lab E
//Lab Code: LEGO
//bst.c
#include <math.h>
#include "bst.h"

//note: how does insert handle duplicates?
BST* insert(BST* tree, int data) {
	//base case: create new node and return
	if(tree == NULL)
	{
		BST* newNode = malloc(sizeof(BST));
		assert(newNode != NULL); //check memory
		newNode->data = data; 
		newNode->left = NULL;
		newNode->right= NULL;
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

BST* find(BST* tree, int data) {
	//base case
	if(tree == NULL)
		return NULL;
	//match found return node
	if(data == tree->data)
		return tree;
	//recursively traverse right tree	
	if(data > tree->data)
		return find(tree->right, data);
	//recursively traverse left tree	
	if(data < tree->data)
		return find(tree->left, data);
}

void print(BST* tree) {
	if(tree == NULL)
		return;
	//traverse left tree
	print(tree->left);
	//print current tree
	printf("%d ", tree->data);
	//traverse right tree
	print(tree->right);
}

void destroy_tree(BST* tree) {
	//free each node in the tree
	if(tree == NULL)
		return;
	//traverse right tree
	destroy_tree(tree->right);
	//free memory at current tree
	free(tree);
	 //set equal to NULL so nothing tries to dereference
	//traverse left tree
	destroy_tree(tree->left);
}

BST* nearest_to(BST* tree, int data) {
	//traverse tree and try to find the number that is closest to data
	//hint is to use iteration instead of recursion O(log(n))
	int min_difference=101;
	BST *mintreePtr = tree;
	while(tree != NULL)
	{
		//check current node for difference
		int difference = (tree->data - data);
		difference = abs(difference);
		//new smallest difference
		if(difference < min_difference)
		{
			//record value of smallest difference
			min_difference = difference;
			//point to location of smallest difference
			mintreePtr = tree;
		}
		//determine whether to look @ left or right tree next	
		if(data == tree->data)
			return mintreePtr;

		if(data > tree->data)
		{
			tree = tree->right;
		}
		else
		{
			tree = tree->left;
		}
	}
	return mintreePtr;
}


	









