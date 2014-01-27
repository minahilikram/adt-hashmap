#include <stdio.h>
#include "hash.h"
#include <stdlib.h>
#include <string.h>

/* Takes in a value and returns the key. */
/*http://www.cse.yorku.ca/~oz/hash.html*/
int hashFunction(char *elem, int size) {
    
    unsigned int i = 0;
    unsigned int len = 0;
    unsigned int hash = 0;
    len = strlen(elem);
    for(i = 0; i < len; elem++, i++) {
        hash = (*elem) + (hash << 6) + (hash << 16) - hash;
    }

   return hash % size;
}

/* Creates a table and initalizes it to empty. */
tableNode *createTable(int size) {

    int i = 0;
    tableNode *myTable;
    myTable = malloc(sizeof(tableNode));
    myTable->head = malloc(size * sizeof(myTable->head));
    
    myTable->size = size;
    
    for (i = 0; i < size; i++) {
        myTable->head[i] = createList();
    }
    
    return myTable;
}

/* Destroys table and free memory.*/
void destroyTable(tableNode *myTable) {

    int i;
    for (i = 0; i < myTable->size; i++) {
        destroy(myTable->head[i]);
    }
    free(myTable);   
}

/* Inserts an element into the table. */
void insert(tableNode *myTable, char *elem) {
    
    int i;
    i = hashFunction(elem, myTable->size);
    addFront(myTable->head[i], elem);
}

/* Searches for a specific element in the table. */
int lookup(tableNode *myTable, char *value) {

    int compare;
    int i;
    i = hashFunction(value, myTable->size);
    compare = lookupElement(myTable->head[i], value);
    
    return compare;
}

/* Prints Table. */
void printTable(tableNode *myTable) {
    
    int i;
    for (i = 0; i < myTable->size; i++) {
        printf("\n[%d]", i+1);
        printList(myTable->head[i]);
    }    
}
