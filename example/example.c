/*
 * example.c
 * Copyright (C) 2017  Marc Volker Dickmann
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../llist.h"

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
