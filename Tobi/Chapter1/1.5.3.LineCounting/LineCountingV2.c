#include <stdio.h>

main()
{
	int curChar, previousChar;
	
	while ((curChar = getchar()) != EOF)
	{
		if ((curChar == ' ') && (previousChar == ' '))
		{
		} else 
		{
			previousChar = curChar;
			putchar(curChar);
		}
	}
}