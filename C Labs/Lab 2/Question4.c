#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){
	int i=0;

	    while(word[i]!='\0'){
           if(word[i]>='a' && word[i]<='z')
              freq[word[i]-'a']++;
              else if(word[i]>='A' && word[i]<='Z')
              freq[word[i]-'A']++;
           i++;

	    }
	

   
}
