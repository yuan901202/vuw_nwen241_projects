//NWEN 241 C_Assignment 2 - q4
//Program description: count the length of a string
//Author: Tianfu Yuan
//ID: 300228072  

#include <stdio.h>

int stringlen( const char *s ); /* prototype */

int main( void ) 
{ 
    char string[ 80 ]; /* create char array */
 
    printf( "Enter a string: "); 
    scanf( "%[^\n]", string ); 
    printf( "%d\n", stringlen( string ) ); 

    return 0; 
}

int stringlen( const char *s )
{
    int a;
    //looping through  the string
    for(a = 0; *s != '\0'; s++){
	a++;
    }
    
    return a;
}