#include "InputStream.h"

bool hasNext();
byte next();
void delete();
byte filter(char character);

InputStream input;

typedef struct
{
	bool (*hasNext)();
	byte (*next)();
	void (*delete)();
	byte (*filter)(char character);
} FilterInputStream;