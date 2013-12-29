#include <stdio.h>

main()
{
	int c;
	
	c = getchar();
	
	//while ((c != EOF) && (c != 'x'))
	//{
	//	putchar(c);
	//	c = getchar();
	//}
	
	while (c = getchar() != EOF)
	{
		putchar(c);
	}
}