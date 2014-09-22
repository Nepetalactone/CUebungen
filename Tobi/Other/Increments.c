#include <stdio.h>

void main()
{
	int i = 0;
	int j = i++ + i++;
	printf("%d", j);
}