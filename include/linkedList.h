#ifndef list_included
#define list_included

struct listNode {
	char *cmd;
	struct listNode * next;
};

typedef struct listNode node;

/* Preconditions: None.
Postconditions: A list is created and initialized to empty. */
node * createList();

/* Preconditions: A list exists.
Postconditions: List is destroyed. */
void destroy(node * dummyNode);

/* Preconditions: A list exists.
Postconditions: An element is added to the list. */
void addFront(node *head, char *elem);

/* Preconditions: A list exists.
Postconditions: None. */
int lookupElement(node *head, char *value);

/* Preconditions: A list exists.
Postconditions: None. */
void printList(node * head);

/* Preconditions: A list exists.
Postconditions: None. */
int listLength(node *head);

/* Preconditions: A list exists.
Postconditions: None. */
char *getFront(node * head);

/* Preconditions: A list exists.
Postconditions: An element is removed from the list. */
void removeFront(node * head);

node *initNode(char *elem);

#endif
