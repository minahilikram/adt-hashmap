#include "linkedList.h"

typedef struct table {
	int size;
	node **head;
} tableNode;

/* Preconditions: None.
Postconditions: A new table is created of the size sent and is initialized to empty. */
tableNode *createTable(int size);

/* Preconditions: A table exists.
Postconditions: Table is detroyed. */
void destroyTable(tableNode *myTable);

/* Preconditions: A table exists.
Postconditions: An element is added to the table. */
void insert(tableNode *myTable, char *elem);

/* Preconditions: A table exists.
Postconditions: Integer is returned indicating if an element exists. Table is unchanged. */
int lookup(tableNode *myTable, char *value);

/* Preconditions: A table exists.
Postconditions: None. */
void printTable(tableNode *myTable);
