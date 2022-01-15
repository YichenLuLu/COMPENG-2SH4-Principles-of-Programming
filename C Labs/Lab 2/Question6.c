#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){
	 int j = 0,i;
	    for(i = 0; i < size; i++){
	        if(source[i] != 0){
	            val[j] = source[i];
	            pos[j] = i;
	            j++;
	        }
	    }
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){
	int i,j;
	    for( i = 0; i < m; i++){
	        source[i] = 0;
	        for(j = 0; j < n; j++){

	            if(i == pos[j]){
	                source[i] = val[j];
	                break;
	            }
	        }
	    }

    
	

}
