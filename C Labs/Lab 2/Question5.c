#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void string_copy(const char source[], char destination[], int n){
    int i, len = 0;
    while (source[len]) {
        len++;
    }
    for (i = 0; i < n-1 && i < len; ++i) {
        destination[i] = source[i];
    }
    destination[i] = '\0';

	
    
}
