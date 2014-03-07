#include <stdio.h>
#include <limits.h>
#include <float.h>

main()
{
	printf("Name\tMin\tMax\n");
	printf("Char\t%d\t%d\n",CHAR_MIN, CHAR_MAX);
	printf("Short\t%d\t%d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Int\t%d\t%d\n", INT_MIN, INT_MAX);
	printf("Long\t%d\t%d\n", LONG_MIN, LONG_MAX);
	printf("Float\t%d\t%d\n", FLT_MIN, FLT_MAX);
}