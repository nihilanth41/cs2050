#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"

int is_phone_number(char *word) {
	if(*word == '(' && *(word+4) == ')')
	{
		if(*(word+5) == '-' && *(word+9) == '-')
		{
			int i;
			for(i=1; i<4; i++)
			{
				if(!isdigit(*(word+i)))
				{
					return 0;
				}
			}
			for(i=6; i<9; i++)
			{
				if(!isdigit(*(word+i)))
				{
					return 0;
				}
			}
			for(i=10; i<14; i++)
			{
				if(!isdigit(*(word+i)))
				{
					return 0;
				}
			}
			return 1;
		}
		return 0;
	}
	else
	{
		return 0;
	}
}

int is_date(char *word) {
	static const int validDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //valid days for each month
	char c, k; 
	c = *(word+2);
	k = *(word+5);
	if(c == '/' && k == '/')
	{
		//turn dashes to null terminators
		*(word+2) = '\0';
		*(word+5) = '\0';
		//get month,day,year in terms of ints
		int month, day, year;
		month = atoi(word);
		day = atoi(word+3);
		year = atoi(word+6);
		//check valid month
		if(month < 1 || month > 12)
		{
			return 0;
		}
		//check valid day
		if(day < 1 || day > validDays[month-1])
		{
			return 0;
		}
		*(word+2) = '/';
		*(word+5) = '/';
		return 1;
	}
	else
	{
		//no dashes
		return 0;
	}
}
	
int looks_like_name(const char *word) {
	//first letter must be capital
	if(isupper(*word))
	{
		//get length of word
		int len = strlen(word);
		int i=0;
		for(i=1; i<len; i++) //dont check /0
		{	//check if each letter after the first is lowercase and a letter
			if(!(islower(*(word+i)) && isalpha(*(word+i))))
			{
				//if not
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

int is_email(char *word) {
	int len = strlen(word);
	int atpos = 0;
	int dotpos = 0;
	int i;
	for(i=0; i<len; i++)
	{
		if(*(word+i) == '@')
		{
			atpos = i;
		}
		if(*(word+i) == '.')
		{
			dotpos = i;
		}
	}
	if(atpos && dotpos)
	{
		for(i=0; i<atpos; i++)
		{
			if(!isalnum(*(word+i)))
			{
				return 0;
			}
		}
		for(i=(atpos+1); i<dotpos; i++)
		{
			if(!isalnum(*(word+i)))
			{
				return 0;
			}
		}
		char *postfix = (word+(dotpos+1));
		if(!strcmp(postfix, "com") || !strcmp(postfix, "edu") || !strcmp(postfix, "gov"))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}


	
	






