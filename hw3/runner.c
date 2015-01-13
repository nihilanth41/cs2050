//Zachary Rump
//12337948/ZRRM74
//Lab E
//HW3 
//11/21/2014
//RUNNER.C
//
//
#include <stdio.h>
#include <string.h>
#include "calculator.h"

#define BUFFERSIZE 100

int main(int argc, char* argv[]) {
	//check input args	
	if (argc < 2) 
	{
        	printf("Error: not enough arguments\nUsage: %s <input file>\n", argv[0]);
        	return -1;	
	}
    	//open file
	FILE* fp = fopen(argv[1], "r");
	if(fp == NULL) {
        printf("unable to open file: %s\n", argv[1]);
        return -1;
    }
    //buff to hold str expressions
    char buffer[BUFFERSIZE];
    //for each line in file
    while(fgets(buffer, BUFFERSIZE, fp)) 
    {
        if (buffer[strlen(buffer)-1] == '\n') 
		buffer[strlen(buffer)-1] = '\0'; //change newline to nul terminator
        //convert to postfix notation
        char *postfix = to_postfix(buffer);
	//evaluate postfix notation
        int result = eval(postfix);
	//print integer result
        printf("%s = %d\n", buffer, result);
    }
    //close file
    fclose(fp);
    return 0;
}
