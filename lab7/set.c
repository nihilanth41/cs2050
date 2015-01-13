#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "set.h"

Set* set_insert(Set* set, int data) {
	if(set == NULL)
	{
		Set *newset = malloc(sizeof(Set));
		newset->next = NULL;
		newset->data = data;
		return newset;
	}
	Set *pos = NULL;
	Set *prevPtr = NULL;
	Set *nextPtr = set->next;
	Set *currPtr = set;
	//iterate through all to find dupes
	while(nextPtr != NULL)
	{
		prevPtr = currPtr;
		currPtr = nextPtr; 
		nextPtr = currPtr->next;
		//dupe found
		if(currPtr->data == data)
			return set; //return original head
	}
	//no dupes insert @ head
	Set *newset = malloc(sizeof(Set));
	newset->data = data;
	newset->next = set; 
}



Set* set_remove(Set* set, int data) {
	//check for null ptr
	assert(set != NULL);
	//ptr to next set
	Set *nextsetPtr = set->next;
	if(set->data == data)
	{
		//remove head of set
		free_set(set);
		return nextsetPtr;
	}
	else
	{
		if(nextsetPtr->data == data)
		{
			set->next = nextsetPtr->next;
			free_set(nextsetPtr);
			return set; 
		}
		else
			return set_remove(nextsetPtr, data);
	
	}
}

Set* set_intersection(Set* first, Set* second) {
	Set *intersection_head = NULL;
	while(first!=NULL)
	{
		while(second!=NULL)
		{
			if(first->data==second->data)
				intersection_head = set_insert(intersection_head, first->data); 
				
			
		}
	}
	return intersection_head;
}

void print_set(Set* list) {
	do {

		printf("%d -> ", list->data);
		list = list->next; 
	}while(list != NULL);
	printf("NULL\n");
}

void free_set(Set* list) {
	free(list);
}


