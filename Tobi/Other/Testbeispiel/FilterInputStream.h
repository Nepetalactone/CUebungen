#include "InputStream.h"

bool fis_hasNext();
byte fis_next();
void fis_delete();

typedef struct FilterInputStream
{
	InputStream_t * is;
	bool (*hasNext)();
	byte (*next)();
	void (*delete)();
} FilterInputStream_t;

FilterInputStream_t fis_t = { &is_t, &fis_hasNext, &fis_next, &fis_delete };