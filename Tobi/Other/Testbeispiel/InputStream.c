#include "InputStream.h"

bool is_hasNext(struct InputStream * input)
{
	char * c = input->stream;
	c += input->index;
	//printf("2%c\n", *c);
	c += 1;
	//printf("3%c\n", *c);
	if (c == '\0')
	{
		return FALSE;
	}
	return TRUE;
}

byte is_next(struct InputStream * input)
{
	char * c = input->stream;
	c += input->index;
	if (is_hasNext(input) == TRUE)
	{
		input->index++;
	}
	return * c;
}

void is_delete(struct InputStream * input)
{
}

InputStream_t * newInputStream()
{
	InputStream_t * in_t = (InputStream_t*) malloc(sizeof(InputStream_t));
	in_t->stream = "blablabla";
	in_t->index = 0;
	in_t->hasNext = is_hasNext;
	in_t->next = is_next;
	in_t->delete = is_delete;
	return in_t;
}