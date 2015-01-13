//Zach Rump
//ZRRM74
//12337948
//Lab E
//HW2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char* argv[]) {
   if(argc<2)		
   {
	   printf("Not enough arguments\n");
	   printf("Usage: ./runner <file1> ... [file n]\n");
	   return -1;
   }
   Seat *headSeat = NULL;
   //for each input file argument
   int i=0;
   for(i=1; i<argc; i++)
   {
	//check for bad input
	FILE *file = fopen(argv[i], "r");
	if(file == NULL) { 
		perror(argv[i]);
		return EXIT_FAILURE; 
	}
	//dynamic? STR_SIZE?
	char buf[100];
	char *origin = strdup(argv[i]);
	//remove ".txt" from origin str
	origin[strlen(origin)-4] = '\0'; 
	//call land()
	if(!(i==1))
	{	//don't run on first file because no passengers yet
		headSeat = land(headSeat, origin);
	}
	//for each entry in file
	while(fgets(buf, sizeof(buf), file) != NULL) 
	{	
		//how to allocate these dynamically?
		char fName[STRING_SIZE];
		char lName[STRING_SIZE];
		char destination[STRING_SIZE];
		int seatNumber;
		//parse string into variables
		sscanf(buf, "%s %s %s %d", fName, lName, destination, &seatNumber);
		//call create_seat()
		Seat *newSeat = create_seat(fName, lName, origin, destination, seatNumber);
		//print boarding info
		printf("%s %s got on the plane in %s\n", fName, lName, origin);
		//check in new seat (insert into linked list)
	 	headSeat = check_in(headSeat, newSeat);
		
	}
	free(origin);
	fclose(file);
   }
   return EXIT_SUCCESS;
}




