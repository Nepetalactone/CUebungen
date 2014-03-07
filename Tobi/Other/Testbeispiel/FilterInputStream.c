#include "FilterInputStream.h"

bool hasNext()
{
	return input.hasNext();
}

byte next()
{
	return input.next();
}

void delete()
{
	input.delete();
}

byte filter(char character)
{
	byte b = character;
	return b;
}