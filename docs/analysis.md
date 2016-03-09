# Overview

I did not have createTable as an option in main because then I would have to keep track of more than one table. There is no input validation.

> test.c

The program has a menu of options to choose from to test it. The example takes in any input without truncating because it saves it as a character array. Update function would have to replace the word with another, but it would then become impossible to find again as the key would be different. Print table function prints the whole table, an easier way to print or another print function could also have been to print the list corresponsing to the particular word. It would make it easier to see things. 

> simulation.c

The program does not accept more than 10 characters, characters are truncated if longer and the while loop only takes in integers. Prompts user if input entered is not letters from A-Z or a-z. Asks to either search or quit. In search: jumbled letters can be entered which are then used to form anagrams and tested to see if they are in the dictionary file. I chose 50, 000 as my table size because when I had a table size of 10, 000 I found that my lists were too full. When I entered a size of 50, 000, the list became more readable and each list had less than 20 items. I didn't notice a difference in speed when these two table sizes were tested.

## Tests

| TESTS |RESULTS | FIX |
| ------------------ |--------------------| -------------------|
| if destroyTable function is called more than once         | crashes       		      | check for table		    |
| if any function is sent a bad pionter                     | seg faults    		      | keep track of pointers  |
| checking for memory leaks using Valgrind         	        | no leaks found 		      | no fix needed          	| 
| if characters are put into the input menu                 | crashes          	      	  | check for characters	|
| if destroyList of destroyTable are called twice           | crashes       		      | check for empty         |
| if any function is sent a bad pionter                  	| seg faults     		      | keep track of pointers 	| 
| checking for memory leaks using Valgrind                  | no leaks found   	      	  | no fix needed       	|
    
## References

[Here](http://www.cse.yorku.ca/~oz/hash.html) is a reference for the algorithm to write the hashFunction; it has been somewhat changed. [Here](http://www.daniweb.com/software-development/c/code/216770/permutations-of-a-string-using-recursion) is this website I used to help me come up with my permutation function.
