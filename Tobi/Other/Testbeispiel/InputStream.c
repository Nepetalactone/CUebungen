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