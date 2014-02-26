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
	mainBlock->length = MAXLENGTH;
	mainBlock->valid = 0;	//create giant non-valid block, spanning the whole memory array
	
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

	while (iterator < (block_t *)&memory[MAXLENGTH])	//search for a non-valid block in the array
	{
		if ((iterator->valid == 0) && (iterator->length + sizeof(unsigned int) * 3 >= length))	//if a sufficiently big block is found, allocate it 
		{
			void * newVoidBlock = (void *) iterator;	//"if", checking whether remaining length is sufficient for three uints is missing
			newVoidBlock += sizeof(unsigned int) * 3 + length;	
			struct block * newBlock = (block_t *) newVoidBlock;
			newBlock->length = iterator->length - (length + sizeof(unsigned int) * 3);	//create a new non-valid block at the end of the newly allocated block, length is the 
																						//original length of the non-valid block minus the now allocated blocklength
			iterator->valid = 1;	//set block to valid and update allocated space
			iterator->length = length;
			
			allocatedSpace += (sizeof(unsigned int) * 3) + length;
			void *voidIT = (void *)iterator;
			voidIT += (sizeof(unsigned int) * 3);
			return voidIT;
		}
		
		void *voidIT = (void *)iterator;	//iterate further through the array
		voidIT += (sizeof(unsigned int) * 3) + iterator->length;
		iterator = (block_t *) voidIT;
	}
	printf("Error: couldn't allocate specified space\n");
	return NULL;
}

void nfree(void *toDelete)
{
	toDelete -= (sizeof(unsigned int) * 3);		//set block to not valid, update allocated space
	struct block * temp = (block_t *) toDelete;
	allocatedSpace = allocatedSpace - (temp->length + sizeof(unsigned int) * 3);
	void * voidIT = (void *) toDelete;
	voidIT += sizeof(unsigned int) * 3 + temp->length;
	struct block * iterator = (block_t *) voidIT;
	
	while ((iterator->valid == 0)&&(iterator < (block_t *)&memory[MAXLENGTH]))	//add length of adjacent non-valid blocks to valid block
	{
			temp->length += sizeof(unsigned int) * 3 + iterator->length;
			void *voidIT = (void *)iterator;
			voidIT += (sizeof(unsigned int) * 3) + iterator->length; 
			iterator = (block_t *) voidIT;
	}
	temp->valid = 0;
}

void defragment()
{
	struct block * iterator = (block_t *) &memory[0];
	struct block * temp = (block_t *) &memory[0];
	
	while (iterator < (block_t *)&memory[MAXLENGTH])	//iterate through the whole array
	{
		while ((iterator->valid == 0)&&(iterator < (block_t *)&memory[MAXLENGTH]))		//add length of adjacent non-valid blocks to valid block
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