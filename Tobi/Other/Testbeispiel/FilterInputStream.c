#include "FilterInputStream.h"

bool fis_hasNext(struct FilterInputStream * fis)
{
	return fis->is->hasNext(fis->is);
}

byte fis_next(struct FilterInputStream * fis)
{
	return fis->is->next(fis->is);
}

void fis_delete(struct FilterInputStream * fis)
{
}

FilterInputStream_t * newFilterInputStream(InputStream_t * input)
{
	FilterInputStream_t * fis_t = (FilterInputStream_t*) malloc(sizeof(FilterInputStream_t));
	fis_t->is = input;
	fis_t->hasNext = fis_hasNext;
	fis_t->next = fis_next;
	fis_t->delete = fis_delete;
	return fis_t;
}