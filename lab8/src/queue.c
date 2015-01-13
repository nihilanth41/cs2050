#include "queue.h"

Queue* enqueue(Queue* queue, char* data) {
	if(queue == NULL)
	{
		Queue *newQueue = malloc(sizeof(Queue));
		newQueue->next=NULL;
		newQueue->data = strdup(data);
		return newQueue;
	}
	Queue *queuePtr = queue; 
	while(queuePtr->next != NULL)
	{
		queuePtr = queuePtr->next;
	}
	//queuePtr->next == NULL
	//insert @ tail
	//malloc for new queue
	Queue *newQueue = malloc(sizeof(Queue));
	//old tail points to new tail
	queuePtr->next = newQueue;
	//cpy string
	newQueue->data = strdup(data);
	//new tail points to NULL
	newQueue->next = NULL;
	//return head of queue
	return queue;
}

char* dequeue(Queue** queue) {
	//temp ptr to point to head of queue
	Queue *head = (*queue);
	//move head down one
	(*queue) = ((*queue)->next);
	//point to string
	char *str = head->data;
	//free memory alloc'd for struct
	free(head);
	//return str pointer
	return str;
}

//recursive accessor for linkedlist length
int size(Queue* queue) {
	if(queue == NULL)
		return 0;
	else
		return (1+size(queue->next));
}



