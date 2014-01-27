#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
#include <string.h>

/* Creates and initalizes list. */
node *createList() {

    node *dummyNode;
    dummyNode = malloc(sizeof(node));
    dummyNode->cmd = NULL;
    dummyNode->next = NULL;
    
    return dummyNode;
}

/* Destroys list and frees memory. */
void destroy(node *head) {

    node *temp = head;
    while (temp != NULL) {
        temp = temp->next;
        free(head->cmd);
        free(head);
        head = temp;
    }
}

/* Adds element to the front of the list. */
void addFront(node *head, char *elem) {
    
    node *newNode;
    newNode = initNode(elem);
    newNode->next = head->next;
    head->next = newNode;
}

/* Adds element and element value. */
node *initNode(char *elem) {
    
    node *newNode;
    newNode = malloc(sizeof(node));
    newNode->cmd = NULL;
    newNode->cmd = malloc((strlen(elem)+1) * (sizeof(char)));
    strncpy(newNode->cmd, elem, strlen(elem)+1);
    newNode->next = NULL;
    
    return newNode;
}

/* Looks up element in the list. */
int lookupElement(node *head, char *value) {
    head = head->next;
    while ( head != NULL ){
        if (strcmp(value, head->cmd) == 0) {
            return 0;
        }
        head = head->next;
    }
    return -1;
}

/* Prints list. */
void printList(node * head) {
    node * N;
    N = head;
    N = N->next;
    while (N != NULL) {
        printf("%s, ", N->cmd);
        N = N->next;
    }
}

/* Checks the length of the list. */
int listLength(node *head) {
    
    node * N;
    int length = 0;
    N = head;
    N = N->next;
    while (N != NULL) {
        length++;
        N = N->next;
    }
    
    return length;
}

/* Gets the first element in the list. */
char *getFront(node * head) {
    
    return head->next->cmd;
}

/* Removes first element in the list. */
void removeFront(node * head) {
    node * tempPtr;
    tempPtr = head->next;
    head->next = head->next->next;
    free(tempPtr);
    
}
