//NWEN 241 C_Assignment 1 - q3
//Program name: finds the smallest of several integers entered by user
//Author: Tianfu Yuan
//ID: 300228072

#include<stdio.h>

int main(void){
  int number; /* number of integers to be entered */
  int value; /* value input by user */
  int smallest; /* smallest number */
  int i; /* counter */
  
  //ask user to enter a number that how many intergers want to process
  printf("Please enter the number of intergers that you want to calculate: ");
  scanf("%d", &number);
  
  //ask user to input the interger
  printf("Enter an interger: ");
  scanf("%d", &smallest);
  
  //ask user to input the interger until all intergers entered
  for(i = 2; i <= number; i++){
      printf("Enter an interger: ");
      scanf("%d", &value);
      
      //find the smallest interger
      if(value < smallest){
	  smallest = value;
      }
  }
   
  //print out the smallest interger
  printf("The smallest interger is: %d \n", smallest);
  
  return 0;
}
