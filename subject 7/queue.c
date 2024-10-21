/* C program to illustrate Topological Sorting */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //for INT_MAX
#include "queue.h"

struct node
{
	int val;
   	struct node *next;
};

struct list
{
    struct node *head;
    struct node *tail;
};

struct node* CreateNode(int x);
int GetVal(struct node *p);
Queue* CreateArrayOfQueues(int);
void UpdateQueue(Queue p, int *deg, Queue *q);

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

/* Add an element to the queue */
void EnQueue(Queue *q, int v)
{
	struct node *p;

	p = CreateNode(v);
	
	if (!IsEmpty(*q))
	{
		(*q)->tail->next = p;	/* Add element to queue tail */
	}
	else
	{
		(*q)->head = p;		/* Special case for empty queue */
	}
	(*q)->tail = p;
}

/* Remove and return an element from a non-empty queue */
int DeQueue(Queue *q)
{
	struct node *t;
	int x;

	if (IsEmpty(*q))
	{
		fprintf(stderr, "\nUnderflow: Queue is empty\n");
		(*q)->tail = NULL;
		(*q)->head = NULL;
		x = INT_MAX;
	}
	else
	{	
		x = (*q)->head->val;
		t = (*q)->head->next;
		free((*q)->head);
		(*q)->head = t;
		if (IsEmpty(*q))
		{
			(*q)->tail = NULL;
			(*q)->head = NULL;
		}
	}
	return x;
}

// Create an empty list
Queue Init(void)
{
	Queue p;

	p = (Queue) malloc(sizeof(*p));
	if (p == NULL)
    {
       fprintf(stderr, "\nAllocation failed\n");
       exit(1);
    }
    p->head = NULL;
    p->tail = NULL;

    return p;
}

// Create an Array of empty lists
Queue* CreateArrayOfQueues(int N)
{
	Queue *QA = NULL;
	int i;

	QA = (Queue *)malloc(N*sizeof(Queue));
	if (QA == NULL)
    {
       fprintf(stderr, "\nAllocation failed\n");
       exit(1);
    }
	for (i = 0; i < N; i++)
	{
		QA[i] = Init();
	}

    return QA;
}

int IsEmpty(Queue q)
{
	return q->head == NULL;
}

// Process x queue
void ProcessQueue(int N)
{
	Queue q;
	int i, j;
	Queue *qa;
	int *deg;
	
	deg = (int *)calloc(N, sizeof(int));
	if (deg == NULL)
    {
       fprintf(stderr, "\nAllocation failed\n");
       exit(1);
    }
	
	qa = CreateArrayOfQueues(N);
	
	// Read data
	while (1)
	{
		scanf("%d%d", &i, &j);
		if (i < 0 || j < 0 || i > N || j > N)
		{
			break;
		}
		EnQueue(&(qa[i]), j);
		deg[j]++;
	}
	
	// Initialize queue
	q = Init();
	
	// place nodes of degree 0 to the queue
	for (i = 0; i < N; i++)
	{
		if (deg[i] == 0)
		{
			EnQueue(&q, i);
		}
	}
	while (!IsEmpty(q))
	{
		int x;
	
		x = DeQueue(&q);
		printf("%d, ", x);
		UpdateQueue(qa[x], deg, &q);
	}
	free(qa);
	free(deg);
}

int GetVal(struct node *p)
{
	return p->val;
}

void UpdateQueue(Queue p, int *deg, Queue *q)
{
	struct node *t;
	
	for (t = p->head; t != NULL; t = t->next)
	{
		int pos;
		pos = GetVal(t);

		if (deg[pos] > 0)
		{
			deg[pos]--;
			if (deg[pos] == 0)
			{
				EnQueue(q, pos);
			}
		}
		free(p);
		p = NULL;
	}
}