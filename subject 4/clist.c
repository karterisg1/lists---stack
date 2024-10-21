/* C program to illustrate the operations of a circular linked list */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Clist.h"

struct node
{
	int val;
   	struct node *next;
};

struct list
{
    struct node *cursor;
	struct node *tail;
};

struct node* CreateNode(int x);
void PrintNode(struct node *p);

// create a node with value x
struct node* CreateNode(int x)
{
	struct node *p;

	p = (struct node*) malloc(sizeof(struct node));
	if (p == NULL)
    {
       fprintf(stderr, "\nAllocation failed\n");
       exit(1);
    }
	p->next = NULL;
	p->val = x;

	return p;
}

// Create an empty list
Clist Create(void)
{
	Clist p;

	p = (Clist) malloc(sizeof(*p));
	if (p == NULL)
    {
       fprintf(stderr, "\nAllocation failed\n");
       exit(1);
    }
    p->cursor = NULL;
    p->tail = NULL;

    return p;
};

// Display a node in a linked list
void PrintNode(struct node *p)
{
	if (p == NULL)
    {
		printf("\nNode not exists.\n");
	}
	else
	{
		printf(" %d ==> ", p->val);
	}
}

// Display Circular list, starting from cursor
void PrintList(Clist L)
{
	struct node *p;

	for (p = L->cursor; p != NULL; p = p->next)
	{
		PrintNode(p);
		if (p->next == L->cursor)
			break;
	}
	putchar('\n');
}

// add a new node with value x just after cursor
void Add(Clist * L, int x)
{
    struct node *p;
    
    p = CreateNode(x);
	if ((*L)->cursor == NULL)
	{
		(*L)->cursor = p;
		(*L)->tail = p;
	}
	else
	{	
		p->next = (*L)->cursor;
		(*L)->cursor = p;
	}
	(*L)->tail->next = (*L)->cursor;
}


// Removes a node just after cursor
void Remove(Clist *L)
{
    struct node *p;
  
	if ((*L)->cursor == NULL)
	{
		return;
	}
	p = (*L)->cursor;
	if (p == p->next)
	{
		free((*L)->cursor);
		(*L)->cursor = (*L)->tail = NULL;
		return;
	}
	(*L)->cursor = p->next; 
	free(p);
	(*L)->tail->next = (*L)->cursor;
}

// Advance cursor
void Advance(Clist *L)
{
	if ((*L)->cursor != NULL)
	{
		(*L)->cursor = (*L)->cursor->next;
		(*L)->tail = (*L)->tail->next;
	}
}