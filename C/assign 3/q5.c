//NWEN 241 C_Assignment 3 - q5
//Program description: Allow user to enter two dates and then indicates which date comes earlier.
//Author: Tianfu Yuan
//Username: yuantian
//ID: 300228072

#include <stdio.h>
/* Note: Program assumes years are in the same century. */
struct date {
	int month, day, year;
};

int compare_dates(struct date d1, struct date d2);
void put_date(struct date d);

int main(void)
{
	struct date d1, d2;
	printf("Enter first date (mm/dd/yy): ");
	/* for you to complete */
	scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);
	
	printf("Enter second date (mm/dd/yy): ");
	/* for you to complete */
	scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);
	
	if (compare_dates(d1, d2) < 0) {
		put_date(d1);
		printf(" is earlier than ");
		put_date(d2);
		printf("\n");
	} else {
		put_date(d2);
		printf(" is earlier than ");
		put_date(d1);
		printf("\n");
	}
	return 0;
}

int compare_dates(struct date d1, struct date d2)
{
	/* for you to complete */
	if (d1.year < d2.year){
	    return -1;
	}
	
	else if (d1.year > d2.year){
	    return 1;
	}
    
	if (d1.year == d2.year){
	    if (d1.month < d2.month){
		return -1;
	    }
	    else if (d1.month > d2.month){
		return 1;
	    }
	    else if (d1.day < d2.day){
		return -1;
	    }
	    else if(d1.day > d2.day){
		return 1;
	    }
	    else{
		return 0;
	    }
	}
}

void put_date(struct date d)
{
	printf("%d/%d/%.2d", d.month, d.day, d.year);
}