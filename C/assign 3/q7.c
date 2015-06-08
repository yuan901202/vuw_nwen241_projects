//NWEN 241 C_Assignment 3 - q7
//Program description: Swap the values between ptrp and ptrq.
//Author: Tianfu Yuan
//Username: yuantian
//ID: 300228072

#include <stdio.h>

int main(void)
{ 
	int p = 11, q = 22;
	int *ptrp = &p, *ptrq = &q;
	int **ppp = &ptrp, **ppq = &ptrq;
	swap_ptr(ppp,ppq); /* &ptrp, &ptrq passed */
			/* to swap_ptr() */
	return 0;
}

void swap_ptr(int **pp, int **pq)
{
	int *tmp;
	tmp = *pp; 
	*pp = *pq;
	*pq = tmp; /* the value stored at &ptrp and &ptrq are swapped */
}