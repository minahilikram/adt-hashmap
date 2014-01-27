#include <stdio.h> 
#include <string.h>
#include "perm.h"

/* Finds permuations and saves them to a list. */
void perm(char *a, int i, node *myList) {
    char temp;
    int j;
    char d[10];  
    int len;
    len = strlen(a);
    

    if (i == len) {
        if (lookupElement(myList, a) != 0) {
            addFront(myList, a);
        }
    }
    else {
        for (j = i; j< len; j++) {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            strcpy(d, a);
            perm(d, i+1, myList);
        }
    }
}

/* Changes string to lowercase. */
void toLowerCase(char *input) {
    int len;
    int i;
    len = strlen(input);
    
    for (i = 0; i < len; i++) {
        if (input[i] >= 65 && input[i] <= 90) {
            input[i] = input[i] + 32;
        }
    }       
}

/* Checks if the input entered contains letters from A-Z or a-z. */
int inputValidation(char *input) {
    int len;
    int i;
    len = strlen(input);
    
    for (i = 0; i < len; i++) {
        if ((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input [i] <= 122)) {
            return 1;
        }
    }
    return 0;
}
