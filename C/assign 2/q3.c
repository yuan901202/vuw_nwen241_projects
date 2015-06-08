//NWEN 241 C_Assignment 2 - q3
//Program description: compare two strings, element by element, for equality
//Author: Tianfu Yuan
//ID: 300228072 

#include <stdio.h>

int stringcmp( const char *s1, const char *s2 ); /* prototype */

int main(void) 
{ 
    char string1[ 80 ]; /* create a string */
    char string2[ 80 ]; /* create another string */
 
    printf( "Enter two strings: " ); 
    scanf( "%s%s", string1 , string2 ); 
    printf( "The result is %d\n", stringcmp( string1, string2 ) ); 

    return 0; 
}

int stringcmp( const char *s1, const char *s2 )
{
    for( ; *s1 == *s2; s1++, s2++){
	if(*s1 == '\0'){
	    return 1;
	}
    }
    
    return 0;
}