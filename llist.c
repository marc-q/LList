/*
 * llist.c
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

#include <stdlib.h>
#include "llist.h"

LList *
llist_alloc (void)
{
	return malloc (sizeof (LList));
}

LList *
llist_last (LList *list)
{
	LList *last = list;
	while (last->next)
	{
		last = last->next;
	}
	return last;
}

void
llist_foreach (LList *list,
               void   func (void *data, void *udata),
               void  *udata)
{
	while (list)
	{
		func (list->data, udata);
		list = list->next;
	}
}

LList *
llist_append (LList *list,
              void  *data)
{
	LList *new = llist_alloc ();
	
	new->data = data;
	new->next = NULL;
	
	if (list)
	{
		llist_last (list)->next = new;
		return list;
	}
	return new;
}

LList *
llist_prepend (LList *list,
               void  *data)
{
	LList *new = llist_alloc ();
	
	new->data = data;
	new->next = list;
	
	return new;
}

void
llist_free (LList *list)
{
	LList *next;
	
	while (list)
	{
		next = list->next;
		
		free (list);
		
		list = next;
	}
}

void
llist_free_full (LList *list,
                 void   free_func (void *data))
{
	LList *next;
	
	while (list)
	{
		next = list->next;
		
		free_func (list->data);
		free (list);
		
		list = next;
	}
}

void *
llist_find_custom (LList      *list,
                   int         func (const void *data, const void *udata),
                   const void *udata)
{
	while (list)
	{
		if (func (list->data, udata) == 0)
			return list->data;
		
		list = list->next;
	}
	return NULL;
}
