#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	
	/*write your implementation here*/
	int length=strlen(str1)+strlen(str2);
	z=(char *)malloc((length+1)*sizeof(char));
	int index=0;
	for(int i=0;i<strlen(str1);i++){
		z[index]=str1[i];
		index++;
	}

	for(int i=0;i<strlen(str2);i++){
			z[index]=str2[i];
			index++;
		}

	/* finally, return the string*/
	free(z);
	return z;
	
}
