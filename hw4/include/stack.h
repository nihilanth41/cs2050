#ifndef __STACK_H_
#define __STACK_H_

#include <stdio.h>
#include "bst.h"

typedef struct node_ {
	BST *bst;
	struct node_ *next;
} node;

typedef struct stack_ {
	unsigned int size;
	struct node_ *stack;
} stack;

stack* create_stack();
void push(stack *s, BST *tree);
void pop(stack *s);
BST* top(stack *s);
int isEmpty(stack *s);

#endif
