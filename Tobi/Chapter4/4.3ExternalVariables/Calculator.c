#include <stdio.h>
#include <stdlib.h> /* for atof*/
#include "calc.h"

#define NUMBER '0'
#define MAXOP 100

main()
{
	int type;
	double op2;
	char s[MAXOP];
	
	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
				
			case '+':
				push (pop() + pop());
				break;
			
			case '*':
				push(pop() * pop());
				break;
				
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
				
			case '/':
				op2 = pop();
				if (op2 != 0.0)
				{
					push(pop() / op2);
				} else 
				{
					printf("error: zero divisor\n");
				}
				break;
				
			case '%':
				op2 = pop();
				if (op2 != 0.0)
				{
					push((int)pop() % (int)op2);
				} else 
				{
					printf("error: zero divisor\n");
				}
				break;
				
			case '\n':
				printf("\tResult: %.8g\n", pop());
				break;
				
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}
