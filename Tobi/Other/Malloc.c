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
	printf("Current curPos position1: %d\n\n", curPos);
	void * mll1 = nmalloc(20);
	printf("Current malloc position: %d\n\n", mll1);
	
	void * mll2 = nmalloc(40);
	printf("Current malloc position: %d\n\n", mll2);
	
	void * mll3 = nmalloc(60);
	printf("Current malloc position: %d\n\n", mll3);
	
	nfree(mll2);
	
	void * mll4 = nmalloc(40);
	printf("Current malloc position: %d\n\n", mll4);
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
			voidIT += (sizeof(unsigned int) * 2) + length;
			curPos = (block_t *) voidIT;
			return voidIT - length;
		}
		
		void *voidIT = (void *)iterator;
		voidIT += (sizeof(unsigned int) * 2) + iterator->length;
		iterator = (block_t *) voidIT;
	}
	
	if (MAXLENGTH - allocatedSpace > length) //stimmt noch nicht
	{
		iterator->valid = 1;
		iterator->length = length;
		allocatedSpace += (sizeof(unsigned int) * 2) + length;
		void *voidIT = (void *)iterator;
		voidIT += (sizeof(unsigned int) * 2) + length;
		curPos = (block_t *) voidIT;
		return voidIT - length;
	}
}

void nfree(void *toDelete)
{
	toDelete -= (sizeof(unsigned int) * 2);
	struct block * temp = (block_t *) toDelete;
	temp->valid = 0;
}