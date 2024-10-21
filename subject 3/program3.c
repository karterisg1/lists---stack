/* C program to illustrate the operations of a circular linked list */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Clist.h"

int main()
{
    Clist L;
	int N, i;

	L = Create();

	printf("The persons in circular list are: ");
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		Add(&L, i);
	}
    PrintList(L);
    Remove(&L);
    PrintList(L);
    Advance(&L);
    PrintList(L);
    Advance(&L);
    PrintList(L);
	Remove(&L);
	PrintList(L);
    return 0;
}