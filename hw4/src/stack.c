#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

/**
 * Return: A pointer to an empty stack
 */
stack* create_stack() {
	//create new stack ptr and alloc memory
	stack *sPtr = malloc(sizeof(stack));
	sPtr->size=0;	
	sPtr->stack=NULL;
	return sPtr;
}


/**
 * Param: s   - A pointer to a stack
 * Param: val - A value to be pushed onto the stack
 *
 * Return: None
 */
void push(stack *s, BST *tree) {
	//check for NULL stack ptr
	assert(s != NULL);
	//alloc memory for new node in stack 
	node *newNode = malloc(sizeof(node));
	if(newNode == NULL)
	{
		printf("Error malloc returned null");
	}
	else
	//assign value to new top node of stack
	newNode->bst = tree;
	//new top node points to old top node
	newNode->next = s->stack;
	//assign newNode as new top of stack
	s->stack = newNode;
	//increment stack size
	s->size++;
}


/**
 * Param: s -  A pointer to a stack
 *
 * Return:  None
 *
 * Deletes removes the top node of the stack. 
 * If the stack is empty, nothing should happen. 
 */
void pop(stack *s) {
	//this should never happen 
	assert(s != NULL);
	{
		//top points to top node in the stack
		node *top = s->stack;
		//stack is empty
		if(top == NULL)
			return; //do nothing
		//else
		//move next item in stack to the top
		s->stack = top->next;
		free(top);
		//decrement stack size
		s->size--;
	}
}

/**
 * Param: s - A pointer to a stack
 *
 * Return: The value stored at the top of a stack
 * 
 * This function should return the value at the top of
 * a non-empty stack without modifying it
 */
BST* top(stack *s) {
	assert(isEmpty(s) == 0);
	assert(s->stack != NULL);
	return s->stack->bst;
}

/**
 * Param: s - A pointer to a stack
 *
 * Return: 1 if the stack is empty, 0 otherwise
 */
int isEmpty(stack *s) {
    return s->stack == NULL ? 1 : 0;
}
