#include <stdio.h>

main()
{
	int curChar;
	
	while ((curChar = getchar()) != EOF)
	{
		if (curChar == '\t')
		{
			putchar('\\');
			putchar('t');
		} else if (curChar == '\b')
		{
			putchar('\\');
			putchar('b');
		} else if (curChar == '\\')
		{
			putchar('\\');
			putchar('\\');
		} else 
		{
			putchar(curChar);
		}
	}
}