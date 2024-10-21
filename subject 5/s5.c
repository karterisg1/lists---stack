// C program Subset sum using backtracking
#include <stdio.h>
#include <stdlib.h>

// Print result
void printSum(int a[], int n, int *b)
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		if (b[i] == 1)
		{
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}

// Finding the subset with zero sum in an array
void subsetSum(int a[], int *b, int n, int s, int i)
{
	if (i == -1)
	{
		return;
	}
	subsetSum(a, b, n, s, i - 1);	// By recursion find previous element
	b[i] = 1;
	
	if (s + a[i] == 0)				// When we get sum
	{
		printSum(a, n, b);
	}
	
	subsetSum(a, b, n, s + a[i], i - 1);	// By recursion find previous element
	b[i] = 0;
}

int main()
{
	int a[] = {6, -3, 8, 2, 1, 4, 3};
	int n = sizeof(a) / sizeof(int);
	int *b = (int *) calloc(n, sizeof(int));
	subsetSum(a, b, n, 0, n - 1);
	return 0;
}
