#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node_ {
	int data;
        struct node_ *next;
} Queue;

/**
 ** A queue is an abstract data type where the nodes are kept and
 ** removed in the order that they were added. This means a queue
 ** is a First in First out data structure (FIFO). There are many 
 ** ways to implement a queue, one of which is with a linked list. 
 **
 ** For this prelab you will need to implement the a queues 
 ** enqueue function. This is where a new data element is added
 ** to the rear of the queue. 
 **
 ** Ex. 
 **
 ** Queue = NULL
 ** Queue = Enqueue(Queue, 1)
 ** Queue = 1 -> NULL
 ** Queue = Enqueue(Queue, 2) 
 ** Queue = 1 -> 2 -> NULL
 **/
Queue* enqueue(Queue* queue, int data); 

int main(void) {
	Queue* queue = NULL;
	      
	queue = enqueue(queue, 1);
	   
	assert(queue->next == NULL);
	assert(queue->data == 1);

	queue = enqueue(queue, 2);

	assert(queue->data == 1);
	assert(queue->next != NULL);
	assert(queue->next->data == 2);
	free(queue->next);
	free(queue);

	printf("You have successfully completed the prelab\n");
        return 0;
}

Queue* enqueue(Queue* queue, int data) {
	if(queue == NULL)
	{
		Queue *newqueue = malloc(sizeof(queue));
		newqueue->data = data;
		newqueue->next = NULL;
		return queue;
	}
	else
	{
		if(queue->next == NULL)
		{
			Queue *newqueue = malloc(sizeof(queue));
			newqueue->data = data;
			newqueue->next = NULL;
			return queue; 
		}
		else
		{
			return enqueue(queue->next, data);
		}
	}
}



