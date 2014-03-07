#include <stdio.h>
#define MAXLENGTH 10000

static char memory[MAXLENGTH];
unsigned int allocatedSpace = 0;

void *nmalloc(unsigned int length);
void nfree(void *);

struct block
{
	unsigned int valid;
	unsigned int crc;
	unsigned int length;
};

typedef struct block block_t;
static struct block_t * curPos;

void main()
{
	curPos = (block_t *) &memory[0];
	//nmalloc(39980);
	//nmalloc(2);
	printf("Current curPos position1: %d\n\n", curPos);
	printf("Current allocated memory: %d\n", allocatedSpace);
	
	void * mll1 = nmalloc(20);
	printf("Current malloc position: %d\n\n", mll1);
	printf("Current allocated memory: %d\n", allocatedSpace);

	void * mll2 = nmalloc(40);
	printf("Current malloc position: %d\n\n", mll2);
	printf("Current allocated memory: %d\n", allocatedSpace);
	
	void * mll3 = nmalloc(60);
	printf("Current malloc position: %d\n\n", mll3);
	printf("Current allocated memory: %d\n", allocatedSpace);

	nfree(mll2);
	printf("Current allocated memory: %d\n", allocatedSpace);

	void * mll4 = nmalloc(40);
	printf("Current malloc position: %d\n\n", mll4);
	printf("Current allocated memory: %d\n", allocatedSpace);
}

void *nmalloc(unsigned int length)
{
	struct block * iterator = (block_t *) &memory[0];

	while (iterator != curPos)
	{
		if ((iterator->valid == 0) && (iterator->length >= length))
		{
			iterator->valid = 1;
			iterator->length = length;
			allocatedSpace += (sizeof(unsigned int) * 3) + length;
			void *voidIT = (void *)iterator;
			voidIT += (sizeof(unsigned int) * 3) + length;
			curPos = (block_t *) voidIT;
			return voidIT - length;
		}
		
		void *voidIT = (void *)iterator;
		voidIT += (sizeof(unsigned int) * 3) + iterator->length;
		iterator = (block_t *) voidIT;
	}
	
	printf("%d\n", MAXLENGTH * 4 - allocatedSpace);
	if (MAXLENGTH * 4  - allocatedSpace > length + sizeof(unsigned int) * 3)
	{
		iterator->valid = 1;
		iterator->length = length;
		allocatedSpace += (sizeof(unsigned int) * 3) + length;
		void *voidIT = (void *)iterator;
		voidIT += (sizeof(unsigned int) * 3) + length;
		curPos = (block_t *) voidIT;
		return voidIT - length;
	}
	return NULL;
}

void nfree(void *toDelete)
{
	toDelete -= (sizeof(unsigned int) * 3);
	struct block * temp = (block_t *) toDelete;
	temp->valid = 0;
	allocatedSpace = allocatedSpace - ((sizeof(unsigned int) * 3) + temp->length);
}