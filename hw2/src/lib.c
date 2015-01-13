#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "lib.h"

//Parameters:
//fName : The first name of a passenger
//lName : The last name of a passenger
//origin: A passengers origin
//dest  : A passengers destination
//
//Return: A seat struct populated with the specified information
//
//Each of the strings malloced inside of the struct should be the exact size
//of the string that it holds. So, if a passengers first name is Seth then 
//seat->fName should point to exactly 5 characters; one for each letter in
//the name plus the null terminater. 
//
Seat* create_seat(char* fName, char* lName, char* origin, char* dest, int num) {
	//allocate memory for structure
	Seat *newseat = malloc(sizeof(Seat));	
	//make sure malloc didn't return null ptr
	assert(newseat != NULL); 
	//fill each member w/ data and allocate memory 
	//strdup calls malloc
	newseat->fName = strdup(fName);
	newseat->lName = strdup(lName);
	newseat->origin = strdup(origin);
	newseat->destination = strdup(dest);
	newseat->seatNumber = num;
	//do not link node (yet) -- use check_in() 
	newseat->next = NULL; 
	//return ptr to new seat
	return newseat; 
}

//Parameters:
//seat : A double pointer to a seat struct
//
//Return : Nothing
//
//This function should properly free all the memory inside of a seat and
//set the seat equal to NULL so it may not be referenced by other 
//functions
void empty_seat(Seat** seat) {
	//chck for null ptr
	assert(seat != NULL);
	//free memory allocated by strdup for strings
	free((*seat)->fName);
	free((*seat)->lName);
	free((*seat)->origin);
	free((*seat)->destination);
	//free memory alloc'd for struct (ptrs and int)
	free(*seat);	
	//set ptr to point to NULL
	*seat = NULL; 
}

//Parameters: 
//plane : the head of a linked list
//seat  : a pointer to a seat
//
//Return: The possibly updated head of the linked list
//
//This function should insert the seat into the plane list in sorted order
//by seat number recursively 
Seat* check_in(Seat* plane, Seat* seat) {
	if(plane == NULL)
		return seat;
	if(plane->seatNumber < seat->seatNumber)
	{
		//insert @ head
		seat->next = plane;
		return seat;
	}
	//else iterate list
	return check_in(plane->next, seat);
}

//Parameters:
//plane : the head of a linked list
//location: the current location of the plane
//
//Return : The possibly updated head of the plane list
//
//This method should recursively remove each seat from the plane
//that has the current location as its destination and pass it to 
//empty seat
Seat* land(Seat* plane, char* location) {
	if(plane != NULL)
	{
		land(plane->next, location);
		if(strcmp(plane->destination,location)==0)
		{
			printf("%s %s got off the plane in %s\n", plane->fName, plane->lName, location);
			Seat *nextSeat = plane->next;
			empty_seat(&plane);
		}
		
	}
	return NULL;
}






