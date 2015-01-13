//CS2050 HW4
//Zachary Rump 
//ZRRM74 12337948
//LAB E
//12/6/2014
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#include "stack.h"
#include "bst.h"

#define SIZE_MAX 100

void traverse_preOrder(BST *bstPtr);
void traverse_inOrder(BST *bstPtr);
void traverse_breadthFirst(BST *bstPtr);

int main(int argc, char **argv) {

	//check for proper # of input args
	if(argc < 2) 
	{
		printf("Error not enough arguments. Usage is %s <input file>\n", argv[0]);
		return -1; 
	}
	
	//attempt to open file and check for bad file path	
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL) 
	{
		printf("Error opening file. Check filename\n");
		return -1;
	}
	
	//buffer for storing ints
	char buf[SIZE_MAX];
	int a[SIZE_MAX] = { 0 };
	int size=0;
	
	//read every int in file and store in array
	while(fgets(buf, 100, fp) != NULL)
	{
		a[size] = atoi(buf);
		size++;
	}
	fclose(fp); //close file

	//build balanced bst with array
	BST* bstPtr = build_balanced_tree(a, 0, size-1); 
	
	//print visual representation of tree
	printf("\n\tBalanced Binary Tree\n\n");
	print(bstPtr);

	//perform traversal of tree in 3 different methods
	//pre-order (root, left, right)
	traverse_preOrder(bstPtr);	
	
	//in-order (left, root, right)
	traverse_inOrder(bstPtr);

	//breadth-first 
	traverse_breadthFirst(bstPtr);

	//destroy BST (dealloc memory)
	destroy_tree(bstPtr);
	bstPtr = NULL; 

	return 0;
}


void traverse_preOrder(BST *bstPtr) {
	printf("\nPre-order Traversal\n");
	//create empty stack
	stack *sPtr = create_stack();
	//push root onto stack
	push(sPtr, bstPtr);
	//while stack is not empty
	while(!isEmpty(sPtr))
	{
		//print top node of stack
		BST* b = top(sPtr); 
		printf("%d ", b->data);
		//pop top node of stack
		pop(sPtr);
		if(b->right != NULL)
		{
			push(sPtr, b->right); //push right child node onto stack
		}
		if(b->left != NULL)
		{
			push(sPtr, b->left); //push left child node onto stack
		}
	}
	//free memory alloc'd for stack
	free(sPtr);
	printf("\n");
	
}



void traverse_inOrder(BST *bstPtr) {
	printf("\nIn-order Traversal\n");
	//create empty stack
	stack *sPtr = create_stack();
	//set current node as root
	BST* bstCurrent = bstPtr;
	//traverse left subtree
	while(1) 
	{
		if(bstCurrent != NULL)
		{	
			//push root onto stack
			push(sPtr, bstCurrent);
			bstCurrent = bstCurrent->left; //set current=current->left
		}
		else
		{
			if(bstCurrent == NULL && !isEmpty(sPtr))
			{
				//pop top item from the stack
				BST* b = top(sPtr);
				pop(sPtr); 
				//print element
				printf("%d ", b->data);
				//set current = popped->right
				bstCurrent = b->right;
			}
		}
		//stack is empty and current node is null
		if(bstCurrent == NULL && isEmpty(sPtr))		
		{
			break;
		}		
	}
	//free memory alloc'd for stack
	free(sPtr);
	printf("\n");
}


void traverse_breadthFirst(BST *bstPtr) {
	printf("\nBreadth-first Traversal\n");
	//create empty queue
	Queue *queue = NULL;
	//enqueue the root node
	queue = enqueue(queue, bstPtr);
	//while queue is not empty
	while(size(queue) != 0) 
	{
		//dequeue a node from queue
		BST *b = dequeue(&queue);
		//print the node
		printf("%d ", b->data);
		//enqueue left child
		if(b->left != NULL)
		{
			queue = enqueue(queue, b->left);
		}
		//enqueue right child
		if(b->right != NULL)
		{
			queue = enqueue(queue, b->right);
		}
	}
	//dequeue frees memory 
	printf("\n");
}

		

			
		


