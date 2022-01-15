#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    /*vector3 should store the sum of vector1 and vector2. 
	You may assume that all three arrays have the size equal to n
	*/
	//write your code below
	 int i;
	   for(i=0;i<size;i++){
	       vector3[i] = vector2[i] + vector1[i];
	   }
	
}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;

	//write your code below to calculate the prod value
	
      int i;
      for(i=0;i<size;i++){
          prod+=vector2[i] * vector1[i];
      }


	
	// return the result
      return prod;
}

double norm2(double vector1[], int size)
{
	//this is the variable holding the L2 norm of the passed vector
    double L2;


	//write your code here
	// you should call function scalar_prod().
    L2 = 0;
    double product = 0;    //initial L2 and product
    product = scalar_prod(vector1,vector1,size); //use the function above
    L2 = sqrt(product); //square root of product



	//finally, return the L2 norm
    return L2;
}
