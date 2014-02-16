#include <stdio.h>
#define MAX 10

typedef struct{
	int wert[MAX];
}Array;

int arr[MAX];

void changeValueArray(int array[]);
void changeValueStruct(Array array);

main()
{
	arr[0] = 10;
	Array arr2;
	arr2.wert[0] = 10;
	
	printf("Wert array ohne struct %d\n",arr[0]);
    printf("Wert array mit struct %d\n ",arr2.wert[0]);
}

void changeValueArray(int array[])
{
}

void changeValueStruct(Array array)
{
}