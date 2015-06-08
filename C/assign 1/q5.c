//NWEN 241 C_Assignment 1 - q5
//Program name: counts and prints the number of each different letter grade user entered
//Author: Tianfu Yuan
//ID: 300228072

#include<stdio.h>

int main(void){
  int grade; /* current grade. You can also use char grade.
		You may use either getchar or scanf to handle the input.
	     */
  int aCount = 0; /* total a grades */
  int bCount = 0; /* total b grades */
  int cCount = 0; /* total c grades */
  int dCount = 0; /* total d grades */
  int eCount = 0; /* total e grades */
  
  //ask user to enter the grades
  printf("Enter the grades (A, B, C, D, E): \n");
  printf("Press \"Ctrl + D\" to finish the reading. \n");
  
  //when user press "Ctrl+D" will stop the read
  while((grade = getchar()) != EOF){
      switch(grade){
	case'A':
	   aCount++;
	   break;
	
	case'B':
	   bCount++;
	   break;
	  
	case'C':
	   cCount++;
	   break;
	  
	case'D':
	   dCount++;
	   break;
	  
	case'E':
	   eCount++;
	   break;
	
	//user can have "new line", "tab" or "space" when they enter the grades
	case'\n':
	case'\t':
	case' ':
	   break;
	
	//if user enter invalid grade, return the message
	default:
	   printf("Invalid grade! \n");
	   break;
      }
  }
  
  //print out the summary of grades that user entered
  printf("Summary of grades that you entered: \n");
  printf("A: %d \n", aCount);
  printf("B: %d \n", bCount);
  printf("C: %d \n", cCount);
  printf("D: %d \n", dCount);
  printf("E: %d \n", eCount);
  
  return 0;
}
