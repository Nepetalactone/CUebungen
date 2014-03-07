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