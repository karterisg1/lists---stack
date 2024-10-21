#include <stdio.h>
#include <ctype.h>
#include "dlist.h"

int main()
{
    List L;
	int x;
	
	L = Create();
    Print(L);
	EnQueue(&L, 10);
	Print(L);
	Push(&L, 8);
	Print(L);
	EnQueue(&L, 17);
	Print(L);
	x = Pop(&L);
	printf("Item is %d\n", x);
	Print(L);
	x = Dequeue(&L);
	printf("Item is %d\n", x);
	Print(L);
}