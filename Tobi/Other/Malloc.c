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
void * maxPos = (void *)&memory[MAXLENGTH];

//Example makes use of void pointer arithmetic, which apparently only works thanks to a gcc extension
void main()
{
	curPos = (block_t *) &memory[0];
	void * curPoss = (void *) curPos;
	printf("Current free memory: %d\n\n", maxPos - curPoss);
	//nmalloc(39980);
	nmalloc(2);
	curPoss = (void *) curPos;
	printf("Current free memory: %d\n\n", maxPos - (void *)curPos);
	//printf("Current curPos position1: %d\n\n", curPos);
	//printf("Current allocated memory: %d\n", allocatedSpace);
	//void * mll1 = nmalloc(20);
	//printf("Current malloc position: %d\n\n", mll1);
	//printf("Current allocated memory: %d\n", allocatedSpace);

	//void * mll2 = nmalloc(40);
	//printf("Current malloc position: %d\n\n", mll2);
	//printf("Current allocated memory: %d\n", allocatedSpace);
	
	//void * mll3 = nmalloc(60);
	//printf("Current malloc position: %d\n\n", mll3);
	//printf("Current allocated memory: %d\n", allocatedSpace);
	
	//nfree(mll2);
	//printf("Current allocated memory: %d\n", allocatedSpace);

	//void * mll4 = nmalloc(40);
	//printf("Current malloc position: %d\n\n", mll4);
	//printf("Current allocated memory: %d\n", allocatedSpace);
}

void *nmalloc(unsigned int length)
{
	struct block * iterator = (block_t *) &memory[0];

	while (iterator != (block_t *)curPos)
	{
		if ((iterator->valid == 0) && (iterator->length + sizeof(unsigned int) * 3 >= length))
		{
			void * newVoidBlock = (void *) iterator;
			newVoidBlock += sizeof(unsigned int) * 3 + length;
			struct block * newBlock = (block_t *) newVoidBlock;
			newBlock->length = iterator->length - length;
		
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
	if (MAXLENGTH * 4  - (maxPos - (void *)curPos) > length + sizeof(unsigned int) * 3)
	{
		iterator->valid = 1;
		iterator->length = length;
		allocatedSpace += (sizeof(unsigned int) * 3) + length;
		void *voidIT = (void *)iterator;
		voidIT += (sizeof(unsigned int) * 3) + length;
		curPos = (block_t *) voidIT;
		return voidIT - length;
	}
	printf("Error: couldn't allocate specified space\n");
	return NULL;
}

void nfree(void *toDelete)
{
	toDelete -= (sizeof(unsigned int) * 3);
	struct block * temp = (block_t *) toDelete;
	temp->valid = 0;
	allocatedSpace = allocatedSpace - (temp->length + sizeof(unsigned int) * 3);
}

void defragment()
{
	struct block * iterator = (block_t *) &memory[0];
	struct block * temp = (block_t *) &memory[0];
	
	while (iterator != (block_t *)curPos)
	{
		while ((iterator->valid == 0)&&(iterator < (block_t*)curPos))
		{
			temp->length += sizeof(unsigned int) * 3 + iterator->length;
			void *voidIT = (void *)iterator;
			voidIT += (sizeof(unsigned int) * 3) + iterator->length; 
			iterator = (block_t *) voidIT;
		}
		temp = iterator;
		void *voidIT = (void *)iterator;
		voidIT += (sizeof(unsigned int) * 3) + temp->length;
		iterator = (block_t *) voidIT;
	}
}