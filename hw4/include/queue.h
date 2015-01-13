#ifndef __QUEUE_H_
#define __QUEUE_H_

#include <stdlib.h>
#include "bst.h"

typedef struct Queue_ { 
	BST *bst;
	struct Queue_ *next;
} Queue; 

Queue* enqueue(Queue *queue, BST *tree);
BST*  dequeue(Queue **queue);
int size(Queue *queue);


#endif
