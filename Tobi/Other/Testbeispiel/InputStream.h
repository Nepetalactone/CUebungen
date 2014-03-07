#include <stdio.h>
#include "helper.h"

bool is_hasNext();
byte is_next();
void is_delete();

typedef struct InputStream
{
	char * stream;
	int index;
	bool (*hasNext)();
	byte (*next)();
	void (*delete)();
} InputStream_t;

InputStream_t is_t = { "blablabla", 0, &is_hasNext, &is_next, &is_delete };