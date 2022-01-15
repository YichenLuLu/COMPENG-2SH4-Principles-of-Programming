
#include "Questions.h"



int Q1_for(){
	// calculate your sum below..this has to use for loop
	int sum = 0;

    for(int i = 30; i <= 1000; i++){
    	if (i % 4 == 0) {
    		sum += i;
    	}
    }
	
	// here, we return the calcualted sum:
	return sum;
}

int Q1_while(){
	// calculate your sum below..this has to use while loop
	int sum = 0;
	int i = 30;
	while(i <= 1000){
		if(i % 4 == 0){
			sum += i;
		}
		i++;
	}

    // here, we return the calcualted sum:
	return sum;
}

int Q1_do(){
	// calculate your sum below..this has to use do-while loop
	int sum = 0;
	int i = 30;
	do{
		if(i % 4 == 0){
			sum += i;
		}
		i++;
	}while (i <= 1000);
	
	// here, we return the calcualted sum:
	return sum;
}

//===============================================================================================
int Q2(int Q2_input){

	// this is the flag that is holding whether the input number is 5-digit or not
	// Do your coding below to check
	int IsFiveDigit = 0;
	int count = 0;
    Q2_input = abs(Q2_input);

	while (Q2_input >= 1) {
		Q2_input /= 10;
		count++;
	}
	
	if(count == 5)
		IsFiveDigit = 1;
	else
		IsFiveDigit = 0;
	
	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}

//=======================================G========================================================
int Q3(float Q3_input){
	
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and prints:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program should print a message to signal an invalid input.
*/	
	// this is the varaible that holds the out value to return
	float GPA;
	
	
	// Do your coding below to calculate the GPA variable value
	if(Q3_input>=90 && Q3_input<=100)
		GPA = 4;
	else if(Q3_input>=80 && Q3_input<=89)
		GPA = 3;
	else if(Q3_input>=70 && Q3_input<=79)
	    GPA = 2;
	else if(Q3_input>=60 && Q3_input<=69)
		GPA = 1;
	else if(Q3_input>=0 && Q3_input<=59)
		GPA = 0;
	else
		GPA = -1;
	
	// finally, we return the GPA
	return GPA;	
}

//===============================================================================================
double Q4(int Q4_input){
	
	// this is the varaible that holds the pi value to return


	double pi=4.0;

	int sign = 1; // 0 for plus, 1 for minus
	int base = 3.0;
	// Do your coding below to calculate the pi value
	for (int i = 1; i < Q4_input; i++) {
		if (sign) {
			pi -= 4.0 / base;
		} else {
			pi += 4.0 / base;
		}
		sign = !sign;
		base += 2;
	}
	if (Q4_input <= 0) {
		return 0;
	}

	   
	// finally, we return the pi value
	return pi;	
}
//===============================================================================================
int Q5(){
	
	// this is the varaible that holds and the total number of triples to return at the end of the function
	int totNumTribles=0;
	
	
	/* Do your coding below
		Use a triple-nested for loop that simply tries all possibilities
		print each triple on a separate line, 
		and update the total number of triples if needed
	*/
	for (int a = 1; a <= 400; a++) {
		for (int b = 1; b <= 400; b++) {
			for (int c = 1; c <= 400; c++) {
				if (b <= a) {
					int sumSquareLeft = (a*a) + (b*b);
					int squareRight = (c*c);
					if (sumSquareLeft == squareRight) {
						totNumTribles++;
						printf("A trible found: side1=%d, side2=%d, side3=%d\n",a,b,c);
					}
				}
			}
		}
	}


	//this is the format that you MUST print the found tribles..uncomment this line and fill in the missings to get it working correctly
	//printf("A trible found: side1=%d, side2=%d, side3=%d\n", ...)
	
	//finally you should return the total number of tribles.
	return totNumTribles;
}
//===============================================================================================
int isPerfect(int input) {
	int sum = 0;
	for (int i = 1; i < input ; i++) {
		if (input % i == 0) {
			sum += i;
		}
	}
	if (input == sum) {
		return 1;
	} else {
		return 0;
	}
}

int Q6(int Q6_input, int perfect[]){
	
	
	
		//counts is the variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts=0;

		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*autmoatically reflect in the main calling function.
		*/

		int index = 0;
	    
		for (int i = 1; i < Q6_input; i++) {
			if (isPerfect(i)) {
				counts++;
				perfect[index] = i;
				index++;
			}
		}

	return counts;

}

//===============================================================================================
int Q7a(int Q7_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer

	do {
	    reversedInt *= 10;
	    reversedInt += Q7_input % 10;
	    Q7_input /= 10;
	} while (Q7_input > 0);
	
	return reversedInt;
}

int Q7b(int Q7b_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits
	
	do {
	    reversedInt *= 10;
	    reversedInt += Q7b_input % 10;
	    Q7b_input /= 10;
	} while (Q7b_input > 0);
	
	return reversedInt;
}
