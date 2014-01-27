#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TABLE_SIZE 10

int main() {
    
    tableNode *testTable;   /* Creates a table and initalizes it to empty. */
    char input[10];         
    int menu = 0;
    char c;
    int search;
    
    testTable = createTable(TABLE_SIZE);
    
    while (menu != 3) {
    
        printf("\nWhat would you like to test?\n");
        printf("\n[1] Insert\n");
        printf("[2] Lookup\n");
        printf("[3] Destroy & Exit\n");
        scanf("%d", &menu);

            while((c = getchar()) != '\n' && c != EOF); /*cleans input buffer, incase characters are input*/
            
        if (menu == 1) {
            
            printf("\nPlease Enter a String:");
            fgets(input, 10, stdin);
            input[strlen(input)-1] = '\0';
            
            insert(testTable, input);  /*returns users input to function to add to the table*/
            
            printf("Current Table:\n");
            printTable(testTable);        /* table printed everytime inorder for user to keep track*/
        
        }
        
        if (menu == 2) {
        
            printf("\nPlease Enter a String:");
            fgets(input, 10, stdin);
            input[strlen(input)-1] = '\0';
            
            search = lookup(testTable, input);  /*calls function and sends word to search*/
            if (search == 0) {
                printf("%s was found.\n", input);
            }
            else {
                printf("%s was not found.\n", input);
            }
        }
        
        if (menu == 3) {
        
            destroyTable(testTable); /*destroys table and frees memory*/
            break;
        }
    }
    
    return 0;
}
