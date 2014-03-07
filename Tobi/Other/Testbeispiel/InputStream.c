#include "InputStream.h"

bool hasNext()
{
	if (peek == NULL)
	{
		peek = getchar();
		return peek;
	} else
	{
		return peek;
	}
}

byte next()
{
	//peek = NULL;
	//return getchar();
	return (byte) 'x';
}

void delete()
{
}