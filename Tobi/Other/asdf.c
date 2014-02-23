#include <stdio.h>
#include <inttypes.h>

#define MAX_MEMORY_SIZE 10000
#define MAX_HEADER_SIZE 1000

typedef struct {
	int crc;
	int len;
	int flag;
} header;

static header* curMemoryPos;		// pointer to the last allocated header position
static char memory[MAX_MEMORY_SIZE]; // HW storage


static void * mem_alloc (int size) {
	header  * tmp = (header *) &memory[0];
	int curAllocatedSize = 0;

	if (curMemoryPos == NULL){
		curMemoryPos = (header *) &memory[0];
	}

	while (tmp != curMemoryPos){
		if (tmp->flag == 0) {
			if (tmp->len >= size) {
				//alte speichergröße merken
				int sizeOld = tmp->len;
				tmp->len = size;
				tmp->flag = 1;

				int sizeAvailable = sizeOld - sizeof(header) - size;
				header * newBlock = tmp + sizeof(header) + tmp->len;

				newBlock->flag = 0;
				newBlock->len = sizeAvailable;
			}
		}
		curAllocatedSize = curAllocatedSize + size + sizeof(header);
		tmp = tmp + sizeof(header) + tmp->len;
	}
	if ((MAX_MEMORY_SIZE - curAllocatedSize) > (size + sizeof(header))) {
		tmp->len = size;
		tmp->flag = 1;
		curMemoryPos = curMemoryPos + sizeof(header) + size;
		memory[curAllocatedSize] = (char *) tmp;
		return (void *) (tmp + sizeof(header));
	}

	return NULL;	//Fehlermeldung, nicht genÃ¼gend Speicher Ã¼brig
}

int main() {
	mem_alloc(512);
	mem_alloc(1024);
	return 0;
}

void mem_free(void* delBlock) {
	//Flag des Headers an der Adresse delBlock auf Null
	header * delHeader;

	delHeader = (header*) delBlock - sizeof(header);

	delHeader->flag = 0;
	defragment();
}

void defragment() {
		header * current = (header*) memory[0];
		header * next = current + current->len + sizeof(header);
		while (next != curMemoryPos){
			next = current + current->len + sizeof(header); //header nach current

			while (next->flag == 0){
				current->len = current->len + next->len + sizeof(header);
				next = next + next->len;		//block nach next
			}
			current = next;
		}
}
