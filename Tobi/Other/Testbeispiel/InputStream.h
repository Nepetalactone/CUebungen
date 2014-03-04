#include <stdio.h>
#include "bool.h"

bool hasNext();
byte next();
void delete();

char peek;

typedef struct
{
	bool (*hasNext)(); 
	byte (*next)();
	void (*delete)();
} InputStream;