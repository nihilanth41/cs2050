//Zachary Rump
//ZRRM74
//Lab Code: LAST LAB
//LAB E
//12/5/2014
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

#define MAX_LINE 250 

int main(int argc, char **argv) {
	//check for input args
	if(argc<2) 
	{
		printf("Error: not enough arguments. Usage is %s <filename>\n", argv[0]);
		return -1;
	}
	//open file
	FILE *fp = fopen(argv[1], "r");
	//check if open is successful
	if(fp == NULL)
	{
		printf("Error opening file.\n");
		return -1;
	}

	//buffer to store lines from input file
	char buf[MAX_LINE];
	//for each line in file add to buf and null terminate 
	int numTokens = 0;
while(fgets(buf, MAX_LINE, fp) != NULL)
{
		//printf("%s", buf);
		//strip newline from buf
		if(buf[(strlen(buf)-1)] == '\n')
		{
			buf[strlen(buf)-1] = '\0'; //replace w/ null terminator
		}
	

	char *token = "";
	char *fname = "";
	//use strtok to parse individual words from the line
	token = strtok(buf, " \n\r\t"); //first call to strtok sets input buf 
	int isName = 0;
	while(token != NULL)
	{		
			//count tokens
			numTokens++;
			//printf("token: %s\n", token);
			//function call logic
			//check for phone #
			if(is_phone_number(token))
			{
				printf("Phone Number: %s\n", token);
			}
			//check for date
			else if(is_date(token))
			{
				printf("Date: %s\n", token);
			}
			//check for e-mail
			else if(is_email(token))
			{
				printf("E-mail: %s\n", token);
			}
			//check for name
			else if(looks_like_name(token))
			{
				if(isName) //previous token was name
				{
					//two names found
					printf("Name: %s %s\n", fname, token); 
					isName = 0; //reset
				}
				else //set flag
				{
					//record name
					fname = strdup(token);
					isName = 1;
				}
				
			}
			else
			{
				//doesn't look like name
				isName = 0; 
			}
			token = strtok(NULL, " \n\r\t"); //call strtok w/ NULL to get next token  
	}
}
	printf("There are %d words in the file\n", numTokens);
	fclose(fp);
	return 0;
}
