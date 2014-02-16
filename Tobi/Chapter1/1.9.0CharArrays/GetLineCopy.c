#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[]);

main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
	{
		//if (len > max)
		//{
		//	max = len;
		//	copy(longest, line);
		//}
		
		//if (len >= 8)
		//{
		//	printf("%s %d", line, len);
		//}
		
		reverse(line);
		printf("%s", line);
	}
	//if (max > 0)
	//{
	//	printf("%s", longest);
	//}
	return 0;
}

int getline(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c!='\n'; ++i)
	{
		s[i] = c;
	}
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
	{
		++i;
	}
}

void reverse(char s[])
{
	char t;
	int i, j;
	
	j = 0;
	i = 0;
	
	while ((s[j] != '\0') && (s[j] != '\n'))
	{
		j++;
	}
	
	j--;
	
	for (j; j > i; j--)
	{
		t = s[i];
		s[i] = s[j];
		s[j] = t;
		i++;
	}
}