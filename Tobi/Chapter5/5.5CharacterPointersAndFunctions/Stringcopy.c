#include <stdio.h>

void stringcopy(char *s, char *t);
int stringcompare(char *s, char *t);

void stringcopy(char *s, char *t)
{
	int i;
	
	i = 0;
	while ((*s = *t) != '\0')
	{
		s++;
		t++;
	}
}

int stringcompare(char *s, char *t)
{
	for ( ; *s == *t; s++, t++)
	{
		if (*s == '\0')
		{
			return 0;
		}
	}
	
	return *s - *t;
}