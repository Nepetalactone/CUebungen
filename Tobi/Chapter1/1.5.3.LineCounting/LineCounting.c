#include <stdio.h>

main()
{
	int c, nl, nt, nb;
	
	nl = 0;
	nt = 0;
	nb = 0;
	
	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			++nl;
		} else if (c == '\t')
		{
			++nt;
		} else if (c == ' ')
		{
			++nb;
		}
	}
	printf("Lines\t	Tabs\t	Blanks\n	%d\t%d\t%d\t", nl, nt, nb);
}