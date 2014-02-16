#include <stdio.h>

void printCharArray(char *pChar, int size);

main()
{
	char arr[10];
	arr[0] = 'a';
	arr[1] = 'b';
	arr[2] = 'c';
	arr[3] = 'd';
	arr[4] = 'e';
	arr[5] = 'f';
	arr[6] = 'g';
	arr[7] = 'h';
	arr[8] = 'i';
	arr[9] = 'j';

	char *pChar = &arr[9];
	char arrCopy[10];
	int i;
	int arrSize = sizeof(arr);
	
	for(i = 0; arrSize-i >= 0; i++)
	{
		arrCopy[i] = *pChar;
		pChar--;
	}
	
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(char));
	
	printCharArray(&arrCopy[0], sizeof(arrCopy));
}

void printCharArray(char *pChar, int size)
{
	int i = 0;
	while (i < size)
	{
		printf("%c", *pChar);
		pChar++;
		i++;
	}
}