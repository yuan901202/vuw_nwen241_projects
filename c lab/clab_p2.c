//NWEN 241 C_Lab Q2
//Program description: Postfix Evaluator
//Author: Tianfu Yuan
//Username: yuantian
//ID: 300228072

#include <stdio.h>
#include <stdlib.h> /* malloc */
#include <string.h> /* strlen bug fixed */

#define Node_Size sizeof(StackNode)

struct snpckNode 
{
    int data;
    struct snpckNode *nextPtr;
};
typedef struct snpckNode StackNode;
typedef StackNode *StackNodePtr;

int evaluatePostfixExpression( char *expr ); /* Evaluate the postfix expression */
int calculate( int op1, int op2, char operator ); /* Evaluate the expression op1 operator op2 */
void push( StackNodePtr *topPtr, int value ); /* Push a value on the snpck */
int pop( StackNodePtr *topPtr ); /* Pop a value off the snpck */
int isEmpty( StackNodePtr topPtr ); /* Determine if the snpck is empty */
void printStack( StackNodePtr topPtr ); /* Print the snpck */

int main(void)
{
    char postfix[1024];

    printf("Enter a postfix expression:\n");
    scanf("%s", postfix);

    int length;
    length = strlen(postfix);
    postfix[length] = '\0'; //Append the null character ('\0') to the end of the postfix expression                                                          

    printf("The value of the expression is: %d", evaluatePostfixExpression(postfix)); //evaluate it
    printf("\n");
}

//Evaluate the postfix expression
int evaluatePostfixExpression( char *expr )                                             
{
    StackNodePtr snp = NULL;
    int i;
    
    //While '\0' has not been encountered, read the expression from left to right
    for (i = 0; expr[i] != '\0'; i++)                                                        
    {
		//If the current character is a digit
		if (isdigit(expr[i]))                                                               
		{
	    	push(&snp, (expr[i] - '0')); //Push its integer value onto the stack (the integer value of a digit character is its
					 					 //value in the computer's character set minus the value of '0' in the computer's character set)
	    	printStack(snp);
		}
	
		//if the current character is an operator
		else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^' || expr[i] == '%')            
		{
	    	//Pop the two top elements of the stack into variables x and y
	    	//Push the result of the calculation onto the stack
	    	int x = pop(&snp);                                                                                                           
	    	printStack(snp);
      
	    	int y = pop(&snp);
	    	printStack(snp);
	    
	    	int result = calculate(y, x, expr[i]); //Calculate y operator x.                                                                           
	    	push(&snp, result);                                                                                                         
	    	printStack(snp);
		}
    }
    return pop(&snp);                                                                                                   
}

//Evaluate the expression op1 operator op2
int calculate( int op1, int op2, char operator )                   
{
    int result;
    
    if (operator == '+')
    {
		result = op1 + op2;
		return result;
    }
  
    else if (operator == '-')
    {
		result = op1 - op2;
		return result;
    }
  
    else if (operator == '*')
    {
		result = op1 * op2;
		return result;
    }
  
    else if (operator == '/')
    {
		result = op1 / op2;
		return result;
    }
    
    else if (operator == '^')
    {
		int result = 1;
		int base = op1; //set op1 as base
		int power = op2; // set op2 as power
    
		while(power != 0)
		{
	    	result *= base;
	    	--power;
		}
		return result;
    }
  
    else if (operator == '%')
    {
		result = op1 % op2;
		return result;
    }
}

//Push a value on the stack
void push( StackNodePtr *topPtr, int value )                                               
{
    StackNodePtr snp = malloc(Node_Size);

    if (snp != NULL)
    {
		snp->data = value;
		snp->nextPtr = *topPtr;
		*topPtr = snp;
    }
}

//Pop a value off the stack
int pop( StackNodePtr *topPtr )                                                             
{
    int value;
    StackNodePtr temp;

    temp = *topPtr;
    value = temp->data;
    *topPtr = temp->nextPtr;
    free(temp);

    return value;
}

//Determine if the stack is empty
int isEmpty( StackNodePtr topPtr )                                                          
{
    if (topPtr->nextPtr == NULL)
    {
		return 1;                    
    }
    else
    {
		return 0;                     
    }
}

//Print the stack
void printStack( StackNodePtr topPtr )                                                     
{
    if (topPtr == NULL)
    {
		printf("NULL \n");
    }
    else
    {
		while (topPtr != NULL)
		{
	    	printf("%d     ", topPtr->data);
	    	topPtr = topPtr->nextPtr;
		}
		printf("NULL \n");
    }
}