#include <stdio.h>

void printVerticalHistogramm(int digit[10]);
void printHorizontalHistogramm(int ndigit[10]);
int maxValueInArray(int ndigit[10]);
void printCharHistogram(int ndigit[25]);
int maxValueInBigArray(int ndigit[26]);

main()
{
	int c, i, nwhite, nother;
	int ndigit[10];
	int charactersToCount[26];
	
	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
	{
		ndigit[i] = 0;
	}
	
	for (i = 0; i < 25; ++i)
	{
		charactersToCount[i] = 0;
	}
	
	while ((c = getchar()) != EOF)
	{
		if (c >= '0' && c <= '9')
		{
			ndigit[c - '0']++;
		} else if (c == ' ' || c == '\n' || c == '\t')
		{
			++nwhite;
		} else 
		{
			++nother;
			charactersToCount[(int)(c - 'a')]++;
		}
	}
	
	//printf("digits: ");
	//	for (i = 0; i < 10; i++)
	//	{
	//		printf("%d", ndigit[i]);
	//	}
		
	//	printf ("\nwhite space = %d, other = %d\n", nwhite, nother);
	
	printVerticalHistogramm(ndigit);
	printf("\n\n\n");
	printHorizontalHistogramm(ndigit);
	printf("\n\n\n");
	printCharHistogram(charactersToCount);
}

void printVerticalHistogramm(int ndigit[10])
{
	int i, j;
	for(i = 0; i < 10; i++)
	{
		printf("\t%d", i);
	}
	printf("\n");
	int maxValue = maxValueInArray(ndigit);
	
	for (maxValue; maxValue > 0; maxValue--)
	{
		printf("%d", maxValue);
		for (j = 0; j < 10; j++)
		{
			if (ndigit[j] >= maxValue)
			{
				printf("\t*");
			} else 
			{
				printf("\t ");
			}
		}
		printf("\n");
	}
}

void printHorizontalHistogramm(int ndigit[10])
{
	int i, j;
	int maxValue = maxValueInArray(ndigit);
	
	for (i = 1; i <= maxValue; i++)
	{
		printf("\t%d", i);
	}
	
	for (i = 0; i < 10; i++)
	{
		printf("\n%d", i);
		
		for (j = 1; j <= ndigit[i]; j++)
		{
			printf("\t*");
		}
	}
}

int maxValueInArray(int ndigit[10])
{
	int i;
	int maxValue = 0;
	
	for (i = 0; i < 10; i++)
	{
		if (ndigit[i] > maxValue)
		{
			maxValue = ndigit[i];
		}
	}
	
	return maxValue;
}

void printCharHistogram(int ndigit[26])
{
	int i, j;
	int maxValue = maxValueInBigArray(ndigit);
	
	for (i = 1; i <= maxValue; i++)
	{
		printf("\t%d", i);
	}
	
	for (i = 0; i < 26; i++)
	{
		printf("\n%c", (char)(((int)'a') + i));
		
		for (j = 1; j <= ndigit[i]; j++)
		{
			printf("\t*");
		}
	}
}

int maxValueInBigArray(int ndigit[26])
{
	int i;
	int maxValue = 0;
	
	for (i = 0; i < 26; i++)
	{
		if (ndigit[i] > maxValue)
		{
			maxValue = ndigit[i];
		}
	}
	
	return maxValue;
}