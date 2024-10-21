#include <stdio.h>
#include <ctype.h>
#include "stack.h"

void main()
{
	int c, result;
	Stack data, op;
	
	data = Init();
	op = Init();
	
	while ((c=getchar()) != EOF)
	{
		if (isdigit(c))
		{
		    int t;
		    
		    ungetc(c, stdin);
		    scanf("%d", &t);
			Push(data, t);
		}
		else if (c == '+' || c == '-' || c == '*')
		{
			Push(op, c);
		}
		else if (c == ')')
		{
			int x, y, z, s;
			y = Pop(data);
			x = Pop(data);
			s = Pop(op);
			if (s == '+')
			{
				z = x + y;
			}
			else if (s == '-')
			{
				z = x - y;
			}
			else
			{
				z = x * y;
			}
			Push(data, z);
		}
	}
	result = Pop(data);
	printf("Result is %d\n", result);
}