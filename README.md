# LList

LList provides a quick way of using linked lists inside projects by providing
a simple api. Since linked lists can be used several times inside a single
project this allows for reducing redundant code.
 

## Example

A simple Hello World like example using the api.  
The `example` folder contains this as well as a Makefile to compile it.

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

int
main (void)
{
	LList *list = NULL;
	
	// Append the first entry to the list
	list = llist_append (list, strdup ("Hello"));
	
	// Should print the word Hello
	LList *pos;
	
	LLIST_FOR_EACH (pos, list)
	{
		printf ("%.255s\n", (char*)pos->data);
	}
	
	// Make it a greeting to the World
	list = llist_append (list, strdup (" World!"));

	// Print all list entries
	LLIST_FOR_EACH (pos, list)
	{
		printf ("%.255s\n", (char*)pos->data);
	}
	
	// Free the memory of all list entries
	llist_free_full (list, free);
	
	return 0;
}
```
