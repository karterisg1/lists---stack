#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "pq.h"

#define LEFT(i) 2 * (i) + 1
#define RIGHT(i) LEFT(i) + 1
#define PARENT(i) ((i)-1) / 2

void swap(int *x, int *y);

void swap(int *x, int *y)
{
	int t;
	
	t = (*x);
	(*x) = (*y);
	(*y) = t;
}

/*Insert an element into the A */
void InsertHeap(PQ A, int *n, int key)
{
	int i;
    
	i = ++(*n);
    A[i] = key; /*Insert in the last place and adjust its position*/
		
    while(i > 0 && A[PARENT(i)] < A[i]) 
    {
		swap(&(A[PARENT(i)]), &(A[i]));
        i = PARENT(i);
    }
}

// Delete root of max-heap

int DeleteMax(PQ A, int *n) 
{
	int max;
	
	if ((*n) < 0)
	{
		fprintf(stderr, "empty heap\n");
		return -1; 
	}
	
	max = A[0]; 
	A[0] = A[(*n)];
	FixHeap(A, (*n), 0);
    (*n)--;
	
	return max;
}

// Organize heap
void FixHeap(PQ A, int n, int i) 
{
	int largest, left, right;
	
	largest = i; 
	left = LEFT(i); 
	right = RIGHT(i);
	
	if (left < n && A[left] > A[largest])
	{
		largest = left;
	}
	if (right < n && A[right] > A[largest])
	{
		largest = right; 
	}
	if (largest != i)
	{
		swap(&(A[i]), &(A[largest]));
		FixHeap(A, n, largest);
	}
}

void PrintHeap(PQ A, int n)
{
     int i;
     
     for (i = 0; i < n; i++)
     {
         printf("%d ", A[i]);
     }
     printf("\n");
}

PQ Init(int n)
{
	PQ p;

	p = (PQ) malloc(n*sizeof(*p));
	if (p == NULL)
    {
       fprintf(stderr, "\nAllocation failed\n");
       exit(1);
    }
	return p;
}

void HeapSort(PQ A, int n)
{
	int i;
	
	for (i = n/2-1; i >= 0; i--)
	{
		FixHeap(A, n, i);
	}

	for (i = n-1; i > 0; i--) 
	{
		swap(&A[0], &A[i]);
		FixHeap(A, i, 0);
	}
}