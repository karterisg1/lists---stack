#include <stdio.h>
#include "pq.h"

#define SIZE 100

int main()
{
    PQ A;
	
	A = Init(SIZE);
	int n = -1;

	InsertHeap(A, &n, 20);
	InsertHeap(A, &n, 17);
	InsertHeap(A, &n, 12);
	InsertHeap(A, &n, 10);
	InsertHeap(A, &n, 16);
	InsertHeap(A, &n, 6);
	InsertHeap(A, &n, 4);
	InsertHeap(A, &n, 8);
	InsertHeap(A, &n, 3);
	InsertHeap(A, &n, 15);
	PrintHeap(A, n);
	
    printf("\n\nIt is out %d\n\n", DeleteMax(A, &n));
    PrintHeap(A, n);
	HeapSort(A, n);
	PrintHeap(A, n);
    return 0;
}