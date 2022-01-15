#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr []){
	int index=0; //the index of arr[]

	//the up-left triangle of arr[]
	for(int k=0;k<N3;k++){
	int i=k,j=0;
	while(i>=0){
	arr[index]=mat[i][j];
	i--;
	j++;
	index++;
	  }
	}
	//the bottom-right triangle of arr[]
	for(int k=1;k<N3;k++){
	int i=N3-1,j=k;
	while(j<N3){
	arr[index]=mat[i][j];
	i--;
	j++;
	index++;
	  }
	}
	
}
