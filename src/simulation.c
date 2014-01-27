#include "hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "perm.h"
#define SIZE 50000

int main(int argc, const char * argv[]) {
    
    tableNode *table;
    node *myList;
    FILE *inputFile = NULL;
    char lineBuffer[20];    /* Variable for reading dictionary file. */
    int length;             /* Checks the length of the permutation list. */
    int i;
    char input[10];         /* Variable for user input to find permutations. */
    int menu = 0;
    char *myWord;
    int count = 0;          /* Checks the number of permutations found. */
    char c;
    
    table = createTable(SIZE);  /* Creates a table and initalizes it to empty. */
    
    myList = createList();  /* Creates a list and initalizes it to empty. */
    
     if (argc != 2) {   /* Incase no file is found. */
		printf ("Usage Error: please  path/to/executable path/to/input/file\n");
		exit(1);
	}
    /* open the file for reading */
	inputFile = fopen (argv[1], "r");

	if (inputFile == NULL) {    /* Checks if file is found. */
		printf ( "Error. Input file does not exist!\n");
		exit(1);
	}
	
	else {
	    while (fgets(lineBuffer, 20, inputFile) != NULL) {
	        lineBuffer[strlen(lineBuffer)-1] = '\0';    /* Gets rid of newline. */
	        toLowerCase(lineBuffer);
	        insert(table, lineBuffer);
	    }
	}
	
    while (menu != 2) {
        
        count = 0;
        
        printf("Enter Word:");
        fgets(input, 10, stdin);
        input[strlen(input)-1] = '\0';
        
        if (inputValidation(input) != 1) {
            printf("invalid input.");
        }
        else {
            toLowerCase(input);

            perm(input, 0, myList);

            length = listLength(myList);
            
            printf("**anagrams found**\n");
            for (i = 0; i < length; i++) {
                myWord = getFront(myList);
                if (lookup(table, myWord) == 0) {
                    printf("%s\n", myWord);
                    count++;
                }
                removeFront(myList);
            }
            printf("%d anagrams found.\n", count);
        }
        
        printf("\n[1] Search\n");
        printf("[2] Quit\n");
        scanf("%d", &menu);
        
        while((c = getchar()) != '\n' && c != EOF);
    }
    
    destroy(myList);
    destroyTable(table);
    
    return 0;
}
