//NWEN 241 C_Lab Q1
//Program description: Infix-to-Postfix Converter
//Author: Tianfu Yuan
//Username: yuantian
//ID: 300228072

#include <stdio.h>
#include <stdlib.h> /* malloc */
#include <string.h> /* strlen bug fixed */

#define Node_Size sizeof(StackNode)

struct snpckNode
{
    char data;
    struct snpckNode *nextPtr;
};
typedef struct snpckNode StackNode;
typedef StackNode *StackNodePtr;

void convertToPostfix( char infix[], char postfix[] ); /* Convert the infix expression to postfix notation */
int isOperator( char c ); /* Determine if c is an operator */
int precedence( char operator1, char operator2 ); /* Determine if the precedence of operator1 is less than, equal to, or greater than
						      the precedence of operator2. The function returns -1, 0 and 1, respectively */
void push( StackNodePtr *topPtr, char value ); /* Push a value on the snpck */
char pop( StackNodePtr *topPtr ); /* Pop a value off the snpck */
char snpckTop( StackNodePtr topPtr ); /* Return the top value of the snpck without popping the snpck */
int isEmpty( StackNodePtr topPtr ); /* Determine if the snpck is empty */
void printStack( StackNodePtr topPtr ); /* Print the snpck */

int postfixIndex; /* Index of postfix */

int main(void)
{
    char infix[1024]; //create an array, read the expression into character array infix
    char postfix[1024]; //create an array, put the expression into character array postfix
    
    int i, j = 0;
    
    //ask user to input the infix
    printf("Enter the infix expression: \n");
    scanf("%s", infix);
    
    printf("The original infix expression is: \n");
    while(infix[i] != '\0')
    {
		printf("%c",infix[i]);
		i++;
    }
    printf("\n");
    
    convertToPostfix(infix, postfix); //calling method to convert infix to postfix
    
    //printout the postfix
    printf("The expression in postfix notation is: \n");
    
    for(j = 0; j < postfixIndex; j++)
    {
		printf("%c", postfix[j]);
    }
    printf("\n");
    
    return 0;
}

//Convert the infix expression to postfix notation.
void convertToPostfix( char infix[], char postfix[] )
{
    StackNodePtr snp = NULL;
    int length = strlen(infix);
    //int length = sizeof(infix);
    int i = 0;
    postfixIndex = 0;

    push(&snp, '('); //Push a left parenthesis '(' onto the stack                         
    printStack(snp);
    infix[length] = ')'; //Append a right parenthesis ')' to the end of infix                       

    //While the stack is not empty, read infix from left to right and do the following
    while(isEmpty(snp) == 0)                           
    {	
		//If the current character in infix is a digit, copy it to the next element of postfix
		if(isdigit(infix[i]))                 
		{
	    	postfix[postfixIndex] = infix[i];
	    	postfixIndex++;
	    	i++;
		}
	
		//If the current character in infix is a left parenthesis, push it onto the stack
		else if(infix[i] == '(')              
		{
	    	push(&snp, infix[i]);
	    	printStack(snp);
	    	i++;
		}
	
		//If the current character in infix is an operator
		else if(isOperator(infix[i]))          
		{
	  
	    	//Pop operators (if there are any) at the top of the stack while they have equal or
	    	//higher precedence than the current operator, and insert the popped operators in postfix
	    	if(isOperator(snpckTop(snp)))
	    	{
				while(precedence(snpckTop(snp), infix[i]) >=0) 
				{
		    		if(isOperator(snpckTop(snp)))
		    		{
						char temp = pop(&snp);
						printStack(snp);
						postfix[postfixIndex] = temp;
						postfixIndex++;
		    		}
		    		else
		    		{
						break;                                   
		    		}
				}
				push(&snp, infix[i]);              
				printStack(snp);
				i++;
	    	}
	    
	    	//Push the current character in infix onto the stack
	    	else
	    	{
				push(&snp, infix[i]);
				printStack(snp);
				i++;
	    	}
		}
    
		//If the current character in infix is a right parenthesis
		else if(infix[i] == ')')                 
		{
	    	//Pop operators from the top of the stack and insert them in postfix until a left
	    	//parenthesis is at the top of the stack
	    	while(snpckTop(snp) != '(')                 
	   		{
				char ts = pop(&snp);
				printStack(snp);
				postfix[postfixIndex] = ts;
				postfixIndex++;
	    	}
	    	pop(&snp); //Pop (and discard) the left parenthesis from the stack                   
	    	printStack(snp);
	    	i++;
		}
    }
}

//Determine if c is an operator.
int isOperator( char c )
{
    switch(c)
    {
        case '+':
	    	return 1;
        
		case '-':
	    	return 1;
        
		case '*':
	    	return 1;
        
		case '/':
	    	return 1;
        
		case'^':
	    	return 1;
        
		case '%':
	    	return 1;
        
		default:
	    	return 0;
    }
}

//Determine if the precedence of operator1 is less than, equal to, or greater than
//the precedence of operator2. The function returns -1, 0 and 1, respectively.
int precedence( char operator1, char operator2 )
{
    if(operator1 == '+' || operator1 == '-')
    {
		if(operator2 == '+' || operator2 == '-')
		{
	    	return 0;
		}
		else if(operator2 == '*' || operator2 == '/' || operator2 == '%' || operator2 == '^')
		{
	    	return -1;
		}
    }
  
    else if(operator1 == '*' || operator1 == '/' || operator1 == '%')
    {
		if(operator2 == '+' || operator2 == '-')
		{
	    	return 1;
		}
		else if(operator2 == '*' || operator2 == '/' || operator2 == '%')
		{
	    	return 0;
		}
		else if(operator2 == '^')
		{
	    	return -1;
		}
    }
  
    else if(operator1 == '^')
    {
		if(operator2 == '+' || operator2 == '-')
		{
	    	return 1;
		}
		else if(operator2 == '*' || operator2 == '/' || operator2 == '%')
		{
	    	return 1;
		}
		else if(operator2 == '^')
		{
	    	return 0;
		}
    }
}

//Push a value on the snpck.
void push( StackNodePtr *topPtr, char value )
{
    StackNodePtr snp = malloc(Node_Size);

    if(snp != NULL)
    {
		snp->data = value;
		snp->nextPtr = *topPtr;
		*topPtr = snp;
    }
}

//Pop a value off the snpck.
char pop( StackNodePtr *topPtr )
{
    char c;
    StackNodePtr temp;

    temp = *topPtr;
    c = temp->data;
    *topPtr = temp->nextPtr;
    free(temp);

    return c;
}

//Return the top value of the snpck without popping the snpck.
char snpckTop( StackNodePtr topPtr )
{
    if(isEmpty(topPtr) == 0){
		return topPtr->data;
    }
}

//Determine if the snpck is empty.
int isEmpty( StackNodePtr topPtr )
{
    if(topPtr == NULL){
		return 1;
    }
    
    else
    {
		return 0;
    }
}

//Print the snpck.
void printStack( StackNodePtr topPtr )
{
    if(topPtr == NULL)
    {
		printf("The stack is empty. \n");
    }
    
    else
    {
		while(topPtr != NULL)
		{
	    	printf("%c     ", topPtr->data);
	    	topPtr = topPtr->nextPtr;
		}
		printf("NULL \n");
    }
}