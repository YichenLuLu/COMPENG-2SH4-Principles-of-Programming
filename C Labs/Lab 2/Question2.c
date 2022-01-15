#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag=0;
	 for (int row = 0; row < N2; row++){
		 int sumOfRow = 0;
		 for (int col = 0; col < N2; col++){
			 if(row != col){
				 sumOfRow = sumOfRow + fabs(mat[row][col]);
			 }
	   }
		 if (fabs(mat[row][row]) < sumOfRow)
			 return 0;
	 }

	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise
    return 1;
	


    return isDiag;
}
