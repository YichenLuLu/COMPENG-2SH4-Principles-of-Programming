#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){
	int i=0,j=0,k=0;
	    while(1){
	        if(i==k1 || j==k2)
	            break;
	        if(pos1[i] == pos2[j]){
	            int temp = val1[i] + val2[j];
	            if(temp!=0){
	                val3[k] = temp;
	                pos3[k] = pos1[i];
	                k++;
	            }
	            i++;
	            j++;
	        }

	        else if(pos1[i]>pos2[j]){
	            val3[k] = val2[j];
	            pos3[k] = pos2[j];
	            j++;
	            k++;
	        }
	        else if(pos1[i]<pos2[j]){
	            val3[k] = val1[i];
	            pos3[k] = pos1[i];
	            i++;
	            k++;
	        }
	    }
	    while(i<k1){
	        val3[k] = val1[i];
	        pos3[k] = pos1[i];
	        i++;
	        k++;
	    }

	    while(j<k2){
	       val3[k] = val2[j];
	       pos3[k] = pos2[j];
	       j++;
	       k++;
	    }
	
}
