#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

//Param string: a string
//Return: 1 if str is a phone number, 0 otherwise
//A phone number is in form (xxx)-xxx-xxxx where x is 0-9

int is_phone(char* string);

int main(void) {
	assert(is_phone("(123)-456-7890") == 1);
	assert(is_phone("(123) 456-7890") == 0);
	assert(is_phone("123-456-7890") == 0);
	assert(is_phone("(123)-45e-7890") == 0);
	assert(is_phone("(123)-456-789") == 0);

	printf("Yay!!\n");

	return 0; 
}

int is_phone(char *string) {
	int x=0;
	//check for parenthesis
	if(*string == '(' && *(string+4) == ')')
	{
		//check # inside parenthesis
		for(x=1; x<4; x++)
		{
			if(!isdigit(*(string+x)))
			{
				return 0;
			}
		}
	}
	//check for dashes
	if(*(string+4) == '-' && *(string+8) == '-')
	{
		//check first 3 numbers after area code
		for(x=6; x<9; x++)
		{
			if(!isdigit(*(string+x)))
			{
				return 0;
			}
		}
		//(123)-678-(10)(11)(12)(13)
		for(x=10; x<14; x++)
		{
			if(!isdigit(*(string+x)))
			{
				return 0;
			}
		}
	}
	return 1;
}
