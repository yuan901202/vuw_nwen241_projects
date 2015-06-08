//NWEN 241 C_Assignment 2 - q2
//Program description: swaps the values between x[i] and x[SIZE-1-i]
//Author: Tianfu Yuan
//ID: 300228072

#include <stdio.h>
#define SIZE 10 

void v_exchange(int a[]); 

int main(void) 
{ 
    int i, x[SIZE]; /* x[] has 10 int elements */

    for (i=0; i<SIZE; i++) 
	x[i] = i; /* assign i to x[i] */
    v_exchange(x); /* call for value exchange */

    for (i=0; i<SIZE; i++) 
	printf("x[%d]=%d, &x[%d]=%x\n", i, x[i], i, &x[i]); 

    return 0; 
} 

void v_exchange(int a[])
{
    int i, temp;
    
    for(i = 0; i < (SIZE / 2); i++){
	temp = *(a + i);
	*(a + i) = *(a + SIZE - 1 - i); /* the value stored at the addresses of x[i], x[SIZE-1-i] */
	*(a + SIZE - i) = temp; 	/* are swapped */
    }
}