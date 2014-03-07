#include "UpperInputStream.h"

bool uis_hasNext(struct UpperInputStream * uis)
{
	return uis->fis->hasNext(uis->fis);
}

byte uis_next(struct UpperInputStream * uis)
{
	char c = uis->fis->next(uis->fis);
	
	if ((c >= 'a') || (c <= 'z'))
	{
		c += 'A' - 'a';
	}
	return c;
}

void uis_delete(struct UpperInputStream * uis)
{
	
}

UpperInputStream_t * newUpperInputStream(FilterInputStream_t * input)
{
	UpperInputStream_t * uis_t = (UpperInputStream_t*) malloc(sizeof(UpperInputStream_t));
	uis_t->fis = input;
	uis_t->hasNext = uis_hasNext;
	uis_t->next = uis_next;
	uis_t->delete = uis_delete;
	return uis_t;
}