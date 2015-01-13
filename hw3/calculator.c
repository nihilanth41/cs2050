#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

#define MAX_EQU_LEN 100


/**
 * Param: operator - a character
 *
 * Return: A number corresponding to the arithmetic precedence 
 *         of the character. 
 *         Multiplication:  * => 5
 *         Division:        / => 4
 *         Modulus:         % => 3
 *         Addition:        + => 2
 *         Subtration:      - => 1
 *         NonOperator           0
 */
static char prec(char operator) {
	if(operator == '*')
		return 5;
	if(operator == '/')
		return 4;
	if(operator == '%')
		return 3;
	if(operator == '+')
		return 2;
	if(operator == '-')
		return 1;
	else
		return 0;
}

/**
 * Param: num - A string
 *
 * Return: 1 if the string contains only contains numbers
 *         0 otherwise
 */
static int isNumeric(char *num) {
	while(*num)
	{	
		//isdigit returns 0 if char is non-numeric (ctype.h) 
		if(!isdigit(*num))
			return 0;
		
		//iterate string
			num++;
	}
	return 1;
}

/**
 * Param: infix - A valid infix expression
 *
 * Return: The corresponding postfix expression
 *
 * To convert an expression from infix to postfix, 
 * use the following algorithm
 *
 * create an empty string called postfix
 * create an empty stack
 *
 * for each token in the string
 *      if the token is a number
 *          append it to the postfix string
 *      else if the token is a left paren
 *          push it onto the stack
 *      else if the next token is an operator (+, -, *, /, %)
 *          while the stack is not empty and the operator at the top of the stack has higher precedence than the token
 *              pop the top element off of the stack and append it to the postfix string
 *          push the current token onto the stack
 *      else if the next token is a right paren
 *          while the stack is not empty and the corresponding left paren is not at the top of the stack
 *              pop the next operator off of the stack
 *              append it to the postfix string
 * while there are elements remaining on the stack
 *      pop the top element off of the stack
 *      append it to the postfix string
 *
 * return the postfix string
 *
 *
 * Hint: Put spaces between numbers and operators so 
 *       that you can use strtok in eval 
 */


//NOTE: I spent a lot of time on this function and go nowhere with it. 
//At one point I found a different implementation and tried to use it as a template 
//and I ran out of time and didn't really get a chance to fix it or change it back
//hoping to get some feedback or maybe an example of how this function should look when used in conjunction with eval()
char* to_postfix(char* infix) {
	//empty postfix string 
	char postfix[MAX_EQU_LEN] = { 0 };
	//ptr to infix str
	char *i = infix;
	//ptr to postfix str
	char *p = postfix;
	//empty stack
	stack *s = create_stack();
	//for each char in str
	while(i != NULL)
	{
		printf("infix: %s\n", infix);
		printf("postfix: %s\n", postfix);
		//if infix consists of only numbers 
		if(isNumeric(i))
		{
			while(isNumeric(i))
			{
				//append number(s) to postfix string 
				 *p = *i; 
				//increment position in both strings
				p++; 
				i++;
				//add space after number(s)
				*p = ' ';
				p++;
			}
		}
	
		//check for left paren
		if(*i == '(')
		{
			//push left paren onto stack 
			push(s, *i);
			//increment infix str
			i++;
		}
		
		//if NEXT token is operator
		if(prec(*(i+1)) > 0)
		//if(prec(*i)>0)
		{
			//while stack is not empty
			while(!isEmpty(s))
			{
			
				//while operator on top of stack has higher precedence than token
				while(prec(top(s)) > prec(*i))
				{
					//pop top element off stack and append to postfix string
					*p = top(s);	
					p++; 
					pop(s);
					//insert space between operators
					*p = ' ';
					p++;
				}
			}
			//push current token onto stack
			push(s, *i);
			i++;
		}

		//if NEXT token is right paren
		if(*(i+1) == ')')
		//if(*i == ')')
		{
			//while stack is not empty
			while(!isEmpty(s))
			{
				//while left paren is not at top of stack
				while(top(s) != '(')
				{
					//pop NEXT operator off of stack and append to postfix str
					*p = top(s);
					p++;
					pop(s);
					//insert space after operator
					*p = ' ';
					p++;
				}
			
			}
		}
		
		//while infix str is space or tab, increment
		while(*i == ' ' || *i == '\t')
		{
			i++;
		}
	
	} //end WHILE(*infix)
	//while there are elements left on stack
	while(!isEmpty(s))
	{
		//pop top element off and append to postfix string
		*p = top(s);
		pop(s);
		p++;
	}
	*p = '\0';
	return p;	
}

/**
 * Param: postfix - A valid postfix string
 *
 * Return: The value that the expression evaluates to
 *
 *
 * To evaluate a postfix string, use the following algorithm
 *
 * create an empty stack
 *
 * for each token in the string
 *      if the token is numeric
 *          convert it to an integer
 *          push it onto the stack
 *      else
 *          pop the top two elements off of the stack
 *          the first element goes into the right variable
 *          the second goes into the left variable
 *          appy the operation: 
 *              result = left op right
 *              ex: result left + right
 *          push the result onto the stack
 *
 * The final result will be the only element on the stack
 * pop it and return it. 
 */
int eval(char* postfix) {
    stack *s = create_stack();
    int result;

    char* token = strtok(postfix, " \n");
    while(token != NULL) {
        if (isNumeric(token)) {
            push(s, atoi(token));
        } else {
            int x = top(s);
            pop(s);
            int y = top(s);
            pop(s);

            switch(token[0]) {
                case '*':
                    result = y * x;
                    break;
                case '/':
                    result = y / x;
                    break;
                case '%':
                    result = y % x;
                    break;
                case '+':
                    result = y + x;
                    break;
                case '-':
                    result = y - x;
                    break;
            }

            push(s, result);
        }

        token = strtok(NULL, " \n");
    }

    result = top(s);
    pop(s);
    free(s);

    return result;
}

