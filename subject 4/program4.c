/* C program to illustrate the operations of a circular linked list */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Clist.h"

int main(int argc, char **argv)
{
    Clist L;
	int N, M, P, c, i;

	L = Create();

	N = atoi(argv[1]);
	M = atoi(argv[2]);
	P = atoi(argv[3]);
	
	for (i = N; i >= 1; i--)
	{
		Add(&L, i);
	}
	PrintList(L);
	while (--P)
	{
		Advance(&L);
	}
	
	for (c = 1; c < N; c++)
	{
		for (i = 1; i < M; i++)
		{
            Advance(&L);
		}
		Remove(&L);
    }
	PrintList(L);
	return 0;
}