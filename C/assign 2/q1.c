//NWEN 241 C_Assignment 2 - q1
//Program description: Write three functions sum1, sum2, sum3 to sum up the integers between from 				and to (including from and to), using recursion, iteration and algorithm, 				respectively.
//Author: Tianfu Yuan
//ID: 300228072

#include <time.h>
#include <stdio.h>

unsigned int sum1(unsigned int from, unsigned int to); /* recursion */ 
unsigned int sum2(unsigned int from, unsigned int to); /* iteration */ 
unsigned int sum3(unsigned int from, unsigned int to); /* algorithm */ 
/* algorithm: sum(1..n) = n*(n+1)/2, sum(m..n) = sum(1..n) - sum(1..m-1) */

int main(void) 
{ 
    unsigned int s; 
    unsigned from, to; 
    double t1, t2; 
    
    printf("Enter the fist integer:"); 
    scanf("%d", &from); 
    printf("Enter the second integer:"); 
    scanf("%d", &to); 
 
    t1 = clock(); 
    s = sum1(from, to); 
    t2 = clock();
    printf("sum1=%d, %fseconds.\n", s, (t2-t1)/CLOCKS_PER_SEC);
 
    t1 = clock();
    s = sum2(from, to); 
    t2 = clock(); 
    printf("sum2=%d, %fseconds.\n", s, (t2-t1)/CLOCKS_PER_SEC);
 
    t1 = clock(); 
    s = sum3(from, to); 
    t2 = clock(); 
    printf("sum3=%d, %fseconds.\n", s, (t2-t1)/CLOCKS_PER_SEC); 

    return 0; 
} 

//recursion
unsigned int sum1(unsigned int from, unsigned int to)
{
    if(from == to){
	return from;
    }
    
    unsigned int a = (from + to) / 2;
    return sum1(from, a) + sum1(a + 1, to);
}

//iteration
unsigned int sum2(unsigned int from, unsigned int to)
{
    unsigned int a, result = 0;
    
    for(a = from; a <= to; a++){
	result += a;
    }
    
    return result;
}

//algorithm
unsigned int sum3(unsigned int from, unsigned int to)
{
    unsigned int result = (to * (to + 1)) / 2;
    
    if(from > 1){
	result -= (from * (from - 1)) / 2;
    }
    
    return result;
}