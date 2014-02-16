#include <stdio.h>

void swap(int *pP1, int *pP2);

main()
{
	int x = 1;
	int *pPointer = &x;
	int y = *pPointer;
	y = 2;
	
	printf("x: %d\nPointer to x: %d\ny: %d\n", x, *pPointer, y);
	
	swap(&x, &y);
	printf("x: %d\nPointer to x: %d\ny: %d\n", x, *pPointer, y);
}

void swap(int *pP1, int *pP2)
{
	int temp = *pP1;
	*pP1 = *pP2;
	*pP2 = temp;
}