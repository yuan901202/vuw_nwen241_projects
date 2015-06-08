//NWEN 241 C_Assignment 1 - q4
//Program name: prints the echelon of "*" pattern
//Author: Tianfu Yuan
//ID: 300228072

#include<stdio.h>

int main(void){
  int row; /* row counter */
  int col; /* column counter */
  
  //print out 4 rows of "*"
  for(row = 1; row < 5; row++){
      //print out the "*"
      for(col = 1; col <= row; col++){
	  printf("*");
      }
      printf("\n");
  }
  
  return 0;
}
