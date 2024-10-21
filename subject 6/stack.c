#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

struct node
{
	int val;
   	struct node *next;
};

struct stack
{
	struct node *head;
};

struct node * CreateNode(int);

// create a node with value x
struct node * CreateNode(int x)
{
	struct node * p;

	p = (struct node *) malloc(sizeof(struct node));
	if (p == NULL)
    {
       fprintf(stderr, "\nAllocation failed\n");
       exit(1);
    }
	p->next = NULL;
	p->val = x;

	return p;
}

// Initialize a new stack
Stack Init(void)
{
	Stack p;

	p = (Stack) malloc(sizeof(*p));
	if (p == NULL)
    {
       fprintf(stderr, "\nAllocation failed\n");
       exit(1);
    }
	p->head = NULL;
	return p;
}     

// Push a new node with val x at the top of the stack.
void Push(Stack s, int x)
{
	Node p;

	p = CreateNode(x);   
    p->next = s->head;
    s->head = p;
}                            	

// Pop top item of stack
int Pop(Stack s)
{
	if (s->head != NULL)
	{
		int x;
		Node t;
		
		x = s->head->val;
		t = s->head;
		s->head = s->head->next;
		free(t);
		return x;
	}
}