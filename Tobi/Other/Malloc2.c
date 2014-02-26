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

void main()
{
	struct block * mainBlock = (block_t *) &memory[0];
	mainBlock->length = MAXLENGTH - 1;
	mainBlock->valid = 0;
}

void *nmalloc(unsigned int length)
{
	struct block * iterator = (block_t *) &memory[0];

	while (iterator != curPos)
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
}

void defragment()
{
	struct block * iterator = (block_t *) &memory[0];
	struct block * temp = (block_t *) &memory[0];
	
	while (iterator != curPos)
	{
		while ((iterator->valid == 0)&&(iterator < curPos))
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