//Zachary Rump
//ZRRM74
//11/01/14
//Lab E
//Lab Code: PUMPKIN
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> //for sleep()
#include <assert.h>
#include <string.h>
#include "queue.h"

#define STRLEN_MAX 100

//prototypes
Queue* print(Queue* queue);

int main(int argc, char **argv) {
	//read in one input file (ignore extraneous args)
	if(argc<2)
	{
		printf("Not enough arguments.\nUsage is: ./printer <file1>\n");
		return EXIT_FAILURE;
	}
	//declare Queue
	Queue *q = NULL;
	//open file
	FILE *fp = fopen(argv[1], "r");
	//check for bad file arg
	assert(fp != NULL);
	//buffer for fgets
	char buf[STRLEN_MAX]; 
	while(fgets(buf, 100, fp) != NULL)
	{
		//buf is now filled w/ a line from the file
		//enqueue whole line as str
		q = enqueue(q, buf);
		int queueSize = size(q);
		//print will call dequeue which will recursively dequeue everything	
		if(queueSize >= 3)
		{
			sleep(1);
			q = print(q);
		}
	}
	fclose(fp);
	return EXIT_SUCCESS;
}


//Dequeue every item in the queue and print out it's string
Queue* print(Queue* queue) {
	if(queue == NULL)
		return queue;
	else
	{
		Queue *next = queue->next;
		printf("%s", dequeue(&queue));
		return print(next);
	}
}

	




