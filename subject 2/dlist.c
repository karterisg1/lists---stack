#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

struct node
{
	int val;
   	struct node *next;
	struct node *prev;
};

struct list
{
    struct node *head;
    struct node *tail;
};

struct node* CreateNode(int x);

/* Add an element to the tail of the queue */
void EnQueue(List *q, int v)
{
	struct node *p;

	p = CreateNode(v);
	
	if ((*q)->tail != NULL)
	{
		(*q)->tail->next = p;	/* Add element to queue tail */
		p->prev = (*q)->tail;
	}
	else
	{
		(*q)->head = p;		/* Special case for empty queue */
	}
	(*q)->tail = p;
}

/* Add an element to the start of the queue */
void Push(List *q, int v)
{
	struct node *p;

	p = CreateNode(v);
	
	if ((*q)->head != NULL)
	{
		(*q)->head->prev = p;	/* Add element to queue tail */
		p->next = (*q)->head;
	}
	else
	{
		(*q)->tail = p;		/* Special case for empty queue */
	}
	(*q)->head = p;
}

/* Remove and return first element from a non-empty queue */
int Pop(List *q)
{
	struct node *t;
	int x;

	if (IsEmpty(*q))
	{
		fprintf(stderr, "\nUnderflow: Queue is empty\n");
		return INT_MAX;
	}
	x = (*q)->head->val;
	t = (*q)->head->next;
	t->prev = NULL;
	free((*q)->head);
	(*q)->head = t;
	
	return x;
}

/* Remove and return last element from a non-empty queue */
int Dequeue(List *q)
{
	struct node *t;
	int x;

	if (IsEmpty(*q))
	{
		fprintf(stderr, "\nUnderflow: Queue is empty\n");
		return INT_MAX;
	}
	x = (*q)->tail->val;
	t = (*q)->tail->prev;
	t->next = NULL;
	free((*q)->tail);
	(*q)->tail = t;
	
	return x;
}

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
	p->prev = NULL;
	p->val = x;

	return p;
}

// Create an empty list
List Create(void)
{
	List p;

	p = (List) malloc(sizeof(*p));
	if (p == NULL)
    {
       fprintf(stderr, "\nAllocation failed\n");
       exit(1);
    }
    p->head = NULL;
    p->tail = NULL;

    return p;
}

// Display Queue
void Print(List L)
{
	struct node *p;

	putchar('\n');
	for (p = L->head; p != NULL; p = p->next)
	{
		printf(" %d <==> ", p->val);
	}
	putchar('\n');
}

int SizeOf(List L)
{
	struct node *p;
	int c = 0;

	for (p = L->head; p != NULL; p = p->next)
	{
		c++;
	}
	return c;
}

int IsEmpty(List L)
{
	return L->head == NULL;
}